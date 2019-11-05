#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
  printf("caller3:pid=%d,ppid=%d\n",getpid(),getppid());
  execl("/home/rlk/linuxprogram/week9/code/test1/./test1","./test1","123","hello","world",NULL);
  printf("after calling\n");
  return 0;
}
