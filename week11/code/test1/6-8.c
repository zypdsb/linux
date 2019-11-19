#include<time.h>      //tail  /tmp/6-8.log
#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
void init_daemon(void);
int main(){
  FILE *fp;
  time_t t;
  init_daemon();
  while(1){
    sleep(10);
    if((fp=fopen("6-8.log","a"))>=0)
    {
	t=time(0);
	fprintf(fp,"daemon process is running,time is:%s",asctime(localtime(&t)));
	fclose(fp);
    }
  }
}
