#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct my_msgbuf {
    long mtype;
    char mtext[20000];
};

int main(void){
	struct my_msgbuf buf1, buf2, buf3, buf4, buf5, buf6, buf7, buf8, buf9, buf10;
	int msgqid1, msgqid2, msgqid3, msgqid4, msgqid5, msgqid6, msgqid7, msgqid8, msgqid9, msgqid10;
	key_t key1, key2, key3, key4, key5, key6, key7, key8, key9, key10;
	FILE *file1, *file2, *file3, *file4, *file5;

	if((key1 = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/DatabaseEngine/client1", 19)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid1 = msgget(key1, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);
	}

    // printf("%d\n",msgqid1);
	if(msgrcv(msgqid1, &buf1, sizeof(buf1), 1, MSG_NOERROR) == -1){
		perror("msgrcv");
		exit(1);
	}

    printf("Data received from client1.\n");
	// printf("%s\n", buf1.mtext);

    if((key2 = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/DatabaseEngine/client1", 20)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid2 = msgget(key2, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);
	}

    buf2.mtype = 2;
    long numbytes1;
    char *buffer1;
	if(access(buf1.mtext, F_OK) != -1){
		file1 = fopen(buf1.mtext, "r");
		fseek(file1, 0L, SEEK_END);
		numbytes1 = ftell(file1);
		fseek(file1, 0L, SEEK_SET);
		buffer1 = (char*)calloc(numbytes1, sizeof(char));
		fread(buffer1, sizeof(char), numbytes1, file1);
        fclose(file1);
        // printf("%s\n", buffer);
        strncpy(buf2.mtext, buffer1, numbytes1);
        if(msgsnd(msgqid2, &buf2, numbytes1, 0) == -1){
        	perror("msgsnd");
        }
        printf("Data sent back to the client1.\n\n");

	}
	else{
		printf("File Not exists.\n");
	}

	//___________________________________________________________________________

	if((key3 = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/DatabaseEngine/client2", 19)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid3 = msgget(key3, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);
	}

    // printf("%d\n",msgqid1);
	if(msgrcv(msgqid3, &buf3, sizeof(buf3), 3, MSG_NOERROR) == -1){
		perror("msgrcv");
		exit(1);
	}

    printf("Data received from client2.\n");
	// printf("%s\n", buf1.mtext);

    if((key4 = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/DatabaseEngine/client2", 20)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid4 = msgget(key4, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);
	}

    buf4.mtype = 4;
    long numbytes2;
    char *buffer2;
	if(access(buf3.mtext, F_OK) != -1){
		file2 = fopen(buf3.mtext, "r");
		fseek(file2, 0L, SEEK_END);
		numbytes2 = ftell(file2);
		fseek(file2, 0L, SEEK_SET);
		buffer2 = (char*)calloc(numbytes2, sizeof(char));
		fread(buffer2, sizeof(char), numbytes2, file2);
        fclose(file2);
        // printf("%s\n", buffer);
        strncpy(buf4.mtext, buffer2, numbytes2);
        if(msgsnd(msgqid4, &buf4, numbytes2, 0) == -1){
        	perror("msgsnd");
        }
        printf("Data sent back to the client2.\n\n");

	}
	else{
		printf("File Not exists.\n");
	}

	//___________________________________________________

	if((key5 = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/DatabaseEngine/client3", 19)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid5 = msgget(key5, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);
	}

    // printf("%d\n",msgqid1);
	if(msgrcv(msgqid5, &buf5, sizeof(buf5), 5, MSG_NOERROR) == -1){
		perror("msgrcv");
		exit(1);
	}

    printf("Data received from client3.\n");
	// printf("%s\n", buf1.mtext);

    if((key6 = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/DatabaseEngine/client3", 20)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid6 = msgget(key6, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);
	}

    buf6.mtype = 6;
    long numbytes3;
    char *buffer3;
	if(access(buf5.mtext, F_OK) != -1){
		file3 = fopen(buf5.mtext, "r");
		fseek(file3, 0L, SEEK_END);
		numbytes3 = ftell(file3);
		fseek(file3, 0L, SEEK_SET);
		buffer3 = (char*)calloc(numbytes3, sizeof(char));
		fread(buffer3, sizeof(char), numbytes3, file3);
        fclose(file3);
        // printf("%s\n", buffer);
        strncpy(buf6.mtext, buffer3, numbytes3);
        if(msgsnd(msgqid6, &buf6, numbytes3, 0) == -1){
        	perror("msgsnd");
        }
        printf("Data sent back to the client3.\n\n");

	}
	else{
		printf("File Not exists.\n");
	}

	//_______________________________________________________________

	if((key7 = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/DatabaseEngine/client4", 19)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid7 = msgget(key7, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);
	}

    // printf("%d\n",msgqid1);
	if(msgrcv(msgqid7, &buf7, sizeof(buf7), 7, MSG_NOERROR) == -1){
		perror("msgrcv");
		exit(1);
	}

    printf("Data received from client4.\n");
	// printf("%s\n", buf1.mtext);

    if((key8 = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/DatabaseEngine/client4", 20)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid8 = msgget(key8, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);
	}

    buf8.mtype = 8;
    long numbytes4;
    char *buffer4;
	if(access(buf7.mtext, F_OK) != -1){
		file4 = fopen(buf7.mtext, "r");
		fseek(file4, 0L, SEEK_END);
		numbytes4 = ftell(file4);
		fseek(file4, 0L, SEEK_SET);
		buffer4 = (char*)calloc(numbytes4, sizeof(char));
		fread(buffer4, sizeof(char), numbytes4, file4);
        fclose(file4);
        // printf("%s\n", buffer);
        strncpy(buf8.mtext, buffer4, numbytes4);
        if(msgsnd(msgqid8, &buf8, numbytes4, 0) == -1){
        	perror("msgsnd");
        }
        printf("Data sent back to the client4.\n\n");

	}
	else{
		printf("File Not exists.\n");
	}

	//_________________________________________________________

	if((key9 = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/DatabaseEngine/client5", 19)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid9 = msgget(key9, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);
	}

    // printf("%d\n",msgqid1);
	if(msgrcv(msgqid9, &buf9, sizeof(buf9), 9, MSG_NOERROR) == -1){
		perror("msgrcv");
		exit(1);
	}

    printf("Data received from client5.\n");
	// printf("%s\n", buf1.mtext);

    if((key10 = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/DatabaseEngine/client5", 20)) == -1){
		perror("ftok");
		exit(1);
	}

	if((msgqid10 = msgget(key10, 0666 | IPC_CREAT)) == -1){
		perror("msgget");
		exit(1);
	}

    buf10.mtype = 10;
    long numbytes5;
    char *buffer5;
	if(access(buf9.mtext, F_OK) != -1){
		file5 = fopen(buf9.mtext, "r");
		fseek(file5, 0L, SEEK_END);
		numbytes5 = ftell(file5);
		fseek(file5, 0L, SEEK_SET);
		buffer5 = (char*)calloc(numbytes5, sizeof(char));
		fread(buffer5, sizeof(char), numbytes5, file5);
        fclose(file5);
        // printf("%s\n", buffer);
        strncpy(buf10.mtext, buffer5, numbytes5);
        if(msgsnd(msgqid10, &buf10, numbytes5, 0) == -1){
        	perror("msgsnd");
        }
        printf("Data sent back to the client5.\n\n");

	}
	else{
		printf("File Not exists.\n");
	}

	return 0;
}
