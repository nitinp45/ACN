#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
int main()
{
	int server_sockfd;
	server_sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

	char recv[100],send[100];

	struct sockaddr_in server_addr,client_addr;
	int clientsize=sizeof(client_addr);
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(50128);
	server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

	bind(server_sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr));
	recvfrom(server_sockfd,recv,sizeof(recv),0,(struct sockaddr *)&client_addr,&clientsize);

	printf("%s",recv);
	printf("\nEnter your data:");
	scanf("%s",send);
	sendto(server_sockfd,send,sizeof(send),0,(struct sockaddr *)&client_addr,clientsize);
}
