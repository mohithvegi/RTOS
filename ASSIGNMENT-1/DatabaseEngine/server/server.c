#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf {
    long mtype;
    char mtext[200];
};

int main(void){
	struct my_msgbuf buf1;
	int msgqid1;
	key_t key1;
	char data1[10000];
	FILE *file1;

	if((key1 = ftok("client1", 19)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid1 = msgget(key1, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);	
	}

	printf("Data received from client1.\n");

	if(msgrcv(msgqid1, &buf1, sizeof(buf1.mtext), 1, 0) == -1){
		perror("msgrcv");
		exit(1);
	}

	printf("%s\n", buf1.mtext);

	if(access(buf1.mtext, F_OK) != -1){
		file1 = fopen(buf1.mtext, "r");
		int i;
		while((fscanf(file1, "%s", data1[i]))!=EOF){
			printf("%s\n", data1[i]);
			i++;
		}
	}
	else{
		printf("File Not exists.\n");
	}

	return 0;
}