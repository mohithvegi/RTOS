# EchoEngine

## Results

### Trail-1 : When same data is sent multiple times.

SNO | Sending Time(in micro seconds) | Service Time(in micro seconds)
--- | ------------------------------ | ------------------------------
  1 |               6                |                19              
  1 |               6                |                24              
  1 |               7                |                24              
  1 |               5                |                22              
  1 |               7                |                23              

### Trail-2 : When data is sent through multiple clients.

No of clients | Sending Time(in micro seconds) | Service Time(in micro seconds)
------------- | ------------------------------ | ------------------------------
  1           |               14               |                21              
  2           |               14               |                24              
  3           |               15               |                26              
  4           |               17               |                32              
  5           |               17               |                33              