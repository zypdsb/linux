#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
  char *arg[]={"./test1","123","hello","world",NULL};
  printf("caller4:pid=%d,ppid=%d\n",getpid(),getppid());
  execv("/home/rlk/linuxprogram/week9/code/test1/./test1",arg);
  printf("after calling\n");
  return 0;
}
