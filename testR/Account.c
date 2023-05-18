#include "Header.h"


int rech(char pseudo[]){
    struct client compte ;
    FILE *F;
    F=fopen("compte.txt","r");
    do{
        fscanf(F,"%s ;%s \n",&compte.pseudo,&compte.mdp);
        fflush(stdin);
        if(strcmp(compte.pseudo, pseudo) == 0){
            fclose(F);
            return 1;
        }
    }while(!feof(F));

    fclose(F);
    return -1;
}

void creercompte(){
    struct client compte ;
    FILE*F;
    char pseudo[100];
    F=fopen("compte.txt","a");
    printf("\n Entrez le pseudo : ");
    scanf("%s",pseudo);
    fflush(stdin);
    while(rech(pseudo) == 1){
        printf("\n Ce pseudo existe deja :");
        printf("\n Entrez un nouveau pseudo : ");
        scanf("%s",pseudo);
    }
    strcpy(compte.pseudo, pseudo);
    printf("\n Entrez le mot de passe : ");
    scanf("%s",compte.mdp);
    fflush(stdin);
    fprintf(F,"%s ;%s \n",compte.pseudo,compte.mdp);
    fclose(F);
}

void supprimercompte() {
    struct client compte ;
    char rep;
    char pseudo[100];
    printf("Entrer le pseudo du compte à supprimer :\n\n");
    scanf("%s", pseudo);
    fflush(stdin);
    if (rech(pseudo) == 1) {
        printf("Voulez-vous vraiment supprimer ce compte ? (O/N)\n");
        scanf(" %c", &rep);
        fflush(stdin);
        if (tolower(rep) == 'o') {
            FILE* Fich, *F;
            F = fopen("compte.txt", "r");
            Fich = fopen("tempcompte.txt", "a");
            do {
                fscanf(F, "%s ;%s \n", compte.pseudo, compte.mdp);
                if (strcmp(pseudo, compte.pseudo) != 0) {
                    fprintf(Fich, "%s ;%s \n", compte.pseudo, compte.mdp);
                }
            } while (!feof(F));
            fclose(Fich);
            fclose(F);
            remove("compte.txt");
            rename("tempcompte.txt", "compte.txt");
            printf("Suppression effectuée avec succès.\n");
        }
    } else {
        printf("\nCe pseudo n'existe pas.\n");
    }
}

void voirstock(){
    FILE*fichier;
    char caractere;
    fichier=fopen("Fruit.txt","r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }
    caractere= fgetc(fichier);
    while (caractere != EOF) {
        printf("%c", caractere);
        caractere = fgetc(fichier);
        // fclose(fichier);
    }
}