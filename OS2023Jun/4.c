#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdbool.h>
#include <signal.h>
#include <time.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define MAX 1024

bool shouldquit = false;

int sigusr1 = 0;
int sigusr2 = 0;

void sighandler(int signum){
    switch(signum){
        case SIGUSR1:
            sigusr1 = 1;
            break;
        case SIGUSR2:
            sigusr1 = 1;
            break;
        default:
            shouldquit = true;
            break;
    }
}

int main(){

    check_error(SIG_ERR != signal(SIGUSR1, sighandler), "signal");
    check_error(SIG_ERR != signal(SIGUSR2, sighandler), "signal");
    check_error(SIG_ERR != signal(SIGQUIT, sighandler), "signal");

    char path[MAX];

    while(!shouldquit){
        scanf("%s", path);
        pause();
        if(sigusr1){
            sigusr1 = 0;
            struct stat fileinfo;
            check_error(stat(path, &fileinfo)!=-1, "stat");
            printf("%ld\n", fileinfo.st_size);
        }else if(sigusr2){
            sigusr2 = 0;
            struct stat fileinfo;
            check_error(stat(path, &fileinfo)!= -1, "stat");
            time_t curr = fileinfo.st_mtime;
            struct tm *timet = localtime(&curr);
            check_error(timet != NULL, "localtime");
            printf("%d\n", timet->tm_mday);
        }
    }
    exit(EXIT_SUCCESS);
}