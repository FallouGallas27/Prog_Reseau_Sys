#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pidfils,pidfils2,pidfils3;
    pidfils=fork();
    switch(pidfils){
        case -1:perror("Erreur de creation du processus\n");break;
        case 0:
            printf("%d --> %d \n",getppid(),getpid());

        default :printf("%d -->%d \n",getpid(),getppid()); break;
        wait(NULL);
    }
    pidfils2=fork();
    switch(pidfils2){
        case -1:perror("Erreur de creation du processus\n");break;
        case 0:
            printf("%d --> %d \n",getppid(),getpid());

        default :printf("%d -->%d \n",getpid(),getppid()); break;
        wait(NULL);
    }
    pidfils3=fork();
    switch(pidfils2){
        case -1:perror("Erreur de creation du processus\n");break;
        case 0:
            printf("%d --> %d \n",getppid(),getpid());

        default :printf("%d -->%d \n",getpid(),getppid()); break;
        wait(NULL);
    }
    return 0;
}
