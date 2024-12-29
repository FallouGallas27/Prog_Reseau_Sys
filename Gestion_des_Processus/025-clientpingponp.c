#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<sys/socket.h>
int main(int argc,char* argv[]){
// pour executer on ouvre u nouveau terminal et executer la cmd nc -lp numero de port (8000)
// et dans le terminal de travail on donne l@ et le numero de port

    if(argc<3){
        printf("Erreur nombre d'argument insuffisant\n");
        printf("Usage %s  Addresse_IP PORT\n",argv[0]);
        return 0;
    }
    //1 creation de socket
    int sockClient =socket(AF_INET,SOCK_STREAM,0);
    if(sockClient ==-1){
        perror("Erreur de creation de la socket\n");
        return 0;
    }
    //2 preparation de la struct vers le serveur
    struct sockaddr_in addrServer;
    memset(&addrServer,0,sizeof(struct sockaddr_in));

    addrServer.sin_family=AF_INET;
    addrServer.sin_port =htons(atoi(argv[2]));
    addrServer.sin_addr.s_addr = inet_addr(argv[1]);

    //3.connect
    int resultat = connect( sockClient,(struct sockaddr*)&addrServer,
        sizeof(struct sockaddr_in));
    if(resultat ==-1){
        perror("Erreur d'ouverture de la connexion\n");
        return 0;
    }



    //4.Logique de l'application'

    char bufRecive[10];
    char bufSend[]="Pong";
    int nbRecive=0;
    int  i=0;

    while(1){
        memset(bufRecive,0,10*sizeof(char));
        nbRecive = recv(sockClient,bufRecive,10*sizeof(char),0);
        if(nbRecive>0)
            printf("[%d]  Client > Serveur: %s\n",i++,bufRecive);
        sleep(1);
        send(sockClient ,bufSend,strlen(bufSend),0);
        printf("[%d] Serveur > Client %s\n",i,bufSend);
    }
    close(sockClient);
    return 0;
}
