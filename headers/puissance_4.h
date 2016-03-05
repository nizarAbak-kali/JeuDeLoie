/**
 * \file puissance_4.h
 * \brief Header du Jeu de Puissance 4 en SDL.
 * \author Nouira Chafik
 * \date 11 mars 2013
 *
 *
 * Un mini-jeu pour le projet "Jeu de l'Oie Revisité" - Réalisation de programmes - Semestre 2 2012/2013
 */
#define VIDE 0 /**< Valeur d'une case vide : 0.*/
#define NOIR 1 /**< Valeur d'une case qui contient un jeton noir : 1.*/
#define ORANGE 2 /**< Valeur d'une case qui contient un jeton orange : 2.*/
#define NB_LIGNES 6 /**< Nombre de ligne de la matrice du jeu.*/
#define NB_COLONNES 7 /**< Nombre de colonnes de la matrice du jeu.*/

//Matrice contenant les données des coups joués
int Mat[NB_LIGNES][NB_COLONNES]; /**< Matrice dans laquelle on va affecter les coups joués et à partir de laquelle on va mettre à jour l'affichage à chaque tour, c'est dans cette matrice qu'on effectuera la vérification des résultats également.*/

/*Matrice contenant le nombre de coups joués dans chaque colonne, elle nous sera très utile 
  pour vérifier si un coup est jouable ou pas*/
int Colonne[NB_COLONNES] = {0,0,0,0,0,0}; /**< Tableau qui contient le nombre de jetons pour chaque colonne, très utile pour vérifier la validité des coups joués.*/

/************Lise des Fonctions************/

/**
 * \fn void init_Mat_Colonne()
 * \brief Fonction d'initialisation de la matrice Mat[NB_LIGNES][NB_COLONNES] et du tableau Colonne[NB_COLONNES], elle affectera la valeur VIDE à toutes les cases
 *
 */
void init_Mat_Colonne();
/**
 * \fn int Jouable(int x)
 * \brief Fonction qui détermine si un coup est jouable ou pas, elle effectuera la vérification dans le tableau Colonne[NB_COLONNES]
 *
 * \param[in] x c'est la valeur du coup qu'on veut jouer (NOIR ou ORANGE).
 * \return Si le coup est jouable elle retourne 1, sinon elle retourne 0.
 */
int Jouable(int x);
/**
 * \fn int Remplie()
 * \brief Fonction qui vérifie si la matrice du jeu est remplie ou pas, elle effectuera la vérification dans le tableau Colonne[NB_COLONNES].
 *
 * \return Elle retourne 1 si la matrice est complétement remplie, 0 sinon.
 */
int Remplie();
/**
 * \fn int Puis_4(int a, int b)
 * \brief Fonction qui vérifie l'existence de 4 jetons de même couleur et alignés à partir de la case qui a \a a et \a b comme coordonnées, cette fonction ne parcourt pas la matrice.
 *
 * \param[in] a numéro de la ligne.
 * \param[in] b numéro de la colonne.
 * \return Elle retourne NOIR s'il y a 4 jetons noirs alignés, ORANGE s'il y a 4 jetons oranges alignés et 0 sinon.
 */
int Puis_4(int a, int b);
/**
 * \fn int verif_Gagnant_p4()
 * \brief Fonction qui parcourt la matrice et fait appel à la fonction Puis_4 pour chaque case afin de vérifier l'existence d'un gagnant.
 *
 * \return Elle retourne la valeur de la fonction Puis_4 si celle-ci est différente de 0 (NOIR ou ORANGE), elle retourne 0 sinon.
 */
int verif_Gagnant_p4();
/**
 * \fn int verif_Colonne(SDL_Rect* pos)
 * \brief Fonction qui prend la position du pointeur sur l'écran et le transforme en indice de colonne.
 *
 * \param[in] pos Coordonnées du pointeurs de la souris sur l'écran au moment du clic.
 * \return Si on a cliqué à l'intérieur de la matrice du jeu cette fonction retourne l'indice de la matrice correspondante, elle retourne -1 sinon.
 */
int verif_Colonne(SDL_Rect* pos);
/**
 * \fn void jouer_Coup(int col, int coup)
 * \brief Fonction qui affecte un coup à la matrice du jeu.
 *
 * \param[in] col Indice de la colonne dans laquelle on va affecter le coup joué.
 * \param[in] coup Valeur du coup joué (NOIR ou ORANGE).
 * \return Cette fonction ne retourne rien, car elle est appelée seulement quand le coup est jouable.
 */
void jouer_Coup(int col, int coup);
/**
 * \fn void update_Screen(SDL_Surface* ecran)
 * \brief Fonction qui met à jour l'affichage en parcourant la matrice Mat[NB_LIGNES][NB_COLONNES] et en faisant les blittages des images nécessaires.
 *
 * \param[out] ecran C'est l'écran principal du jeu sur lequel on va blitter les différentes images tout au long d'une partie.
 */
void update_Screen(SDL_Surface* ecran);
/**
 * \fn int Jouer_Puissance_4(SDL_Surface* ecran, char j1[], char j2[])
 * \brief Fonction principale du jeu, elle sert à alterner les tours entre 2 joueurs et affecter les coups joués à la matrice après vérification de leur validité.
 *
 * \param[out] ecran l'écran principal sur lequel on va blitter les différentes images correpondantes à l'évolution d'une partie.
 * \param[in] *j1 nom du premier joueur.
 * \param[in] *j2 nom du deuxième joueur.
 * \return Elle fait appel à la fonction verif_Gagnant_p4 et retourne sa valeur, NOIR si le joueur 1 gagne, ORANGE si c'est le 2ème et 0 pour un match nul,
 * dans le dernier cas, une nouvelle partie est lancée, en gros faut qu'il y ait un gagnant pour pouvoir sortir "propremenet" de la fonction.
 */
int Jouer_Puissance_4(SDL_Surface* ecran, char j1[], char j2[]);
/**
 * \fn int Accueil_Puissance_4(SDL_Surface* ecran, char *j1, char *j2)
 * \brief Fonction qui sert d'un accueil du jeu, histoire de ne pas lancer une partie "vulgairement", le joueur doit appuyer sur "Entrée" pour jouer.
 *
 * \param[out] ecran l'écran principal sur lequel on va blitter les différentes images correpondantes à l'évolution d'une partie.
 * \param[in] *j1 nom du premier joueur.
 * \param[in] *j2 nom du deuxième joueur.
 * \return Elle fait appel à la fonction Jouer_Puissance_4 une fois l'utilisateur appuie sur "Entrée", elle récupère le n° du gagnant à la fin et le retourne.
 */
int Accueil_Puissance_4(SDL_Surface *ecran, char *j1, char *j2);
