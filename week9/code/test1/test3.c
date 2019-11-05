#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
static void __attribute__((constructor)) before_main()
{
   printf("before test2 main\n");
}
static void callback1(void)
{
  printf("callback1 is running!\n");
}
static void callback2(void)
{
  printf("callback2 is running!\n");
}
static void callback3(void)
{
  printf("callback3 is running!\n");
}
int main(int argc,char *argv[]){
   int i;
   atexit(callback1);//zhuche huidiaohanshu
   atexit(callback2);//zhuche huidiaohanshu
   atexit(callback3);//zhuche huidiaohanshu
   printf("test2:pid=%d,ppid=%d\n",getpid(),getppid());
   while(1){
	sleep(1);
  }
   printf("test2 main finsheds!\n");
   return 0;
}
