#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h> 

#define MAX_ARRAY 1024

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

typedef struct{
    sem_t inDataReady;
    sem_t averageCalculated;
    float array[MAX_ARRAY];
    unsigned arrayLen;
    float average;
}OsData;

void *getBlock(const char* path, unsigned *size){
    int memFd = shm_open(path, O_RDWR, 0);
    check_error(memFd != -1, "shm_open");

    struct stat fileinfo;
    check_error(fstat(memFd, &fileinfo) != -1, "stat");
    *size = fileinfo.st_size;

    void *addr;
    check_error(MAP_FAILED != (addr = mmap(NULL, *size, PROT_READ | PROT_WRITE, MAP_SHARED, memFd, 0)), "mmap");
    close(memFd);
    return addr;
}

int main(int argc, char ** argv){
    check_error(argc == 2, "argc");

    int size;
    OsData * data = getBlock(argv[1], &size); 

    check_error(sem_wait(&data->inDataReady) != -1, "sem_wait");

    float sum = 0;
    for(unsigned i = 0; i < data->arrayLen; i++){
        sum += data->array[i];
    }
    sum /= data->arrayLen;
    data->average = sum;
    check_error(sem_post(&data->averageCalculated)!= -1, "sem_post");

    check_error(munmap(data, size) != -1, "munmap");
    return 0;
}