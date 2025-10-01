/*
============================================================================
Name : 34b.c
Author : Abhishek Mandal
Description : Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Date: 1st October 2025
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<pthread.h>

void* handle_client(void *arg){
    int newsockfd = *(int *)arg;
    char buffer[1024];
    read(newsockfd, buffer, sizeof(buffer));
    printf("Message from client: %s\n", buffer);
    char reply[100] = "Hello from server";
    write(newsockfd, reply, strlen(reply)+1);
    close(newsockfd);
    return NULL;
}

int main(){
    int sockfd, newsockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);

    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(sockfd, 5);

    clilen = sizeof(cliaddr);
    while(1){
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        pthread_t tid;
        int *p = malloc(sizeof(int));
        *p = newsockfd;
        pthread_create(&tid, NULL, handle_client, p);
        pthread_detach(tid); // detach thread to free resources automatically
    }
    close(sockfd);
    return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 34b.c
ab@ab:~/handson2$ ./a.out
Message from client: helo from client 1!
Message from client: hello from another client!
Message from client: hello from client 3
^C
============================================================================
*/