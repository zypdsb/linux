#include "my.h"
void *foo(void *v)
{
  printf("thread is running!\n");
  return (void *)0;
}
int main(){
  pthread_t tid;
  int ret;
  ret=pthread_create(&tid,NULL,foo,NULL);
  if(ret!=0){
    perror("create thread failed!\n");
    exit(-1);
    }
  //pthread_join(tid[i],NULL);
  pthread_detach(tid);
    printf("master done!\n");
  sleep(5);
}
