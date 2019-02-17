// C program for message queue.
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

// structure for message queue.
struct message_queue {
    long message_type;
    char message_text;
} message, message2, message3, message4, message5, message6, message7, message8, message9, message10;

int main(){
    key_t key, key2, key3, key4, key5, key6, key7, key8, key9, key10;
    int message_id, message_id2, message_id3, message_id4, message_id5, message_id6, message_id7, message_id8, message_id9, message_id10;
    char C, C2, C3, C4, C5;

    // ftok to generate unique key.
    key = ftok("client1", 65);

    // msgget creates a message queue and returns identifier.
    message_id = msgget(key, 0666 | IPC_CREAT);

    // msgrcv to receive message.
    msgrcv(message_id, &message, sizeof(message), 1, 0);

    // display the message
    printf("Data Received from client1 is : %c \n", message.message_text);

    C = message.message_text;
    if(C >= 'a' && C <= 'z'){
        C = C - 32;
    }
    else if(C >= 'A' && C <= 'Z'){
        C = C + 32;
    }
    else{
        C = C;
    }
    printf("%c\n", C);
    message2.message_text = C;
    message2.message_type = 1;
    // to destroy the message queue
    //msgctl(message_id, IPC_RMID, NULL);

    key2 = ftok("server", 65);
    message_id2 = msgget(key2, 0666 | IPC_CREAT);
    msgsnd(message_id2, &message2, sizeof(message2), IPC_NOWAIT);
    printf("Message sent to client1.\n");

    // __________________________________________________________

    key3 = ftok("client2", 65);
    message_id3 = msgget(key3, 0666 | IPC_CREAT);
    // printf("%d\n", message_id3);
    msgrcv(message_id3, &message3, sizeof(message3), 2, 0);
    printf("Data Received from client2 is : %c \n", message3.message_text);
    C2 = message3.message_text;
    if(C2 >= 'a' && C2 <= 'z'){
        C2 = C2 - 32;
    }
    else if(C2 >= 'A' && C2 <= 'Z'){
        C2 = C2 + 32;
    }
    else{
        C2 = C2;
    }
    message4.message_text = C2;
    message4.message_type = 2;
    printf("%c\n", message4.message_text);

    key4 = ftok("server2", 65);
    message_id4 = msgget(key4, 0666 | IPC_CREAT);
    msgsnd(message_id4, &message4, sizeof(message4), 0);
    printf("Message sent to client2.\n");

    // __________________________________________________________

    key5 = ftok("client3", 65);
    message_id5 = msgget(key5, 0666 | IPC_CREAT);
    // printf("%d\n", message_id5);
    msgrcv(message_id5, &message5, sizeof(message5), 3, 0);
    printf("Data Received from client2 is : %c \n", message5.message_text);
    C3 = message5.message_text;
    if(C3 >= 'a' && C3 <= 'z'){
        C3 = C3 - 32;
    }
    else if(C3 >= 'A' && C3 <= 'Z'){
        C3 = C3 + 32;
    }
    else{
        C3 = C3;
    }
    message6.message_text = C3;
    message6.message_type = 3;
    printf("%c\n", message6.message_text);

    key6 = ftok("server3", 65);
    message_id6 = msgget(key6, 0666 | IPC_CREAT);
    msgsnd(message_id6, &message6, sizeof(message6), 0);
    printf("Message sent to client3.\n");

    // __________________________________________________________

    key7 = ftok("client4", 65);
    message_id7 = msgget(key7, 0666 | IPC_CREAT);
    // printf("%d\n", message_id7);
    msgrcv(message_id7, &message7, sizeof(message7), 4, 0);
    printf("Data Received from client4 is : %c \n", message7.message_text);
    C4 = message7.message_text;
    if(C4 >= 'a' && C4 <= 'z'){
        C4 = C4 - 32;
    }
    else if(C4 >= 'A' && C4 <= 'Z'){
        C4 = C4 + 32;
    }
    else{
        C4 = C4;
    }
    message8.message_text = C4;
    message8.message_type = 4;
    printf("%c\n", message8.message_text);

    key8 = ftok("server4", 65);
    message_id8 = msgget(key8, 0666 | IPC_CREAT);
    msgsnd(message_id8, &message8, sizeof(message8), 0);
    printf("Message sent to client4.\n");

    // __________________________________________________________

    key9 = ftok("client5", 65);
    message_id9 = msgget(key9, 0666 | IPC_CREAT);
    // printf("%d\n", message_id9);
    msgrcv(message_id9, &message9, sizeof(message9), 5, 0);
    printf("Data Received from client5 is : %c \n", message9.message_text);
    C5 = message9.message_text;
    if(C5 >= 'a' && C5 <= 'z'){
        C5 = C5 - 32;
    }
    else if(C5 >= 'A' && C5 <= 'Z'){
        C5 = C5 + 32;
    }
    else{
        C5 = C5;
    }
    message10.message_text = C5;
    message10.message_type = 5;
    printf("%c\n", message10.message_text);

    key10 = ftok("server5", 65);
    message_id10 = msgget(key10, 0666 | IPC_CREAT);
    msgsnd(message_id10, &message10, sizeof(message10), 0);
    printf("Message sent to client5.\n");

    return 0;
}
