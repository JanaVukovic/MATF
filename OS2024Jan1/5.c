#define _XOPEN_SOURCE 700
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <ftw.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <limits.h>
#include <errno.h>
#include <pthread.h>


#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define check_errorP(threadError, usrmsg)\
do{\
    int thError = threadError;\
    if(thError > 0){\
        errno = thError;\
        check_error(0, usrmsg);\
    }\
}while(0)

typedef struct{
    long int sum;
    pthread_mutex_t lock;
}data;

data global;

void* fun(void *arg){
    char* path = arg;

    struct stat fileinfo;
    check_error(stat(path, &fileinfo) != -1, "stat");
    int size = fileinfo.st_size;

    check_errorP(pthread_mutex_lock(&global.lock), "lock");
    global.sum += size;
    check_errorP(pthread_mutex_unlock(&global.lock), "unlock");
    
    return NULL;
}

int main(int argc, char** argv){
    check_error(argc >= 2, "argc");

    global.sum = 0;

    check_errorP(pthread_mutex_init(&global.lock, NULL), "mutex_init");

    int threadNo = argc-1;
    pthread_t *tids = malloc(threadNo*sizeof(pthread_t));
    check_error(tids != NULL, "malloc");

    int i;
    for(i = 0; i < threadNo; i++){
        check_errorP(pthread_create(&tids[i], NULL, fun, argv[i+1]), "pthread_create");
    }

    for(int i = 0; i < threadNo; i++){
        check_errorP(pthread_join(tids[i], NULL), "pthreads_join");
    }


    printf("%ld\n", global.sum);

    check_errorP(pthread_mutex_destroy(&global.lock), "mutex_destroy");

    free(tids);

    exit(EXIT_SUCCESS);
}