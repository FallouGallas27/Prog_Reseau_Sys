#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
void executer(char* argv[]);
char **buildargv(char* cmd);
int main(int argc,char* argv[]){
    char cmd[255];
    char **argvbis;
    do{
        printf("Minishell:~$  \n");
        gets(cmd);
        argvbis= buildargv(cmd);
        executer(argvbis);
    }while(strcmp(cmd,"quit")!=0);

}

void executer(char* argv[]){
    pid_t pidfils= fork();
    switch(pidfils){
        case -1:perror("Erreur de creation de processus\n");break;
        case 0:
            execvp(argv[0],argv);
            perror("Erreur de ");break;
        default :
            wait(NULL);

    }
}
char **buildargv(char* cmd){
    char** argvbis =malloc(255*sizeof(char*));
    int i;
    for(i=0;i<255;i++){
        argvbis[i]=NULL;
    }
    char cmdbuff[255];
    strcpy(cmdbuff,cmd);
    i=0;
    argvbis[i]=strtok(cmdbuff," ");
    while(argvbis[i]!=NULL){
        i++;
        argvbis[i]=strtok(NULL, " ");

    }
    return argvbis;
}
