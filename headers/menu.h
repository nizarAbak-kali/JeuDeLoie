/**
 * \file menu.h
 * \brief Header du fichier menu.c.
 * \author Matsima Claude
 * \date 11 mars 2013
 *
 * Header du fichier menu.c pour le projet "Jeu de l'Oie Revisité" - Réalisation de programmes - Semestre 2 2012/2013
 */

//Booléen gérant les polices sur la fenêtre
int Bool=0; /**< Une valeur entière qui désigne l'indice d'un élément sélectionné dans un menu qeulconque.*/
/**
 * \fn void charge_Menu1(SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2)
 * \brief Fonction qui sert d'écran d'accueil du jeu.
 * \details C'est seulement un écran d'accueil, il faut appuyer sur 'Entrée' pour afficher le Menu Principal du jeu.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] font1 Un pointeur vers la police (Font) utilisée pour les éléments non sélectionnés.
 * \param[in] font2 Un pointeur vers la police (Font) utilisée pour l'élément sélectionné.
 */
void charge_Menu1(SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2);
/**
 * \fn void charge_Menu2 (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2)
 * \brief Fonction qui affiche le Menu Principal du jeu.
 * \details Liste des éléments du Menu Principal : 1 - Jouer | 2 - Options | 3 - Règles | 4 - Editer | 5 - Quitter
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] font1 Un pointeur vers la police (Font) utilisée pour les éléments non sélectionnés.
 * \param[in] font2 Un pointeur vers la police (Font) utilisée pour l'élément sélectionné.
 */
void charge_Menu2 (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2);
/**
 * \fn void charge_Menu3 (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2)
 * \brief Fonction qui affiche le Menu 'Jouer'.
 * \details Liste des éléments du Menu 'Jouer' :1-Nouvelle Partie | 2-Charger Partie
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] font1 Un pointeur vers la police (Font) utilisée pour les éléments non sélectionnés.
 * \param[in] font2 Un pointeur vers la police (Font) utilisée pour l'élément sélectionné.
 */
void charge_Menu3 (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2);
/**
 * \fn void charge_Menu4 (SDL_Surface *ecran,TTF_Font *font2)
 * \brief Fonction qui affiche le Menu 'Options'.
 * \details Liste des éléments du Menu 'Options' : Gestion du Son
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] font2 Un pointeur vers la police (Font) utilisée pour le seul élément du Menu 'Options'.
 */
void charge_Menu4 (SDL_Surface *ecran,TTF_Font *font2);
/**
 * \fn void charge_Menu5 (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2)
 * \brief Fonction qui affiche le Menu 'Règles'.
 * \details Liste des éléments du Menu 'Règles' : 1-Commandes du Jeu | 2-Règles du Jeu
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] font1 Un pointeur vers la police (Font) utilisée pour les éléments non sélectionnés.
 * \param[in] font2 Un pointeur vers la police (Font) utilisée pour l'élément sélectioné.
 */
void charge_Menu5 (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2);
/**
 * \fn void charge_Menu6 (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2,int *ptr)
 * \brief Fonction du Gestionnaire du Son.
 * \details Liste des éléments du Gestionnaire du Son : 1-Son <ON>/<OFF> | 2-Volume
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] font1 Un pointeur vers la police (Font) utilisée pour les éléments non sélectionnés.
 * \param[in] font2 Un pointeur vers la police (Font) utilisée pour l'élément sélectioné.
 * \param[in] ptr En attendant l'explication de Claude.
 */
void charge_Menu6 (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2,int *ptr);
/**
 * \fn void charge_Menu7(SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2)
 * \brief Fonction de Gestion du Volume.
 * \details Liste des éléments de la Gestion du Volume : 1-Faible | 2-Moyen | 3-Fort
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] font1 Un pointeur vers la police (Font) utilisée pour les éléments non sélectionnés.
 * \param[in] font2 Un pointeur vers la police (Font) utilisée pour l'élément sélectioné.
 */
void charge_Menu7(SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2);
