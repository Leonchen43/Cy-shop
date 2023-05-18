#include "Header.h"



int main(){
    struct client compte;
    int choix;
    char rep;
    do{
        system("clear");
        printf("Menu\n");
        printf("1 Creer un compte \n");
        //printf("2 Supprimer compte \n");
        printf("2 gérant \n");
        do{
            printf("\n Entrez votre choix : ");
            if (scanf("%d",&choix) !=1 && scanf("%d",&choix) !=2 ) {
                choix = -1;
                scanf("%*s");  // Ignorer l'entrée invalide
            }
        } while(choix!=1 && choix !=2);
        switch(choix){
            case 1:
                creercompte();
                break;
            /*case 2:
                supprimercompte();
                break;*/  
            case 2:
                voirstock();
                break;
                
        }
        printf(" \n Voulez-vous continuer O/N : ");
        scanf(" %c",&rep);
        fflush(stdin);
    }while(tolower(rep) == 'o');
    return 0;
}