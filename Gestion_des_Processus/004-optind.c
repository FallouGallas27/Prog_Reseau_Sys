#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

extern int optind,optopt;
extern char * optarg;

int main(int argc, char* argv[]){
    int opt,nmax,pas,i;
    while((opt = getopt(argc ,argv,":n:k:"))!=-1){
        switch(opt){
            case 'n':
                nmax= atoi(optarg);
            case 'k':
                pas= atoi(optarg);
                printf("L'argument -%c est suivie de %s\n",opt,optarg);
                break;
            case ':':
                printf("L'option -%c attend un argument\n",opt);
                break;
            case '?':
                printf("L'option -%c inconnue\n",optopt);
                break;
        }
    }
    for(i=optind; i < argc; i++){
        printf("L'argument optionnel %s\n",argv[i]);
    }
}
