#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
int main(){
  int pid1,pid2,pid3,rv,status,i;
  FILE *fp;
  char buffer[30];
  for(i=0;i<30;i++)
  buffer[i]='\0';
  fp=fopen("out.dat","w+");
  pid1=fork();
  if(pid1<0){
    perror("fork failed\n");
    return -1;
  }
  else if(pid1==0){
    fprintf(fp,"123456");
    printf("child1 pid =%d\n",getpid());
    sleep(3);
    exit(18);
  }
  else{
    printf("parent fork child2\n");
    pid2=fork();
    if(pid2<0){
    perror("fork failed\n");
    return -1;
    }
    else if(pid2==0){
    fprintf(fp,"123456");
    printf("child2 pid =%d\n",getpid());
    sleep(5);
    exit(99);}
    else{
        printf("parent fork child3\n");
	pid3=fork();
        if(pid3<0){
          perror("fork failed\n");
          return -1;
         }
        else if(pid3==0){
          fprintf(fp,"123456");
          printf("child3 pid =%d\n",getpid());
          sleep(2);
          exit(108); }
        else{
           printf("parent waiting child end\n");
           rv=wait(&status);
           printf("1:child %d end. exit code is %d\n",rv,WEXITSTATUS(status));
           status=0;
           rv=waitpid(pid1,&status,0); //mangden
           printf("2:child %d end. exit code is %d\n",rv,WEXITSTATUS(status));
           status=0;
           rv=waitpid(pid2,&status,0);  //zhusai
           printf("3:child %d end. exit code is %d\n",rv,WEXITSTATUS(status));
           fseek(fp, 0, SEEK_SET);  
           fread(buffer,30,1,fp);
           printf("%s\n",buffer);
           fclose(fp);
           return 0;
        }
    
     }
  }
}
