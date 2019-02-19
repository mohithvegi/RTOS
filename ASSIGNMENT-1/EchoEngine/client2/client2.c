// C program for message queue.

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/time.h>

// structure for message queue.
struct message_queue {
    long message_type;
    char message_text;
} message, message2;

int main(){
    struct timeval start, intermediate, stop;
    key_t key, key2;
    int message_id, message_id2;

    // ftok to generate unique key.
    key = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/EchoEngine/client2", 65);

    // msgget creates a message queue and returns identifier.
    message_id = msgget(key, 0666 | IPC_CREAT);
    // printf("%d\n", message_id);
    message.message_type = 2;

    printf("Enter the data\n");
    scanf("%c", &message.message_text);
    // gets(message.message_text);
    gettimeofday(&start, NULL);
    msgsnd(message_id, &message, sizeof(message), 0);
    gettimeofday(&intermediate, NULL);

    key2 = ftok("/home/dell/IMT2015046/8th sem/RTOS/A/ASSIGNMENT-1/EchoEngine/client2", 66);
    message_id2 = msgget(key2, 0666 | IPC_CREAT);
    msgrcv(message_id2, &message2, sizeof(message2), 2, 0);
    gettimeofday(&stop, NULL);
    printf("Sending time:%lu Response Time:%lu\n", (intermediate.tv_sec - start.tv_sec)*1000000 + (intermediate.tv_usec - start.tv_usec), (stop.tv_sec - intermediate.tv_sec)*1000000 + (stop.tv_usec - intermediate.tv_usec));
    printf("Data Received from server is : %c \n", message2.message_text);

    return 0;
}
