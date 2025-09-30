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
	int fd = open("myfifo1", O_WRONLY);
	char buff[50];
	printf("enter data to be sent:\n");
	scanf(" %[^\n]", buff);
	write(fd, buff, sizeof(buff));
	return 0;
}

/*
============================================================================
output:
ab@ab:~/handson2$ cc 22b.c -o 22b
ab@ab:~/handson2$ ./22b
enter data to be sent:
hello from program 1
============================================================================
*/


