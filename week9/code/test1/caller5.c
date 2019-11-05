#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
  char *arg[]={"./test1","123","hello","world",NULL};
  printf("caller5:pid=%d,ppid=%d\n",getpid(),getppid());
  execvp("./test1",arg);
  printf("after calling\n");
  return 0;
}
