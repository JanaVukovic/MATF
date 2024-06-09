#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <pwd.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

int main(int argc, char** argv){
    check_error(argc > 1, "./a.out files");
    int indeks = -1;
    long int maks = 0;
    struct stat fileinfo;
    for(int i = 0; i <argc; i++){
        if(-1 == lstat(argv[i], &fileinfo))continue;
        if(!S_ISREG(fileinfo.st_mode))continue;
        if(fileinfo.st_size > maks){
            maks = fileinfo.st_size;
            indeks = i;
        }
    }
    if(indeks != -1){
        check_error(lstat(argv[indeks], &fileinfo) != -1, "lstat");
        struct passwd* name= getpwuid(fileinfo.st_uid);
        check_error(name != NULL, "getpwuid");
        char* real = strrchr(argv[indeks], '/');
        if(real == NULL) real = argv[indeks];
        printf("%s %ld %s\n", name->pw_name, fileinfo.st_size, real);
    }else{
        printf("neuspeh\n");
    }
    exit(EXIT_SUCCESS);
}