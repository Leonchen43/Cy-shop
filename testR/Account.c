#include "Header.h"


int rech(char pseudo[]){
    struct client compte ;
    FILE *F;
    F=fopen("compte.txt","r");
    do{
        fscanf(F,"%s ;%s \n",compte.pseudo,compte.mdp);
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

void login(){
    int choix;
    FILE* F;
    struct client compte ;

    F = fopen("compte.txt", "r");
    if (F == NULL) {
        printf("Erreur lors de l'ouverture du fichier compte.txt.\n");
        return;
    }

    printf("\n Entrez votre pseudo : ");
    scanf("%99s", compte.pseudo);

    if (rech(compte.pseudo) == 1){
        printf("\n Ce pseudo existe.");

        printf("\n Entrez votre mot de passe : ");
        scanf("%99s", compte.mdp);

        if (rechlogin(compte.pseudo, compte.mdp) == 1){
            printf("Connexion reussie.\n");
            printf("1 Voir stock\n");

            do{
                if (scanf("%d", &choix) != 1){
                    choix = -1;
                    scanf("%*s");  // Ignorer l'entree invalide
                }
            } while (choix != 1);

            switch (choix){
                case 1:
                    voirstock();
                    break;
            }
        }
        else{
            printf("\n Mot de passe incorrect.\n");
        }
    }
    else{
        printf("\n Ce pseudo n'existe pas.\n");
    }

    fclose(F);
}

int rechlogin(char pseudo[], char mdp[]){
    FILE *F;
    struct client compte ;

    F = fopen("compte.txt", "r");
    if (F == NULL) {
        printf("Un probleme sur l'ouverture du fichier compte.txt .\n");
        return -1;
    }

    while (fscanf(F, "%99s ;%99s", compte.pseudo, compte.mdp) == 2) {
        if (strcmp(compte.pseudo, pseudo) == 0 && strcmp(compte.mdp, mdp) == 0) {
            fclose(F);
            return 1;
        }
    }

    fclose(F);
    return -1;
}