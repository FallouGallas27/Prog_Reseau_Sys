#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char * argv[]){
    int fd;
    fd = open(argv[1],O_RDONLY);
    if(fd != -1)
        printf("Ouverture en lecture seul OK\n");
    else
       printf("Erreur d'ouverture du fichier en lecture\n");
    fd = open(argv[1],O_WRONLY);
    if(fd != -1)
        printf("Ouverture en ecriture seul OK\n");
    else
        printf("Erreur d'ouverture du fichier en ecriture\n");
    close(fd);

}