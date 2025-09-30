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

int main(){;
	int fd1;
	fd1 = open("myfifo1", O_WRONLY);
	write(fd1, "hello from program 1\n",22);
	printf("message sent to program 2\n");
	
	return 0;
}

/*
============================================================================
output:
ab@ab:~/handson2$ cc 20a.c -o 20a
ab@ab:~/handson2$ ./20a
message sent to program 2
============================================================================
*/
