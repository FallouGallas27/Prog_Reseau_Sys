#include<stdio.h>
#include<unistd.h>

int main(int argc,char* argv[]){
    printf("Nouvelle commande ls\n");
    execlp("ls","ls","-l","-a",(char *)0);
    printf("Erreur d'execution de exec\n");
    return 0;
}
