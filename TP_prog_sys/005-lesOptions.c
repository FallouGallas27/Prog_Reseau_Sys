#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>

extern char *optarg;
extern int optopt;

int main(int argc, char* argv[]) 
{
	int opt;

	while ((opt = getopt(argc, argv, "lm:nk:")) != -1) {
		switch (opt) {
			case 'l':
			case 'n':	
				printf("L'option -%c est fournie.\n", opt);
				break;
			case 'm':
			case 'k': 
				printf("L'option -%c est fournie avec comme argument %s\n", opt, optarg);
				break;
			case ':':
				// L'option attend un argument, mais celui-ci est absent
				printf("Erreur : L'option '-%c' attend un argument.\n", optopt);
				break;
			case '?':
				// Option non reconnue
				printf("Erreur : Option '-%c' inconnue.\n", optopt);
				break;
		}
	}
	return 0;
}

