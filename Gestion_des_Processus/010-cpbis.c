#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
    int fdsrc, fdDest;
    fdsrc =open(argv[1],O_RDONLY);
    if(fdsrc!=-1){
        printf("Ouverture du fichier source OK\n");
    }
    else{
        perror("Erreur d'ouverture du fichier\n");
        exit(-1);
    }
    fdDest =open(argv[2],O_RDWR | O_CREAT | O_EXCL , S_IWUSR |S_IRUSR |S_IRGRP |S_IROTH);
    if(fdDest != -1){
        printf("Ouverture du fichier en ecriture OK\n");
    }
    else{
        perror("Erreur d'ouverture du fichier en ecriture\n");
        exit(1);
    }
    char buff;
    int nbRead,i;
    char puff[255];

    do{
       nbRead= read(fdsrc, &buff,sizeof(char));
       if(nbRead>0){
        if(write(fdDest, &buff,sizeof(char))<=0)
            perror("Erreur\n");
    }
    }while(nbRead>=0);
    close(fdDest);
    close(fdsrc);
    return 0;
}