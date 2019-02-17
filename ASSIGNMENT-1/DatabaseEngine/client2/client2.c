#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
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
	char s1[10];

	if((key1 = ftok("client2", 19)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid1 = msgget(key1, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);	
	}

	buf1.mtype = 1;
	printf("Enter file name : \n");
	scanf("%s %s", s1, buf1.mtext);
	int len = strlen(buf1.mtext);

	if(msgsnd(msgqid1, &buf1, len+1, 0) == -1){
		perror("msgsnd");
	}

	return 0;
}