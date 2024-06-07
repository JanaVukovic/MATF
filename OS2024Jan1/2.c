#define _XOPEN_SOURCE 700
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <ftw.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <limits.h>


#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define UNUSED(x) ((void)x)

int fn(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf){
    if(!S_ISFIFO(sb->st_mode)) return 0;
    if(((S_IRGRP | S_IWGRP)& sb->st_mode) != (S_IRGRP | S_IWGRP))return 0;

    struct passwd *a = getpwuid(sb->st_uid);
    char * myPath = realpath(fpath, NULL);

    printf("%s: %s\n", myPath, a->pw_name);
    
    free(myPath);
    return 0;
}

int main(int argc, char** argv){
    check_error(argc == 2, "./a.out dir");

    check_error(-1 != nftw(argv[1], fn, 60, 0), "nftw");

    exit(EXIT_SUCCESS);
}