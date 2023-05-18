#ifndef HEADER_H
#define HEADER_H
#endif 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct client {
    char pseudo[30];
    char mdp[30];
};



// fonction Account.c

int rech(char pseudo[]);
void creercompte();
void supprimercompte();
void login();
int rechlogin(char pseudo[], char mdp[]);


// fonction stockage.C

void voirstock();