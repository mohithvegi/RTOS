#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char*argv[])
	{
  		int server_desc, client_desc, val;
		struct sockaddr_in server,client;
		unsigned char message[BUFSIZE];
		int opt = 1;
		int addrlen = sizeof(client);
		uint8_t *buf;
        ssize_t r;

	    int ret = 1;
    	int error;

		server_desc = socket(AF_INET,SOCK_STREAM,0);

	  	server.sin_family=AF_INET;
		server.sin_addr.s_addr=INADDR_ANY;
		server.sin_port=htons(8000);
		memset(server.sin_zero, '\0', sizeof server.sin_zero);

		int bind_check = bind(server_desc, (struct sockaddr *)&server, sizeof(server));
  		printf("Binding done:\n ");
  		listen(server_desc, 1);
  		client_desc = accept(server_desc, (struct sockaddr *)&client, (socklen_t*)&addrlen);
  		//int ptr=fopen("temp.dat", "wb");
		//remove("out2.mpg");
  		int fd = open("out2.mpg", O_RDWR);
		int count=0;
		/*
		if(!fork()){
			system("ffmpeg -f v4l2 -standard PAL -thread_queue_size 512 -i /dev/video0 -f alsa -thread_queue_size 512 -i hw:0,0 -vcodec libx264 -preset superfast -crf 25 -s 640x480 -r 25 -aspect 16:9 -acodec libmp3lame -b:a 128k -channels 2 -ar 48000 -t 20 out2.mpg");
			//sleep(20);
		}
		else{*/
		while(1){
			int br = read(fd, message, sizeof(message));
				if(br > 0 && count<4){
					write(client_desc, message, br);
					count=0;
				}
				else if (br <= 0 && count <4)
				{
                	              sleep(1);
                	              count = count +1;
		
				}
				else{
					break;
				}
			}
		//}
	
	return 0;
}
