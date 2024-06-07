#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdbool.h>
#include <signal.h>
#include <time.h>
#include <errno.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define MAX 255

int main(int argc, char** argv){
    check_error(argc == 3, "./a.out fileA, fileB");

    int fd = open(argv[1], O_RDWR);
    check_error(fd != -1, "open");
    FILE* file = fdopen(fd, "r+");
    check_error(file != NULL, "fdopen");

    FILE* output = fopen(argv[2], "w");
    check_error(output != NULL, "fopen");

    char buffer[MAX];
    int lines = 0;
    while(fgets(buffer, MAX, file) != NULL){
        struct flock lock;
        lock.l_type = F_WRLCK;
        lock.l_start = ftell(file);
        lock.l_len = -strlen(buffer);
        lock.l_whence = SEEK_SET;

        int res = fcntl(fd, F_SETLK, &lock);
        if(res != -1){
            fprintf(output, "%s", buffer);
            lines++;
            lock.l_type = F_UNLCK;
            check_error(-1 != fcntl(fd, F_SETLK, &lock), "fcntl");
        }else{
            if(errno != EACCES && errno != EAGAIN)
                check_error(1 == 0, "...");
            continue;
        }
    }
    printf("%d\n", lines);
    fclose(output);
    fclose(file);
    exit(EXIT_SUCCESS);
}