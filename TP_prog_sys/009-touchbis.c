#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h> 

int main(int argc, char *argv[]) {


    if (argc < 2) {
        printf("Erreur : aucun fichier spécifié\n");
        printf("Usage : %s <nom_du_fichier>\n", argv[0]);
        return 1; 
    }
    
    int fd = open(argv[1] , O_WRONLY | O_CREAT | O_EXCL ,
    			S_IWUSR | S_IRUSR |S_IRGRP |
    			S_IROTH 
    			) ;
    			
    if (fd == -1) {
        perror("Erreur d'ouverture en écriture seule");
        return 0 ;
    }
    
    return 0 ;
    
    }
