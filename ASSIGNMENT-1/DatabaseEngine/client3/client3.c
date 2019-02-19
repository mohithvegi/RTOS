#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/time.h>

struct my_msgbuf {
    long mtype;
    char mtext[20000];
};

int main(void){
	struct my_msgbuf buf1, buf2;
	struct timeval start, intermediate, stop;
	int msgqid1, msgqid2;
	key_t key1, key2;
	char s1[10];

	if((key1 = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/DatabaseEngine/client3", 19)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid1 = msgget(key1, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);
	}

	buf1.mtype = 5;
	printf("Enter file name : \n");
	scanf("%s %s", s1, buf1.mtext);
	int len = strlen(buf1.mtext);

    printf("sent\n");

    if((key2 = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/DatabaseEngine/client3", 20)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid2 = msgget(key2, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);
	}

	gettimeofday(&start, NULL);

	if(msgsnd(msgqid1, &buf1, len+1, 0) == -1){
		perror("msgsnd");
	}

	gettimeofday(&intermediate, NULL);

    if(msgrcv(msgqid2, &buf2, sizeof(buf2), 6, MSG_NOERROR) == -1){
        perror("msgrcv");
        exit(1);
    }

    gettimeofday(&stop, NULL);

    printf("Sending time:%lu Response Time:%lu\n", (intermediate.tv_sec - start.tv_sec)*1000000 + (intermediate.tv_usec - start.tv_usec), (stop.tv_sec - intermediate.tv_sec)*1000000 + (stop.tv_usec - intermediate.tv_usec));
    printf("Data received back from the server.\n");
    printf("%s\n", buf2.mtext);

	return 0;
}
