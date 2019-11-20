#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<sys/param.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<signal.h>
#include<time.h>
void init_daemon(void)
{
  pid_t child1;
  int i;
  child1=fork();
  if(child1>0)
    exit(0);
  else if(child1<0)
  {
    perror("creat son failed");
    exit(1);
  }
  setsid();
  chdir("/tmp");
  umask(0);
  for(i=0;i<NOFILE;++i)
    close(i);
  return;
}
