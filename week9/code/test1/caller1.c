#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
  int ret;
  printf("caller11:pid=%d,ppid=%d\n",getpid(),getppid());
  ret=system("./test1 123 445 hello world");
  printf("after calling!!!ret=%d\n",ret);
  sleep(10);
  return 0;
}
