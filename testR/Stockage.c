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
    do {
        printf("Entrez le prix du fruit : ");
        scanf("%f", &f.prix);
        if(f.prix < 0.1){
            printf("Veuillez renseigner un prix superieur a 0.1 euro.\n");
        }
    }while(f.prix < 0.10);
    
 //---------------------------------------------------//
//                 quantité du fruit                 //
    do {
        printf("Entrez la quantite de fruits : ");
        scanf("%d", &f.quantite);
        if(f.quantite<1){
                printf("La valeur saisie doit etre superieure ou egale à 1.\n");
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