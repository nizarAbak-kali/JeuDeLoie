/**
 * \file pong.h
 * \brief Header du Jeu de Pong en SDL.
 * \author Abak-kali Nizar
 * \date 11 mars 2013
 *
 *
 * Un mini-jeu pour le projet "Jeu de l'Oie Revisité" - Réalisation de programmes - Semestre 2 2012/2013
 */
//taille de la fenetre
#define TAILLE_FENETRE_X 600 /**< Hauteur de la fenêtre principale du jeu.*/
#define TAILLE_FENETRE_Y 600 /**< Largeur de la fenêtre principale du jeu.*/

// la largeur et la longueur des deux raquettes sont les mêmes
#define TAILLE_RAQUETTE_LONGUEUR 120 /**< Longueur de la raquette.*/
#define TAILLE_RAQUETTE_LARGEUR 30 /**< Largeur de la raquette.*/

// un seule macro car la balle est carre
#define TAILLE_BALLE 30 /**< Taille de la balle.*/

// la largeur de la ligne
#define LARGEUR_LIGNE_DU_MILIEU 10 /**< Largeur de la ligne du milieu.*/

// Definition du nombres de joueurs
#define NB_JOUEURS 4 /**< Nombre de joueurs.*/

// Definition du score max a atteindre
#define SCORE_MAX 3 /**< Score maximum à atteindre pour gagner.*/
/**
 * \fn int jouer_pong(SDL_Surface* screen,int _indicej1 , int _indicej2)
 * \brief Fonction principale du jeu, elle sert a lancer un duel de pong entre 2 joueurs et gerer toutes les taches necessaires pour le bon fonctionnement du jeu.
 *
 * \param[out] screen l'ecran principal sur lequel on va blitter les differentes images correpondantes a l'evolution d'une partie.
 * \param[in] _indicej1 Indice du premier joueur.
 * \param[in] _indicej2 Indice du deuxieme joueur.
 * \return Elle retourne l'indice du gagnant à la fin de la partie.
 */
int jouer_pong(SDL_Surface* screen,int _indicej1 , int _indicej2);

