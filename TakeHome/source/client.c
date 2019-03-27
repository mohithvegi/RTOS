#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PORT 1111

int main(){

    struct timeval start, intermediate, stop;
	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024] = {0};
	char s1[10], s2[10];

	if((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket failed.");
		exit(EXIT_FAILURE);
	}

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if((ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr))) < 0){
		perror("connection failed.");
		exit(EXIT_FAILURE);
	}

	printf("Send the request.\n");
	scanf("%s", s2);

	while(1){
        FILE *file;
		// printf("Enter file name : ");
		// scanf("%s %s", s1, s2);
		gettimeofday(&start, NULL);
		send(clientSocket, s2, strlen(s2), 0);
		gettimeofday(&intermediate, NULL);

		if(strcmp(buffer, ":exit") == 0){
			close(clientSocket);
			printf("[-]Disconnected from server.\n");
			exit(1);
		}

		if(recv(clientSocket, buffer, 1024, 0) < 0){
			printf("[-]Error in receiving data.\n");
		}
		else{
            file = fopen("values.csv", "a");
            fprintf(file, "%s\n", buffer);
            fclose(file);
			printf("Data received back from Server : %s\n", buffer);
		}
		gettimeofday(&stop, NULL);
		printf("Sending time:%lu Response Time:%lu\n", (intermediate.tv_sec - start.tv_sec)*1000000 + (intermediate.tv_usec - start.tv_usec), (stop.tv_sec - intermediate.tv_sec)*1000000 + (stop.tv_usec - intermediate.tv_usec));
	}

	return 0;
}
