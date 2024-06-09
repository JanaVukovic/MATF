#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

#define MAX 1024

time_t mod = -1;
char fajl[MAX];

void find(char* path){
    DIR* dir = opendir(path);
    check_error(dir != NULL, "opendir");
    struct dirent *entry = NULL;
    while((entry = readdir(dir)) != NULL){
        char* new = malloc(sizeof(char)*(strlen(path) + strlen(entry->d_name) + 2));
        strcpy(new, path);
        strcat(new, "/");
        strcat(new, entry->d_name);
        struct stat fileinfo;
        check_error(lstat(new, &fileinfo) != -1, "lstat");
        if(S_ISLNK(fileinfo.st_mode)){
            if(fileinfo.st_mtime > mod){
                char* name = strrchr(entry->d_name, '/');
                if(name == NULL)strcpy(fajl, entry->d_name);
                else strcpy(fajl, name);
                mod = fileinfo.st_mtime;
            }
        }else if(S_ISDIR(fileinfo.st_mode)){
            find(new);
        }
        free(new);
    }
    check_error(-1 != closedir(dir), "closedir");
}

int main(int argc, char ** argv){
    check_error(argc == 2, "./a.out dirpath");


    struct stat fileinfo;
    check_error(lstat(argv[1], &fileinfo) != -1, "lstat");

    check_error(S_ISDIR(fileinfo.st_mode), "not a directory");

    strcpy(fajl, "neuspeh");

    find(argv[1]);

    printf("%s\n", fajl);

    exit(EXIT_SUCCESS);
}