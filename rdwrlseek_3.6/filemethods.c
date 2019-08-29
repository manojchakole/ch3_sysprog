#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd, readoffset, writeoffset, lseekoffset;
//	char readstr[1024], writestr[] = "this is text matter to be written--------";
        char readstr[1024], writestr[] = "matters of india------";

	fd = open("xyz",O_CREAT|O_RDWR|O_APPEND, 0744);

	if(fd != -1)
		printf("opened file success fd %d\n", fd);

	writeoffset = write(fd, writestr, strlen(writestr));

//        writeoffset = write(fd, writestr, sizeof(readstr));

//        fd = open("xyz",O_RDWR|O_APPEND);

	lseekoffset = lseek(fd, 3, SEEK_SET);
/*
	while((readoffset = read(fd, readstr, 2)) != 0)
	{
		write(1, readstr, 2);
	}
*/
      	readoffset = read(fd, readstr, 7);
        write(fd, readstr, 7);

	return 0;
}
