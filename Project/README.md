# **RTOS Project**

## **Problem** : 
1. The first part of problem statement is transmission of video from server to client through socket and playing it at the client from the program itself.
2. Performing live streaming i.e capturing of Video from webcam and audio through PAL at Server end and playing it at client through TCP Socket.  

## **Solution** :
We have used v4l to record video from webcam,aucodec to get audio and we used ffmeg stream converter to get it combined in the form of mpg video file and playing the mpg video file.
## **Implementation** : 
For capturing the video we used video4linux and for recording the audio we used  different formats like aucodec,pulse audio as there was a bit problem in sync of video and audio.
At server we are recording the video through and then sending it to the client through the socket and then playing the video at the client.
### ffmpeg command we used : 
    ffmpeg -f v4l2 -standard PAL -thread_queue_size 512 -i /dev/video0 -f alsa -thread_queue_size 512 -i default -vcodec libx264 -preset superfast -crf 25 -s 640x480 -r 25 -aspect 16:9 -acodec libmp3lame -b:a 128k -channels 2 -ar 48000 -t 20 out2.mpg
### ffmpeg arguments : 
    -f(format of input/output)
        The format is normally auto detected for input files and guessed from the file extension for output files.
    -thread_queue_size
        this option sets the maximum number of queued packets when reading from the file.
    -i(input)
        input file url.
    -b:a
        sets the audio bit rate.
    -r 25
        sets the frame rate to 25.
    -ar 48000
        sets the audio sample rate.
    -channels
        number of audio channels.
    -vcodec libx264
        sets the video codec.
    -t(duration)
        duration for reading from input file or for writing into the output file.

## **Challenges**
We tried different permutations for the sync of audio and video and used different audio sources like pulse audio, alsa...
### Some of the commands we used using ffmpeg :
    ffmpeg -y -f alsa -ac 2 -i pulse -acodec pcm_s16le -f v4l2 -framerate 25 -video_size 640x480 -i /dev/video0 out.mp4
    
    ffmpeg -f alsa -ac 2 -i default -itsoffset 00:00:02.5 -f video4linux2 -s 320x240 -r 25 -i /dev/video0 out2.mpg

### Varying itsoffset to delay the audio, so that it should with the video.
        
## **Problems**
We tried implementing two sockets one for audio and one for video. We have used video4linux for video capturing to store the frames and then play it. We are not able to capture multiple frames. We tried to capture the frames as images using v4l, but we are able to capture only one image.
        
## **Github link** : <https://github.com/mohithvegi/RTOS>
