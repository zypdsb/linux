#include "dylib.h"
#include<stdio.h>
int main(){
  int a[5];
  initarray(a,5);
  showarray(a,5);
  printf("max:%d\n",max(a,5));
  printf("sum:%d\n",sum(a,5));
}
