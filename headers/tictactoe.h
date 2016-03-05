/**
 * \file tictactoe.h
 * \brief Header du Jeu de TicTacToé en SDL.
 * \author Nouira Chafik
 * \date 11 mars 2013
 *
 *
 * Un mini-jeu pour le projet "Jeu de l'Oie Revisité" - Réalisation de programmes - Semestre 2 2012/2013
 */

/** \struct Coordonnees tictactoe.h "Jeudeloie/headers/tictactoe.h"
* \brief Une structure qui contient deux entiers qui nous serviront de coordonnées dans une matrice.
* \details \n\n \b Explication: \n \a x et \a y sont les deux entiers de cette structure, sa déclaration se trouve dans le fichier tictactoe.h.
*/
typedef struct {
  int x; /*!< Numéro de la ligne. */
  int y; /*!< Numéro de la colonne. */
} Coordonnees;

/*Matrice contenant les valeurs de tous les coups joués afin de vérifier les coups au cours d'une partie et le résultat à la fin 
  de cette dernière*/
int Matrice[3][3]; /**<Matrice Globale pour le TicTacToe*/
/*Coor_Mat c'est un tableau qui contient les coordonnées du blittage des surfaces (croix et rond) sur chacune des 9 cases de la matrice
  sur l'écran princupal du jeu*/
Coordonnees Coor_Mat[9] = {{175,180},{271,182},{361,177},{181,272},{271,272},{361,272},{181,362},{271,362},{361,362}}; /**<Tableau de coordonnées de blittage*/


#define ROND 1 /**< Valeur jouée par le joueur 1.*/
#define CROIX 2 /**< Valeur jouée par le joueur 2*/
/**
 * \fn void init_Mat()
 * \brief Fonction qui parcourt la matrice Mat(qui est une variable globale de taille 3x3) et qui initialise toutes ses cases à -1.
 *
 */
void init_Mat();
/**
 * \fn int verif_Case(SDL_Rect* pos)
 * \brief Fonction qui permet de se repérer dans l'écran principal du jeu, elle retourne \a -1 si on survole pas la matrice, sinon elle retourne le \a n° de la case.
 *
 * \param[in] pos c'est la position du pointeur(de la souris) sur l'écran.
 * \return Elle retourne l'indice de la case sur laquelle on a cliqué sur la matrice, si on clique en dehors de la matrice la fonction retourne -1.
 */
int verif_Case(SDL_Rect* pos);
/**
 * \fn int update_Mat(int position, int coup)
 * \brief Fonction qui sert à affecter la valeur d'un coup à la case correspondante de la matrice Mat.
 *
 * \param[in] position c'est la case dans la quelle on veut affecter le coup.
 * \param[in] coup c'est la valeur du coup(ROND ou CROIX).
 * \return Elle retourne 1 si le coup est bel et bien affecté, 0 sinon.
 */
int update_Mat(int position, int coup);
/**
 * \fn int verif_Gagnant(void)
 * \brief Fonction de vérification de l'existence d'un gagnant.
 *
 * \return Elle retourne ROND si c'est le joueur 1 qui a gagné, CROIX si c'est le joueur 2 et 0 pour un match nul.
 */
int verif_Gagnant();
/**
 * \fn int Jouer_Tictactoe(SDL_Surface* ecran, char *j1, char *j2)
 * \brief Fonction principale du jeu, elle sert à alterner les tours entre 2 joueurs et affecter les coups joués à la matrice après vérification de leur validité.
 *
 * \param[out] ecran l'écran principal sur lequel on va blitter les différentes images correpondantes à l'évolution d'une partie.
 * \param[in] *j1 nom du premier joueur.
 * \param[in] *j2 nom du deuxième joueur.
 * \return Elle fait appel à la fonction verif_Gagnant et retourne sa valeur, ROND si le joueur 1 gagne, 2 si c'est le 2ème et 0 pour un match nul,
 * dans le dernier cas, une nouvelle partie est lancée, en gros faut qu'il y ait un gagnant pour pouvoir sortir "propremenet" de la fonction.
 */
int Jouer_Tictactoe(SDL_Surface* ecran, char *j1, char *j2);
/**
 * \fn int Accueil_TicTacToe(SDL_Surface* ecran, char *j1, char *j2)
 * \brief Fonction qui sert d'un accueil du jeu, histoire de ne pas lancer une partie "vulgairement", le joueur doit appuyer sur "Entrée" pour jouer.
 *
 * \param[out] ecran l'écran principal sur lequel on va blitter les différentes images correpondantes à l'évolution d'une partie.
 * \param[in] *j1 nom du premier joueur.
 * \param[in] *j2 nom du deuxième joueur.
 * \return Elle fait appel à la fonction Jouer_Tictactoe une fois l'utilisateur appuie sur "Entrée", elle récupère le n° du gagnant à la fin et le retourne.
 */
int Accueil_TicTacToe(SDL_Surface *ecran, char *j1, char *j2);
