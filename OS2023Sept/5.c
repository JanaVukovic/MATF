#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <sys/wait.h>
#include <grp.h>
#include <pwd.h>
#include <semaphore.h>
#include <sys/mman.h>

#define MAX_SIZE 1024

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define UNUSED(x) ((void)x)

typedef struct{
    sem_t dataReady;
    sem_t operationDone;
    int arraySize;
    char array[MAX_SIZE];
    int resultSize;
    char result[MAX_SIZE];
}OsInputData;

void* getBlock(char* path, unsigned* size){
    int memFd = shm_open(path, O_RDWR, 0);
    check_error(memFd != -1, "shm_open");

    struct stat fileinfo;
    check_error(fstat(memFd, &fileinfo) != -1, "fstat");
    *size = fileinfo.st_size;

    void* addr = mmap(NULL, *size, PROT_READ|PROT_WRITE, MAP_SHARED, memFd, 0);
    check_error(MAP_FAILED != addr, "mmap");

    close(memFd);
    return addr;
}

int main(int argc, char** argv){
    check_error(argc == 2, "./a.out shmpath");
    unsigned size = 0;
    OsInputData* data = getBlock(argv[1], &size);

    check_error(sem_wait(&(data->dataReady))!=-1, "sem_wait");
    
    int i = 0, j = 0;
    for(i = 0; i < data->arraySize; i++){
        if(isdigit(data->array[i])){
            data->result[j] = data->array[i];
            j++;
        }
    }
    data->resultSize = j;
    check_error(sem_post(&(data->operationDone))!=-1, "sem_post");

    printf("%d\n", j);

    exit(EXIT_SUCCESS);
}