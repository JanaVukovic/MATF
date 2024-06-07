#include <stdio.h>
#include <sys/types.h>
#include <grp.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>

#define check_error(cond, usrmsg)\
do{\
    if(!(cond)){\
    perror(usrmsg);\
    exit(EXIT_FAILURE);\
    }\
}while(0)

int main(int argc, char** argv){
    check_error(argc == 2, "argc");

    struct stat fileinfo;
    check_error(-1 != lstat(argv[1], &fileinfo), "lstat");
    struct group * group = getgrgid(fileinfo.st_gid);
    check_error(NULL != group, "getgrgid");
    
    struct passwd * user = getpwuid(fileinfo.st_uid);
    check_error(user != NULL, "getpwuid");

    printf("%s %s\n", user->pw_name, group->gr_name);

    return 0;
}