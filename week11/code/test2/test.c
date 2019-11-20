#include <stdio.h>

int main ()
{
   FILE *fp;
   int c,i;
   char buffer[30];
   for(i=0;i<30;i++)
    buffer[i]='\0';
   fp = fopen("out.dat","r");
   fread(buffer,30,1,fp);
   printf("%s",buffer);
   fclose(fp);
   return(0);
}
