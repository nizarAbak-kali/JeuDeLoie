#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdio.h>

//taille de la fenetre
#define TAILLE_FENETRE_X 600
#define TAILLE_FENETRE_Y 600

// la largeur et la longueur des deux raquettes sont les mêmes
#define TAILLE_RAQUETTE_LONGUEUR 120
#define TAILLE_RAQUETTE_LARGEUR 30

// un seule macro car la balle est carre
#define TAILLE_BALLE 30

// la largeur de la ligne
#define LARGEUR_LIGNE_DU_MILIEU 10

// Definition du nombres de joueurs
#define NB_JOUEURS 4

// Definition du score max a atteindre
#define SCORE_MAX 3

struct joueurs {
    int position_sur_le_plateau;
    char * nom_du_joueur[NB_JOUEURS];
    };

