/*
============================================================================
Name : 28.c
Author : Abhishek Mandal
Description : Write a program to change the exiting message queue 
permission. (use msqid_ds structure)
Date: 30th September 2025
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
struct msg{
	long int mType;
	char msg[100];
};
int main(){
	key_t key = ftok(".", 1234);
	int mqid = msgget(key, IPC_CREAT |0666);
	struct msg mymsg;
	mymsg.mType = 10;
	printf("enter the message:\n");
	scanf("%[^\n]", mymsg.msg);
	int size = strlen(mymsg.msg);
	msgsnd(mqid, &mymsg, size + 1, 0);
	return 0;
}


/*
============================================================================
output:
============================================================================
*/
