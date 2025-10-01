/*
============================================================================
Name : 33client.c
Author : Abhishek Mandal
Description : Write a program to communicate between two machines using socket.
Date: 1st October 2025
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(){
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // change to server IP if remote

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    char msg[100];
    printf("Enter message for server: ");
    scanf("%[^\n]", msg);

    write(sockfd, msg, strlen(msg)+1);
    read(sockfd, buffer, sizeof(buffer));

    printf("Reply from server: %s\n", buffer);

    close(sockfd);
    return 0;
}

/*
============================================================================
output:
ab@ab:~/handson2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0xffffffff 9          ab         666        1         
0xc8062bca 10         ab         666        1         
0x2c062bca 11         ab         666        1         

ab@ab:~/handson2$ cc 32d.c
ab@ab:~/handson2$ ./a.out
Semaphore removed successfully
ab@ab:~/handson2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0xffffffff 9          ab         666        1         
0xc8062bca 10         ab         666        1 
============================================================================
*/