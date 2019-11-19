#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
static void callback1(void)
{
  printf("-------callback1----------\n");
}
static void callback2(void)
{
  printf("-------callback2----------\n");
}
static void __attribute__((constructor)) before_main()
{
   printf("before test1 main\n");
}
static void __attribute__((destructor)) after_main()
{
   printf("after test1 main\n");
}
int main(int argc,char *argv[]){
   int i;
   atexit(callback1);
   atexit(callback2);
   FILE *fp;
   char buf[]={"hello world"};
   if((fp=fopen("test.dat","w+"))==NULL){
	perror("failed to create file\n");
	return -1;
   }
   if(fputs(buf,fp)==EOF){       //quan huanchong
	perror("failed to fputs file\n");
	return -1;
   }
   printf("test message!");
   //exit(0);
   _exit(0);
   //return 0;
}
