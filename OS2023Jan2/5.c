#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>
#include <sys/mman.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define MAX_SIZE 1024

typedef struct{
    sem_t dataReady;
    sem_t operationDone;
    int array[MAX_SIZE];
    int arraySize;
    int result[MAX_SIZE];
}OsInputData;

void* getBlock(const char* fpath, unsigned* size){
    int memFd = shm_open(fpath, O_RDONLY, 0);
    check_error(memFd != -1, "shm_open");
    struct stat fileinfo;
    check_error(-1 != fstat(memFd, &fileinfo), "fstat");
    *size = fileinfo.st_size;
    void* addr;
    check_error(MAP_FAILED != (addr = mmap(NULL, *size, PROT_READ | PROT_WRITE, MAP_SHARED, memFd,  0)), "mmap");
    close(memFd);
    return addr;
}

int main(int argc, char** argv){
    check_error(argc == 2, "./a.out fpath");
    unsigned size;
    OsInputData *data = getBlock(argv[1], &size);

    check_error(sem_wait(&data->dataReady) != -1, "sem_wait");
    int j = 0;
    for(int i = 0; i < data->arraySize; i++){
        if(data->array[i] % 2 == 0){
            data->result[j] = data->array[i];
            j++;
        }
    }
    if(j == 0)j = -1;
    data->arraySize = j;
    check_error(sem_post(&data->operationDone) != -1, "sem_post");
    check_error(munmap(data, size) != -1, "munmap");
    
    exit(EXIT_SUCCESS);
}