# DatabaseEngine

## Results

### Trail-1 : When same data is sent multiple times.

SNO | Sending Time(in micro seconds) | Service Time(in micro seconds)
--- | ------------------------------ | ------------------------------
  1 |               4                |                9              
  1 |               6                |                13              
  1 |               4                |                9              
  1 |               6                |                12              
  1 |               6                |                19              

### Trail-2 : When data is sent through multiple clients.

No of clients | Sending Time(in micro seconds) | Service Time(in micro seconds)
------------- | ------------------------------ | ------------------------------
  1           |               7                |                79              
  2           |               7                |                92              
  3           |               7                |                151              
  4           |               16               |                162              
  5           |               17               |                198              