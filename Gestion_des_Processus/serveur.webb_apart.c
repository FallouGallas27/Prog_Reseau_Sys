

int repondre_requete(int sock , char requete[]){
    //entete fichier
    char reueteTemp[8192];
    strcpy(reueteTemp,requete);
    printf("+++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Requete Temp %s \n",,reueteTemp);
    printf("+++++++++++++++++++++++++++++++++++++++++++\n");
    char templateentete[8192]="HTTP/1.1 200 OK\n\
    DATE sat ,14,dec 2024  12: 07 :23 GMT \n\
    server Apache ugb\n\
    Content -Type %s \n\
    Content-length %d\n\";
    char *nomFichierRecu= strtok(reueteTemp," ");
    char nomFichierComplet[255];
    char extensionFichier[100];
    if(strcmp(nomFichierRecu,"/")==0){
        sprint(nomFichierComplet,"%s%sindex.html",RACIN_SITE,nomFichierRecu);
        strcpy(reueteTemp,nomFichierRecu);
    }
    else{
        sprint(nomFichierComplet,"%s%sindex.html",RACIN_SITE,nomFichierRecu);
        strcpy(reueteTemp,nomFichierRecu);
        strcpy(extensionFichier,strtok(reueteTemp," "));
        strcpy(extensionFichier,strtok(NULL, ""));

    }
    char typeMime[255];//type mime  a specifier
    if(strcmp(extensionFichier,"html")==0){
        strcpy(typeMime,"application/html")
    }
    else if(strcmp(extensionFichier,"pdf")==0){
        strcpy(typeMime,"application/pdf");
    }
    else if(strcmp(extensionFichier,"mp4")==0){strcpy(typeMime,"video/mp4");}
    else if(strcmp(extensionFichier,"png")==0){strcpy(typeMime,"image/mp4");}
    else {
        strcpy(typeMime,application/octet-strem);
    }
    //determinatio de la taille du fichier
    struct stat setfile;
    stat(nomFichierComplet,&setfile);
    char reponseComplete[8192];
    sprint(reponseComplete,templateentete,typeMime,setfile.st_size);
    printf("Reponse %s\n",reponseComplete);
    // Envoie de l'entete de la reponse  HTTP
    int nbsend= send(sock,reponseComplete,strlen(reponseComplete),0);
    if(nbsend<0){
        perror("Erreur de la reponse ");
        return -1;
    }
    int fd =open(nomFichierComplet,O_RDONLY);
    if(fd==-1){
        perror("Erreur d'ouverture du fichier ");
        return -1;
    }

     char buffread[1048576];
     int nbread,nbreadtotal=0;
     do{
         nbread=read(fd,buffread,1048576*sizeof(char));
         if(nbread>0){
             nbsend=send(sock,buffread,nbread*sizeof(char),0);
             nbreadtotal+= nbsend;
             printf("===============%d\n",nbreadtotal);
        }
    }while(nbread>0);
    close (fd);
    return 0;
    /* Poir compiler il faut:
    mettre au moins lune des interface en reseau prive hote
    et configure l'une des  interface
}
