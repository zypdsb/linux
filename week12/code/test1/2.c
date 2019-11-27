#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<string.h>

int main(){
  pid_t p;
  int fd[2],rn,wn,i,psize;
  char rbuf[1],wbuf[30];
  memset(rbuf,0,sizeof(rbuf));
  memset(wbuf,0,sizeof(wbuf));
  //psize=fcntl(fd[0],?F_GETPIPE_SZ);
  pipe(fd);
  p=fork();
  if(p<0){
    perror("fork failed!\n");
    return -1;
  }
  else if(p==0)
  {
    close(fd[0]);
    sprintf(rbuf,"1");
    for(i=0;i<65537;i++)
	write(fd[1],rbuf,sizeof(rbuf));
    close(fd[1]);
    exit(0);
  }
  else
  {
   wait(NULL);
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
