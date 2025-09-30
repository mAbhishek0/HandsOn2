/*
============================================================================
Name : 20a.c
Author : Abhishek Mandal
Description :Write two programs so that both can communicate by FIFO 
-Use one way communication.
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
	fd1 = open("myfifo1", O_WRONLY);
	fd2 = open("myfifo2", O_RDONLY);
	write(fd1, "hello from program 1\n",22);
    read(fd2, buff1, sizeof(buff1));
	printf("message from program 2 is: %s\n",buff1);
	
	return 0;
}

/*
============================================================================
output:
ab@ab:~/handson2$ cc 20a.c -o 20a
ab@ab:~/handson2$ ./20a
message from program 2 is: hello from program 2
============================================================================
*/
