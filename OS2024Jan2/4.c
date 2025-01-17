#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define check_error(cond, usrmsg)                                              \
  do {                                                                         \
    if (!(cond)) {                                                             \
      perror(usrmsg);                                                          \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
  } while (0)

#define MAX 1024

void process(struct inotify_event *event, char *dir) {
  if (!(event->mask & IN_MOVED_TO))
    return;
  pid_t child = fork();
  if (child == 0) {
    chdir(dir);
    execl("/bin/cat", "cat", event->name, NULL);
    exit(EXIT_FAILURE);
  } else {
    wait(NULL);
    return;
  }
  return;
}

void process_all(char *buff, ssize_t readbytes, char *dir) {
  char *p = NULL;
  for (p = buff; p < buff + readbytes;) {
    struct inotify_event *event = (struct inotify_event *)p;
    process(event, dir);
    p += sizeof(struct inotify_event) + event->len;
  }
}

int main(int argc, char **argv) {
  check_error(argc == 2, "argc");

  int inotifyFd = inotify_init();
  check_error(inotifyFd != -1, "inotify_init");

  struct stat fileinfo;
  check_error(stat(argv[1], &fileinfo) != -1, "stat");
  check_error(S_ISDIR(fileinfo.st_mode), "nije dir");

  int wd = inotify_add_watch(inotifyFd, argv[1], IN_MOVED_TO);
  check_error(wd != -1, "inotify_add_watch");

  char buffer[MAX];
  while (1) {
    ssize_t readbytes = read(inotifyFd, buffer, MAX);
    check_error(readbytes != -1, "read");
    process_all(buffer, readbytes, argv[1]);
  }
  return 0;
}
