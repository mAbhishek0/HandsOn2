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
	key_t key = ftok(".", 12);
	int mqid = msgget(key, IPC_CREAT | 0666);
	struct msqid_ds st;

	msgctl(mqid, IPC_STAT, &st);
	printf("current message queue permission: %o\n",st.msg_perm.mode);

	st.msg_perm.mode = 0744;
	msgctl(mqid, IPC_SET, &st);
	msgctl(mqid, IPC_STAT, &st);
	printf("new message queue permission: %o\n", st.msg_perm.mode);
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