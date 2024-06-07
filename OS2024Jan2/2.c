#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


#define MAX 1024
#define RD_END 0
#define WR_END 1

#define check_error(cond, usermsg)\
do{\
    if(!(cond)){\
        perror(usermsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

extern char** environ;

int main(){
    char* path = getenv("REG_FAJL");
    check_error(path != NULL, "getenv");
    int pipeFds[2];
    check_error(-1 != pipe(pipeFds), "pipe");
    pid_t child = fork();
    if(child == 0){
        close(pipeFds[RD_END]);
        check_error(-1 != dup2(STDOUT_FILENO, pipeFds[WR_END]), "dup2");
        check_error(execlp("cat", "cat", path, NULL) != -1, "execlp");
    }else{
        check_error(wait(NULL) != -1, "wait");
        close(pipeFds[WR_END]);
        int maxLength = 0;
        FILE* input = fdopen(pipeFds[RD_END], "r");
        check_error(input != NULL, "fdopen");
        char *buffer = NULL;
        while(-1 != getline(&buffer, 0, input)){
            int n = strlen(buffer);
            if(n > maxLength)
                maxLength = n;
        }
        free(buffer);
        fclose(input);
        printf("%d\n", maxLength);
    }
    exit(EXIT_SUCCESS);
}