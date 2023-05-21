#include "Header.h"

void sommeQuantiteStock(int taille, int* sommeStock) { //somme les quantite en fonction de leur taille
    FILE *StockFruits;
    struct fruit f;
    *sommeStock = 0;

    StockFruits = fopen("StockFruits.txt", "r");
    if (StockFruits == NULL) {
        printf("Problème pour lire le fichier stock de fruits.\n");
        return;
    }

    while (fscanf(StockFruits, "%49s; %d; %f; %d; %d\n", f.nom, &f.taille, &f.prix, &f.quantite, &f.numeroref) != EOF) {
        if (f.taille == taille) {
            *sommeStock += f.quantite;
        }
    }

    fclose(StockFruits);
}

void ajoutFruits(){
    FILE *StockFruits;
    int taille;
    struct fruit f;
    int stockActuel = 0; 

 //---------------------------------------------------//
//            ouverture du fichier StockFruits       //
    StockFruits = fopen("StockFruits.txt", "a");
    if (StockFruits == NULL) {
        printf("y'a un problème sur l'ouverture du fichier StockFruits.\n");
        return;
    }
   //---------------------------------------------------//
  // Saisie des caractéristiques du fruit à rajouter   //
 //---------------------------------------------------//
//                    nom du fruit                   //   
    printf("Entrez le nom du fruit : ");
    scanf("%50s", f.nom);    
 //---------------------------------------------------//
//                 taille du fruit                   //
    /*do{
        printf("Entrez la taille du fruit :\n1.Petit 2.Moyen 3.Grand\n");
        scanf("%d", &f.taille);
        if(f.taille < 1 || f.taille > 3 ){
            printf("Taille incorrecte. Veuillez essayer a nouveau.\n");
        }
    }while(f.taille < 1 || f.taille >3);
    */

    do{
        printf("Entrez la taille du fruit :\n1.Petit 2.Moyen 3.Grand\n ");
        if (scanf("%d", &f.taille) != 1 || f.taille < 1 || f.taille > 3){
                f.taille = -1;
                scanf("%*s");
        }
   }while (f.taille < 1 || f.taille > 3);
    

 //---------------------------------------------------//
//                  prix du fruit                    //
    /*do {
        printf("Entrez le prix du fruit : ");
        scanf("%f", &f.prix);
        if(f.prix < 0.1){
            printf("Veuillez renseigner un prix superieur a 0.1 euro.\n");
        }
    }while(f.prix < 0.10);
    */
    do{
        printf("Entrez le prix du fruit : ");
        if (scanf("%f", &f.prix) != 1 && scanf("%f", &f.prix) < 0.10){
            f.prix = -1;
            scanf("%*s");
        }
    }while (f.prix < 0.1);

 //---------------------------------------------------//
//                 quantité du fruit                 //
    /*do {
        printf("Entrez la quantite de fruits : ");
        scanf("%d", &f.quantite);
        if(f.quantite<1){
                printf("La valeur saisie doit etre superieure ou egale à 1.\n");
        }else{
        switch (f.taille)*/
    do{
        printf("Entrez la quantite de fruits :");
        if (scanf("%d", &f.quantite) != 1 && scanf("%d", &f.quantite) < 1){
            f.quantite = -1;
            scanf("%*s");
        }else{
        switch (f.taille)
        {
        case (1):   //Taille moyenne
            taille = f.taille;
            sommeQuantiteStock(taille,&stockActuel);                  // Stock actuel avant l'ajout
            if (stockActuel + f.quantite > STOCKFRUITPET) {
                printf("Le stockage de fruits de petite taille est depasse. Veuillez essayer a nouveau.\n");
            }
            break;

        case (2):   //Taille moyenne
            taille = f.taille;
            sommeQuantiteStock(taille,&stockActuel);                  // Stock actuel avant l'ajout
            f.quantite = f.quantite * 2;
            if (stockActuel + f.quantite > STOCKFRUITMOY) {
                printf("Le stockage de fruits de moyenne taille est depasse. Veuillez essayer a nouveau.\n");
            }
            break;
        case (3):   //Taille grande
            taille = f.taille;
            sommeQuantiteStock(taille,&stockActuel);                  // Stock actuel avant l'ajout
            f.quantite = f.quantite * 3;
            if (stockActuel + f.quantite > STOCKFRUITGRA) {
                printf("Le stockage de fruits de grande taille est depasse. Veuillez essayer a nouveau.\n");
            }
            break;
        default:
            break;
        }
        }
    }while(f.quantite < 1 || (stockActuel + f.quantite > STOCKFRUITPET) || (stockActuel + f.quantite > STOCKFRUITMOY) || (stockActuel + f.quantite > STOCKFRUITGRA));
   
 //---------------------------------------------------//
//                 référence du fruit                //
    printf("Entrez le numero de reference du fruit : ");
    scanf("%d", &f.numeroref);

  //---------------------------------------------------//
 //            remplissage du fichier fruit           //
// nom; taille; prix; quantite; numeroref
        fprintf(StockFruits, "%s; %d; %.2f; %d; %d\n", f.nom, f.taille, f.prix, f.quantite, f.numeroref);
        fclose(StockFruits);

        printf("Nouveaux fruits ajouté.\n");
    }
    
void voirstock(){
    FILE* StockFruits;
    char caractere;

    StockFruits = fopen("StockFruits.txt", "r");
    if (StockFruits == NULL) {
        printf("un problème sur l'ouverture stock de fruits.\n");
        return;
    }

    while ((caractere = fgetc(StockFruits)) != EOF) {
        printf("%c", caractere);
    }

    fclose(StockFruits);
}

void rechercheNom(char Nom[]) {
    FILE* F;
    F = fopen("StockFruits.txt", "r");
    if (F == NULL) {
        printf("Le fichier StockFruits.txt ne peut pas être ouvert.\n");  
    }

    char ligne[100]; // Variable pour stocker une ligne du fichier
    int found = 0; // Variable pour indiquer si le fruit recherché a été trouvé

    while (fgets(ligne, sizeof(ligne), F) != NULL) {
        char nom[50];
        sscanf(ligne, "%[^;]", nom);
        if (strcmp(nom, Nom) == 0) {
            printf("%s\n", ligne);
            found = 1; // Le fruit a été trouvé
            break; // Sortie de la boucle puisque le fruit a été trouvé
        }
    }

    fclose(F);

    if (!found) {
        printf("Le fruit '%s' n'a pas été trouvé dans le fichier.\n", Nom);
    }
}

void rechercheRef(int Ref) {
    FILE* F;
    F = fopen("StockFruits.txt", "r");
    if (F == NULL) {
        printf("Le fichier StockFruits.txt ne peut pas être ouvert.n");    
        return;
    }

    char ligne[100]; // Variable pour stocker une ligne du fichier
    int found = 0; // Variable pour indiquer si le fruit recherché a été trouvé

    while (fgets(ligne, sizeof(ligne), F) != NULL) {
        int ref;
        sscanf(ligne, "%*[^;];%*[^;];%*[^;];%*[^;];%d", &ref);
        if (Ref == ref) {
            printf("%s\n", ligne);
            found = 1; // Le fruit a été trouvé
            break; // Sortie de la boucle puisque le fruit a été trouvé
        }
    }

    fclose(F);

    if (!found) {
        printf("Le fruit de numéro de référence '%d' n'a pas été trouvé dans le fichier.\n", Ref);
    }
}