#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<wait.h>
int g=0;
int main(){
  int t=20;
  static int s=30;
  int status;
  pid_t pid;
  pid=fork();
  if(pid<0)
  {
     perror("vfork failed\n");
     exit(-1);
  }
  if(pid==0)
  {
     printf("before child pid=%d:&g=%p,&t=%p,&s=%p\n",getpid(),&g,&t,&s);
     g=100;
     t=200;
     s=300;
     printf("after child pid=%d:g=%d,t=%d,s=%d\n",getpid(),g,t,s);
     sleep(3);
    // _exit(0);
    // return 0;
     exit(119);
  }
  else
  {
     wait(&status);
     printf("parent pid=%d:&g=%p,&t=%p,&s=%p\n",getpid(),&g,&t,&s);
     printf("parent pid=%d:g=%d,t=%d,s=%d\n",getpid(),g,t,s);
     return 0;
  }
}
