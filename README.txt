# 

=== TCP Socket ===

Author: Srinivasa Maringanti

== Description ==
TCP socket program with no limit data transfer from client to server.No FILES operations were used.
*TCP program assignment uses client.c and server.c for running execution.
*TCP program assignment uses file and yfileCopy files to send and transfer data using stdin and stdout.NOT USING FILES.

== How to compile and run the files ==

------TCP code running and execution------

** After the code is ready first compile the files using make file that is already in the folder.
** Command for make is make netcat netcatd.
** Check for errors.Ignore warnings.If compiled the program is ready to run.
** Now on the server side of the terminal use the following command
	./netcatd 8207 > myfileCopy
where 8207 is the port number which we are giving using command line argument and myfileCopy is the name of the text file where the data from client is saved.
** Server starts running and is waiting for the client.
** Now on the client side of the terminal use the following command
	cat myfile | ./netcat 192.168.1.1 8207
where 192.168.1.1 is the ip address which should be same as we hardcoded in the server,8207 is the port number which we are giving using command line argument and myfile is the name of the text file where the data is present that has to be sent to the server.
**As the server is already waiting, once client runs it accepts the data and prints the IP and Port number of the client it is connected to.

== Documents ==

*In the documents folder you will find the results in different formats and also a copy of this README file in the document folder.


== Screenshots ==

*In the screenshot folder you will find a few screenshots of both the program executions and outputs.
