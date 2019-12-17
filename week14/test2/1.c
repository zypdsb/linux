#include "my.h"
int arg=0;
void foo(void *v)
{
  int n=(int)v;
  int *sum=NULL;
  int i;
  sum=(int *)malloc(sizeof(int));
  arg++;
  printf("%d:global arg=%d\n",n,arg);
  for(i=0;i<(n+1)*100;i++)
    *sum=*sum+i;
  int arg;
  arg=n*100;
  printf("%d:local arg=%d\n",n,arg);
  pthread_exit((void *)sum);
}
int main(){
  pthread_t tid[NUM];
  int i,ret[NUM],**pt;
  for(i=0;i<NUM;i++){
    ret[i]=pthread_create(&tid[i],NULL,(void *(*)())foo,(void*)i);
    if(ret[i]!=0){
      perror("create thread failed!\n");
      exit -1;;
    }
    pthread_join(tid[i],(void **)&pt);
    printf("master%d: arg=%d,sum=%d\n",i,arg,*pt);
  }
}

