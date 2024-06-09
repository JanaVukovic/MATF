#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <pwd.h>
#include <ftw.h>
#include <time.h>
#include <pthread.h>
#include <errno.h>
#include <stdbool.h>
#include <ctype.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define check_errorP(_perrno, usrmsg)\
do{\
    int _perror = _perrno;\
    if(_perror > 0){\
        errno = _perror;\
        check_error(false, usrmsg);\
    }\
}while(0)

typedef struct{
    long int all;
    long int maks;
    char most;
    pthread_mutex_t lock;
}global;

global data;

char* fpath;

void *fun(void* argv){
    int fd = open(fpath, O_RDONLY);
    char c = (*(int*)argv) + 'a';
    char buffer[1];
    int num = 0;
    while(read(fd, buffer, 1) > 0){
        if(tolower(buffer[0]) == c)num++;
    }
    check_errorP(pthread_mutex_lock(&data.lock), "lock");
    if(num > data.maks){
        data.maks = num;
        data.most = c;
    }
    check_errorP(pthread_mutex_unlock(&data.lock), "unlock");
    close(fd);
    return NULL;
}

int main(int argc, char** argv){
    check_error(argc == 2, "./a.out fpath");

    fpath = argv[1];

    data.all = data.maks = 0;
    
    check_errorP(pthread_mutex_init(&data.lock, NULL), "mutex_init");

    pthread_t *tids = malloc(26*sizeof(pthread_t));
    check_error(tids != NULL, "malloc");

    int* nums = malloc(sizeof(int)*26);
    check_error(nums != NULL, "malloc");

    for(int i = 0; i < 26; i++){
        nums[i] = i;
        check_errorP(pthread_create(&tids[i], NULL, fun, &nums[i]), "pthread_create");
    }

    for(int i = 0; i < 26; i++){
        check_errorP(pthread_join(tids[i], NULL), "pthread_join");
    }

    printf("%ld %c\n", data.maks, data.most);

    free(nums);
    free(tids);
    check_errorP(pthread_mutex_destroy(&data.lock), "destroy");

    exit(EXIT_SUCCESS);
}