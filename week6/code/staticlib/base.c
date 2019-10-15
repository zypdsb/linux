#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void showarray(int *a,int n)
{
	int i;
    for(i=0;i<n;i++)
	  printf("%d :%d\n",n,a[i]);
}
void initarray(int *a,int n)
{
 int x,i;
    srand(time(0));
    for(i=0;i<n;)
      { 
        x=rand();
        if(x>0&&x<=1000)
        {
          a[i]=x;
          i++;
        }
      }
}
