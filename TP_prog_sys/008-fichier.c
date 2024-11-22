#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>  // Correction de <fcntn.h> en <fcntl.h>

int main(int argc, char *argv[]) {

    // Vérification que le nom du fichier a été passé en argument
    if (argc < 2) {
        printf("Erreur : aucun fichier spécifié\n");
        printf("Usage : %s <nom_du_fichier>\n", argv[0]);
        return 1; // Sortie avec un code d'erreur
    }

    // Tentative d'ouverture du fichier en lecture seule
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Erreur d'ouverture en lecture seule");
    } else {
        printf("Ouverture en lecture seule OK\n");
        close(fd); 
    }

    // Tentative d'ouverture du fichier en écriture seule
    fd = open(argv[1], O_WRONLY);
    if (fd == -1) {
        perror("Erreur d'ouverture en écriture seule");
    } else {
        printf("Ouverture en écriture seule OK\n");
        close(fd); 
    }

    return 0;
    
   }

