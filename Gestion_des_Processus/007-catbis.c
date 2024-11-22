#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char* argv[]){
    if(argc <2 ){
        printf("Nombre d'argument insuffisant\n");
        printf("Usage %s <nom fichier>\n",argv[0]);
    }
    int fd ;
    fd = open (argv[1],O_RDONLY);
    if(fd !=-1){
        printf("Ouverture du fichier en mode lecture OK\n");
    }
    else
        printf("Erreur d'ouverture du fichier \n");
    char buff;
    int nblit=0;
    do{
        nblit = read(fd , &buff, sizeof(char));
        if(nblit !=-1)
            printf("%c",buff);
        else
            printf("Erreur de lecture\n");
    }while(nblit>0);
    close(fd);
    return 0;
}
