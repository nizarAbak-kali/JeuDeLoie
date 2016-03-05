/**
 * \file info.h
 * \brief Header du fichier info.c.
 * \author Matsima Claude
 * \date 11 mars 2013
 *
 * Header du fichier info.c pour le projet "Jeu de l'Oie Revisité" - Réalisation de programmes - Semestre 2 2012/2013
 */
/**
 * \fn void affiche_Regle(SDL_Surface *ecran,TTF_Font *police,TTF_Font *font1);
 * \brief Fonction qui sert à afficher les règles du jeu.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] police Première police (Font) utilisée dans la fonction.
 * \param[in] font1 Deuxième police (Font) utilisée dans la fonction.
 */
void affiche_Regle(SDL_Surface *ecran,TTF_Font *police,TTF_Font *font1);
/**
 * \fn void affiche_Commande(SDL_Surface *ecran,TTF_Font *police1,TTF_Font *police2);
 * \brief Fonction qui sert à afficher les commandes du jeu.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] police1 Première police (Font) utilisée dans la fonction.
 * \param[in] police2 Deuxième police (Font) utilisée dans la fonction.
 */
void affiche_Commande(SDL_Surface *ecran,TTF_Font *police1,TTF_Font *police2);
