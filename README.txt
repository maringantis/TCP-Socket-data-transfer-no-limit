=== TCP Socket ===

Author: Srinivasa Maringanti

== Description ==
TCP socket program with no limit data transfer from client to server.No FILES operations were used.
*TCP program assignment uses client.c and server.c for running execution.
*TCP program assignment uses file and yfileCopy files to send and transfer data using stdin and stdout.NOT USING FILES.

== How to compile and run the files ==

------TCP code running and execution------

** After the code is ready first compile the files using make file that is already in the folder.
** Check for errors.Ignore warnings.If compiled the program is ready to run.
** Now on the server side of the terminal use the following command
	./server 8207 > FileCopy
where 8207 is the port number which we are giving using command line argument and FileCopy is the name of the text file where the data from client is saved.
** Server starts running and is waiting for the client.
** Now on the client side of the terminal use the following command
	cat File | ./client 192.168.1.1 8207
where 192.168.1.1 is the ip address which should be same as we hardcoded in the server,8207 is the port number which we are giving using command line argument and File is the name of the text file where the data is present that has to be sent to the server.
**As the server is already waiting, once client runs it accepts the data and prints the IP and Port number of the client it is connected to.

