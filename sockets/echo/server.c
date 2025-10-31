#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netdb.h>
#include <unistd.h>
#include <arpa/inet.h>  
#include <netinet/in.h>
#include <pthread.h>

#define BACKLOG 10
#define MYPORT "3490"




void* get_addr_info(struct sockaddr* sa)
{
  if(sa->sa_family==AF_INET){
    return &(((struct sockaddr_in *)sa)->sin_addr);
  }
  else{
    return &(((struct sockaddr_in6 *)sa)->sin6_addr);
  }
}


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


freeaddrinfo(res);




while(1){


struct sockaddr_storage client_addr;
socklen_t addr_len = sizeof client_addr;
  //accept the connection 
int new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);
if (new_fd == -1) {
    perror("accept");
    close(sockfd);
    exit(1);
}

    //print client info:
  char ip_str[INET_ADDRSTRLEN];
    inet_ntop(client_addr.ss_family,get_addr_info((struct sockaddr *)&client_addr),ip_str,sizeof(ip_str));
    //extracting port
            int port = ntohs(((struct sockaddr_in *)&client_addr)->sin_port);
    printf("Client connected from %s:%d\n",ip_str,port);



     //recv msg
    char buff[1024];
    memset(&buff,0,sizeof(buff));
    int bytes_recv=recv(new_fd,buff,sizeof(buff)-1,0);
      printf("bytes recvd: %d\n",bytes_recv);

    //echo msg
    char* msg=buff;
  int bytes_sent= send(new_fd,msg,strlen(msg),0);
    printf("bytes sent: %d\n",bytes_sent);


}



close(sockfd);
     return 0;
}
