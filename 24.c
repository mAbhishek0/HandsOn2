/*
============================================================================
Name : 24.c
Author : Abhishek Mandal
Description : 24. Write a program to create a message queue and print the 
key and message queue id.
Date: 30th September 2025
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<fcntl.h>

int main(){
	key_t msgKey = ftok(".", 123456);
	int msgid = msgget(msgKey, IPC_CREAT);
	printf("the key is: %d\n", msgKey);
	printf("the message queue id is: %d\n", msgid);
	return  0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 24.c
ab@ab:~/handson2$ ./a.out
the key is: 1074146250
the message queue id is: 1
============================================================================
*/
