#include "Header.h"



int main(){
    struct client compte;
    int choix;
    char rep;
    do{
        system("clear");
        printf("Menu\n");
        printf("1 Creer un compte \n");
        printf("2 Connexion\n");
        printf("3 Supprimer compte \n");
        printf("4 ajouter un nouveau fruit \n");
        printf("5 voir le stock \n");
        do{
            printf("\n Entrez votre choix : ");
            /*if (scanf("%d",&choix) !=1 && scanf("%d",&choix) !=2 ) {
                choix = -1;
                scanf("%*s");  // Ignorer l'entrée invalide*/

            if (scanf("%d", &choix) != 1 || choix < 1 || choix > 5){
                choix = -1;
                scanf("%*s");
            }
        }while (choix < 1 || choix > 5);
        switch(choix){
            case 1:
                creercompte();
                break; 
            case 2:
                login();
                break;
            case 3:
                supprimercompte();
                break;
            case 4:
                ajoutFruits();
                break;
            case 5:
                voirstock();
                break;
        }
        printf(" \n Voulez-vous continuer O/N : ");
        scanf(" %c",&rep);
        fflush(stdin);
    }while(tolower(rep) == 'o');
    return 0;
}