/*
============================================================================
Name : 21b.c
Author : Abhishek Mandal
Description : Write two programs so that both can communicate by FIFO 
-Use two way communications
Date: 30th September 2025
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
	char buff1[50], buff2[50];
	int fd1, fd2;
	fd1 = open("myfifo1", O_RDONLY);
	fd2 = open("myfifo2", O_WRONLY);
	write(fd2, "hello from program 2\n",22);
    read(fd1, buff2, sizeof(buff2));
	printf("message from program 1 is: %s\n",buff2);
	
	return 0;
}

/*
============================================================================
output:
ab@ab:~/handson2$ cc 20b.c -o 20b
ab@ab:~/handson2$ ./20b
message from program 1 is: hello from program 1
============================================================================
*/

