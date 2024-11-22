#include<stdio.h>
#include<unistd.h>

extern int optopt;
extern char * optarg;

int main(int argc, char* argv[]){
    int opt;
    while((opt = getopt(argc , argv, ":lm:nk:"))!= -1){
        switch(opt){
            case 'l':
            case 'n':
                printf("argument -%c est fournie",opt);
                break;
            case 'm' :
            case 'k' :
                printf("argument -%c suivi de l'argument%s",opt,optarg);
                break;
            case ':' :
                printf("L'option -%c attend un argument \n",optopt);
                break;
            case '?' :
                printf("Unkow option %c\n",optopt);
                break;
        }

    }

    return 0;
}
