#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

extern int optopt;
extern char* optarg;

int main(int argc, char*argv[]){
    int opt,nmax,pas;
    while((opt = getopt(argc , argv ,":n:k:"))!=-1){
        switch(opt){
            case 'n':
                nmax = atoi(optarg);
            case 'k':
                pas = atoi(optarg);
                printf("L'argument -%c est suivi de %s \n",opt,optarg);
                break;
            case ':':
                printf("L'argument -%c attend un argument\n",optopt);
                break;
            case '?':
                printf("L'option -%c  inconnu\n",optopt);
                break;
        }
    }
    int i;
    for(i=0; i<nmax; i+=pas){
        printf("%d\t",i);
    }
    return 0;
}
