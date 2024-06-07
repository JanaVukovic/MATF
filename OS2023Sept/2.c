#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
        perror(usrmsg);\
        exit(EXIT_FAILURE);\
    }\
}while(0)

int main(int argc, char** argv){
    check_error(argc >= 2, "argc");

    for(int i = 1 ; i < argc ; i++){
        struct stat fileinfo;
        check_error(stat(argv[i], &fileinfo) != -1, "stat");

        struct passwd * pw = getpwuid(fileinfo.st_uid);
        check_error(pw != NULL, "getpwuid");

        int ngroups = 10;
        gid_t *groups = malloc(sizeof(gid_t)*ngroups);
        if(getgrouplist(pw->pw_name, pw->pw_gid, groups, &ngroups) == -1){
            groups = realloc(groups, sizeof(gid_t)*ngroups);
            getgrouplist(pw->pw_name, pw->pw_gid, groups, &ngroups);
        }
        struct group *gr; 
        for(int i = 0; i < ngroups; i++){
            gr = getgrgid(groups[i]);
            printf("%s ", gr->gr_name);
        }
        printf("\n");
        free(groups);
    }

    exit(EXIT_SUCCESS);
}