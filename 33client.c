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

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

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
ab@ab:~/handson2$ cc 33client.c -o client
ab@ab:~/handson2$ ./client
Enter message for server: hello from client!
Reply from server: hello from server!
============================================================================
*/