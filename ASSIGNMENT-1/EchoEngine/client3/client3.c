// C program for message queue.

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

// structure for message queue.
struct message_queue {
    long message_type;
    char message_text;
} message, message2;

int main(){
    key_t key, key2;
    int message_id, message_id2;

    // ftok to generate unique key.
    key = ftok("client3", 65);

    // msgget creates a message queue and returns identifier.
    message_id = msgget(key, 0666 | IPC_CREAT);
    // printf("%d\n", message_id);
    message.message_type = 3;

    printf("Enter the data\n");
    scanf("%c", &message.message_text);
    // gets(message.message_text);

    // msgsnd to send message.
    msgsnd(message_id, &message, sizeof(message), 0);

    key2 = ftok("server3", 65);
    message_id2 = msgget(key2, 0666 | IPC_CREAT);
    // printf("before\n");
    // if(msgrcv(message_id2, &message2, sizeof(message2), 1, 0)!=-1){printf("dvshn\n");}
    msgrcv(message_id2, &message2, sizeof(message2), 3, 0);
    // printf("after\n");
    printf("Data Received from server is : %c \n", message2.message_text);

    return 0;
}
