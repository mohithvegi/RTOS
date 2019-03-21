#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
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
    FILE *file1, *file2, *file3, *file4, *file5;

    char buffer[1024] = {0};
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
                long numbytes1, numbytes2, numbytes3, numbytes4, numbytes5;
                char *buffer1, *buffer2, *buffer3, *buffer4, *buffer5;
                char *message, *Time;
                char comma = ',';

                time_t rawtime;
                struct tm * timeinfo;

                recv(newSocket, buffer, 1024, 0);
                file1 = fopen("sensor1.txt", "r");
                fseek(file1, 0L, SEEK_END);
                numbytes1 = ftell(file1);
                fseek(file1, 0L, SEEK_SET);
                buffer1 = (char*)calloc(numbytes1, sizeof(char));
                fread(buffer1, sizeof(char), numbytes1, file1);
                fclose(file1);

                file2 = fopen("sensor2.txt", "r");
                fseek(file2, 0L, SEEK_END);
                numbytes2 = ftell(file2);
                fseek(file2, 0L, SEEK_SET);
                buffer2 = (char*)calloc(numbytes2, sizeof(char));
                fread(buffer2, sizeof(char), numbytes2, file2);
                fclose(file2);

                file3 = fopen("sensor3.txt", "r");
                fseek(file3, 0L, SEEK_END);
                numbytes3 = ftell(file3);
                fseek(file3, 0L, SEEK_SET);
                buffer3 = (char*)calloc(numbytes3, sizeof(char));
                fread(buffer3, sizeof(char), numbytes3, file3);
                fclose(file3);

                file4 = fopen("sensor4.txt", "r");
                fseek(file4, 0L, SEEK_END);
                numbytes4 = ftell(file4);
                fseek(file4, 0L, SEEK_SET);
                buffer4 = (char*)calloc(numbytes4, sizeof(char));
                fread(buffer4, sizeof(char), numbytes4, file4);
                fclose(file4);

                file5 = fopen("sensor5.txt", "r");
                fseek(file5, 0L, SEEK_END);
                numbytes5 = ftell(file5);
                fseek(file5, 0L, SEEK_SET);
                buffer5 = (char*)calloc(numbytes5, sizeof(char));
                fread(buffer5, sizeof(char), numbytes5, file5);
                fclose(file5);

                rawtime = time(NULL);
                timeinfo = localtime(&rawtime);
                Time = asctime(timeinfo);
                size_t len1 = strlen(buffer1);
                buffer1[len1] = comma;
                buffer1[len1+1] = '\0';
                strcat(buffer1, buffer2);
                size_t len2 = strlen(buffer1);
                buffer1[len2] = comma;
                buffer1[len2+1] = '\0';
                strcat(buffer1, buffer3);
                size_t len3 = strlen(buffer1);
                buffer1[len3] = comma;
                buffer1[len3+1] = '\0';
                strcat(buffer1, buffer4);
                size_t len4 = strlen(buffer1);
                buffer1[len4] = comma;
                buffer1[len4+1] = '\0';
                strcat(buffer1, buffer5);

                size_t l = strlen(Time);
                Time[l] = comma;
                Time[l+1] = '\0';
                strcat(Time, buffer1);

                message = Time;

                if(strcmp(buffer, ":exit") == 0){
                    printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
                    break;
                }else{
                    printf("Data received from Client : %s\n", buffer1);
                    send(newSocket, message, strlen(message), 0);
                    printf("Message sent back to the client.\n");
                    bzero(message, sizeof(message));
                }
            }
        }

    }

    close(newSocket);


    return 0;
}
