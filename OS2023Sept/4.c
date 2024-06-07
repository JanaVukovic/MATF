#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdbool.h>

#define UNUSED(x) ((void)x)

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define check_errorP(Perrno, usrmsg)\
do{\
    int _perrno = Perrno;\
    if(_perrno > 0){\
        errno = _perrno;\
        check_error(false, usrmsg);\
    }\
}while(0)

typedef struct{
    int data;
    pthread_mutex_t lock;
}OSdata;

OSdata global;

void *fun(void* arg){
    int n = *((int*)arg);
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n /= 10;
    }
    check_errorP(pthread_mutex_lock(&global.lock), "lock");
    global.data += sum;
    check_errorP(pthread_mutex_unlock(&global.lock), "unlock");
    return NULL;
}

int main(int argc, char ** argv){
    check_error(argc == 1, "./a.out");
    UNUSED(argv);

    global.data = 0;

    check_errorP(pthread_mutex_init(&global.lock, NULL), "mutex_init");


    int n;
    scanf("%d", &n);
    pthread_t* tids = malloc(sizeof(pthread_t)*n);
    check_error(tids != NULL, "malloc");

    int *a = malloc(sizeof(int) * n);
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0 ; i < n; i++)
        check_errorP(pthread_create(&tids[i], NULL, fun, &a[i]), "create");
    for(i = 0 ; i < n; i++)
        check_errorP(pthread_join(tids[i], NULL), "join");

    printf("%d\n", global.data);

    free(tids);
    free(a);

    check_errorP(pthread_mutex_destroy(&global.lock), "mutex_destroy");
    exit(EXIT_SUCCESS);
}