/**
 * \file editer.h
 * \brief Header du fichier editer.c.
 * \author Fofana Ibrahim
 * \date 11 mars 2013
 *
 * Header du fichier editer.c pour le projet "Jeu de l'Oie Revisité" - Réalisation de programmes - Semestre 2 2012/2013
 */
/**
 * \fn int suiv_Parcours()
 * \brief Fonction qui permet de trouver le premier nom disponible pour une carte à partir de zéro.
 *
 * \details Astuce : Le nom d'une carte est "unnombre".txt donc on a juste besion d'avoir le nombre et on aura le nom complet.
 * \return Elle retourne un entier qui désigne le premier nombre(nom) disponible pour une carte.
 */
int suiv_Parcours();
/**
 * \fn int nb_Parcours(int ieme)
 * \brief Fonction qui permet de trouver le nom d'une ième carte. 
 *
 * \param[in] ieme Un entier qui désigne le numéro d'une carte.
 * \return Elle retourne un entier qui désigne le nombre de cartes disponibles.
 */
int nb_Parcours(int ieme);
/**
 * \fn void creation(SDL_Surface* ecran, int* nb)
 * \brief Fonction qui permet de créer une carte de jeu. 
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[out] nb Entier qui désigne le nombre de parcours/cartes créés.
 * \return Cette fonction ne retourne rien, elle affecte une valeur à la variable \a nb à l'aide d'un passage par pointeurs.
 */
void creation(SDL_Surface* ecran, int* nb);
/**
 * \fn void aff_Cadre_Editer(SDL_Surface* ecran, SDL_Surface* carre)
 * \brief Fonction qui affiche le quadrillage de l'édition d'une carte.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[out] carre Le carré avec lequel on va initialiser l'écran principal.
 */
void aff_Cadre_Editer(SDL_Surface* ecran,SDL_Surface* carre);
/**
 * \fn void aff_Fantome(SDL_Surface* ecran, SDL_Surface* carre, SDL_Rect pos)
 * \brief Fonction qui affiche la case qui se deplace dans le quadrillage. (On l'a appelée fantome)
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] carre Variable qui contient l'image du fantôme.
 * \param[in] pos Nouvelle position du fantôme sur l'écran principale.
 */
void aff_Fantome(SDL_Surface* ecran, SDL_Surface* carre, SDL_Rect pos);
/**
 * \fn int selec_Aff_Case_Dispo(SDL_Surface* ecran, SDL_Surface* carre, int nbcase, SDL_Rect pos_ij, SDL_Rect position_chemin[64], SDL_Rect position_chemin_dans_image[64])
 * \brief Fonction qui sert a faire le choix de la case qu'on veut ajouter à telle ou telle endroit.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param carre En attendant L'explication d'Ibrahim.
 * \param nbcase En attendant L'explication d'Ibrahim.
 * \param pos_ij En attendant L'explication d'Ibrahim.
 * \param position_chemin[64] En attendant L'explication d'Ibrahim.
 * \param position_chemin_dans_image[64] En attendant L'explication d'Ibrahim.
 * \return Elle retourne en entier (En attendant L'explication d'Ibrahim.)
 */
int selec_Aff_Case_Dispo(SDL_Surface* ecran, SDL_Surface* carre, int nbcase, SDL_Rect pos_ij, SDL_Rect position_chemin[64], SDL_Rect position_chemin_dans_image[64]);
/**
 * \fn void aff_Parcous(SDL_Surface* ecran, SDL_Surface* carre, SDL_Rect position_chemin[64], SDL_Rect position_chemin_dans_image[64])
 * \brief Fonction qui sert à afficher un parcours.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] carre Variable qui contient l'image à partir de laquelle on va blitter différentes parties.
 * \param[in] position_chemin[64] Position dans l'image d'origine.
 * \param[in] position_chemin_dans_image[64] Position sur l'écran du jeu.
 */
void aff_Parcous(SDL_Surface* ecran, SDL_Surface* carre, SDL_Rect position_chemin[64], SDL_Rect position_chemin_dans_image[64]);
/**
 * \fn int possiblite_Case_Ij(SDL_Rect pos_ij, SDL_Rect chemin[64])
 * \brief Fonction qui vérifie si la case dans laquelle on veut placer un évènement est libre.
 *
 * \param pos_ij En attendant l'explication d'Ibrahim
 * \param chemin[64] En attendant l'explication d'Ibrahim. 
 * \return En attendant l'explication d'Ibrahim.
 */
int possiblite_Case_Ij(SDL_Rect pos_ij, SDL_Rect chemin[64]);
/**
 * \fn void sauvegarde_Edition(SDL_Rect pos_sur_ecran[64], SDL_Rect pos_sur_image[64], int iemeparcours)
 * \brief Fonction qui sauvegarde une carte créée dans un fichier.
 *
 * \param pos_sur_ecran[64] Les positions des différentes cases (De l'image d'origine) dans l'écran principal du jeu.
 * \param pos_sur_image[64] Les positions des différentes cases dans leur image d'origine.
 * \param iemeparcours Numéro de la carte.
 */
void sauvegarde_Edition(SDL_Rect pos_sur_ecran[64], SDL_Rect pos_sur_image[64], int iemeparcours);
/**
 * \fn void charge_Sauvegarde_Edition(SDL_Rect pos_sur_ecran[64], SDL_Rect pos_sur_image[64], int iemeparcours)
 * \brief Fonction qui charge une carte créée à partir d'un fichier.
 *
 * \param pos_sur_ecran[64] Les positions des différentes cases (De l'image d'origine) dans l'écran principal du jeu.
 * \param pos_sur_image[64] Les positions des différentes cases dans leur image d'origine.
 * \param iemeparcours Numéro de la carte.
 */
void charge_Sauvegarde_Edition(SDL_Rect pos_sur_ecran[64], SDL_Rect pos_sur_image[64], int iemeparcours);
/**
 * \fn int transforme_Pos_Image_En_Val(SDL_Rect pos)
 * \brief Fonction qui transforme une positon d'un carré dans une image en valeur qui sera utilisée pour la génération d'évènements.
 * \details Cette fonction est appelée 64 fois avant le début d'une partie afin de stocker les valeurs des évènements dans un tableau qui servira d'indice d'évènements au lieu d'exécuter la fonction à chaque tour.
 *
 * \param pos Position de la case dont on veut connaître la valeur de l'évènement.
 * \return Elle retourne une valeur entière qui désigne un évènement. \n1 : Bonus. \n2 : Malus. \n3 : Prison. \n4 : Rejouer. \n0 : Pour les autres cases.)
 */
int transforme_Pos_Image_En_Val(SDL_Rect pos);
/**
 * \fn void menu_Editer(SDL_Surface* ecran)
 * \brief Fonction qui sert de Menu principal de la partie édition.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 */
void menu_Editer(SDL_Surface* ecran);
/**
 * \fn void visualisation_Suppression(SDL_Surface* ecran, int* nb)
 * \brief Fonction qui sert à afficher les cartes disponibles avec la possibilité de supprimer une/des carte(s).
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[out] nb Nombre de cartes disponibles.
 */
void visualisation_Suppression(SDL_Surface* ecran, int* nb);
