#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

void main(){

	struct sockaddr_in server,client;
	int sock,clientSocket;
	int n1,n2,flag=0;
	char operand,receivedBytes[1024],sendBytes[1024];
	int bytes,result;
	if((sock = socket(AF_INET,SOCK_STREAM,0)) == -1){
		perror("Invalid Socket Descriptor");
		exit(1);	
	}
	
	server.sin_family = AF_INET;
	server.sin_port = htons(5000);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&(server.sin_zero),8);

	if(bind(sock,(struct sockaddr *)&server,sizeof(server)) == -1){
		perror("Unable to bind");
		exit(1);
	}
	
	if(listen(sock,5) == -1){
		perror("Unable to listen");
		exit(1);
	}
	printf("Server waiting for client...");
	fflush(stdout); 

	while(1){
		int len = sizeof(client);
		clientSocket = accept(sock,(struct sockaddr *)&client,&len);
		if(clientSocket == -1){
			perror("Connection error");
			exit(1);
		}
		printf("I recevied a connection from %s on port %d",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
	
		while(1){
			printf("\nReceiving first number...");
			bytes = recv(clientSocket,receivedBytes,1024,0);
			receivedBytes[bytes] = '\0';
			n1 = atoi(receivedBytes);

			printf("\nReceiving second number...");
			bytes = recv(clientSocket,receivedBytes,1024,0);
			receivedBytes[bytes] = '\0';
			n2 = atoi(receivedBytes);

			printf("\nReceiving the operand...");
			bytes = recv(clientSocket,receivedBytes,1024,0);
			receivedBytes[bytes] = '\0';
			operand = receivedBytes[0];

			switch(operand){
				case '+':
					result = n1 + n2;
					sprintf(sendBytes,"%d",result);
					break;
				case '-':
					result = n1 - n2;
					sprintf(sendBytes,"%d",result);
					break;
				case '*':
					result = n1 * n2;
					sprintf(sendBytes,"%d",result);
					break;
				case '/':
					result = n1 / n2;
					sprintf(sendBytes,"%d",result);
					break;
				case '%':
					result = n1 % n2;
					sprintf(sendBytes,"%d",result);
					break;
				case 'q':
					printf("Client wants to exit...");
					flag=1;
					break;
			}
			if(flag == 1){
				close(clientSocket);	
				break;
			}

			printf("\nSending result...");
			bytes = send(clientSocket,sendBytes,1024,0);						
		}
	}
}
/*
socket()
bind()
listen()
accept()
recv()
send()
*/
