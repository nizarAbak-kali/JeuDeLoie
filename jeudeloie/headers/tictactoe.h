#define ROND 1
#define CROIX 2

typedef struct {
  int x;
  int y;
} Coordonnees;

/*Matrice contenant les valeurs de tous les coups joués afin de vérifier les coups au cours d'une partie et le résultat à la fin 
  de cette dernière*/
int Matrice[3][3];
/*Coor_Mat c'est un tableau qui contient les coordonnées du blittage des surfaces (croix et rond) sur chacune des 9 cases de la matrice
  sur l'écran princupal du jeu*/
Coordonnees Coor_Mat[9] = {{175,180},{271,182},{361,177},{181,272},{271,272},{361,272},{181,362},{271,362},{361,362}};


void init_Mat();
int verif_Case(SDL_Rect* pos);
int update_Mat(int position, int coup);
int verif_Gagnant();
int Jouer_Tictactoe(SDL_Surface* ecran, char *j1, char *j2);
int Accueil_TicTacToe(SDL_Surface *ecran, char *j1, char *j2);
