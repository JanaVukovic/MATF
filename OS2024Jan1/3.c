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

#define RD_END 0
#define WR_END 1

#define MAX 1024

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define UNUSED(x) ((void)x)

int main(int argc, char** argv){
    check_error(argc == 2, "./a.out dir");

    int pipeFds[2];
    check_error(-1 != pipe(pipeFds), "pipe");
    pid_t child = fork();

    if(child == 0){
        close(pipeFds[WR_END]);
        int readbytes;
        char buffer[MAX];

        while((readbytes = read(pipeFds[RD_END], &buffer, MAX)) == 0);

        mode_t oldUmask = umask(0);
        check_error(-1 != mkdir(buffer, 0777), "mkdir");
        umask(oldUmask);
        exit(EXIT_SUCCESS);
    }else{
        close(pipeFds[RD_END]);
        char * dir = malloc(sizeof(char)*(strlen(argv[1]) + 5));
        strcpy(dir, argv[1]);
        strcat(dir, ".dir");
        check_error(-1 != write(pipeFds[WR_END], dir, strlen(dir)+1), "write");
        close(pipeFds[WR_END]);
        free(dir);
        int status;
        check_error(wait(&status) != -1, "wait");

        exit(status);
    }

    exit(EXIT_SUCCESS);
}