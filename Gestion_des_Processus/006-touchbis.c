#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc , char * argv[]){
    int fd;
    fd = open(argv[1],O_WRONLY | O_CREAT |O_EXCL | S_IWUSR | S_IRGRP | S_IRUSR |
                            S_IROTH );
    if(fd != -1){
        printf("Creation du fichier avec succes!!!\n");
    }
    else
        perror("Erreur de creation du fichier\n");
}
