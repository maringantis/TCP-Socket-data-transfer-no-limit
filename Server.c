/*=== Assignment 1 ===

Author: Srinivasa Maringanti
SJSU id: 009874969
Tags: TCP
Course: CMPE 207
Submitted to: Prof. Wei Xu
Server side
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void err(const char *msg)// Method used to call errors
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int fd, nfd, portnum;// fd and nfd will be used as a socket descriptor
     struct sockaddr_in server, client;
     socklen_t c_len;

     char buffer[2];// Unbounded buffer. We recieve data byte by byte 
     int n;

     if (argc < 2) 
	{
         fprintf(stderr,"[USAGE:] ./netcatd <PORT>\n");
         exit(1);
      }
	// Creating socket and assigning socket descriptor
     fd = socket(AF_INET, SOCK_STREAM, 0);// TCP uses stream so SOCK_STREAM
	// Try opening the socket
     if (fd < 0) 
        err("[ERROR:] Opening socket");

	//Assigning the PORT IP and FAMILY
     portnum = atoi(argv[1]);
     server.sin_family = AF_INET;
     server.sin_addr.s_addr = inet_addr("10.250.4.34");
     server.sin_port = htons(portnum);

	// Binding
     if (bind(fd, (struct sockaddr *) &server,sizeof(server)) < 0) 


              err("[ERROR:] Binding");
	// Listen 
     listen(fd,5);

     c_len = sizeof(client);
	char cpt[c_len];


	//Accept the connection from client     
	if (nfd < 0) 

	     nfd = accept(fd,(struct sockaddr *) &client,&c_len);
		inet_ntop(AF_INET, &(client.sin_addr.s_addr),cpt, c_len);
		fprintf(stderr,"Client Address: %s\n",cpt);
	
		fprintf(stderr,"Client Port: %i \n",client.sin_port);
	     if (nfd < 0) 
		  {
		err("[ERROR:] Accepting");
     		  }
		while(1)
		{
		     n = read(nfd,buffer,1);// Read data byte by byte and print
		     if (n < 0) 
		err("[ERROR:] Reading socket");
	             else if (n == 0)
			{ 
		fprintf(stderr,"Recieved all bytes. \n");
		exit(1);
			}

                     else
			{
			printf("%c",buffer[0]);
			}

    
     
    		 }//While loop
     close(nfd);
     close(fd);
     return 0; 
//Main
}
