#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <sys/types.h>         
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <stdio.h>
#include <arpa/inet.h> 
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <pulse/simple.h>
#include <pulse/error.h>
#include <pulse/gccmacro.h>

#define BUFSIZE 1024

int main(int argc, char*argv[]){
    int clientSocket;
    struct sockaddr_in server_addr;
    struct hostent *ptrh;
    uint8_t buf[BUFSIZE];
    unsigned char *message;
    if((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
        printf("\n Socket creation error \n");
        return -1;
        }
  
    memset((char*)&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8000);
    
    ptrh = gethostbyname("172.16.128.228");
    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr)<=0) 
        {
            printf("\nInvalid address2/ Address not supported \n");
            return -1;
        }
    if(connect(clientSocket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        {
            printf("\nConnection Failed \n");
            return -1;
        }

    static const pa_sample_spec ss = {
        .format = PA_SAMPLE_S16LE,
        .rate = 8000,
        .channels = 2
    };

    pa_simple *s = NULL;
    int ret = 1;
    int error;

    if (!(s = pa_simple_new(NULL, argv[0], PA_STREAM_RECORD, NULL, "record", &ss, NULL, NULL, &error))) 
        {
            fprintf(stderr, __FILE__": pa_simple_new() failed: %s\n", pa_strerror(error));
            goto finish;
        }

    while(1){
        if(pa_simple_read(s, buf, sizeof(buf), &error) < 0){
            fprintf(stderr, __FILE__": pa_simple_read() failed: %s\n", pa_strerror(error));
            goto finish;
        }
        //sleep(1);
        message = (unsigned char*)buf;
        write(clientSocket, message, BUFSIZE);      
    }
    
    ret = 0;
    
    finish:
        if(s)
        pa_simple_free(s);

    return ret;
}