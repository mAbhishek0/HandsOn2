/*
============================================================================
Name : 29.c
Author : Abhishek Mandal
Description : Write a program to remove the message queue.
Date: 30th September 2025
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
int main(){
	key_t key = ftok(".", 12);
	int mqid = msgget(key, IPC_CREAT | 0666);
	int temp = msgctl(mqid, IPC_RMID, NULL);
	if(temp != -1){
		printf("message queue deleted\n");
	}
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 29.c
ab@ab:~/handson2$ ./a.out
message queue deleted
============================================================================
*/
