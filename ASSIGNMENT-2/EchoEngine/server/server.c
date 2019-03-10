#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 1111

int main(){

    int sockfd, ret;
    struct sockaddr_in serverAddr;

    int newSocket;
    struct sockaddr_in newAddr;

    socklen_t addr_size;

    char buffer[1024] = {0};
    char buffer1[1];
    pid_t childpid;

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if((ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr))) < 0){
        perror("bind failed.");
        exit(EXIT_FAILURE);
    }

    if(listen(sockfd, 10) == 0){
        printf("[+]Listening....\n");
    }else{
        printf("[-]Error in binding.\n");
    }


    while(1){
        newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
        if(newSocket < 0){
            exit(1);
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

        if((childpid = fork()) == 0){
            close(sockfd);

            while(1){
                recv(newSocket, buffer, 1024, 0);
                char C = buffer[0];
                if(C >= 'a' && C <= 'z'){
                    C = C - 32;
                }
                else if(C >= 'A' && C <= 'Z'){
                    C = C + 32;
                }
                else{
                    C = C;
                }
                buffer1[0] = C;
                buffer1[1] = '\0';
                if(strcmp(buffer, ":exit") == 0){
                    printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
                    break;
                }else{
                    printf("Data received from Client : %s\n", buffer1);
                    send(newSocket, buffer1, strlen(buffer1), 0);
                    printf("Message sent back to the client.\n");
                    bzero(buffer1, sizeof(buffer1));
                }
            }
        }

    }

    close(newSocket);


    return 0;
}
