#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <pwd.h>
#include <ftw.h>
#include <time.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

long int size = 0;
#define mod (7*24*60*60)
char* extension;

int fn(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf){
    if(typeflag != FTW_F) return 0;
    char* found = strstr(fpath, extension);
    if(found == NULL)return 0;
    if((found - fpath) != (strlen(fpath)-strlen(extension)))return 0;
    time_t now = time(NULL);
    if((now - sb->st_mtime) <= mod)
        size += sb->st_size;
    return 0;
}

int main(int argc, char** argv){
    check_error(argc == 3, "./a.out dir ekst");

    extension = argv[2];
    check_error(-1 != nftw(argv[1], fn, 50, 0), "nftw");
    printf("%ld\n", size);
    exit(EXIT_SUCCESS);

}