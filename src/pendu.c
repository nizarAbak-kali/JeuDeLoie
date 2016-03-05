/**
 * \file pendu.c
 * \brief Code source du Mini-jeu Pendu en SDL.
 * \author Nouira Chafik
 * \date 11 mars 2013
 *
 */
/*
pendu.c
----------

Par Nouira Chafik 11291558, pour le projet "Jeu de l'oie Revisité" - Réalisation de programmes Semestre 2 2012/2013

Rôle : Jeu du "Pendu" en SDL
*/

#include "../headers/bibliotheque_mini_jeux.h"

//Fonction qui affiche l'image du pendu qui correspond au nombre de coups ratés
void bonhomme(SDL_Surface* ecran, int n) {
  SDL_Surface *pendu = NULL;
  SDL_Rect positionpendu = {175,10,0,0};
  //Chargement de l'image qui correspond à n (Nombre de coups ratés)
  switch (n) {
    case 1: pendu = IMG_Load("../images/Mini-jeux/Pendu1.png"); break;
    case 2: pendu = IMG_Load("../images/Mini-jeux/Pendu2.png"); break;
    case 3: pendu = IMG_Load("../images/Mini-jeux/Pendu3.png"); break;
    case 4: pendu = IMG_Load("../images/Mini-jeux/Pendu4.png"); break;
    case 5: pendu = IMG_Load("../images/Mini-jeux/Pendu5.png"); break;
    case 6: pendu = IMG_Load("../images/Mini-jeux/Pendu6.png"); break;
    case 7: pendu = IMG_Load("../images/Mini-jeux/Pendu7.png"); break;
    case 8: pendu = IMG_Load("../images/Mini-jeux/Pendu8.png"); break;
    case 9: pendu = IMG_Load("../images/Mini-jeux/Pendu9.png"); break;
    case 10: pendu = IMG_Load("../images/Mini-jeux/Pendu10.png"); break;
    default: break;
  }

  //Blit de l'image chargée
  SDL_BlitSurface(pendu, NULL, ecran, &positionpendu);
}


/*Cette fonction sert à charger un mot à partir d'un fichier texte et le stocker dans une chaine (Dans le mot à découvrir)*/
//La variable n est entier généré au hasard dans la fonction jouer_Pendu. (Entre 1 et 100)
void chargement_Mot(char mot[], int n) {
  int i=0;
  char ch[10];
  FILE *fichier = NULL;
  fichier = fopen("../Sauvegarde/mots.txt","r+");
  do {
    i++;
    strcpy(ch,"");
    fscanf(fichier,"%s",ch);
  } while (i < n);
  strcpy(mot,ch);
  fclose(fichier);
}


/*La fonction initialiser sert à copier une chaine ch1 dans une autre ch2 puis remplacer 
les caractères de ch2 par des tirets pour que les caractères soient cachés*/
void initialiser(char mot_cache[], char mot_decouvert[]) {
  int i;
  for (i = 0; mot_cache[i] != '\0'; i++) {
    mot_decouvert[i] = '-';
  }
  mot_decouvert[i] = '\0';
}


/*La fonction existe renvoi le nombre d'occurences d'un caractère dans une liste, 0 s'il n'existe pas.*/
int existe(char ch[], char c) {
  int i, n = 0;
  for (i = 0; ch[i] != '\0'; i++) {
    if (c == ch[i]) 
      n++; 
  }
  return n;
}


//Fonction principale du jeu du Pendu, elle gérera l'affichage des différentes étapes d'une partie
int jouer_Pendu(SDL_Surface *ecran, char j1[], char j2[]) {
  //Déclaration des variables locales nécassaires pour la fonction
  SDL_Surface *s_mot_cache = NULL, *s_mot_decouvert = NULL, *resultat = NULL, *joueur = NULL;
  SDL_Rect position_mot_decouvert={200,500,0,0}, positionresultat = {50,400,0,0}, positionjoueur = {0,350,0,0};
  SDL_Event event;
  TTF_Font *police = NULL, *police2 = NULL;
  SDL_Color couleurNoire = {0, 0, 0, 0};
  int j=0, i, continuer=1, coups_reussis=0, coups_rates=1, joueuractuel = 1, joueur1, joueur2;
  char c, ch[30], mot_cache[30], mot_decouvert[30];
  Mix_Chunk *son1, *son2; 
  son1 = Mix_LoadWAV("../Music/Mini-jeux/coup_reussi_pendu.ogg");
  son2 = Mix_LoadWAV("../Music/Mini-jeux/coup_rate_pendu.ogg");

  srand(time(NULL));

  //Chargement de la police
  police = TTF_OpenFont("../Police/comicbd.ttf", 30);
  police2 = TTF_OpenFont("../Police/comicbd.ttf", 40);
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  joueur1 = joueur2 = 0;

  //Point de départ d'un tour (On retourne à cette ligne pour alterner les tours entre les joueurs)
 debut:
  /*Initialisation des variables utilisées durant une partie*/
  c = '0';
  //Génération d'un nombre au hasard entre 1 et 100, ce nombre sera l'indice du mot caché qui sera chargé du fichier mots.txt avec la fonction chargement_Mot
  i = rand()%100+1;
  chargement_Mot(mot_cache,i);
  //Initialisation de la chaine qui va contenir le mot saisi par un joueur
  initialiser(mot_cache,mot_decouvert);
  s_mot_decouvert = TTF_RenderText_Blended(police, mot_decouvert, couleurNoire);
  j++;
  continuer = 1;
  //Alternance du tour
  if(joueuractuel == 1) sprintf(ch,"Joueur : %s",j1);
  else sprintf(ch,"Joueur : %s",j2);
  joueur = TTF_RenderText_Blended(police2, ch, couleurNoire);
  //Boucle while qui gérera l'affichage des différentes étapes du jeu
  while(continuer) {
    SDL_WaitEvent(&event);
    switch(event.type) {
      //En cas de fermeture de la fenêtre
      case SDL_QUIT: continuer = 0; return 0; break;
	//En cas d'appuie sur un bouton, stocker le caractère dans la variable c
      case SDL_KEYDOWN : 
        switch(event.key.keysym.sym) {
          default : c = event.key.keysym.sym; break;
	}

	//Si c'est une lettre en majuscule, la convertir en minuscule
	if(c >= 'A' && c <= 'Z') c -= 32;
	//Si c'est une lettre, faire les tests nécessaires pour voir si le mot caché contient la lettre saisie
	if(c >= 'a' && c <= 'z') {
	  //Si la lettre saisie existe dans le mot caché, l'afficher dans sa/ses position(s) dans le mot découvert (le mot qui contient n tirets | n c'est la longueur du mot caché)
	  if (existe(mot_cache,c) > existe(mot_decouvert,c)) {
	    coups_reussis++;
	    Mix_PlayChannel(1,son1,0);
	    for (i = 0; mot_cache[i] != '\0'; i++) {
	      if (mot_cache[i] == c)
		mot_decouvert[i] = c;
	    }
	    s_mot_decouvert = TTF_RenderText_Blended(police, mot_decouvert, couleurNoire);  
	  }
    /*Si la lettre n'existe pas dans mot_cache, on incrémente les coups ratés de 1, puis on appelle la fonction bonhomme 
      avec le nombre coups_rates qui s'occupera d'afficher l'image correspondante du pendu*/ 
	  else if(existe(mot_cache,c) == existe(mot_decouvert,c)){
	    Mix_PlayChannel(1,son2,0);
	    coups_rates++;
	  } 
	}
	break;
	default : break;
    }

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    bonhomme(ecran,coups_rates);
    SDL_BlitSurface(s_mot_decouvert,NULL, ecran, &position_mot_decouvert);
    //Si le joueur atteint le nombre max de coups ratés, on affiche le mot caché et on garde le nombre de coups ratés afin de le comparer avec celui de l'autre joueur.
    if(coups_rates == 10) {
      if(joueuractuel == 1) {joueuractuel = 2; joueur1 = coups_rates;}
      else {joueuractuel = 1; joueur2 = coups_rates;}
      continuer = 0;
      coups_rates = 1;
      sprintf(ch,"Le mot etait '%s'",mot_cache);
      resultat = TTF_RenderText_Blended(police2, ch, couleurNoire);
      SDL_BlitSurface(resultat,NULL, ecran, &positionresultat);
    }
    //Si le joueur trouve le mot caché, on affiche le texte correspondant et on garde le nombre de coups ratés afin de le comparer avec celui de l'autre joueur.
    else if(!strcmp(mot_cache,mot_decouvert)) {
      if(joueuractuel == 1) {joueuractuel = 2; joueur1 = coups_rates;}
      else {joueuractuel = 1; joueur2 = coups_rates;}
      sprintf(ch,"Bravoo !");
      resultat = TTF_RenderText_Blended(police2, ch, couleurNoire);
      SDL_BlitSurface(resultat,NULL, ecran, &positionresultat);
      continuer = 0;
      coups_rates = 1;
    }
    SDL_BlitSurface(joueur,NULL, ecran, &positionjoueur);
    SDL_Flip(ecran);
  }
  sleep(2);

  //Si les 2 joueurs ont le même score ou si c'est le tour du 2ème joueur, relancer le jeu avec un mot différent.
  if(joueur1 == joueur2 || j&1) goto debut;

  SDL_FreeSurface(s_mot_decouvert);
  SDL_FreeSurface(s_mot_cache);
  SDL_FreeSurface(resultat);
  Mix_FreeChunk(son1);//Libération du son
  Mix_FreeChunk(son2);//Libération du son

  //Renvoie de l'indice du gagnant
  if(joueur1 > joueur2) return 2;
  else return 1;
}


/*Cette fonction sert de page d'accueil du jeu du Pendu, elle fait appel à la fonction jouer_Pendu quand l'utilisateur
  appuie sur "Entrer", et à la fin elle récupère l'indice du gagnant et le renvoie à son tour*/
int Accueil_Pendu(SDL_Surface *ecran, char *j1, char *j2) {
  //Déclaration des variables locales nécessaires pour la fonction.
  SDL_Surface *texte1 = NULL, *texte2 = NULL, *pendu = NULL;
  SDL_Rect positiontexte1, positiontexte2, positionpendu;
  SDL_Event event;
  TTF_Font *police1 = NULL, *police2 = NULL;
  SDL_Color couleurNoire = {0, 0, 0, 0}, couleurBlanche = {255, 255, 255, 0};
  int continuer = 1, gagnant;
  Mix_Music *musique; //Création d'un pointeur de type Mix_Music
  Mix_VolumeMusic(MIX_MAX_VOLUME);
  musique = Mix_LoadMUS("../Music/Mini-jeux/pendu.ogg"); //Chargement de la musique
  Mix_PlayMusic(musique, -1); //Jouer infiniment la musique

  //Chargement de l'image du pendu
  pendu = IMG_Load("../images/Mini-jeux/Pendu10.png");

  //Chargement de la police
  police1 = TTF_OpenFont("../Police/chata.ttf", 65);
  police2 = TTF_OpenFont("../Police/chata.ttf", 25);

  //Initialisation du texte
  texte1 = TTF_RenderText_Shaded(police1, "Le Pendu", couleurNoire, couleurBlanche);
  texte2 = TTF_RenderText_Shaded(police2, "Appuyer sur entrer pour commencer", couleurNoire, couleurBlanche);

  SDL_SetColorKey(texte1, SDL_SRCCOLORKEY, SDL_MapRGB(texte1->format, 255, 255, 255));
  SDL_SetColorKey(texte2, SDL_SRCCOLORKEY, SDL_MapRGB(texte2->format, 255, 255, 255));

  //Remplissage de l'écran principal avec la couleur blanche
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 200, 100));

  //Initialisation des positions des différentes surfaces et textes
  positiontexte1.x = (ecran->w - texte1->w) / 2;
  positiontexte1.y = 0;
  positiontexte2.x = (ecran->w - texte2->w) / 2;
  positiontexte2.y = 250 + (ecran->h - texte2->h) / 2;
  positionpendu.x = (ecran->w / 2) - (pendu->w / 2);
  positionpendu.y = (ecran->h / 2) - (pendu->h / 2);

  //Remplissage de l'écran principal avec la couleur blanche
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 200, 100));

  //Blit du texte de la page d'accueil
  SDL_BlitSurface(texte1, NULL, ecran, &positiontexte1);
  SDL_BlitSurface(texte2, NULL, ecran, &positiontexte2);

  //Blit de l'image du pendu
  SDL_BlitSurface(pendu, NULL, ecran, &positionpendu);

  //Mise à jour de l'écran
  SDL_Flip(ecran);

  /*Une boucle infine afin de maintenir l'affichage et quitter le programme quand l'utilisateur ferme la fenêtre*/
  while (continuer) {
    SDL_PollEvent(&event);
    switch(event.type) {
    case SDL_QUIT:
      continuer = 0;
      break;
    //En cas d'apuui sur un bouton
    case SDL_KEYDOWN :
      //S'il s'agit du bouton "Entrer", appeler la fonction joueur_Pendu
      if(event.key.keysym.sym == SDLK_RETURN) gagnant = jouer_Pendu(ecran,j1,j2);
      continuer = 0;
      break;
    default: break;
    }
  }

  //Libération de la mémoire occupée par les surfaces et les polices et arrêt de la SDL
  TTF_CloseFont(police1);
  TTF_CloseFont(police2);
  SDL_FreeSurface(pendu);
  SDL_FreeSurface(texte1);
  SDL_FreeSurface(texte2);
  Mix_FreeMusic(musique); //Libération de la musique

  return gagnant;
}
