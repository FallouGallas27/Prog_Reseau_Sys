#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pidfils;
    int cmpterpere=0;
    int cmpterfils=0;
    pidfils=fork();
    switch(pidfils){
        case -1:perror("Erreur de creation du processus\n");break;
        case 0:
            //printf("Processus Fils PPID %d et PID %d \n",getppid(),getpid());
            while(1){
                printf("ppid :%d----pid %d \n",getppid(),getpid());
                cmpterfils++;
            }
            break;
        default ://printf("Processus Pere PID %d et PPID %d \n",getpid(),getppid()); break;
             while(1){
                printf("ppid :%d----pid %d \n",getppid(),getpid());
                cmpterfils++;
            }
            break;

    }
    wait(NULL);
    return 0;
}
