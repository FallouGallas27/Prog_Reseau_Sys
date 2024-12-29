#include "commom.h"
#include <errno.h>

int main(int argc , char* argv[]) {
    if (argc < 2) {
        printf("Erreur : nombre d'arguments insuffisant \n");
        printf("Usage : %s PORT \n", argv[0]);
        return 1;
    }

    int sockserv;
    sockserv = socket(AF_INET, SOCK_STREAM, 0);
    if (sockserv == -1) {
        perror("socket");
        exit(1);
    }
    printf("Creation de la socket reussie\n");

    struct sockaddr_in serversock;
    memset(&serversock, 0, sizeof(struct sockaddr_in));
    serversock.sin_family = AF_INET;
    serversock.sin_port = htons(atoi(argv[1]));
    serversock.sin_addr.s_addr = inet_addr("0.0.0.0");

    int resultat = bind(sockserv, (struct sockaddr*)&serversock, sizeof(struct sockaddr_in));
    if (resultat < 0) {
    perror(" bind: ");
    close(sockserv);
    exit(1);
}

    printf("Bind reussie !\n");
    
    int ecoute = listen(sockserv, 5);
    if (ecoute < 0) {
        perror("listen");
        exit(1);
    }
    printf("Listen reussie\n");
        // --- Accept et gestion des connexions clients ---
    struct sockaddr_in clientsock;
    int longueur = sizeof(struct sockaddr_in);
    int sockclient;
     printf("En attente de connexions...\n");

        sockclient = accept(sockserv, (struct sockaddr*)&clientsock, &longueur);
        if (sockclient < 0) {
            perror("accept");
            // continue;  // Ne quitte pas en cas d'échec, attend une nouvelle connexion
        }

         printf("Connexion acceptee depuis %s : %d\n", 
            inet_ntoa(clientsock.sin_addr), ntohs(clientsock.sin_port));
        //Initialisation du compteur a 0;
        struct taille count;
        count.compteur = 0;
        memset(&count.compteur,0, sizeof(int ));
        int ecrits,nbread;
        while (1) {
        ecrits = write(sockclient, &count.compteur,sizeof(int));
        if(ecrits < 0){
        perror("write");
        exit(0);
        }
        printf("Message envoye\n");
        nbread = read(sockclient , &count.compteur ,sizeof(int));
        if(nbread < 0){
            perror("read");
            exit(0);
        }
        printf("Le nbre d'octets lus (%d) : contenu %d\n",nbread,count.compteur);
        count.compteur++;
        sleep(1);
   }

    return 0;
}
