#include<stdio.h>

int main(int argc ,char * argv[]){
    int i;
    if(argc<2){
        printf("Nombre d'argument insuffisant\n");
        printf("Usage : nom fichier %s d'autres argument\n");
        return 0;
    }
    printf("nombre d'argument argc = %d\n",argc);
    for(i=0; i<argc; i++){
        printf("argv[%d] =%s\t",i,argv[i]);
    }
}
