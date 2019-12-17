#include"my.h"
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_rwlock_t rwlock;
int A[1000];
int B[1000];
int MAXAB;
int MAXA=0;
int MAXB=0;

void *fun(void *param)
{
  int i;
  pthread_rwlock_rdlock(&rwlock);
  for(i=0;i<1000;i++){
    pthread_mutex_lock(&mutex);
    if(A[i]>MAXA)
      MAXA=A[i];
    pthread_mutex_unlock(&mutex);
  }
  pthread_rwlock_unlock(&rwlock);
  printf("MAXA-----------%d\n",MAXA);
  return NULL;
}
void *fun2(void *param)
{
  int i;
  pthread_rwlock_rdlock(&rwlock);
  for(i=0;i<1000;i++){
    pthread_mutex_lock(&mutex);
    if(B[i]>MAXB)
      MAXB=B[i];
    pthread_mutex_unlock(&mutex);
  }
  pthread_rwlock_unlock(&rwlock);
  printf("MAXB-----------%d\n",MAXB);
  return NULL;
}
int main(){
  pthread_t tid[2];
  int i,ret;
  srand(time(NULL));
  for(i=0;i<1000;i++)
    A[i]=rand()%1000;
  for(i=0;i<1000;i++)
    B[i]=rand()%1000;
  ret=pthread_rwlock_init(&rwlock,NULL);
  if(ret){
    perror("rwlock init failed");
    exit(1);
  }
  pthread_rwlock_wrlock(&rwlock);
  ret=pthread_create(&tid[0],NULL,fun,NULL);
  if(ret){
      perror("pthread init failed");
      exit(2);
  }
  ret=pthread_create(&tid[1],NULL,fun2,NULL);
  if(ret){
      perror("pthread init failed");
      exit(2);
  }  
  pthread_rwlock_unlock(&rwlock);
  for(i=0;i<2;i++){
    pthread_join(tid[i],NULL);
  }
  pthread_rwlock_destroy(&rwlock);
  MAXAB=MAXA+MAXB;
  printf("MAXA+MAXB--------------%d\n",MAXAB);
  pthread_mutex_destroy(&mutex);
}
