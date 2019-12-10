#include"my.h"


void * fun(void *arg){
  int TID=pthread_self();//syscall(SYS-gettid);
  printf("worker-----%d:gettid return %d\n",TID,TID);
  printf("worker-----%d:pthread_self return %p\n",TID,(void*)pthread_self());
  printf("worker-----%d:will exit! %p\n",TID);
  pthread_exit(NULL);
}
int main(){
  pthread_t tid;
  int i,ret;
  ret=pthread_create(&tid,NULL,fun,NULL);
  if(ret!=0){
    perror("create thread failed!\n");
    return -1;
    }
  pthread_join(tid,NULL);
  ret=pthread_create(&tid,NULL,fun,NULL);
  if(ret!=0){
    perror("create thread failed!\n");
    return -1;
    }
  pthread_join(tid,NULL);
  printf("%d:all done!\n",getpid());
  return 0;
}
