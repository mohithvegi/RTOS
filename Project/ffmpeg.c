#include <stdio.h>
#include <stdlib.h>

int main(){
	system("ffmpeg -f v4l2 -standard PAL -thread_queue_size 512 -i /dev/video0 -f alsa -thread_queue_size 512 -i default -vcodec libx264 -preset superfast -crf 25 -s 640x480 -r 25 -aspect 16:9 -acodec libmp3lame -b:a 128k -channels 2 -ar 48000 -t 20 out2.mpg");

	return 0;
}
