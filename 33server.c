/*
============================================================================
Name : 33server.c
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
#include<netinet/in.h>

int main(){
    int sockfd, newsockfd;
    char buffer[1024];
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;   // accept from any interface
    servaddr.sin_port = htons(8080);         // port 8080

    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(sockfd, 5);

    printf("Server waiting for connection...\n");
    clilen = sizeof(cliaddr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);

    read(newsockfd, buffer, sizeof(buffer));
    printf("Message from client: %s\n", buffer);

    char reply[] = "Hello from server!";
    write(newsockfd, reply, strlen(reply)+1);

    close(newsockfd);
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