
//  client.c
#include<sys/socket.h>
#include<strings.h>
#include <netdb.h>       // <-- defines struct addrinfo, getaddrinfo(), AI_PASSIVE, etc.
#include <arpa/inet.h>  
#include <netinet/in.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#define PORT "3490"
void* get_in_addr(struct sockaddr* ss)
{
  if (ss->sa_family==AF_INET)
    { 
    return &(((struct sockaddr_in*)ss)->sin_addr);
  }
  else{
    return &(((struct sockaddr_in6*)ss)->sin6_addr);
  }
}


int main(int argc,char* argv[])
{
  struct addrinfo *res;
  struct addrinfo hints={0};

  hints.ai_family=AF_UNSPEC;
  hints.ai_socktype=SOCK_STREAM;
  hints.ai_flags=AI_PASSIVE;


int s = getaddrinfo(argv[1],PORT, &hints, &res);
           if (s != 0) {
               fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
               exit(1);
           }



//get the socket fd
int sockfd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
if(sockfd==-1)
  {
    perror("client:socket");
  }

//extracting server info:
  char ip_str[INET_ADDRSTRLEN];
  inet_ntop(res->ai_family,get_in_addr((struct sockaddr*)res->ai_addr),ip_str,sizeof ip_str);
  printf("client: attempting connection to %s\n", ip_str);

 //connext to the server 
  if(connect(sockfd,res->ai_addr,res->ai_addrlen)==-1)
  {
    perror("client:connect");
  }

//connected
  char ser[INET_ADDRSTRLEN];
inet_ntop(res->ai_family,
            get_in_addr((struct sockaddr *)res->ai_addr),
            ser, sizeof ser);
    printf("client: connected to %s\n", ser);


//send and recieve the data


char* msg= argv[2];
int bytes_sent= send(sockfd,msg,strlen(msg),0);
printf("bytes sent: %d\n",bytes_sent);


//recieve

  char buff[1024];
  int bytes_recv=recv(sockfd,buff,sizeof(buff)-1,0);
  printf("bytes recvd: %d\n",bytes_recv);
  printf("msg:%s\n",buff);


  freeaddrinfo(res);
  close(sockfd);
return 0;
}
