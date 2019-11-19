#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
  pid_t pid = 0;
  int fd = -1;
  char buf[4] = { 'a', 'b', 'c', 'd'};
  char buf2[4] = { '1', '2', '3', '4'};
  fd = open("forkfile1.dat", O_CREAT|O_RDWR|O_TRUNC);
  if ( fd==-1) {
     printf("open ./forkfile failed\n");
     return -1;
     }
  write(fd, &buf[0], sizeof(buf));
  pid = fork();
  if (pid > 0) {
     printf("this is parent process, fd=%d\n", fd);
     } else if (0 == pid){
     printf("this is child process, fd=%d\n", fd);
     write(fd, &buf2[0], sizeof(buf));
     } else {
     printf("fork failed\n");
     }
   close(fd);
   return 0;
}
