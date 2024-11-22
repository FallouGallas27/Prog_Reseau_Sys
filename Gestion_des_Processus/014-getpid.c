#include<stdio.h>
#include<unistd.h>


int main(){
    printf("Mon PID %d \n",getpid());
    printf("Mon PPID %d\n",getppid());
    return 0;
}
