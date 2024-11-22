#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char* argv[]){
    if(argc<3){
        printf("Nombre d'argument insuffisant\n");
        printf("Usage: %s nomfichier,entieer\n");
        return 0;
    }
    int fd;
    fd= open(argv[1],O_RDWR |O_CREAT | O_EXCL ,S_IWUSR | S_IRUSR |S_IRGRP
    |S_IROTH);
    if(fd!=-1){
        printf("Ouverture du fichier en lecture-ecriture  OK\n");
    }
    else{
        perror("Erreur d'ouverture du fichier\n");
        exit(1);
    }
    int nmax =atoi(argv[2]);
    char buff[255];
    int i;
    for(i=0;i<nmax;i++){
        sprintf(buff ,"%d",i);
        if(write(fd, buff , sizeof(char*))<=0){
            perror("Erreur\n");
            return 0 ;
        }
    }
        close(fd);
        return 0;
}
