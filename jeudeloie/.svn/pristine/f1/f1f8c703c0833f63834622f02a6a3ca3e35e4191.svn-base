#ifndef BIBLIOTHEQUE_P4
#define BIBLIOTHEQUE_P4
#define VIDE 0
#define NOIR 1
#define ORANGE 2
#define NB_LIGNES 6
#define NB_COLONNES 7

//Matrice contenant les données des coups joués
int Mat[NB_LIGNES][NB_COLONNES];

/*Matrice contenant le nombre de coups joués dans chaque colonne, elle nous sera très utile 
  pour vérifier si un coup est jouable ou pas*/
int Colonne[NB_COLONNES] = {0,0,0,0,0,0};

/************Lise des Fonctions************/

void init_Mat_Colonne();
int Jouable(int x);
int Remplie();
int Puis_4(int a, int b);
int verif_Gagnant_p4();
int verif_Colonne(SDL_Rect* pos);
void jouer_Coup(int col, int coup);
void update_Screen(SDL_Surface* ecran);
int Jouer_Puissance_4(SDL_Surface* ecran, char j1[], char j2[]);
int Accueil_Puissance_4(SDL_Surface *ecran, char *j1, char *j2);
#endif
