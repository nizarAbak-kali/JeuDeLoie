/**
 * \file nb_mysterieux.h
 * \brief Header du Jeu du Nombre Mystérieux en SDL.
 * \author Nouira Chafik
 * \date 11 mars 2013
 *
 * Un mini-jeu pour le projet "Jeu de l'Oie Revisité" - Réalisation de programmes - Semestre 2 2012/2013
 */
/**
 * \fn int Jouer_Nb_Mysterieux(SDL_Surface *ecran, char j1[], char j2[])
 * \brief Fonction principale du jeu, elle sert à alterner les tours entre 2 joueurs (Chacun un nombre mystérieux à trouver).
 *
 * \param[out] ecran l'écran principal sur lequel on va blitter les différentes images correpondantes à l'évolution d'une partie.
 * \param[in] *j1 nom du premier joueur.
 * \param[in] *j2 nom du deuxième joueur.
 * \return Elle vérifie à chaque fois si le joueur est arrivé à trouver le nombre mystérieux, et elle retourne le n° du gagnant à la fin de la partie, s'il n'y a pas de gagnant, une autre partie est lancée.
 */
int Jouer_Nb_Mysterieux(SDL_Surface *ecran, char j1[], char j2[]);
/**
 * \fn int Accueil_Nb_Mysterieux(SDL_Surface *ecran, char j1[], char j2[])
 * \brief Fonction qui sert d'un accueil du jeu, histoire de ne pas lancer une partie "vulgairement", le joueur doit appuyer sur "Entrée" pour jouer.
 *
 * \param[out] ecran l'écran principal sur lequel on va blitter les différentes images correpondantes à l'évolution d'une partie.
 * \param[in] *j1 nom du premier joueur.
 * \param[in] *j2 nom du deuxième joueur.
 * \return Elle fait appel à la fonction Jouer_Nb_Mysterieux une fois l'utilisateur appuie sur "Entrée", elle récupère le n° du gagnant à la fin et le retourne.
 */
int Accueil_Nb_Mysterieux(SDL_Surface *ecran, char j1[], char j2[]);
