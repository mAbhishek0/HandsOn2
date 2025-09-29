/*
============================================================================
Name : 18.c
Author : Abhishek Mandal
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 29th September 2025
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	int fd1[2], fd2[2];

	pipe(fd1);
	pipe(fd2);

	if(!fork()){
		dup2(fd1[1], 1);
		close(fd1[0]);
		close(fd2[0]);
		close(fd2[1]);
		execlp("ls", "ls", "-Rl", (char *)NULL);
	} else {
		if(!fork()){
			dup2(fd1[0], 0);
			dup2(fd2[1], 1);
			close(fd2[0]);
			close(fd1[1]);
			execlp("grep", "grep", "^d", (char *)NULL);
	
		} else {
			dup2(fd2[0], 0);
			close(fd1[0]);
			close(fd1[1]);
			close(fd2[1]);
			execlp("wc", "wc", (char *)NULL);
		}

	}

	close(fd1[0]);
	close(fd1[1]);
	close(fd2[0]);
	close(fd2[1]);
	wait(0);
	wait(0);
	wait(0);
	
	return 0;
}	

		
/*
============================================================================
output:
ab@ab:~/handson2$ cc 18.c
ab@ab:~/handson2$ ./a.out
      0       0       0
============================================================================
*/

