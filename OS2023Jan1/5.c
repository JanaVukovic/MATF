#define _XOPEN_SOURCE 700
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
#include <string.h>

#define MAX 1024

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

int main(int argc, char** argv){
    check_error(argc == 2, "./a.out fpath");
    
    int fd = open(argv[1], O_RDWR);
    check_error(-1 != fd, "open");

    FILE* f = fdopen(fd, "r+");
    check_error(NULL != f, "fdopen");

    char buffer[MAX];

    while(fgets(buffer, MAX, f) != NULL){
        struct flock lock;
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = ftell(f);
        lock.l_len = -strlen(buffer);

        fcntl(fd, F_GETLK, &lock);
        if(lock.l_type == F_UNLCK){
            lock.l_type = F_RDLCK;
        }else{
            printf("%s w\n", buffer);
            continue;
        }
        fcntl(fd, F_GETLK, &lock);
        if(lock.l_type == F_UNLCK) continue;

        printf("%s r", buffer);
    }
    
    fclose(f);
    exit(EXIT_SUCCESS);
}