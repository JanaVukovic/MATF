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
#include <limits.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define MAX 1024
#define RD_END 0
#define WR_END 1

int main(int argc, char** argv){
    check_error(argc > 1, "./a.out files");
    char fajl[MAX];
    long int mostLines = 0;

    for(int i = 1; i < argc; i++){
        int fds[2];
        check_error(-1 != pipe(fds), "pipe");
        pid_t child = fork();
        if(child == 0){
            close(fds[RD_END]);
            check_error(-1 != dup2(fds[WR_END], STDOUT_FILENO), "dup2");
            execlp("cat", "cat", argv[i], NULL);
            close(fds[WR_END]);
            exit(EXIT_FAILURE);
        }else{
            close(fds[WR_END]);
            int status;
            check_error(wait(&status), "wait");
            if(status > 0)continue;
            char buffer[MAX];
            long int curr = 0;
            while(read(fds[RD_END], buffer, 1) > 0){
                if(buffer[0] == '\n')curr++;
            }
            close(fds[RD_END]);
            if(curr > mostLines){
                mostLines = curr;
                char * new = strrchr(argv[i], '/');
                if(new == NULL) strcpy(fajl, argv[i]);
                else strcpy(fajl, new);
            }
        }

    }

    printf("%s %ld\n", fajl, mostLines);

    exit(EXIT_SUCCESS);
}