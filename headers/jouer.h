/**
 * \file jouer.h
 * \brief Header du fichier jouer.c.
 * \author Matsima Claude, Nouira Chafik, Fofana Ibrahim, Abak-kali Nizar
 * \date 11 mars 2013
 *
 * Header du fichier jouer.c pour le projet "Jeu de l'Oie Revisité" - Réalisation de programmes - Semestre 2 2012/2013
 */
/** 
 * \struct Joueur jouer.h "Jeudeloie/headers/jouer.h"
 * \brief Une structure contenant 4 champs qui correspondent aux données d'un joueur (Position, Nom, Valeur de Prison, Score)
 * \details \n\n \b Explication: La déclaration de cette structure se trouve dans le fichier jouer.h.
 */
typedef struct {
  int pos; /*!< Position du joueur. */
  char nom[8]; /*!< Nom du joueur. */
  int prison; /*!< La valeur de prison du joueur (Nombre de tours dans lesquels il ne jouera pas). */
  int score; /*!< Score du joueur. */
}Joueur;
/**
 * \fn void nom_Fichier(SDL_Surface *ecran, char nom[])
 * \author Nouira Chafik
 * \brief Fonction qui permet d'écrire une chaine de caractère (Nom d'un fichier) tout en affichant ce que l'utilisateur tape sur l'écran.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[out] nom Chaine de caractère dans laquelle sera stocké le nom du fichier saisi par l'utilisateur
 */
void nom_Fichier(SDL_Surface *ecran, char nom[]);
/**
 * \fn int sauvegarder_Partie(SDL_Surface *ecran, char nom_fichier[], Joueur joueurs[], int num_carte, int nb_joueurs)
 * \author Nouira Chafik
 * \brief Fonction qui permet de sauvegarder une partie dans un fichier txt. (Elle sauvegarde 5 parties au maximum)
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] nom_fichier Nom du fichier dans lequel on veut sauvegarder la partie (Le fichier sera créé par la fonction)
 * \param[in] joueurs[] Tableau contenant les données des joueurs (Noms, scores, positions, et la valeur de prision de chacun)
 * \param[in] num_carte Le numéro de la carte/parcours du jeu.
 * \param[in] nb_joueurs Nombre de joueurs.
 * \return Elle retourne 1 si la partie est sauvegardée avec succès, 0 sinon. (Elle retourne 0 s'il y a déjà 5 parties sauvegardées)
 */
int sauvegarder_Partie(SDL_Surface *ecran, char nom_fichier[], Joueur joueurs[], int num_carte, int nb_joueurs);
/**
 * \fn void menu_Exit(SDL_Surface *ecran, Joueur joueurs[], int num_carte, int nb_joueurs)
 * \brief Fonction qui sert de Menu de suspension/arrêt d'une partie.
 * \details On peut choisir sois de Sauvegarder la partie et quitter, sois de Quitter sans faire la sauvegarde.
 * \author Nouira Chafik
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] joueurs[] Tableau contenant les données des joueurs (Noms, scores, positions, et la valeur de prision de chacun)
 * \param[in] num_carte Le numéro de la carte/parcours du jeu.
 * \param[in] nb_joueurs Nombre de joueurs.
 */
void menu_Exit(SDL_Surface *ecran, Joueur joueurs[], int num_carte, int nb_joueurs);
/**
 * \fn int menu_Chargement(SDL_Surface *ecran, int *num_cartechoisie, Joueur joueur[], int *nbre_joueur)
 * \brief Fonction qui sert de Menu de Chargement d'une partie sauvegardée.
 * \details Elle affiche la liste des parties sauvegardés (Les noms des fichiers) et permet à l'utilisateur de sélectionner la partie qu'il veut charger.
 * \author Nouira Chafik
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[out] num_cartechoisie N° de la carte du jeu. 
 * \param[out] joueur[] Tableau qui contiendra les données des joueurs (Noms, scores, positions, et la valeur de prision de chacun)
 * \param[in] nbre_joueur Nombre de joueurs.
 * \return Elle retourne 1 si une partie est chargée avec succès, 0 sinon(En générale elle retourne 0 quand il n'y a aucune partie sauvegardée)
 */
int menu_Chargement(SDL_Surface *ecran, int *num_cartechoisie, Joueur joueur[], int *nbre_joueur);
/**
 * \fn void choix_Nb_Joueur (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2,int bool)
 * \author Matsima Claude
 * \brief Fonction qui permet de choisir le nombre de joueurs pour une partie.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] font1 Un pointeur vers la première police (Font) utilisée. 
 * \param[in] font2 Un pointeur vers la deuxième police (Font) utilisée.
 * \param[in] bool Numéro du choix sélectionné (Qui n'est pas encore validé bien sûr)
 */
void choix_Nb_Joueur (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2,int bool);
/**
 * \fn void saisie_Nom(SDL_Surface *ecran,int num_joueur,char *nom,TTF_Font *font1)
 * \author Matsima Claude
 * \brief Fonction qui permet de saisir un nom/pseudo pour chaque joueur.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] num_joueur Le numéro du joueur pour lequel on va attribuer un nom/pseudo.
 * \param[out] nom Chaine de caractère qui contiendra le nom d'un joueur saisi au clavier.
 * \param[in] font1 Un pointeur vers la police (Font) utilisée pour cette fonction.
 * \return Cette fonction ne retourne rien, elle stocke le résultat directement dans une chaine de caractère (Ce qui est un passage par pointeurs).
 */
void saisie_Nom(SDL_Surface *ecran,int num_joueur,char *nom,TTF_Font *font1);
/**
 * \fn void aff_j(SDL_Rect pos,SDL_Surface *ecran,SDL_Surface*pion,int i)
 * \author Fofana Ibrahim
 * \brief Fonction qui affiche un pion donnée sur la carte du jeu.
 *
 * \param[in] pos Position du pion sur la carte. (Coordonnées de la case sur laquelle on va blitter le pion)
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] pion Le pion qu'on va placer sur l'écran.
 * \param[in] i Numéro du joueur correspondant au pion.
 */
void aff_j(SDL_Rect pos,SDL_Surface *ecran,SDL_Surface*pion,int i);
/**
 * \fn int visualisation(SDL_Surface* ecran,SDL_Surface* carre,int *nb)
 * \author Fofana Ibrahim
 * \brief Fonction qui permet de visualiser les cartes disponibles et d'en choisir une pour commencer une partie.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param carre En attendant l'explication d'Ibrahim.
 * \param nb En attendant l'explication d'Ibrahim.
 */
int visualisation(SDL_Surface* ecran,SDL_Surface* carre,int *nb);
/**
 * \fn void affNombreCase(SDL_Surface* ecran,SDL_Rect case_dans_ecran[64])
 * \author Fofana Ibrahim
 * \brief Fonction de numérotation des cases une fois la partie est lancé.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] case_dans_ecran[64] Tableau des positions des 64 cases sur l'écran principal.
 * \return En attendant l'explication d'Ibrahim.
 */
void affNombreCase(SDL_Surface* ecran,SDL_Rect case_dans_ecran[64]);
/**
 * \fn int lancement_De(SDL_Surface *ecran, char j[])
 * \brief Fonction de lancement du dé.
 * \details Cette fonction affiche un dé et lance un son de tambour et attend que le joueur appuie sur 'Espace' pour lui retourner un n° aléatoire entre 1 et 6 toute en affichant la face du dé correspondante.
 * \author Nouira Chafik
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] j Nom du joueur qui va lancer le dé.
 * \return Elle retourne un nombre aléatoire entre 1 et 6.
 */
int lancement_De(SDL_Surface *ecran, char j[]);
/**
 * \fn int gestion_Bonus (SDL_Surface *ecran,TTF_Font *font1,char *nom_joueur)
 * \author Abak-kali Nizar
 * \brief Fonction de gestion des Bonus.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] font1 Un pointeur vers la police (Font) utilisée pour cette fonction.
 * \param[in] nom_joueur Nom du joueur actuel.
 * \return Elle retourne la valeur du bonus obtenue. (Entre 1 et 3)
 */
int gestion_Bonus (SDL_Surface *ecran,TTF_Font *font1,char *nom_joueur);
/**
 * \fn gestion_Malus(SDL_Surface *ecran,TTF_Font *font1,char *nom_joueur)
 * \author Abak-kali Nizar
 * \brief Fonction de gestion des Malus.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] font1 Un pointeur vers la police (Font) utilisée pour cette fonction.
 * \param[in] nom_joueur Nom du joueur actuel.
 * \return Elle retourne la valeur du malus obtenue. (Entre -1 et -3)
 */
int gestion_Malus(SDL_Surface *ecran,TTF_Font *font1,char *nom_joueur);
/**
 * \fn int gestion_Prison(SDL_Surface *ecran,TTF_Font *font1,char *nom_joueur,int nb_joueur)
 * \author Abak-kali Nizar
 * \brief Fonction de gestion de la Prison.
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] font1 Un pointeur vers la police (Font) utilisée pour cette fonction.
 * \param[in] nom_joueur Nom du joueur actuel.
 * \param[in] nb_joueur Le nombre des joueurs.
 * \return Elle retourne la valeur de prison obtenue. (Entre 2 et 6)
 */
int gestion_Prison(SDL_Surface *ecran,TTF_Font *font1,char *nom_joueur,int nb_joueur);
/**
 * \fn void gestion_Mini_Jeux(SDL_Surface *ecran,TTF_Font *font1,Joueur* tabjoueur,int nb_joueur)
 * \author Abak-kali Nizar
 * \brief Fonction de gestion des Mini-jeux (5 mini-jeux avec chacun son propre fichier .c | Les .c des mini-jeux sont inclus dans jouer.c).
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] font1 Un pointeur vers la police (Font) utilisée pour cette fonction.
 * \param[in] tabjoueur Tableau des joueurs.
 * \param[in] nb_joueur Le nombre des joueurs.
 * \return Cette fonction ne retourne rien, elle lance un mini-jeu au hasard dans lequel 2 joueurs choisis aussi au hasard vont s'affronter (Sauf s'il n'y a que 2 joueurs). à la fin de la partie du mini-jeux les résultats sont directement affectés dans le tableau des joueurs, le gagnant avance de 3 cases, et le perdant recule de 3 cases.
 */
void gestion_Mini_Jeux(SDL_Surface *ecran,TTF_Font *font1,Joueur* tabjoueur,int nb_joueur);
/**
 * \fn void jouer (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2, int n)
 * \brief Fonction principale du jeu.
 * \details Cette fonction fait appel aux différentes fonctions du fichier jouer.c pour exécuter les différentes tâches nécessaires pour le bon déroulement d'une partie.
 * \author Matsima Claude, Nouira Chafik, Abak-kali Nizar, Fofana Ibrahim
 *
 * \param[out] ecran Ecran principal sur lequel on va blitter les différentes images qui correspondent aux tâches qui sont en train d'être exécutées.
 * \param[in] font1 Un pointeur vers la premièrs police (Font) utilisée pour cette fonction.
 * \param[in] font1 Un pointeur vers la deuxième police (Font) utilisée pour cette fonction.
 * \param[in] charger Une valeur entière pour indiquer si l'utilisateur à charger une partie déjà existante (Valeur 1) ou s'il a lancé une nouvelle partie (Valeur 0).
 * \return Cette fonction ne retourne rien, pour en sortir faut que la partie soit terminée ou suspendue.
 */
void jouer (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2, int charger);
