#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<string.h>

int main(){
  pid_t p;
  int fd[2],rn,wn;
  char rbuf[30],wbuf[30];
  memset(rbuf,0,sizeof(rbuf));
  memset(wbuf,0,sizeof(wbuf));
  pipe(fd);
  p=fork();
  if(p<0){
    perror("fork failed!\n");
    return -1;
  }
  else if(p==0)
  {
    close(fd[0]);
    sprintf(wbuf,"[child%d]is running\n",getpid());  //65537B
    while(1){
	wn=write(fd[1],wbuf,sizeof(wbuf));
	printf("[child] write to pipe %d b\n",wn);
        if(wn==-1){
	printf("[child] write error\n");
        break;
        }
    }
    close(fd[1]);
    exit(0);
  }
  else
  {
    close(fd[1]);
    while(1){
	rn=read(fd[0],rbuf,sizeof(rbuf));
	printf("[parent] read from pipe %d b,content of pipe:%s\n",rn,rbuf);
    if(rn==0){
	printf("[parent] read error\n");
        break;
       }
    }
    close(fd[0]);
    return 0;
  }
}
