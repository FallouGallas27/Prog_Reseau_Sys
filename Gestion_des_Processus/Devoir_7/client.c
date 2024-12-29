#include "commom.h"

int main(int argc,char* argv[]){
    if(argc < 3)
    {
		printf("Erreur : nombre d'arguments insuffisant \n");
		printf("Usage : %s ADRESSE_IP PORT \n", argv[0]);
		return 0;
	}
    int sockclient;
    struct sockaddr_in sockC;
    sockclient = socket(AF_INET ,SOCK_STREAM, 0);
    if(sockclient < 0){
        perror("socket");
        exit(0);
    }
    printf("Creation de la socket reussi!\n");
    memset(&sockC, 0, sizeof(struct sockaddr_in));
    sockC.sin_family = AF_INET;
    sockC.sin_port = htons(atoi(argv[2]));
    sockC.sin_addr.s_addr = inet_addr(argv[1]);

    // Appel de l'appel systeme connect 

    int resultat = connect(sockclient , (struct sockaddr*)&sockC , sizeof(struct sockaddr_in));
    if(resultat < 0){
        perror("connect");
        exit(0);
    }
    printf("Connexion reussi !\n");
    struct taille count;
    int nbread,nbwrite;
    while(1){
        nbread = read(sockclient , &count.compteur ,sizeof(int));
        if(nbread < 0){
            perror("read");
            exit(0);
        }
        printf("Le nbre d'octets lus (%d) : contenu %d\n",nbread,count.compteur);
        count.compteur++;
        sleep(1);
        nbwrite = write(sockclient, &count.compteur, sizeof(int ));
        if(nbwrite < 0){
            perror("write");
            exit(0);
        }
        printf("Compteur incremante et envoye au serveur\n");
    }
}