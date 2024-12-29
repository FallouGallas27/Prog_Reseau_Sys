#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>
int main(int argc , char*argv[]){
    //creation de socket TCP
    //netstat -ntlp   donne les umero de ports ou ya pas de connexion
    int socketserverTCP =socket(AF_INET,SOCK_STREAM,0);
     if(socketserverTCP ==-1){
         perror("Erreur de creation de la socket TCP\n");
         return 0;
    }
    printf("creation de la socket TCP avec succes\n");

    //2 Initialisation de la structure d'adreass
        struct sockaddr_in addrServer;
        memset(&addrServer ,0, sizeof(struct sockaddr_in));
        addrServer.sin_family =AF_INET;
        addrServer.sin_port=htons(atoi(argv[1]));
        addrServer.sin_addr.s_addr = inet_addr("0.0.0.0");
    //3.Appel binnd

        int resultat = bind(socketserverTCP ,(struct sockaddr*)&addrServer,sizeof(struct sockaddr_in));
        if(resultat ==-1){
            perror("Erreur de lancement de bind\n");
            return 0;
        }

        resultat = listen(socketserverTCP,5);
         if(resultat ==-1){
            perror("Erreur de lancement de bind\n");
            return 0;
        }
        printf("Execution de listen avec succes\n");


        ///Accept
        ///Declaration de la structure qui va contenir l @ dostante
        struct sockaddr_in addrClient;
        int taille =sizeof(struct sockaddr_in);
        int sockClientTCP;

        //buffer
        char bufferSend[]="Pong";
        char bufferRecive[10]= "Ping";
        while(1){
        sockClientTCP=accept(socketserverTCP,(struct sockaddr *)&addrClient,&taille);
        printf("Connexion acceptee pour le client %s :%s\n",inet_ntoa(addrClient.sin_addr),ntohs(addrClient.sin_port));
        // envoye ping
        send(sockClientTCP,bufferSend,strlen(bufferSend),0);
        printf("Envoie de ping\n");
                sleep(1);
        //recevoir port
                memset(bufferRecive,0,10);
        recv(sockClientTCP,bufferRecive,5*sizeof(char),0);
        printf("Donnees recus %s",bufferRecive);
        close(sockClientTCP);
    }

    return 0;
}
