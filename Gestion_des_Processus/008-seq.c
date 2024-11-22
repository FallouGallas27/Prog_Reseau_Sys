#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    if(argc<3){
        printf("Nombre d'argument insuffisant\n");
        printf("Usage: %s <n1,n2>\n",argv[0]);
        return 0;
    }
    int fd;
    fd =open(argv[2], O_RDWR
        | O_CREAT |O_EXCL, S_IWUSR |S_IRUSR | S_IRGRP | S_IROTH);
    if(fd !=-1){
        printf("Ouverture en lecture et ecriture du fichier OK\n");
    }
    else
        perror("Erreur d'ouverture du fichier\n");

    int nb=atoi(argv[1]);int i,nbWrite=0;
    for(i=0; i<nb; i++){
        nbWrite= write(fd,&i, sizeof(int));
        if(nbWrite<=0)
            printf("Erreur\n");
    }
    close (fd);
    return 0;
}
