#include"func.h"
void main(){
  int x;
  printf("********************\n");
  printf("0:退出\n");
  printf("1:创建新文件\n");
  printf("2:写文件\n");
  printf("3:读文件\n");
  printf("4:修改文件权限\n");
  printf("5:查看当前文件权限\n");
  printf("********************\n");
  while(1){
    printf("please input your choice(0-6):");
    scanf("%d",&x);
    switch(x){
    case 0:
	return;
    case 1:
	createfile_1();
        break;
    case 2:
	writefile_1();
        break;
    case 3:
	readfile_1();
        break;
    case 4:
	changechmod_1();
        break;
    case 5:
	readchomd_1();
        break;
    default:
	printf("input error!\n");
    }
  }
}
