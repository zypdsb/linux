#include"my.h"
int main(){
  char *vector[]={"test4","123","abc",NULL};
  printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
  execvp("test4",vector);
  printf("-------after calling-------\n");
}
