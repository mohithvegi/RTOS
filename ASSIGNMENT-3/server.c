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
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <pulse/simple.h>
#include <pulse/error.h>
#include <pulse/gccmacro.h>

#define BUFSIZE 1024

int main(int argc, char*argv[])
	{
		int serverSocket, new_socket;
	  	int opt = 1;
		unsigned char message[1024];
    	struct sockaddr_in address, server_addr;
    	int addrlen = sizeof(address);
		// Creating socket file descriptor
    	if((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    		{
        		perror("socket failed");
        		exit(EXIT_FAILURE);
    		}
    	memset((char*)&server_addr, 0, sizeof(server_addr));	
    	if(setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    		{
        		perror("setsockopt");
        		exit(EXIT_FAILURE);
    		}
	    address.sin_family = AF_INET;
	    address.sin_addr.s_addr = INADDR_ANY;
	    address.sin_port = htons( 8000 );
	    if(bind(serverSocket, (struct sockaddr *)&address, sizeof(address))<0)
	    	{
	    	    perror("bind failed");
	        	exit(EXIT_FAILURE);
	    	}
	    if(listen(serverSocket, 2) < 0)
	    	{
	        	perror("listen");
	        	exit(EXIT_FAILURE);
	    	}
	  	uint8_t *buf;
	    ssize_t r;

		static const pa_sample_spec ss = {
	        .format = PA_SAMPLE_S16LE,
	        .rate = 8000,
	        .channels = 2
	    };
	  	pa_simple *s = NULL;
	    int ret = 1;
	    int error;
	    if (!(s = pa_simple_new(NULL, argv[0], PA_STREAM_PLAYBACK, NULL, "playback", &ss, NULL, NULL, &error))) {
	    	    fprintf(stderr, __FILE__": pa_simple_new() failed: %s\n", pa_strerror(error));
	        	goto finish;
	    }

	    new_socket = accept(serverSocket, (struct sockaddr *)&address,(socklen_t*)&addrlen);
	  	while(1)
	  		{
	      		if((r = read(new_socket, message, BUFSIZE)) <= 0) {
	            	if (r == 0) /* EOF */
	                	break;
	            	fprintf(stderr, __FILE__": read() failed: %s\n", strerror(errno));
	            	goto finish;
	        	}
	        	buf = (uint8_t*)message;
	  	  		if(pa_simple_write(s, buf, (size_t) r, &error) < 0) {
	            	fprintf(stderr, __FILE__": pa_simple_write() failed: %s\n", pa_strerror(error));
	            	goto finish;
	        	}
	  		}
	  	if(pa_simple_drain(s, &error) < 0) {
	    	fprintf(stderr, __FILE__": pa_simple_drain() failed: %s\n", pa_strerror(error));
	        goto finish;
	    }

    	ret = 0;

		finish:
	    	if (s)
        	pa_simple_free(s);

    	return ret;
	}