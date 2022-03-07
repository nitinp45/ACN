#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>

/*
int main()
{
    int clsocke;

    clsocke = socket(AF_INET,SOCK_STREAM,0);

}
*/

int main()
{
    int clsock, stat, cnt;
    struct sockaddr_in ser_addr;
    char msg[]="Hello";
    char msgrcv[]="aaaaaa";

    clsock = socket(AF_INET,SOCK_STREAM,0);
    if(clsock==-1)
    {
        printf("Could not create socket....\n");
        exit(0);
    }

    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(5000);
    ser_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    printf("Enter 1 to connect\n");
    scanf("%d",&stat);

    connect(clsock,(struct sockaddr*)&ser_addr,sizeof(ser_addr));

    printf("Sending data ...\n");
    cnt = send(clsock,msg,6,0);
    printf("Byts send: %d\n",cnt);

    cnt = recv(clsock,msgrcv,5,0);
    printf("recived %d bytes\n",cnt);
    printf("Message Recived: %s\n",msg);

    return(1);



}

