#include "my.h"
static void __attribute__((constructor)) before_main()
{
   printf("before test2 main\n");
}
static void __attribute__((destructor)) after_main()
{
   printf("after test2 main\n");
}
static void callback1(void)
{
  printf("callback1\n");
}
static void callback2(void)
{
  printf("callback2\n");
}
static void callback3(void)
{
  printf("callback3\n");
}
int main(){
  atexit(callback1);
  atexit(callback2);
  atexit(callback3);
  printf("Main\n");
  return 0;
}
