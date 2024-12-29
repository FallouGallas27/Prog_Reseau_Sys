#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
int main(int argc , char*argv[]){
    if(argc<3){
        printf("Nombre d'arguments insufissant\n");
        printf("Usage  :%s addresse IP PORT \n",argv[0]);
        return 0;
    }
    struct sockaddr_in addrServer;
    //Initialiser la structure a 0
    memset(&addrServer,0,sizeof(struct sockaddr_in));
    addrServer.sin_family =AF_INET;
    addrServer.sin_port =atoi(argv[2]);
        addrServer.sin_addr.s_addr = inet_addr(argv[1]);
    //addrServer.sin_addr.s_addr = inet_ntoa(addrServer.sin_port);
    //addrServer.sin_port=  htons(atoi(argv[2]));

    printf("Adresse IP : %s :%X \n", inet_ntoa(addrServer.sin_addr),ntohl(addrServer.sin_addr.s_addr));
    printf("Numero de PORT %d :   %d\n",ntohs(addrServer.sin_port),
           addrServer.sin_port);
    return 0;

}
