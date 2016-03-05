/*
tictactoe.c
----------

Par Nouira Chafik 11291558, pour le projet "Jeu de l'oie Revisité" - Réalisation de programmes Semestre 2 2012/2013

Rôle : Jeu du "Tic Tac Toé" en SDL
*/

#include "../headers/bibliotheque_mini_jeux.h"

//Cette fonction sert à initialiser la matrice Mat en affectant la valeur -1 à toutes ses cases.
void init_Mat() {
  int i,j;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      Matrice[i][j] = -1;
}


/*Cette fonction permet de se repérer dans l'écran principal du jeu, elle renvoie le n° de la case correspondante si 
  le pointeur survole la matrice, elle renvoie -1 sinon.
  La variable "pos" prise en paramètre permet de récupérer les coordonnées du pointeur sur l'écran du jeu*/
int verif_Case(SDL_Rect* pos) {
  int v = -1;
  if((pos->x >= 171 && pos->x < 261) && (pos->y >= 172 && pos->y < 262)) v = 0;
  if((pos->x >= 261 && pos->x < 351) && (pos->y >= 172 && pos->y < 262)) v = 1;
  if((pos->x >= 351 && pos->x < 441) && (pos->y >= 172 && pos->y < 262)) v = 2;
  if((pos->x >= 171 && pos->x < 261) && (pos->y >= 262 && pos->y < 352)) v = 3;
  if((pos->x >= 261 && pos->x < 351) && (pos->y >= 262 && pos->y < 352)) v = 4;
  if((pos->x >= 351 && pos->x < 441) && (pos->y >= 262 && pos->y < 352)) v = 5;
  if((pos->x >= 171 && pos->x < 261) && (pos->y >= 351 && pos->y < 442)) v = 6;
  if((pos->x >= 261 && pos->x < 351) && (pos->y >= 351 && pos->y < 442)) v = 7;
  if((pos->x >= 351 && pos->x < 441) && (pos->y >= 351 && pos->y < 442)) v = 8;
  return v;
}

/*Cette fonction sert à affecter la valeur d'un coup à la case correspondante dans la matrice Mat.
  Elle retourne 1 si le coup est bel et bien affecté, elle retourne 0 sinon*/
int update_Mat(int position, int coup) {
  int i, j, cpt = 0;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++) {
      if(cpt == position) {
	if(Matrice[i][j] == -1) {
	  Matrice[i][j] = coup;
	  return 1;
	}
      }
      cpt++;
    }
  return 0;
}


/*Cette fonction sert à vérifier le gagnant et renvoyer la valeur qui lui coorespond.
  ROND pour joueur 1, CROIX pour joueur 2 et 0 pour un match nul*/
int verif_Gagnant() {
  int i;
  for(i = 0; i < 3; i++) {
    if(Matrice[i][0] == ROND && (Matrice[i][1] == ROND && Matrice[i][2] == ROND)) return ROND;
    if(Matrice[i][0] == CROIX && (Matrice[i][1] == CROIX && Matrice[i][2] == CROIX)) return CROIX;
    if(Matrice[0][i] == ROND && (Matrice[1][i] == ROND && Matrice[2][i] == ROND)) return ROND;
    if(Matrice[0][i] == CROIX && (Matrice[1][i] == CROIX && Matrice[2][i] == CROIX)) return CROIX;
  }
  if(Matrice[0][0] == ROND && (Matrice[1][1] == ROND && Matrice[2][2] == ROND)) return ROND;
  if(Matrice[0][2] == ROND && (Matrice[1][1] == ROND && Matrice[2][0] == ROND)) return ROND;
  if(Matrice[0][0] == CROIX && (Matrice[1][1] == CROIX && Matrice[2][2] == CROIX)) return CROIX;
  if(Matrice[0][2] == CROIX && (Matrice[1][1] == CROIX && Matrice[2][0] == CROIX)) return CROIX;

  return 0;
}


/*Cette fonction gère le jeu du Tic Tac Toé, elle alterne les tours entre 2 joueurs et fait le nécessaire à chaque tour 
  (Vérifier la validité d'un coup et l'affecter dans la matrice), afin de sortir de la fonction il faut impérativement qu'il 
  y ait un gagnant, tant qu'il y a des matchs nuls, elle lance une autre partie*/
int Jouer_Tictactoe(SDL_Surface* ecran, char *j1, char *j2) {

  //Déclaration des variables locales nécessaires pour la fonction.
  SDL_Surface *smatrice = NULL, *rond = NULL, *croix = NULL, *texte = NULL, *white = NULL;
  SDL_Rect positionmatrice, positioncoup, positiontexte, positionwhite= {0,0,0,0};
  SDL_Event event;
  TTF_Font *police = NULL, *police2 = NULL;
  SDL_Color couleurNoire = {0, 0, 0, 0}; // couleurBlanche = {255, 255, 255, 0};
  int continuer, joueur, cpt,v;
  char ch[30];
  Mix_Chunk *son; 
  son = Mix_LoadWAV("../Music/Mini-jeux/coup_tictactoe.ogg");

  //Chargement des images croix, rond et matrice
  croix = IMG_Load("../images/Mini-jeux/croix.png");
  rond = IMG_Load("../images/Mini-jeux/rond.png");
  smatrice = IMG_Load("../images/Mini-jeux/tic_tac_toe.gif");
  white = IMG_Load("../images/Mini-jeux/white.png");

  //Chargement de la police du texte "messy.ttf"
  police = TTF_OpenFont("../Police/messy.ttf", 60);
  police2 = TTF_OpenFont("../Police/comicbd.ttf", 60);

  //initialisation des coordonnées de la matrice et du texte sur l'écran du jeu
  positionmatrice.x = (ecran->w/2 - smatrice->w/2);
  positionmatrice.y = (ecran->h/2 - smatrice->h/2);
  positiontexte.x = 80;
  positiontexte.y = 50;

  /*1 - Initialisation des cases de la matrice et d'autres variables nécessaires pour le bon fonctionnement du jeu. 
        Remplissage de l'écran principal avec la couleur blanche et Blittage de la matrice dessus.
    2 - Début de la partie*/
 debut:
  init_Mat();
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  SDL_BlitSurface(smatrice, NULL, ecran, &positionmatrice);
  cpt = 0; continuer = 1; joueur = 1;
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
	  v = verif_Case(&positioncoup);

	  //Si le clic est fait à l'intérieur de la matrice 
	  if(v != -1) {
	    //Récupérer les coordonnées du blittage correspondant à la case sur laquelle on a cliqué.
	    positioncoup.x = Coor_Mat[v].x;
	    positioncoup.y = Coor_Mat[v].y;

	    //Tour du joueur 1
	    if(joueur == 1) {
	      //Il faut bien sûr que la case sois vide pour affecter le coup
	      if(update_Mat(verif_Case(&positioncoup),ROND)) {
		Mix_PlayChannel(1,son,0);
		SDL_BlitSurface(rond, NULL, ecran, &positioncoup);
		joueur = 2; cpt++;
	      }
	    }
	    //Tour du joueur 2
	    else {
	      //Il faut bien sûr que la case sois vide pour affecter le coup
	      if(update_Mat(verif_Case(&positioncoup),CROIX)) {
		Mix_PlayChannel(1,son,0);
		SDL_BlitSurface(croix, NULL, ecran, &positioncoup);
		joueur = 1; cpt++;
	      }
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
    texte = TTF_RenderText_Blended(police2, ch, couleurNoire);
    SDL_BlitSurface(white, NULL, ecran, &positionwhite);
    SDL_BlitSurface(texte, NULL, ecran, &positiontexte);

    //Vérification du gagnant et affichage du résultat sur l'écran en blittant le texte correspondant
    if(verif_Gagnant() == 1) {
      sprintf(ch,"Bravo %s ",j1);
      texte = TTF_RenderText_Blended(police, ch, couleurNoire);
      SDL_BlitSurface(white, NULL, ecran, &positionwhite);
      SDL_BlitSurface(texte, NULL, ecran, &positiontexte);
      continuer = 0;
    }
    else if(verif_Gagnant() == 2) {
      sprintf(ch,"Bravo %s ",j2);
      texte = TTF_RenderText_Blended(police, ch, couleurNoire);
      SDL_BlitSurface(white, NULL, ecran, &positionwhite);
      SDL_BlitSurface(texte, NULL, ecran, &positiontexte);
      continuer = 0;
    }
    else if(cpt == 9 && !verif_Gagnant()){
      texte = TTF_RenderText_Blended(police, "   Match Nul", couleurNoire);
      SDL_BlitSurface(white, NULL, ecran, &positionwhite);
      SDL_BlitSurface(texte, NULL, ecran, &positiontexte);
      continuer = 0;
    }
    SDL_Flip(ecran); 
  }
  if(!verif_Gagnant())
    goto debut;

  /*Appel de la fonction sleep, histoire d'avoir le temps de voir le résultat sur l'écran avant de sortir de la fonction
    ou de commencer une autre partie*/
  SDL_Delay(2000);

  //Libération de la mémoire occupée par les surfaces et la police
  TTF_CloseFont(police);
  SDL_FreeSurface(smatrice);
  SDL_FreeSurface(rond);
  SDL_FreeSurface(croix);
  Mix_FreeChunk(son);//Libération du son

  return verif_Gagnant();
}


/*Cette fonction sert de page d'accueil du jeu Tic Tac Toé, elle fait appel à la fonction Jouer_TicTacToe quand l'utilisateur
  appuie sur "Entrer"*/
int Accueil_TicTacToe(SDL_Surface *ecran, char *j1, char *j2) {

  //Déclaration des variables locales nécessaires pour la fonction.
  SDL_Surface *texte1 = NULL, *texte2 = NULL, *croix = NULL, *rond = NULL;
  SDL_Rect positiontexte1, positiontexte2, positioncroix, positionrond;
  SDL_Event event;
  TTF_Font *police1 = NULL, *police2 = NULL;
  SDL_Color couleurNoire = {0, 0, 0, 0}, couleurBlanche = {255, 255, 255, 0};
  int continuer = 1, gagnant;
  Mix_Music *musique; //Création d'un pointeur de type Mix_Music
  Mix_VolumeMusic(MIX_MAX_VOLUME);
  musique = Mix_LoadMUS("../Music/Mini-jeux/tictactoe.ogg"); //Chargement de la musique
  Mix_PlayMusic(musique, -1); //Jouer infiniment la musique

  //Chargement des images croix et rond
  croix = IMG_Load("../images/Mini-jeux/croix.jpg");
  rond = IMG_Load("../images/Mini-jeux/rond.jpg");
  //Chargement de la police
  police1 = TTF_OpenFont("../Police/chata.ttf", 65);
  police2 = TTF_OpenFont("../Police/chata.ttf", 25);

  //Initialisation du texte
  texte1 = TTF_RenderText_Shaded(police1, "Tic Tac Toe", couleurNoire, couleurBlanche);
  texte2 = TTF_RenderText_Shaded(police2, "Appuyer sur entrer pour commencer", couleurNoire, couleurBlanche);

  //Remplissage de l'écran principal avec la couleur blanche
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

  //Initialisation des position des différentes surfaces et textes
  positiontexte1.x = (ecran->w - texte1->w) / 2;
  positiontexte1.y = 50;
  positiontexte2.x = (ecran->w - texte2->w) / 2;
  positiontexte2.y = 150 + (ecran->h - texte2->h) / 2;
  positioncroix.x = (ecran->w / 2) - croix->w*2;
  positioncroix.y = (ecran->h / 2) - croix->h;
  positionrond.x = (ecran->w / 2) + rond->w;
  positionrond.y = (ecran->h / 2) - rond->h;

  //Blit du texte de la page d'accueil
  SDL_BlitSurface(texte1, NULL, ecran, &positiontexte1);
  SDL_BlitSurface(texte2, NULL, ecran, &positiontexte2);

  //Blit des images
  SDL_BlitSurface(croix, NULL, ecran, &positioncroix);
  SDL_BlitSurface(rond, NULL, ecran, &positionrond);

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
      if(event.key.keysym.sym == SDLK_RETURN)  gagnant = Jouer_Tictactoe(ecran,j1,j2);
      continuer = 0;
      break;
    default: break;
    }
  }

  //Libération de la mémoire occupée par les surfaces et les polices et arrêt de la SDL
  TTF_CloseFont(police1);
  TTF_CloseFont(police2);
  SDL_FreeSurface(rond);
  SDL_FreeSurface(croix);
  SDL_FreeSurface(texte1);
  SDL_FreeSurface(texte2);
  Mix_FreeMusic(musique); //Libération de la musique

  return gagnant;
}
