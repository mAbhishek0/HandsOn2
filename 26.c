/*
============================================================================
Name : 25.c
Author : Abhishek Mandal
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 30th September 2025
============================================================================
*/
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<time.h>
int main(){
	key_t key = ftok(".", 12345);
	int msgid = msgget(key, 0666 | IPC_CREAT);
	struct msqid_ds st;

	printf("access permission: %o\n", st.msg_perm.mode);
	printf("uid and gid of owner: %d, %d\n", st.msg_perm.uid, st.msg_perm.gid);
	printf("time of last message sent and received: %u, %u\n",st.msg_perm.cuid, st.msg_perm.cgid);
	printf("time of last change: %s\n", ctime(&st.msg_ctime));
	printf("current number of bytes in queue: %lu\n",st.__msg_cbytes);
	printf("number of messages in queue: %lu\n", st.msg_qnum);
	printf("ma
}
/*
============================================================================
output:
ab@ab:~/handson2$ ./a.out
============================================================================
*/
