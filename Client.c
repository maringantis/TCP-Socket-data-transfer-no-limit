/*=== Assignment 1 ===

Author: Srinivasa Maringanti
Client side
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


void errormsg(const char *msg)// Method used to call errors
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{

	int fd,portnum;// fd will be used as a socket descriptor
	struct sockaddr_in client;
	//socklen_t c_len;
	char buffer[2];// Unbounded buffer. We transfer byte by byte 

	if (argc<3)
		{
			fprintf(stderr,"[USAGE:] ./netcat IP PORT \n");
			exit(0);
		}
	//Typecast port number from char to int
	portnum=atoi(argv[2]);
	// Creating socket and socket descriptor
	fd=socket(AF_INET,SOCK_STREAM,0);// TCP uses stream so SOCK_STREAM

	// Try opening the socket
	if(fd<0)
	{
		
		errormsg("[ERROR:] Cannot open the socket: ");	
	}
	//Assigning the PORT IP and FAMILY
	
	client.sin_family = AF_INET;
	client.sin_addr.s_addr=inet_addr(argv[1]);// IP
	client.sin_port=htons(portnum);//PORT

	//Connet to the server CHECK
	if(connect(fd,(struct sockaddr*)&client,sizeof(client))<0)
	{
	errormsg("[ERROR:]Cannot connect to the server \n");
	}

	// Read data byte by byte and send it to the server making data unbounded
	while(read(0,&buffer,1)>0)// First 0 indicates stdin
	{
	write(fd,buffer,1);
	}
	close(fd);
	return 0;
}
