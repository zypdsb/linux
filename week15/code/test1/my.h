#include<pthread.h>
#include<unistd.h>
#include<limits.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/types.h>
#include<errno.h>
#include<time.h>
#define LOOP 1000000
struct sendval{
  long sum;
  long t;
};
#define NUM 4
#define TN 100
#define WRITER_FRIST
