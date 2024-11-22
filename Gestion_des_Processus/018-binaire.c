#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pidfils,pidfils2,pidfils3;
    int nbFils;
    int profondeur = 0;
    for(nbFils=0;nbFils<2;){
    pidfils=fork();

    switch(pidfils){
        case -1:perror("Erreur de creation du processus\n");break;
        case 0:
            printf("%d -> %d ;\n",getppid(),getpid());
            profondeur++;
            if(profondeur >3)
                return 0;

           nbFils=0;
           break;
        default :
        wait(NULL);
        nbFils++;
        if(nbFils>2)
            return 0;break;
    }
    }
}
