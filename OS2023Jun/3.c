#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

int main(int argc, char** argv){
    check_error(argc == 4, "./a.out fpath a b");

    int a = atoi(argv[2]);
    int b = atoi(argv[3]);

    int fd = open(argv[1], O_RDONLY);
    check_error(fd != -1, "open");
    check_error((off_t)-1 != lseek(fd, a, SEEK_SET), "lseek");
    char* dir = malloc(sizeof(char)*(b+1));
    check_error(read(fd, dir, b) != -1, "read");
    dir[b] = '\0';
    mode_t oldUmask = umask(0);
    check_error(mkdir(dir, 0777) != -1, "mkdir");
    umask(oldUmask);
    exit(EXIT_SUCCESS);
}