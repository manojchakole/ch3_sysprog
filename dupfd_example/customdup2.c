#include<stdio.h>
#include<fcntl.h>
#include"dupheader.h"
#include<string.h>

int main()
{
	int fd1, fd2 = -1;
	
	//no need to write absolute  path or relative path when you are creating in same directory in which this program resides	
	fd1 = open("abc",O_CREAT|O_RDWR);
	
	if(fd1 != -1)
		printf("opened file success fd1 %d\n", fd1);

//	sprintf(pathStr,"/proc/ elf/fd/%d",fd1);
//	printf("int to char %c\n", intToChar(64));

	printf("Enter non negative value for new fd2\n");
	scanf("%d", &(fd2));

	fd2 = customdup2(fd1, fd2);
	printf("The new non negative value for new fd2 %d\n", fd2);

	return 0;
}
