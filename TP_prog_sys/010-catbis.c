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
  //ouverture
  
   int fd = open(argv[1] , O_RDONLY  );
   
    if (fd == -1) {
        perror("Erreur d'ouverture en écriture seule");
        return 0 ;
    }
    
    char buff ;
    int  nbRead = 0 ;
    
    do{
    	nbRead = read(fd , &buff , sizeof(char) ) ;
    	if(nbRead>0 ) 
    		printf("%c" , buff) ; 
    	
    }while(nbRead >0 /*nbread == -1  en cas d'erreur */  ) ;
    
    close(fd) ;
    
    return 0 ;
   }
