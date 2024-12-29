#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<arpa/inet.h>
void affiche_requete(char *bufferReceve);
void affiche_sockaddr(struct sockaddr_in sockaddr);
int main(int argc,char *argv[]){
    if(argc<2){
        perror("Nbre d'argument insufisant\n");
        printf("Usage : %s PORT ",argv[0]);
        return 0;
    }
    int socketServer =socket(AF_INET,SOCK_STREAM,0);
    if(socketServer==-1){

    }
    printf("[#Server Web#] Creation de la socket .............OK\n");

    //2. Initialiser la structure d'adressse
    struct sockaddr_in addrServer;
    memset(&addrServer,0, sizeof(addrServer));

    addrServer.sin_family =AF_INET;
    addrServer.sin_port= htons(atoi(argv[1]));
    addrServer.sin_addr.s_addr=inet_addr("0.0.0.0");
    printf("[#Server Web#] Initialisation de la structure.............OK\n");
    // Nommage  de la structure
    int resultat = bind(socketServer,(struct sockaddr*)&addrServer,sizeof(struct sockaddr_in));
    if(resultat ==-1){
        perror("Erreur de nommmage de la socket bind\n");
        return 0;
    }
    //4 Appel de listen
    resultat = listen(socketServer,5);
    if(resultat ==-1){
        perror("Erreur d'appel de listen\n");
        return 0;
    }
    printf("[#Server web#] Appel de listen ..................OK\n");


    struct sockaddr_in addrClient;
    int taille_addr=sizeof(struct sockaddr_in);
    int socketClient;
    char bufferReceve[256];
    int nbReceve;
    while(1){
        socketClient =accept(socketServer,(struct sockaddr*)&taille_addr);
        affiche_sockaddr(addrClient);
        memset(bufferReceve,0,819*sizeof(char));
        nbReceve =recv(socketClient,bufferReceve,8192*sizeof(char),0);
        if(nbReceve <0){
            return 0;
        }
        affiche_requete(bufferReceve);
        close(socketClient);
    }
    return 0;
}
void affiche_requete(char *bufferReceve){
    printf("Requete du  Client: \n");
    printf("%s\n",bufferReceve);
    printf("================================================\n");

}

void affiche_sockaddr(struct sockaddr_in sockaddr){
    printf("Client affiche ");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Adresse IP %s\n",inet_ntoa(sockaddr.sin_addr) );
    printf("Numero de port : %d\n",ntohs(sockaddr.sin_port));
}
