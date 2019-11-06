#include "my.h"
static void __attribute__((constructor)) before_main()
{
   printf("before test1 main\n");
}
static void __attribute__((destructor)) after_main()
{
   printf("after test1 main\n");
}
int main(){
  printf("Main\n");
  return 0;
}
