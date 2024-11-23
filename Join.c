#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>    
#include <unistd.h>   
#include <string.h>   


int main(int argc, char *argv[]) {
    // Vérifier que les arguments de la ligne de commande sont suffisants
    if (argc < 3) {
        fprintf(stderr, "Usage : %s fichier_sortie fichier1 fichier2 ... fichierN\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *fichier_exp = argv[1]; 
    char **fichier_imp = &argv[2];        
    int nb_fic= argc - 2;              

     int fdS = open(fichier_exp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fdS < 0) {
        perror("Erreur lors de la création du fichier de sortie");
        exit(EXIT_FAILURE);
    }

    char buffer[4096]; 
    int nb_read;

    for (int i = 0; i < nb_fic; i++) {
        int fd = open(fichier_imp[i], O_RDONLY);
        if (fd < 0) {
            perror("Erreur lors de l'ouverture d'un fichier d'entrée");
            close(fdS);
            exit(EXIT_FAILURE);
        }
        while ((nb_read= read(fd, buffer, sizeof(buffer))) > 0) {
            if (write(fdS, buffer, nb_read) != nb_read) {
                perror("Erreur lors de l'écriture dans le fichier de sortie");
                close(fd);
                close(fdS);
                exit(EXIT_FAILURE);
            }
        }

        if (nb_read < 0) {
            perror("Erreur lors de la lecture du fichier d'entrée");
            close(fd);
            close(fdS);
            exit(EXIT_FAILURE);
        }
        close(fd);
        printf("Fusionné : %s\n", fichier_imp[i]);
    }
    close(fdS);
    printf("Tous les fichiers ont été fusionnés dans : %s\n", fichier_exp);
    return EXIT_SUCCESS;
}
