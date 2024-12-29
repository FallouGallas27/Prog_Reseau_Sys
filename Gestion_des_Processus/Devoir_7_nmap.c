#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>

int main(int argc , char * argv[]){
    int sockecoute;
    struct sockaddr_in sockserv;
    for(int port = 0; port < 3000; port++){
   // Creation de la socket 
    sockecoute = socket(AF_INET , SOCK_STREAM, 0);
    if(sockecoute <0){
        perror ("Erreur de la creation de la socket \n");
        exit(0);
    }

    memset(&sockserv ,0,sizeof(sockserv));
    sockserv.sin_family = AF_INET;
    sockserv.sin_addr.s_addr = inet_addr(argv[1]);
    sockserv.sin_port =htons(port);
    if(connect(sockecoute, (struct sockaddr*)&sockserv, sizeof(sockserv))==0){
            printf("Connexion reussie avec le port %d\n",port);
    }
    else{
          //perror("Connexion echoue !\n");
        //exit(0);
    }
    close(sockecoute);
    }
    return 0;
}