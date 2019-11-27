#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<string.h>
int main(){
  int pid1,pid2,pid3,rv,status;
  int fd[2],fd2[2],rn,wn,i;
  int rbuf[10000],wbuf[10000],buf1[10000],buf2[10000];
  memset(buf1,0,sizeof(buf1));
  memset(buf2,0,sizeof(buf2));
  memset(rbuf,0,sizeof(rbuf));
  memset(wbuf,0,sizeof(wbuf));
  for(i=0;i<10000;i++)
     wbuf[i]=i+1;
  pipe(fd);
  pipe(fd2);
  pid1=fork();
  if(pid1<0){
    perror("fork failed\n");
    return -1;
  }
  else if(pid1==0){
    close(fd[0]);
    wn=write(fd[1],wbuf,sizeof(wbuf));
    printf("[child1] write to pipe1 %d int \n",wn/4);
    if(wn==-1){
	printf("[child1] write error\n");
	return -2;
	}
    close(fd[1]);
    exit(0);
  }
  else{
    int j;
    int sum=0;
    pid2=fork();
    if(pid2<0){
    perror("fork failed\n");
    return -1;
    }
    else if(pid2==0){
    close(fd[1]);
    rn=read(fd[0],rbuf,sizeof(rbuf));
    printf("[child2] read from pipe1 %d int:",rn/4);
    if(rn==0){
	printf("[child2] read error\n");
        return -2;
       }
    for(j=0;j<rn/4;j++)
      printf("%d,",rbuf[j]);
    printf("\n");
    close(fd[0]);
 
    close(fd2[0]);
    wn=write(fd2[1],rbuf,sizeof(rbuf));
    printf("[child2] write to pipe2 %d\n",rn/4);
    if(wn==0){
	printf("[child2] read error\n");
        return -2;
        }
    close(fd2[1]); 
    exit(99);
    }
    else{
	pid3=fork();
        if(pid3<0){
          perror("fork failed\n");
          return -1;
         }
        else if(pid3==0){
          int sum=0;
	  close(fd2[1]);
          rn=read(fd2[0],buf2,sizeof(buf2));
          if(rn==0){
	     printf("[child3] read error\n");
             return -2;
          }
	  for(i=0;i<rn/4;i++)
	     sum=sum+buf2[i];
          printf("[child3] read from pipe2 %d,sum is %d\n",rn/4,sum);
           close(fd2[0]);
          exit(108); }
        else{
          rv=waitpid(pid1,&status,0); //mangden
	  rv=waitpid(pid2,&status,0); //mangden
	  rv=waitpid(pid3,&status,0); //mangden 
	  return 0;
        }
    
     }
  }
}
