#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    struct addrinfo hints, *res, *p;
    int rc;

    if (argc != 2) {
        fprintf(stderr, "usage: %s hostname\n", argv[0]);
        return 1;
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;       // IPv4 only
    hints.ai_socktype = SOCK_STREAM; // TCP

    if ((rc = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
        return 2;
    }

    printf("IP addresses for %s:\n\n", argv[1]);

    for (p = res; p != NULL; p = p->ai_next) {
        struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
        char ipstr[INET_ADDRSTRLEN];

        inet_ntop(p->ai_family, &(ipv4->sin_addr), ipstr, sizeof ipstr);
        printf("  %s\n", ipstr);
    }

    freeaddrinfo(res);
    return 0;
}

