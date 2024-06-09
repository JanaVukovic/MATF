#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define MAX (1024)

int main(int argc, char** argv){
    check_error(argc == 4, "./a.out file a b");

    int fdRead = open(argv[1], O_RDONLY);
    int fdWrite = open(argv[1], O_WRONLY);

    check_error(fdRead != -1, "open");
    check_error(fdWrite != -1, "open");

    long int a = atol(argv[2]);
    long int b = atol(argv[3]);

    check_error(lseek(fdRead, a, SEEK_SET) != (off_t)-1, "lseek");
    check_error(lseek(fdWrite, a, SEEK_SET) != (off_t)-1, "lseek");

    char buffer[MAX];
    check_error(-1 != read(fdRead, buffer, b), "read");
    buffer[b] = '\0';
    printf("%s\n%ld\n", buffer, strlen(buffer));

    int readbytes = 0;
    while((readbytes = read(fdRead, buffer, MAX)) > 0)
        check_error(write(fdWrite, buffer, readbytes) != -1, "write");

    close(fdRead);
    close(fdWrite);
    exit(EXIT_SUCCESS);
}