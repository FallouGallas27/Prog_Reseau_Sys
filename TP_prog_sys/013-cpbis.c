#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h> 



int main(int argc, char *argv[]) {


	if (argc < 3) {
		printf("Erreur : aucun fichier spécifié\n");
		printf("Usage : %s <nombre> <nom_du_fichier>\n", argv[0]);
		return 1; 
	    }
    
       int fdSrc = open(argv[2] , O_RDONLY ) ;
       
       printf("ouverture DU FICHIER A SUCCES ");
       
       //recuperation des information du fichier : mode , taille
       //int fstat(int id , struct stat statbuf ) 
       
       struct stat stFichierSrc ; 
       int resultat = fstat(fd , &stFichierSrc ) ;

       
        if (fd == -1) {
		perror("Erreur d'ouverture en écriture seule");
		return 0 ;
        }
        
      	printf("Mode du fichier (permission) : %o\n", stFichierSrc.st_mode);
   	printf("Taille du fichier : %lld octets\n", (long long)stFichierSrc.st_size); 
   	
   	//copie des donnees 
   	
   	char buff  ;
   	int nbRead,nbWrite ;
   	int nbTotal = 0;
   	do{
   	
   		
   		nbRead = read(fdSrc , &buff , sizeof(char) ) ;
   		if(nbRead > 0 ) 
   		{
   			nbWrite = write(fdDst , &buff , sizeof(char) ) 
   		
   			if(nbWrite ){
   			}
    
   	}while(nbRead > 0  ) ;
      
      
      
      return 0 ;
}
