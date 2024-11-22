#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <string.h>


int main(int argc, char *argv[]) {


    if (argc < 3) {
        printf("Erreur : aucun fichier spécifié\n");
        printf("Usage : %s <nombre> <nom_du_fichier>\n", argv[0]);
        return 1; 
    }
    
      int fd = open(argv[2] , O_WRONLY  |O_CREAT | O_EXCL , S_IRUSR , S_IWUSR , S_IRGRP ,S_IROTH );
   
    if (fd == -1) {
        perror("Erreur d'ouverture en écriture seule");
        return 0 ;
    }
    
    
    
    int nmax = atoi(argv[1]) ;
    char textBuff[256] ;
    
    for(int i = 0 ; i< nmax ; i++ ) {
    	
    	//construction d'une chaine de caractere a partir des variables 
    	sprintf(textBuff , "%d",i ) ;	
    	
    	//ecritre de la chaine de caractere 
    	if( write(fd,textBuff,strlen(textBuff))  <= 0 ){
    		perror("Erreur d'ouverture ");
        return 0 ;
    	} 
    		
    }
    close(fd) ;
    
    return 0 ;
    }
