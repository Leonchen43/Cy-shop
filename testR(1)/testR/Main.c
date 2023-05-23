#include "Header.h"



int main(){
    struct client compte;
    int choix;
    char rep;
    int choix2;
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
            if (scanf("%d", &choix) != 1 || choix < 1 || choix > 7){
                choix = -1;
                scanf("%*s");
            }
        }
            while (choix < 1 || choix > 7);
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
            case 6:
                printf("1 Creer compte gerant\n");
                printf("2 Se connecter a un compte gerant\n");
                printf("\n Entrez votre choix : ");
                do{
                    if (scanf("%d",&choix2)<1 || scanf("%d",&choix2)>2) {
                    choix2 = -1;
                    scanf("%*s"); // Ignorer l'entree invalide
                 }
                }while(choix2<1 || choix2 >2);
                switch (choix2){
                    case 1:
                        creercomptegerant();
                        break;
                    case 2:
                        logingerant();
                        break;
                }
            case 7:
                panier();
                break;
        }
        printf(" \n Voulez-vous continuer O/N : ");
        scanf(" %c",&rep);
        fflush(stdin);
    }while(tolower(rep) == 'o');
    return 0;
}