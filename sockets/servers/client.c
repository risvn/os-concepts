#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netdb.h>
#include <unistd.h>



int main()
{
struct addrinfo hints,*res;

memset(&hints,0,sizeof(hints));

//filling the structure

hints.ai_family=AF_INET;
hints.ai_socktype=SOCK_STREAM;

//use current port as client-port
int rc =getaddrinfo("127.0.0.1","3490",&hints,&res);
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


if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
    perror("connect");
    close(sockfd);
    exit(1);
}


//binding not req for the client side
//if (bind(sockfd,res->ai_addr,res->ai_addrlen) == -1) {
//    perror("bind");
//    close(sockfd);
//    exit(1);
//}


char *msg="hello from the client\n";
int bytes_sent,len;

len=strlen(msg);
bytes_sent=send(sockfd,msg,len,0);
if (bytes_sent == -1) {
        perror("send");
    } else {
        printf("Sent %d bytes to server.\n", bytes_sent);
    }




//clean up
freeaddrinfo(res);
close(sockfd);


     return 0;
}

