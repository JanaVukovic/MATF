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

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define UNUSED(x) ((void)x)

#define RD_END 0
#define WR_END 1
#define MAX 1024

int main(int argc, char** argv){
    UNUSED(argv);
    check_error(argc == 1, "argc");

    int pipeFds[2];
    check_error(-1 != pipe(pipeFds), "pipe");
    pid_t child = fork();

    if(child == 0){
        close(pipeFds[RD_END]);
        check_error(-1 != dup2(pipeFds[WR_END], STDOUT_FILENO), "dup2");
        execlp("pwd", "pwd", NULL);
        close(pipeFds[WR_END]);
        exit(EXIT_FAILURE);
    }else{
        close(pipeFds[WR_END]);
        int status;
        check_error(-1 != waitpid(child, &status, 0), "wait");
        
        char buffer[MAX];
        int readbytes;
        long int size = 0;
        while((readbytes = read(pipeFds[RD_END], &buffer, MAX)) > 0)
            size += readbytes;
        check_error(readbytes != -1, "read");
        printf("%ld\n", size);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_SUCCESS);
}