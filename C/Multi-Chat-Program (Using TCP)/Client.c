/*********TCP Client code**********/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFSIZE 1024

void send_recv(int i, int sockfd)
{
        char send_buf[BUFSIZE];
        char recv_buf[BUFSIZE];
        int nbyte_recvd;

        if (i == 0){
                fgets(send_buf, BUFSIZE, stdin);
                if (strcmp(send_buf , "quit\n") == 0) {
                        exit(0);
                }else
                        send(sockfd, send_buf, strlen(send_buf), 0);
        }else {
                nbyte_recvd = recv(sockfd, recv_buf, BUFSIZE, 0);
                recv_buf[nbyte_recvd] = ' ';
                printf("%s\n" , recv_buf);
                fflush(stdout);
        }
}

void connect_request(int *sockfd, struct sockaddr_in *server_addr)
{
        if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                perror("Socket");
                exit(1);
        }
        server_addr->sin_family = AF_INET;
        server_addr->sin_port = htons(4950);
        server_addr->sin_addr.s_addr = inet_addr("127.0.0.1");
        memset(server_addr->sin_zero, ' ', sizeof server_addr->sin_zero);

        if(connect(*sockfd, (struct sockaddr *)server_addr, sizeof(struct sockaddr)) == -1) {
                perror("connect");
                exit(1);
        }
}

int main()
{
        int sockfd, fdmax, i;
        struct sockaddr_in server_addr;
        fd_set master;
        fd_set read_fds;

        connect_request(&sockfd, &server_addr);
        FD_ZERO(&master);
        FD_ZERO(&read_fds);
        FD_SET(0, &master);
        FD_SET(sockfd, &master);
        fdmax = sockfd;

        while(1){
                read_fds = master;
                if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1){
                        perror("select");
                        exit(4);
                }

                for(i=0; i <= fdmax; i++ )
                        if(FD_ISSET(i, &read_fds))
                                send_recv(i, sockfd);
        }
        printf("client-quited\n");
        close(sockfd);
        return 0;
}
