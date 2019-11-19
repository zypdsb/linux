#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
int main(){
  pid_t pid = 0;
  pid = fork();
  if (pid > 0) {
     printf("parent is waiting child %d\n",pid);
     sleep(15);
     printf("parent %d is running\n", getpid());
     return 0;
     }
      else if (0 == pid){
     printf("child %d is running\n",getpid());
     printf("child will exit\n");
     while(1);
     exit(120);
     } 
     else {
     printf("failed\n");
      
     }
}
