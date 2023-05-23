#ifndef HEADER_H
#define HEADER_H
#endif 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define STOCKFRUITPET 30
#define STOCKFRUITMOY 20
#define STOCKFRUITGRA 10

struct client {
    char pseudo[30];
    char mdp[30];
};

struct fruit {
    char nom[50];
    int taille;
    float prix;
    int quantite;
    int numeroref;
};



// fonction Account.c

int rech(char pseudo[]);
void creercompte();
void supprimercompte();
void login();
int rechlogin(char pseudo[], char mdp[]);
void creercomptegerant();
void logingerant();

// fonction stockage.C

void sommeQuantiteStock(int taille, int* sommeStock);
void voirstock();
void ajoutFruits();
int rechercheNom(char Nom[]);
void rechercheRef(int Ref);
void panier();