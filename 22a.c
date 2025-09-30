/*
============================================================================
Name : 22a.c
Author : Abhishek Mandal
Description : Write a program to wait for data to be written into FIFO
within 10 seconds, use select system call with FIFO
Date: 30th September 2025
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/select.h>

int main(){
	char buff[50];
	int fd;
	fd_set rfds;
	struct timeval tv;
	tv.tv_sec = 10;
	fd = open("myfifo1", O_RDONLY);	
	FD_ZERO(&rfds);
	FD_SET(fd, &rfds);
	
	if(!select(fd + 1, &rfds, NULL, NULL, &tv))
		printf("no data is available for reading\n");
	else {
		printf("data is available now\n");
		read(fd, buff, sizeof(buff));
		printf("data from FIFO: %s\n", buff);
	}

}

/*
============================================================================
output:
ab@ab:~/handson2$ cc 22a.c -o 22a
ab@ab:~/handson2$ ./22a
no data is available for reading
ab@ab:~/handson2$ ./22a
data is available now
data from FIFO: hello from program 1
============================================================================
*/


