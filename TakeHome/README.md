Implementation of Real time data collection system
A set of legacy sensors are used collect real time data (various parameters) of a machine in a
pharmaceutical manufacturing plant. Due to some reason the company do not want to upgrade these
machine and sensors but want to continue using it. A new requirement has come to integrate this with a
real time monitoring and reporting solution. You are assigned to create a real time system to collect,
validate and record the data from sensors.
There are five sensors in the system each of them giving five seperate parameters of the processing
plant. Each of them are Temperature, humudity, concentration of three other gases in parts per million.
Each of them are Methane, Carbon Monoxide and Propane. Objecive is to keep a close watch on these
parameters and study the quality of the products manufactured in the plant.
The problem with sensors are the they do not give any electrical signal and output (either as digital or
analog) instead they write the current data into a file in a small SD card attached to them. However it is
possible to read this data written into this file through a C PRogram which we can develop.
Each time when the sensor has data it writes into a particular file, next time when the data arrives it
over writes the file, so if we want to collect the data we need to read it before the next one arrives.
There is a specific frequeny at which sensor reads data and writes into the file.
You are asked to write a C program which will read the five files and send it to remote computer using
TCP/IP. So we have two programs one is server which runs on the computer inside the plant and it has
access to the file into which the sensor writes data periodically.
Then we have client program which runs on a laptop/Desktop which send periodic request to server to
get data. the client program as soon as it get write into a .csv file, which can processed later to generate
graphs and charts from the data stored.At the server side, for some reason (legacy system) the clocks and timers are not very reliable hence all
timings control has to be from client side.
Client has to fetch the data from the files, in parallel and the append it to a csv file. The csv file will have
five coloums. Each col is for a particular sensor. In short the .csv will look like a table with Six cols. First
col is from the time stamp, next five cols is for each sensor. Time stamp across each sensor has to
match.
Once you had the data captured in .csv file you need to use the graphs in excel and display the data.
