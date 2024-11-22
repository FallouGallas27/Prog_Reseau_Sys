#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    int n = 0;     // Valeur pour -n
    int p = 1;     // Valeur pour -p

    // Traitement des options avec getopt
    while ((opt = getopt(argc, argv, "n:p:")) != -1) {
        switch (opt) {
            case 'n':
                n = atoi(optarg);
                printf("Option -n avec argument : %d\n", n);
                break;
            case 'p':
                p = atoi(optarg);
                printf("Option -p avec argument : %d\n", p);
                break;
            case '?':
                printf("Option non reconnue : %c\n", optopt);
                break;
            case ':':
                printf("Erreur : L'option -%c attend un argument\n", optopt);
                break;
        }
    }

    // Affichage des arguments non optionnels
    for (int i = optind; i < argc; i++) {
        printf("Argument non optionnel : %s\n", argv[i]);
    }

    // Exemple d'utilisation de n et p
    printf("\nCalcul des valeurs en utilisant -n et -p :\n");
    for (int i = 1; i <= n; i += p) {
        printf("%d\n", i);
    }

    return 0;
}

