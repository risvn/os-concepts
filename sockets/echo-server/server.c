#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netdb.h>
#include <unistd.h>
#include <arpa/inet.h>  
#include <netinet/in.h>

#define BACKLOG 10
#define MYPORT "3490"


int main()
{
struct addrinfo hints,*res;

memset(&hints,0,sizeof(hints));

//filling the structure

hints.ai_family=AF_INET;
hints.ai_socktype=SOCK_STREAM;
hints.ai_flags=AI_PASSIVE;      //importatnt for server side 

int rc =getaddrinfo(NULL,MYPORT,&hints,&res);
//return value 0 on success
if(rc!=0){
    printf("getaddrinfo error\n");
    exit(1);
  }


//making socket
int sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
if (sockfd == -1) {
    perror("socket");
    exit(1);
}
//binding the socket
  //handle the error
if (bind(sockfd,res->ai_addr,res->ai_addrlen) == -1) {
    perror("bind");
    close(sockfd);
    exit(1);
}


//listening for incoming reqs
if (listen(sockfd, BACKLOG) == -1) {
    perror("listen");
    close(sockfd);
    exit(1);
}

//printig server-info on the console
struct sockaddr_in *addr = (struct sockaddr_in *)res->ai_addr;
char ipstr[INET_ADDRSTRLEN];
inet_ntop(AF_INET, &(addr->sin_addr), ipstr, sizeof(ipstr));
printf("Server is listening on %s:%d\n", ipstr, ntohs(addr->sin_port));



//storing the client_addr in socktaddr or socket_storage struct
struct sockaddr_storage client_addr;
socklen_t addr_len = sizeof client_addr;

int new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);
if (new_fd == -1) {
    perror("accept");
    close(sockfd);
    exit(1);
}
//now ready to comminucate using new_fd

char buffer[1024];
int bytes_received = recv(new_fd, buffer, sizeof(buffer)-1, 0);
if (bytes_received == -1) {
    perror("recv");
} else if (bytes_received == 0) {
    printf("Client disconnected\n");
} else {
    buffer[bytes_received] = '\0';
    printf("bytes_revceived %d bytes to server.\n", bytes_received);
    printf("Client says: %s\n", buffer);
}


//clean up
freeaddrinfo(res);
close(new_fd);
close(sockfd);


     return 0;
}
