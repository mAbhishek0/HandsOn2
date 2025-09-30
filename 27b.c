/*
============================================================================
Name : 27b.c
Author : Abhishek Mandal
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 30th September 2025
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
struct msg{
	long int mType;
	char msg[100];
};
int main(){
	key_t key = ftok(".", 1234);
	int mqid = msgget(key, 0666);

	struct msg mymsg;
	printf("waiting for message..\n");
	if(msgrcv(mqid, &mymsg, sizeof(mymsg.msg), 10, IPC_NOWAIT) == -1){
		printf("no message recieved\n");
	} else {
		printf("message received: %s\n", mymsg.msg);
	}
	return 0;
}

/*
============================================================================
output:
ab@ab:~/handson2$ cc 27b.c
ab@ab:~/handson2$ ./a.out
waiting for message..
message received: message from terminal 2nd time
ab@ab:~/handson2$ ./a.out
waiting for message..
no message recieved
============================================================================
*/

