#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s nomfichier taille\n", argv[0]);
        return EXIT_FAILURE;
    }

    char fichier[50];
    strcpy(fichier, argv[1]);
    int taille = atoi(argv[2]);

    if (taille <= 0) {
        fprintf(stderr, "Erreur : la taille doit être un entier positif.\n");
        return EXIT_FAILURE;
    }

     int fd = open(fichier, O_RDONLY);
    if (fd < 0) {
        perror("Erreur d'ouverture du fichier source");
        exit(EXIT_FAILURE);
    }

    char partie_fic[256];
    char buffer [256];
    if (!buffer) {
        perror("Erreur d'allocation mémoire");
        close(fd);
        exit(EXIT_FAILURE);
    }

    int nb_part = 1;
    int nb_read;

    while ((nb_read = read(fd, buffer, sizeof(char*))) > 0) {
        snprintf(partie_fic, sizeof(partie_fic), "%s.part%d", fichier, nb_part);

        int fdS = open(partie_fic, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fdS < 0) {
            perror("Erreur de création du fichier de sortie");
            close(fdS);
            exit(EXIT_FAILURE);
        }

        if (write(fdS, buffer, nb_read) != nb_read) {
            perror("Erreur lors de l'écriture dans le fichier de sortie");
            close(fd);
            close(fdS);
            exit(EXIT_FAILURE);
        }

        close(fdS);
        printf("Créé : %s\n", partie_fic);
        nb_part++;
    }

    if (nb_read < 0) {
        perror("Erreur de lecture du fichier source");
    }

    close(fd);
    return EXIT_SUCCESS;
}
