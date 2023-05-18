#include "Header.h"

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