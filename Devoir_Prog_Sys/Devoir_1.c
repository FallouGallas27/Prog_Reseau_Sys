#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
extern int optopt;
extern char * optarg;
int main(int argc ,char* argv[]){
    int opt,i,puis=1,n,prod,k;
    while((opt = getopt(argc ,argv, ":f:g:"))!=-1){
        switch(opt){
        case 'f':
             n =atoi(optarg);
             for(i=0;i<n;i++)
               puis=puis*2;
            printf("f(%d)=2^%d =%d\n",n,n,puis);
            break;
        case'g':
             k =atoi(optarg);
             prod=2*k;
            printf("g(%d)= 2*%d =%d\n",k,k,prod);
            break;
        case ':':
            printf("L'option -%c attend un argument\n",optopt);
            break;
        case '?':
            printf("L'option -%c est inconnue\n",optopt);
            break;
        }

        if(argc == 4){
        if(n && !k){
            n=2*n;
             for(i=0;i<n;i++)
               puis=puis*2;
            printf("f(g) =%d\n",puis);
            break;
        }
        else{
            if(!n && k){
                for(i=0;i<k;i++)
                    puis*=2;
                k=puis*2;
                printf("g(f) = %d\n",k);
                break;
            }
        }}
    }
    return 0;
}
