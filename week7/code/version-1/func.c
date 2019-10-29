#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include "func.h"
void createfile_1()
{
  char filename[100];
  FILE *fd=NULL;
  printf("input the file name:");
  scanf("%s",filename);
  fd=fopen( filename, "w+" );
  if(fd==NULL)
     exit(-1);
  fclose(fd);
}
void writefile_1()
{
  FILE *fd=NULL;
  char filename[100];
  char buf[200];
  printf("input the file name:");
  scanf("%s",filename);
  fd=fopen( filename, "a+" );
  if(fd==NULL)
     printf("failed to open this file\n");
  printf("input the text:");
  scanf("%s",buf);
  fwrite(buf, sizeof(char), sizeof(buf),fd);
  fclose(fd);
}
void readfile_1()
{
  FILE *fd=NULL;
  char filename[100];
  char buf[200];
  printf("input the file name:");
  scanf("%s",filename);
  fd=fopen( filename, "r+" );
  if(fd==NULL)
     printf("failed to open this file\n");
  fread(buf, sizeof(int), 200, fd);
  printf("\n%s",buf);
  fclose(fd);
}
void changechmod_1()
{
  char filename[100];
  int n;
  printf("input the file name:");
  scanf("%s",filename);
  printf("0.读，写，执行 1.读 2.写 3.执行\n"); 
  printf("请选择修改的权限:"); 
  scanf("%d",&n);
  switch(n){
           case 0: chmod(filename,S_IRWXU); break;
           case 1: chmod(filename,S_IRUSR); break;
           case 2: chmod(filename,S_IWUSR); break;
           case 3: chmod(filename,S_IXUSR); break;
           default: printf("你的选择有误请!\n");
        }          
}
void readchomd_1()
{
  char filename[100];
  char *path = "/bin/ls";
  char *argv[4];
  printf("input the file name:");
  scanf("%s",filename);
  argv[0]="ls";
  argv[1]="-l";
  argv[2]=filename;
  argv[3]=NULL;
  execv(path,argv);
}
