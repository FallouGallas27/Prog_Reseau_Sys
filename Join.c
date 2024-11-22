#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>    // Pour open et close
#include <unistd.h>   // Pour read, write et close
#include <string.h>   // Pour les opérations sur les chaînes de caractères

/**
 * Fonction qui fusionne plusieurs fichiers en un seul fichier.
 *
 * @param output_filename Nom du fichier de sortie.
 * @param input_files Tableau contenant les noms des fichiers à fusionner.
 * @param num_files Nombre de fichiers à fusionner.
 */
/*void join_files(const char *output_filename, char *input_files[], int num_files) {
    // Ouvrir le fichier de sortie en mode écriture
    int output_fd = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd < 0) {
        perror("Erreur lors de la création du fichier de sortie");
        exit(EXIT_FAILURE);
    }

    char buffer[4096]; // Buffer pour les opérations de lecture/écriture
    ssize_t bytes_read;

    // Parcourir tous les fichiers d'entrée
    for (int i = 0; i < num_files; i++) {
        // Ouvrir chaque fichier en mode lecture
        int input_fd = open(input_files[i], O_RDONLY);
        if (input_fd < 0) {
            perror("Erreur lors de l'ouverture d'un fichier d'entrée");
            close(output_fd);
            exit(EXIT_FAILURE);
        }

        // Lire les données du fichier d'entrée et les écrire dans le fichier de sortie
        while ((bytes_read = read(input_fd, buffer, sizeof(buffer))) > 0) {
            if (write(output_fd, buffer, bytes_read) != bytes_read) {
                perror("Erreur lors de l'écriture dans le fichier de sortie");
                close(input_fd);
                close(output_fd);
                exit(EXIT_FAILURE);
            }
        }

        if (bytes_read < 0) {
            perror("Erreur lors de la lecture du fichier d'entrée");
            close(input_fd);
            close(output_fd);
            exit(EXIT_FAILURE);
        }

        // Fermer le fichier d'entrée après traitement
        close(input_fd);
        printf("Fusionné : %s\n", input_files[i]);
    }

    // Fermer le fichier de sortie
    close(output_fd);
    printf("Tous les fichiers ont été fusionnés dans : %s\n", output_filename);
}*/

int main(int argc, char *argv[]) {
    // Vérifier que les arguments de la ligne de commande sont suffisants
    if (argc < 3) {
        fprintf(stderr, "Usage : %s fichier_sortie fichier1 fichier2 ... fichierN\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *fichier_exp = argv[1]; // Nom du fichier de sortie
    char **fichier_imp = &argv[2];         // Tableau des fichiers d'entrée
    int nb_fic= argc - 2;              // Nombre de fichiers d'entrée

     int fdS = open(fichier_exp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fdS < 0) {
        perror("Erreur lors de la création du fichier de sortie");
        exit(EXIT_FAILURE);
    }

    char buffer[4096]; // Buffer pour les opérations de lecture/écriture
    int nb_read;

    // Parcourir tous les fichiers d'entrée
    for (int i = 0; i < nb_fic; i++) {
        // Ouvrir chaque fichier en mode lecture
        int fd = open(fichier_imp[i], O_RDONLY);
        if (fd < 0) {
            perror("Erreur lors de l'ouverture d'un fichier d'entrée");
            close(fdS);
            exit(EXIT_FAILURE);
        }

        // Lire les données du fichier d'entrée et les écrire dans le fichier de sortie
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

        // Fermer le fichier d'entrée après traitement
        close(fd);
        printf("Fusionné : %s\n", fichier_imp[i]);
    }

    // Fermer le fichier de sortie
    close(fdS);
    printf("Tous les fichiers ont été fusionnés dans : %s\n", fichier_exp);
    return EXIT_SUCCESS;
}
