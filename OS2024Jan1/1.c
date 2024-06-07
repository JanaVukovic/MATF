#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

int main(int argc, char ** argv){
    check_error(argc >= 2, "argc");

    int indeks = 1;
    int maks = 0;
    struct stat fileinfo;

    for(int i = 1; i < argc; i++){
        check_error(stat(argv[i], &fileinfo), "stat");
        if(fileinfo.st_size > maks){
            maks = fileinfo.st_size;
            indeks = i;
        }
    }
    char* poz = strrchr(argv[indeks], '/');
    if(poz == NULL)printf("%s\n", argv[indeks]);
    else printf("%s\n", poz+1);
    exit(EXIT_SUCCESS);
}