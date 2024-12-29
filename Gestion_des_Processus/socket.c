#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

int main(){
    // Creation de la socket 
    int sock;
    struct sockaddr_in sockadd;
    sock =socket(AF_INET,SOCK_STREAM,0);
    if(sock<0){
        perror("Erreur de creation de la socket\n");
        exit(0);
    }
    printf("Creation de la  socket avec succes!\n");
    //Mise en place de la structure 
    memset(&sockadd ,0, sizeof(struct  sockaddr_in));
    sockadd.sin_family =AF_INET;
    sockadd.sin_port = htons(8000);
    sockadd.sin_addr.s_addr = inet_addr("0.0.0.0");

    //Appel systeme bind();
    if(bind(sock, (struct sockaddr*)&sockadd,sizeof(struct sockaddr_in))<0){
        perror("bind");
        exit(0);
    }
    printf("Bind avec succes \n");
    //Appel systeme de listen
    if(listen(sock, 5)<0){
        perror("listen");
        exit(0);
    }
    printf("Appel systeme de listen avec succes!\n");

    // Appel systeme Accept 
    if(accept(sock, (struct sockaddr*)&sockadd,sizeof(struct sockaddr_in)<0)){
        perror("accept");
        exit(0);
    }
    printf("Connexion accepter\n");
    return 0;
    
}