#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define UNUSED(x) ((void)x)

#define MAX 1024

#define RD_END 0
#define WR_END 1



int main(int argc, char** argv){
    check_error(argc == 1, "./a.out");
    UNUSED(argv);

    int ctppipeFds[2];
    int ptcpipeFds[2];
    check_error(pipe(ctppipeFds) != -1, "pipe");
    check_error(pipe(ptcpipeFds) != -1, "pipe");
    pid_t child = fork();

    if(child == 0){
        close(ptcpipeFds[WR_END]);
        close(ctppipeFds[RD_END]);

        int sum = 0;
        char buffer[MAX];
        memset(buffer, 0, MAX);
        struct stat fileinfo;

        int i = 0;

        while(read(ptcpipeFds[RD_END], &buffer[i], 1) > 0){
            if(buffer[i] != '\n'){i++; continue;}
            buffer[i] = '\0';
            i = 0;
            int res = lstat(buffer, &fileinfo);
            if(res == -1)continue;
            if(!S_ISREG(fileinfo.st_mode)) continue;
            if((S_IROTH & fileinfo.st_mode) == 0) continue;

            FILE* file = fopen(buffer, "r");
            size_t n = 0;
            char* buff = NULL;
            
            while(getline(&buff, &n, file) > 0) sum ++;
            fclose(file);
            free(buff);
        }
        close(ptcpipeFds[RD_END]);

        memset(buffer, 0, MAX);
        sprintf(buffer, "%d", sum);

        write(ctppipeFds[WR_END], buffer, sizeof(buffer));
        close(ctppipeFds[WR_END]);
        exit(EXIT_SUCCESS);
    }else{
        close(ptcpipeFds[RD_END]);
        close(ctppipeFds[WR_END]);

        char buffer[MAX];
        memset(buffer, 0, MAX);

        while(scanf("%s", buffer) != EOF){
            check_error(write(ptcpipeFds[WR_END], buffer, strlen(buffer)) != -1, "write");
            check_error(write(ptcpipeFds[WR_END], "\n", 1), "write");
        }
        
        close(ptcpipeFds[WR_END]);

        check_error(-1 != read(ctppipeFds[RD_END], buffer, MAX), "read");
        close(ctppipeFds[RD_END]);
        check_error(wait(NULL) != -1, "wait");
        
        printf("%s\n", buffer);
        exit(EXIT_SUCCESS);
    }

    exit(EXIT_SUCCESS);
}