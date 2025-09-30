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
int main(){
	key_t key = ftok(".", 1234);
	int mqid = msgget(key, IPC_CREAT | 0666);
	struct msqid_ds stSet;
	struct msqid_ds stRead;

	msgctl(mqid, IPC_STAT, &stRead);
	printf("current message queue permission: %o\n",stRead.msg_perm.mode);

	stSet = stRead;

	stSet.msg_perm.mode = 0744;
	msgctl(mqid, IPC_SET, &stSet);
	msgctl(mqid, IPC_STAT, &stRead);
	printf("new message queue permission: %o\n", stRead.msg_perm.mode);
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 28.c
ab@ab:~/handson2$ ./a.out
current message queue permission: 666
new message queue permission: 744
============================================================================
*/