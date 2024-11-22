#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pidfils,pidfils2,pidfils3;
    int i;
    for(i=0;i<10;i++){
    pidfils=fork();

    switch(pidfils){
        case -1:perror("Erreur de creation du processus\n");break;
        case 0:
            printf("%d -> %d ;\n",getppid(),getpid());break;
        default :
        wait(NULL);
        return 0;
    }
    }
}
