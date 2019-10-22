#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
  //printf("hello\n");
  // setvbuf(stdout, NULL, _IONBF, 0);
  printf("hello");
  //fflush(stdout);
  while(1);
}
