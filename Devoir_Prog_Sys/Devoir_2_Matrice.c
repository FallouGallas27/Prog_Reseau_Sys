#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<ctype.h>

extern int optopt;
extern char * optarg;
int main(int argc,char* argv[]){
    int opt,i,j,dim,**matrice,fd;char buff[256],fichier[50];
    int fdB,fdT;
    while((opt =getopt(argc ,argv ,":catbd:f:"))!=-1){
        switch(opt){
            case 'c':
                printf("Creation de la matrice et allocation\n");
                matrice= (int**)malloc(dim*sizeof(int*));
                for(i=0;i<dim;i++)
                    matrice[i]=(int*)malloc(dim*sizeof(int));
                for(i=0; i<dim ; i++){
                    for(j=0; j<dim ; j++){
                        matrice[i][j]=rand()%100;
                    }
             }
            break;
            case 'a':
                printf("Affichage de la matrice de dimension %d\n",dim);
                fd =open(fichier,O_RDONLY);
                if(fd==-1){
                    perror ("Impossible d'ouvrir le fichier\n");
                    exit(1);
                }

                printf("Affichage mode texte\n");
                char buffre[256] ;int retour = 0;
                int nblit=0;
                do{
                    retour++;
                    nblit=read(fd,buffre,sizeof(char*));
                    if(nblit>0){
                        printf("%6s\t ",buffre);
                        if(retour%dim == 0)
                            printf("\n");
                    }
                }while(nblit>0);
                close(fd);
                break;
            case 'd':
                dim =atoi(optarg);

                 break;
            case 'f':
                printf("creation de %s \n",optarg);
                strcpy(fichier,optarg);
                 int fd =open(optarg,O_CREAT ,S_IWUSR | S_IRUSR | S_IRGRP |S_IROTH);
                if(fd ==-1){
                    perror ("Impossible d'ouvrir le fichier\n");
                    exit(1);
                }
                close(fd);
                break;
            case 't':
                fdT=open(fichier,O_WRONLY);
                 for(i=0; i<dim ; i++){
                    for(j=0; j<dim ; j++){
                        sprintf(buff,"%d\t",matrice[i][j]);
                        if(write(fdT,buff ,sizeof(char*))<0){
                            fprintf(stderr,"Erreur\n");
                            exit(1);
                        }
                        //printf("\n");
                    }
                }
                close(fdT);
                break;
            case 'b':
               fdB= open(fichier,O_WRONLY);
               if(fdB==-1){
                   printf("Erreur\n");
                   exit(-1);
               }
               for(i=0; i<dim ; i++){
                    for(j=0; j<dim ; j++){
                       write(fdB,&matrice[i][j],sizeof(int));
                    }
               }
               printf("Ecriture avec succes\n");
               close(fdB);
               fd=open(fichier,O_RDONLY);
               int buffr ;
               nblit=0;
               do{
                    retour++;
                    nblit=read(fd,&buffr,sizeof(int));
                    if(nblit>0){
                        printf("%6d\t ",buffr);
                        if(retour%dim == 0)
                            printf("\n");
                    }
                }while(nblit>0);
             close(fd);
                break;
            }
    }
    return 0;
}
