#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>

int main()
{
	
	int client_sockfd;
	client_sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

	char recv[100],send[100];

	struct sockaddr_in server_addr,client_addr;
	int serversize=sizeof(server_addr);
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(50128);
	server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

	printf("\nEnter sending data:");
	scanf("%s",send);

	sendto(client_sockfd,send,sizeof(send),0,(struct sockaddr *)&server_addr,sizeof(server_addr));

	recvfrom(client_sockfd,recv,sizeof(recv),0,(struct sockaddr *)&server_addr,&serversize);

	printf("%s",recv);
	close(client_sockfd);
}
