#include<stdio.h>
#include<unistd.h>

int main(int argc,char* argv[]){
    char *argvbis[] ={
        "ls",
        "-l",
        "-a",
        (char*) NULL
    };
    printf("Nouvelle commande ls\n");
    execvp("ls",argvbis);
    printf("Erreur d'execution de exec\n");
    return 0;
}
