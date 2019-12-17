#include "my.h"
void foo(void *v)
{
  int n=(int)v;
  int sum=0;
  int i;
  long time;
  struct sendval *ta=NULL;
  ta=(struct sendval *)malloc(sizeof(struct sendval));
  struct timeval tv1,tv2;
  struct timezone tz;
  gettimeofday(&tv1,&tz);
  for(i=0;i<10000*(n+1);i++)
  {
     sum=sum+i;
  }
  gettimeofday(&tv2,&tz);
  time=tv2.tv_usec-tv1.tv_usec;
  ta->sum=sum;
  ta->t=time;
  pthread_exit((void *)ta);
}
int main(){
  pthread_t tid[NUM];
  int i,ret[NUM];
  struct sendval *pt;
  for(i=0;i<NUM;i++){
    ret[i]=pthread_create(&tid[i],NULL,(void *(*)())foo,(void*)i);
    if(ret[i]!=0){
      perror("create thread failed!\n");
      exit -1;;
    }
    pthread_join(tid[i],(void **)&pt);
    printf("master%d: time=%ld,sum=%d\n",i,(pt)->t,(pt)->sum);
  }
}

