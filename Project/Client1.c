#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <sys/types.h>         
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <arpa/inet.h> 
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char*argv[]){
	int client_fd, len_c, n, check;
	struct sockaddr_in server;
    uint8_t buf[BUFSIZE];
    int con_check;
    unsigned char message[1024];
	ssize_t r;

    int ret = 1;
    int error;

    client_fd = socket(AF_INET,SOCK_STREAM,0);

    server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr(argv[1]);
	server.sin_port=htons(8000);
	memset(server.sin_zero, '\0', sizeof server.sin_zero);

	con_check = connect(client_fd,(struct sockaddr *)&server, sizeof(server));
    printf("connection done\n");
	
	int fd2;
	int count = 0;
	remove("temp.mpg");
	if (!fork())
   		{
     		sleep(1);	   
     		system("xdg-open temp.mpg > /dev/null 2>&1");
   		}	   
  	else
  		{
  			while(1)
  				{
					fd2 = open("temp.mpg",O_WRONLY|O_APPEND|O_CREAT,0644);
      					if ((r = read(client_fd, message, sizeof(message))) <= 0) {
            					if (r == 0 && count<4){
							sleep(0.5);
							count++;
						}

						else{
							break;
						}       
						/* EOF */
            					//sleep(0.05);  
                				//break;
            					//fprintf(stderr, __FILE__": read() failed: %s\n", strerror(errno));
            					//goto finish;
        				}
    
		        		   //printf("%s\n",message);
           					write(fd2,message,r);
	   					close(fd2);
				}
		}

	return 0;
}
