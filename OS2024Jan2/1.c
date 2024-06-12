#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <utime.h>

#define check_error(cond, userMessage)\
do{\
    if(!(cond)){\
        perror(userMessage);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

int main(int argc, char** argv){
    check_error(argc == 1, "argc");

    char *buf;
    check_error((buf = getcwd(NULL, 0)) != NULL, "getwd"); //moze i samo "."

    time_t modifikacija = 0;
    time_t pristup = 0;
    DIR * directory = opendir(buf);
    struct dirent* curr = NULL;
    while((curr = readdir(directory)) != NULL){
        struct stat fileinfo;
        check_error(stat(curr->d_name, &fileinfo)!=-1, "stat");
        if(fileinfo.st_mtime > modifikacija)
            modifikacija = fileinfo.st_mtime;
        if(fileinfo.st_atime > pristup)
            pristup = fileinfo.st_atime;
    }
    struct utimbuf times;
    times.modtime = modifikacija;
    times.actime = pristup;
    check_error(closedir(dir) != -1, "closedir");
    dir = opendir(".");
    check_error(dir != NULL, "opendir");
    curr = NULL;
    while((curr = readdir(directory)) != NULL){
        check_error(utime(curr->d_name, &times)!=-1, "utime");
    }
    check_error(-1 != closedir(directory), "closedir");
    return 0;
}
