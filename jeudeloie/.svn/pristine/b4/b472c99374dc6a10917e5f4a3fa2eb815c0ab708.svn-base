/*
puissance_4.c
----------

Par Nouira Chafik 11291558, pour le projet "Jeu de l'oie Revisité" - Réalisation de programmes Semestre 2 2012/2013

Rôle : Jeu de "Puissance 4" en SDL
*/

#include "../headers/bibliotheque_mini_jeux.h"


//Cette fonction remplie toutes les cases de la matrice Mat par la valeur VIDE (0)
void init_Mat_Colonne() {
  int i,j;
  for(i = 0; i < NB_LIGNES; i++)
    for(j = 0; j < NB_COLONNES; j++)
      Mat[i][j] = VIDE;
  for(i = 0; i < NB_COLONNES; i++)
    Colonne[i] = 0;
}

//Cette fonction retourne 1 si un coup est jouable, 0 sinon.
int Jouable(int x) {
  if ((x >= 0 && x < NB_COLONNES) && (Colonne[x] >= 0 && Colonne[x] < NB_LIGNES)) return 1;
    else return 0;
}

//Cette fonction retourne 1 si la matrice Mat est entièrement remplie, 0 sinon.
int Remplie() {
  int i;
  for(i = 0; i < NB_COLONNES; i++)
    if(Colonne[i] < 6) return 0;
  return 1;
}

/*Cette fonction retourne NOIR (1) si elle trouve 4 jetons noirs alignés, ORANGE (2) si elle trouve 4 jetons oranges alignés
  et 0 en cas d'absence des 2 premiers cas
  P.S : Cette fonction prendra comme point de départ la case Mat[a][b], elle ne parcourt pas la matrice*/
int Puis_4(int a, int b) {
  int i,noir=0,orange=0;

  if(!Mat[a][b]) return 0;

  if(a >= 3) {
    for(i = a; i >= a-3; i--) {
      if(Mat[i][b] == 0) noir = orange = 0;
      if(Mat[i][b] == NOIR) {orange = 0; noir++;}
      if(Mat[i][b] == ORANGE) {noir = 0; orange++;}
    }
    if(noir == 4) return NOIR;
    if(orange == 4) return ORANGE;
  }  

  noir = orange = 0;
  if(a <= 2) {
    for(i = a; i < NB_LIGNES; i++) {
      if(Mat[i][b] == 0) noir = orange = 0;
      if(Mat[i][b] == NOIR) {orange = 0; noir++;}
      if(Mat[i][b] == ORANGE) {noir = 0; orange++;}
    }
    if(noir == 4) return NOIR;
    if(orange == 4) return ORANGE;
  } 

  noir = orange = 0;
  if(b >= 3) {
    for(i = b; i >= b-3; i--) {
      if(Mat[a][i] == 0) noir = orange = 0;
      if(Mat[a][i] == NOIR) {orange = 0; noir++;}
      if(Mat[a][i] == ORANGE) {noir = 0; orange++;}
    }
    if(noir == 4) return NOIR;
    if(orange == 4) return ORANGE;
  }  

  noir = orange = 0;
  if(b <= 3) {
    for(i = b; i < NB_COLONNES; i++) {
      if(Mat[a][i] == 0) noir = orange = 0;
      if(Mat[a][i] == NOIR) {orange = 0; noir++;}
      if(Mat[a][i] == ORANGE) {noir = 0; orange++;}
    }
    if(noir == 4) return NOIR;
    if(orange == 4) return ORANGE;
  }

  if(a <= 2 && b <= 3)
    if(((Mat[a][b] == Mat[a+1][b+1]) && (Mat[a+1][b+1] == Mat[a+2][b+2])) && (Mat[a+2][b+2] == Mat[a+3][b+3]))
      return Mat[a][b];

  if(a >= 3 && b >= 3)
    if(((Mat[a][b] == Mat[a-1][b-1]) && (Mat[a-1][b-1] == Mat[a-2][b-2])) && (Mat[a-2][b-2] == Mat[a-3][b-3]))
      return Mat[a][b];

  if(a >= 3 && b <= 3)
    if(((Mat[a][b] == Mat[a-1][b+1]) && (Mat[a-1][b+1] == Mat[a-2][b+2])) && (Mat[a-2][b+2] == Mat[a-3][b+3]))
      return Mat[a][b];

  if(a <= 2 && b >= 3)
    if(((Mat[a][b] == Mat[a+1][b-1]) && (Mat[a+1][b-1] == Mat[a+2][b-2])) && (Mat[a+2][b-2] == Mat[a+3][b-3]))
      return Mat[a][b];
 
  return 0;
}


/*Cette fonction parcourt la martice Mat afin de vérifier l'existence d'un gagnant, s'il y en a bien un, elle retourne 
  ORANGE ou NOIR selon le résultat, elle retourne 0 sinon*/
int verif_Gagnant_p4() {
  int i,j;

  for(i = 0; i < NB_LIGNES; i++)
    for(j = 0; j < NB_COLONNES; j++)
      if(Mat[i][j] && Puis_4(i,j) != 0)
	return Puis_4(i,j);

  return 0;
}


/*Cette fonction prend une variable de type SDL_Rect en paramètre et retourne l'indice de la colonne survolée par la souris,
  si aucune colonne n'est survolée, elle retourne -1*/
int verif_Colonne(SDL_Rect* pos) {
  int col = -1;
  if(pos->y > 470) return col;
  if(pos->x >= 12 && pos->x <= 83) col = 0;
  if(pos->x >= 96 && pos->x <= 167) col = 1;
  if(pos->x >= 180 && pos->x <= 251) col = 2;
  if(pos->x >= 264 && pos->x <= 335) col = 3;
  if(pos->x >= 348 && pos->x <= 419) col = 4;
  if(pos->x >= 432 && pos->x <= 503) col = 5;
  if(pos->x >= 517 && pos->x <= 588) col = 6;
  return col;
}

/*Cette fonction a pour mission de jouer un coup dans la matrice Mat et d'incrémenter le nb de coups dans la case 
  correspondante dans le tableau Colonne*/
void jouer_Coup(int col, int coup) {
  int i;
  for(i = 0; i < (NB_LIGNES - Colonne[col]); i++);
  Mat[i-1][col] = coup;
  Colonne[col]++;
}

void update_Screen(SDL_Surface* ecran) {
  SDL_Surface *noir = NULL, *orange = NULL;
  SDL_Rect position;
  int i,j;

  //Chargement des images noir.png et orange.png
  noir = IMG_Load("../images/Mini-jeux/noir.bmp");
  orange = IMG_Load("../images/Mini-jeux/orange.bmp");

  //Gérer la transparence des images noir.png et orange.png
  SDL_SetColorKey(noir, SDL_SRCCOLORKEY, SDL_MapRGB(noir->format, 255, 255, 255));
  SDL_SetColorKey(orange, SDL_SRCCOLORKEY, SDL_MapRGB(orange->format, 255, 255, 255));

  for(i = 0; i < NB_LIGNES; i++) {
    for(j = 0; j < NB_COLONNES; j++) {
      switch(Mat[i][j]) {
      case NOIR :
	position.y = i*78 + 9;
	position.x = j*84 + 10;  
	SDL_BlitSurface(noir, NULL, ecran, &position);
	break;
      case ORANGE :
	position.y = i*78 + 9;
	position.x = j*84 + 10;  
	SDL_BlitSurface(orange, NULL, ecran, &position);
	break;
      default : break;
      }
    }
  }
}


int Jouer_Puissance_4(SDL_Surface* ecran, char j1[], char j2[]) {
  //Déclaration des variables locales nécessaires pour la fonction.
  SDL_Surface *matrice = NULL, *texte = NULL, *white = NULL;
  SDL_Rect positionmatrice = {0,0,0,0}, positioncoup, positiontexte = {0,500,0,0}, positionwhite = {0,480,0,0};
  SDL_Event event;
  TTF_Font *police = NULL;
  SDL_Color couleurNoire = {0, 0, 0, 0};
  int continuer, v, joueur;
  char ch[30];
  Mix_Chunk *son; 
  son = Mix_LoadWAV("../Music/Mini-jeux/coup_puissance_4.ogg");
  
  //Chargement de la matrice et d'une surface blanche
  matrice = IMG_Load("../images/Mini-jeux/puissance_4.png");
  white = IMG_Load("../images/Mini-jeux/white.png");

  //Chargement de la police du texte "messy.ttf"
  police = TTF_OpenFont("../Police/comicbd.ttf", 60);

  //Initialisation des coordonnées de la matrice et du texte sur l'écran du jeu


  /*1 - Initialisation des cases de la matrice et d'autres variables nécessaires pour le bon fonctionnement du jeu. 
        Remplissage de l'écran principal avec la couleur blanche et Blittage de la matrice dessus.
    2 - Début de la partie*/
 debut:
  init_Mat_Colonne();
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  SDL_BlitSurface(matrice, NULL, ecran, &positionmatrice);
  continuer = joueur = 1;
  while(continuer) {
    SDL_WaitEvent(&event);
    switch(event.type) {
      //En cas de fermeture de la fenêtre
      case SDL_QUIT: continuer = 0; return 0; break;

	//Si clique avec la souris
      case SDL_MOUSEBUTTONUP :

	//Si bouton gauche
        if(event.button.button == SDL_BUTTON_LEFT) {

	  //Récupérer les coordonnées du pointeur au moment du clic
	  positioncoup.x = event.motion.x;
	  positioncoup.y = event.motion.y;

	  //Vérifier la position du clic (S'il était fait à l'intérieur ou à l'extérieur de la matrice)
	  v = verif_Colonne(&positioncoup);

          if(v != -1) {
	    if(Jouable(v)) {
	      Mix_PlayChannel(1,son,0);
	      jouer_Coup(v,joueur);
	      if(joueur == 1) joueur = 2;
	      else joueur = 1;
	    }
	  }
	}
 	break;
      default : break;
    }
    if(joueur == 1)
      sprintf(ch,"A toi %s!",j1);
    else 
      sprintf(ch,"A toi %s!",j2);
    texte = TTF_RenderText_Blended(police, ch, couleurNoire);
    SDL_BlitSurface(white, NULL, ecran, &positionwhite);
    SDL_BlitSurface(texte, NULL, ecran, &positiontexte);
    update_Screen(ecran);

    //Vérification du gagnant et affichage du résultat sur l'écran en blittant le texte correspondant
    if(verif_Gagnant_p4()) {
      if(verif_Gagnant_p4() == 1)
	sprintf(ch,"Bravo %s!",j1);
      else
	sprintf(ch,"Bravo %s!",j2);
      texte = TTF_RenderText_Blended(police, ch, couleurNoire);
      SDL_BlitSurface(white, NULL, ecran, &positionwhite);
      SDL_BlitSurface(texte, NULL, ecran, &positiontexte);
      continuer = 0;
    }
    else if(Remplie()){
      texte = TTF_RenderText_Blended(police, "   Match Nul", couleurNoire);
      SDL_BlitSurface(white, NULL, ecran, &positionwhite);
      SDL_BlitSurface(texte, NULL, ecran, &positiontexte);
      continuer = 0;
    }

    SDL_Flip(ecran); 
  }

  if(!verif_Gagnant_p4())
    goto debut;

  /*Appel de la fonction sleep, histoire d'avoir le temps de voir le résultat sur l'écran avant de sortir de la fonction
    ou de commencer une autre partie*/
  sleep(2);

  //Libération de la mémoire occupée par les surfaces et la police
  TTF_CloseFont(police);
  SDL_FreeSurface(matrice);
  Mix_FreeChunk(son);//Libération du son

  return verif_Gagnant_p4();
}


/*Cette fonction sert de page d'accueil du jeu Puissance 4, elle fait appel à la fonction Jouer_Puissance_4 quand l'utilisateur
  appuie sur "Entrer"*/
int Accueil_Puissance_4(SDL_Surface *ecran, char *j1, char *j2) {

  //Déclaration des variables locales nécessaires pour la fonction.
  SDL_Surface *texte1 = NULL, *texte2 = NULL, *noir = NULL, *orange = NULL, *puis4 = NULL;
  SDL_Rect positiontexte1, positiontexte2, positionnoir, positionorange, position4;
  SDL_Event event;
  TTF_Font *police1 = NULL, *police2 = NULL;
  SDL_Color couleurNoire = {0, 0, 0, 0}, couleurBlanche = {255, 255, 255, 0};
  int continuer = 1, gagnant;
  Mix_Music *musique; //Création d'un pointeur de type Mix_Music
  Mix_VolumeMusic(MIX_MAX_VOLUME);
  musique = Mix_LoadMUS("../Music/Mini-jeux/puissance_4.ogg"); //Chargement de la musique
  Mix_PlayMusic(musique, -1); //Jouer infiniment la musique

  //Chargement des images noir, orange et 4
  noir = IMG_Load("../images/Mini-jeux/noir.bmp");
  orange = IMG_Load("../images/Mini-jeux/orange.bmp");
  puis4 = IMG_Load("../images/Mini-jeux/4.png");

  //Chargement de la police
  police1 = TTF_OpenFont("../Police/chata.ttf", 65);
  police2 = TTF_OpenFont("../Police/chata.ttf", 25);

  //Initialisation du texte
  texte1 = TTF_RenderText_Shaded(police1, "Puissance 4", couleurNoire, couleurBlanche);
  texte2 = TTF_RenderText_Shaded(police2, "Appuyer sur entrer pour commencer", couleurNoire, couleurBlanche);

  //Remplissage de l'écran principal avec la couleur blanche
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

  //Initialisation des position des différentes surfaces et textes
  positiontexte1.x = (ecran->w - texte1->w) / 2;
  positiontexte1.y = 50;
  positiontexte2.x = (ecran->w - texte2->w) / 2;
  positiontexte2.y = 150 + (ecran->h - texte2->h) / 2;
  positionnoir.x = (ecran->w / 2) - noir->w*4;
  positionnoir.y = (ecran->h / 2) - noir->h;
  positionorange.x = (ecran->w / 2) + orange->w*3;
  positionorange.y = (ecran->h / 2) - orange->h;
  position4.x = (ecran->w / 2) - (puis4->w / 2);
  position4.y = (ecran->h / 2) - (puis4->h / 2);

  //Blit du texte de la page d'accueil
  SDL_BlitSurface(texte1, NULL, ecran, &positiontexte1);
  SDL_BlitSurface(texte2, NULL, ecran, &positiontexte2);

  //Blit des images
  SDL_BlitSurface(noir, NULL, ecran, &positionnoir);
  SDL_BlitSurface(orange, NULL, ecran, &positionorange);
  SDL_BlitSurface(puis4, NULL, ecran, &position4);

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
      //S'il s'agit du bouton "Entrer", appeler la fonction tictactoe
      if(event.key.keysym.sym == SDLK_RETURN)  gagnant = Jouer_Puissance_4(ecran,j1,j2);
      continuer = 0;
      break;
    default: break;
    }
  }

  //Libération de la mémoire occupée par les surfaces et les polices et arrêt de la SDL
  TTF_CloseFont(police1);
  TTF_CloseFont(police2);
  SDL_FreeSurface(noir);
  SDL_FreeSurface(orange);
  SDL_FreeSurface(texte1);
  SDL_FreeSurface(texte2);
  Mix_FreeMusic(musique); //Libération de la musique

  return gagnant;
}
