#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <ftw.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <limits.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <signal.h>
#include <utime.h>
#include <time.h>
#include <sys/time.h>

extern char** environ;

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define UNUSED(x) ((void)x)

bool shouldquit = false;
int sigusr1 = 0;
int sigusr2 = 0;

void sighandler(int signum){
    switch (signum){
        case SIGUSR1:
            sigusr1 = 1;
            break;
        case SIGUSR2:
            sigusr2 = 1;
            break;
        default:
            shouldquit = true;
            break;
    }
        
}

int main(int argc, char ** argv){
    check_error(argc == 2, "./a.out secs");
    time_t new = atol(argv[1]);
    
    char* putanja = getenv("PUTANJA");
    check_error(putanja != NULL, "getenv");
    
    check_error(SIG_ERR != signal(SIGUSR1, sighandler), "signal");
    check_error(SIG_ERR != signal(SIGUSR2, sighandler), "signal");
    check_error(SIG_ERR != signal(SIGQUIT, sighandler), "signal");

    while(!shouldquit){
        pause();
        if(sigusr1 == 1){
            
            struct stat fileinfo;
            check_error(-1 != stat(putanja, &fileinfo), "stat");
            if((S_IRUSR & fileinfo.st_mode) == S_IRUSR) printf("r");
                else printf("-");
            if((S_IWUSR & fileinfo.st_mode) == S_IWUSR) printf("w");
                else printf("-");
            if((S_IXUSR & fileinfo.st_mode) == S_IXUSR) printf("r\n");
                else printf("-\n");
            sigusr1 = 0;
        }
        if(sigusr2 == 1){
            struct utimbuf modify = {new, new};
            check_error(-1 != utime(putanja, &modify), "utime");
            sigusr2 = 0;
        }
    }
    exit(EXIT_SUCCESS);
}