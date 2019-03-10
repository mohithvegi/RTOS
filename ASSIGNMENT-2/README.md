Sockets
Echo Engine
1. We have a Process called Server (a separate executable) running on a computer. The folder where it has started has collection of text files (all ending with .txt extenstion). 
2. We have a five separate process (Called Clients) ClientA, ClientB, ClientC, ClientD, ClientE.  Each of them are running in separate folders.
3. Each client can communicate with Server through a TCP/IP.  Similarly server can send messages back to client through socket
4. As the first step you should implement a server and five clients that can communicate through socket. For example. The Client A sends an alphabet say.... 'd' to server, server receives it converts it into upper case and send it client. Like this every client will send an alphabet to server and it respond back with the corresponding upper case. In case if you send an upper case alphabet, the server responds with lower case. If you send any other character like *, $ % or numbers the server does not do anything it just respond back with the same character.
Once you get such a simple client server working with sockets,we can go to the next level, which is implementing a data base engine.
In this exercise you are expected to measure the time taken by a server to respond to a request under various conditions. Like when all the five clients are sending request at the same time, when only one client is sending when two clients are sending request  like that and tabulate the results.
Data base Engine
Here we need to modify the functionality of both client and server
As it was mentioned earlier the server has a collection of files (hundreds of files) in its folder.   Client send a request as string to the server the request will of the format 
GET <filename>  and server will respond to the request by sending the contents of the file back to the client as another string.
Eg  Client send GET marks.txt  then the server will respond back with contents of the file.
In case if the client send a filename which does not exist in server, the  server will respond with the string "Data not found"
You are expected to test the client server properly with all combinations. Like one client sending a request, multiple clients ( 5 max) sending request still the server responds.
In this exercise you are expected to measure the time taken by a server to respond to a request under various conditions. Like when all the five clients are sending request at the same time, when only one client is sending when two clients are sending request  like that and tabulate the results.
How to do the assignment
1. Create folder called ASSIGNMENT-2 in your GITHUB repository (repository name RTOS)
2. Create folder called EchoEngine inside ASSIGNMENT-2
3. Implement the Echo Engine and upload it into RTOS/ASSIGNMENT-2/SocketEchoEngine
4. Capture the performance data and enter it into a .md (markdown file) and have it in the same folder
5. Implement the Echo Engine and upload it into RTOS/ASSIGNMENT-1/DatabaseEngine
6. Capture the performance data and enter it into a .md (markdown file) and have it in the same folder
