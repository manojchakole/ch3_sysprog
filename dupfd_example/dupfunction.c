#include<stdio.h>
#include<fcntl.h>

/*
char intToChar(int val)
{
	char ch = val + '0';
	return ch;
}
*/

int customdup2(int fd1, int fd2)
{
	char pathStr[1024];
	char writeStr[] = "writing in this fd file...... ", readStr[1024];
	int writeBytes, readBytes, lseekBytes;

	if(fd2 == -1)
	{
//	        sprintf(pathStr,"/proc/self/fd/%d",fd1);
	        sprintf(pathStr,"/dev/fd/%d",fd1);	
	}
	else if(fd2 > -1 && fd2 < 1024)
	{
	        sprintf(pathStr,"/dev/fd/%d",fd2);
//	        sprintf(pathStr,"/proc/self/fd/%d",fd2);	
	}

	printf("path string: %s\n", pathStr);

	fd2 = open(pathStr, O_RDWR|O_APPEND);

	if(fd2 != -1)
        printf("opened file success fd2 %d\n", fd2);

	writeBytes = write(fd2, writeStr, strlen(writeStr));
	printf("Written bytes %d\n",writeBytes);

	lseekBytes = lseek(fd2, 0, SEEK_SET);
	printf("Lseek Bytes1 %d\n",lseekBytes);

	readBytes = read(fd2, readStr, strlen(writeStr));
	printf("Read bytes %d\n",readBytes);

	lseekBytes = lseek(fd2, 0, SEEK_CUR);
	printf("Lseek Bytes2 %d\n",lseekBytes);

	printf("opened file success fd1 %d\n", fd1);
	return fd2;
}

