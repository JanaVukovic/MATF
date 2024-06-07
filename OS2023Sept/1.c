#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

void printGit(char *path){
    struct stat fileinfo;
    check_error(stat(path, &fileinfo) != -1, "stat");

    if(!S_ISDIR(fileinfo.st_mode))return;
    
    DIR *dir = opendir(path);
    check_error(dir != NULL, "opendir");

    struct dirent* entry = NULL;
    while((entry = readdir(dir)) != NULL){
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)return;
        char* new = malloc(sizeof(char)*(strlen(path)+strlen(entry->d_name)+2));
        strcpy(new, path);
        strcat(new, "/");
        strcat(new, entry->d_name);
        char* git = strstr(new, ".git");
        if(git == NULL) printGit(new);
        else{
            char* real = realpath(path, NULL);
            printf("%s\n", real);
            free(real);
        }
        free(new);
    }

    check_error(closedir(dir) != -1, "closedir");
}

int main(int argc, char** argv){
    check_error(argc == 2, "./a.out dir");

    printGit(argv[1]);

    exit(EXIT_SUCCESS);
}