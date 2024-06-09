#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <errno.h>
#include <limits.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define check_errorP(perrno, usrmsg)\
do{\
    int _perrno = perrno;\
    if(_perrno > 0){\
        errno = _perrno;\
        check_error(-1, usrmsg);\
    }\
}while(0)

#define UNUSED(x) ((void)x)

typedef struct{
    double maks;
    pthread_mutex_t lock;
}OsStruct;

OsStruct global;
int m, n;

void* fun(void* argv){
    double* array = (double*)argv;
    double maks = array[0];
    for(int i = 0; i < m; i++){
        if(array[i] > maks)
            maks = array[i];
    }
    check_errorP(pthread_mutex_lock(&global.lock), "lock");
    if(maks > global.maks)global.maks = maks;
    check_errorP(pthread_mutex_unlock(&global.lock), "unlock");
    return NULL;
}

int main(int argc, char** argv){
    check_error(argc == 1, "./a.out");
    UNUSED(argv);

    check_errorP(pthread_mutex_init(&global.lock, NULL), "mutex_init");

    scanf("%d %d", &m, &n);

    double **arr = malloc(m*sizeof(double*));
    for(int i = 0; i < m; i++)
        arr[i] = malloc(sizeof(double)*n);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%lf", &arr[i][j]);
        }
    }

    pthread_t *tids = malloc(m*sizeof(pthread_t));

    for(int i = 0; i < m; i++){
        check_errorP(pthread_create(&tids[i], NULL, fun, arr[i]), "pthread_create");
    }
    for(int i = 0; i < m; i++){
        check_errorP(pthread_join(tids[i], NULL), "join");
    }
    for(int i = 0; i < m; i++)
        free(arr[i]);

    free(arr);
    free(tids);

    check_errorP(pthread_mutex_destroy(&global.lock), "destroy");
    printf("%lf\n", global.maks);
    exit(EXIT_SUCCESS);
}