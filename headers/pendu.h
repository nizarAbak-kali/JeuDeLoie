/**
 * \file pendu.h
 * \brief Header du Jeu du Pendu en SDL.
 * \author Nouira Chafik
 * \date 11 mars 2013
 *
 * Un mini-jeu pour le projet "Jeu de l'Oie Revisité" - Réalisation de programmes - Semestre 2 2012/2013
 */
/**
 * \fn void bonhomme(SDL_Surface* ecran, int n)
 * \brief Fonction qui prend l'écran et le nombre de coups ratés en paramètre et blitte l'image du pendu correspondante sur l'écran.
 *
 * \param[out] ecran L'écran principal sur lequel on va blitter les différentes images correpondantes à l'évolution d'une partie.
 */
void bonhomme(SDL_Surface* ecran, int n);
/**
 * \fn void chargement_Mot(char mot[], int n)
 * \brief Fonction qui permet de charger un mot au hasard à partir d'un fichier texte qui contient \b n mots.
 *
 * \param[out] mot[] Chaine dans laquelle le mot chargé sera stocké.
 * \param[in] n nombre de mots stockés dans le fichier texte, ne doit jamais dépasser le \b vrai nombre de mots existants.
 */
void chargement_Mot(char mot[], int n);
/**
 * \fn void initialiser(char mot_cache[], char mot_decouvert[])
 * \brief Fonction qui permet de calculer la longueur \b n du mot caché (le mot chargé à partir du fichier) et remplit le mot decouvert par \b n tirets.
 *
 * \param[in] mot_cache[] Chaine contenant le mot chargé à partir du fichier texte.
 * \param[out] mot_decouvert[] Chaine qui va contenir \b n tirets (Avec \b n la longueur de la chaine mot_cache[])
 */
void initialiser(char mot_cache[], char mot_decouvert[]);
/**
 * \fn int existe(char ch[], char c)
 * \brief Fonction qui calcule le nombre d'occurences d'un caractère dans une chaine.
 *
 * \param[in] ch[] Chaine contenant le mot chargé à partir du fichier texte.
 * \param[in] c Caractère pour lequel on veut connaitre le nombre d'occurence dans ch[].
 * \return Cette fonction retourne le nombre d'occurence d'un caractère dans une chaine.
 */
int existe(char ch[], char c);
/**
 * \fn int jouer_Pendu(SDL_Surface *ecran, char j1[], char j2[])
 * \brief Fonction principale du jeu, elle sert à alterner les tours entre 2 joueurs (Un mot chacun).
 *
 * \param[out] ecran l'écran principal sur lequel on va blitter les différentes images correpondantes à l'évolution d'une partie.
 * \param[in] *j1 nom du premier joueur.
 * \param[in] *j2 nom du deuxième joueur.
 * \return Elle vérifie à chaque fois si le joueur est arrivé à trouver le mot caché, et elle retourne le n° du gagnant à la fin de la partie, s'il n'y a pas de gagnant, une autre partie est lancée
 */
int jouer_Pendu(SDL_Surface *ecran, char j1[], char j2[]);
/**
 * \fn int Accueil_Pendu(SDL_Surface* ecran, char *j1, char *j2)
 * \brief Fonction qui sert d'un accueil du jeu, histoire de ne pas lancer une partie "vulgairement", le joueur doit appuyer sur "Entrée" pour jouer.
 *
 * \param[out] ecran l'écran principal sur lequel on va blitter les différentes images correpondantes à l'évolution d'une partie.
 * \param[in] *j1 nom du premier joueur.
 * \param[in] *j2 nom du deuxième joueur.
 * \return Elle fait appel à la fonction jouer_Pendu une fois l'utilisateur appuie sur "Entrée", elle récupère le n° du gagnant à la fin et le retourne.
 */
int Accueil_Pendu(SDL_Surface *ecran, char *j1, char *j2);

