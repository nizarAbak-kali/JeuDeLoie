/*
nb_mysterieux.c
----------

Par Nouira Chafik 11291558, pour le projet "Jeu de l'oie Revisité" - Réalisation de programmes Semestre 2 2012/2013

Rôle : Jeu du "Nombre Mystérieux" en SDL
*/


#include "../headers/bibliotheque_mini_jeux.h"

int Jouer_Nb_Mysterieux(SDL_Surface *ecran, char j1[], char j2[]) {
  SDL_Surface *texte1 = NULL, *texte2 = NULL, *essai = NULL, *joueur = NULL;
  SDL_Rect position_texte1 = {10,50,0,0}, position_texte2, position_essai={230,150,0,0}, positionjoueur;
  SDL_Rect position_coups_rates = {10,500,0,0};
  SDL_Event event;
  TTF_Font *police = NULL, *police2 = NULL;
  SDL_Color couleurNoire = {0, 0, 0, 0};
  int nb_mysterieux, continuer, coup, coups_rates, joueuractuel=1, joueur1, joueur2, j=0;
  char ch[30], ch2[10], chj[30];
  Mix_Chunk *son; 
  son = Mix_LoadWAV("../Music/Mini-jeux/coup_nb_mysterieux.ogg");

  srand(time(NULL));

  positionjoueur.x = 50;
  positionjoueur.y = 100;
  
  //Chargement de la police
  police = TTF_OpenFont("../Police/tanglewo.ttf", 37);
  police2 = TTF_OpenFont("../Police/comicbd.ttf", 30);
  texte1 = TTF_RenderText_Blended(police, "Nombre mysterieux entre 1 et 10000", couleurNoire);


 debut:
  coups_rates = 0;
  position_texte2.x = 200;
  position_texte2.y = 300;
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 55, 151, 208));
  j++; coup = 0; continuer = 1;
  strcpy(ch2,"");
  coups_rates = 0;
  nb_mysterieux = rand()%10000+1;
  if(joueuractuel == 1) sprintf(chj,"Joueur : %s",j1);
  else sprintf(chj,"Joueur : %s",j2);
  joueur = TTF_RenderText_Blended(police,chj, couleurNoire);
  while(continuer) {
    SDL_WaitEvent(&event);
    switch(event.type) {
      //En cas de fermeture de la fenêtre
      case SDL_QUIT: continuer = 0; return 0; break;
      case SDL_KEYDOWN : 	  
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 55, 151, 208));
        switch(event.key.keysym.sym) {
	  case SDLK_BACKSPACE : coup /= 10; break;
	  case SDLK_KP0: coup = (coup*10); break;
	  case SDLK_KP1: coup = (coup*10) + 1; break;
	  case SDLK_KP2: coup = (coup*10) + 2; break;
	  case SDLK_KP3: coup = (coup*10) + 3; break;
	  case SDLK_KP4: coup = (coup*10) + 4; break;
	  case SDLK_KP5: coup = (coup*10) + 5; break;
          case SDLK_KP6: coup = (coup*10) + 6; break;
          case SDLK_KP7: coup = (coup*10) + 7; break;
          case SDLK_KP8: coup = (coup*10) + 8; break;
          case SDLK_KP9: coup = (coup*10) + 9; break;
	  case SDLK_RETURN :
            if(coup == nb_mysterieux) {
	      if(joueuractuel == 1) {joueuractuel = 2; joueur1 = coups_rates; sprintf(ch,"Bravo ! Nb de coups %d",joueur1);}
	      else {joueuractuel = 1; joueur2 = coups_rates; sprintf(ch,"Bravo ! Nb de coups %d",joueur2);}
	      position_texte2.x = 100;
	      continuer = 0;
	      texte2 = TTF_RenderText_Blended(police2,ch, couleurNoire);
	      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 55, 151, 208));
	      SDL_BlitSurface(texte2,NULL, ecran, &position_texte2);
	    }
	    else if(coup > nb_mysterieux && coup) {
	      Mix_PlayChannel(1,son,0);
	      sprintf(ch,"Plus petit !"); coups_rates++; coup = 0;
	      texte2 = TTF_RenderText_Blended(police2,ch, couleurNoire);
	      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 55, 151, 208));
	      SDL_BlitSurface(texte2,NULL, ecran, &position_texte2);
	      SDL_BlitSurface(essai,NULL, ecran, &position_essai);
	    }
	    else if(coup < nb_mysterieux && coup) {
	      Mix_PlayChannel(1,son,0);
	      sprintf(ch,"Plus grand !"); coups_rates++; coup = 0;
	      texte2 = TTF_RenderText_Blended(police2,ch, couleurNoire);
	      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 55, 151, 208));
	      SDL_BlitSurface(texte2,NULL, ecran, &position_texte2);
	      SDL_BlitSurface(essai,NULL, ecran, &position_essai);
	    }
          default : break;
	}
	break;
	default : break;
    }

    sprintf(ch2,"%d",coup);
    essai = TTF_RenderText_Blended(police2,ch2,couleurNoire);
    sprintf(ch,"Nombre de Coups rates : %d",coups_rates);
    texte2 = TTF_RenderText_Blended(police2,ch, couleurNoire);
    SDL_BlitSurface(texte1,NULL, ecran, &position_texte1);
    SDL_BlitSurface(texte2,NULL, ecran, &position_coups_rates);
    SDL_BlitSurface(joueur,NULL, ecran, &positionjoueur);
    if(coup)
      SDL_BlitSurface(essai,NULL, ecran, &position_essai);
    SDL_Flip(ecran);
  }
  sleep(2);

  if(joueur1 == joueur2 || j&1) goto debut;

  SDL_FreeSurface(texte1);
  SDL_FreeSurface(texte2);
  SDL_FreeSurface(essai);
  Mix_FreeChunk(son);//Libération du son

  if(joueur1 > joueur2) return 2;
  else return 1;
}


/*Cette fonction sert de page d'accueil du jeu Puissance 4, elle fait appel à la fonction Jouer_Puissance_4 quand l'utilisateur
  appuie sur "Entrer"*/
int Accueil_Nb_Mysterieux(SDL_Surface *ecran, char j1[], char j2[]) {

  //Déclaration des variables locales nécessaires pour la fonction.
  SDL_Surface *texte1 = NULL, *texte2 = NULL, *image = NULL;
  SDL_Rect positiontexte1, positiontexte2, positionimage;
  SDL_Event event;
  TTF_Font *police1 = NULL, *police2 = NULL;
  SDL_Color couleurNoire = {0, 0, 0, 0}, couleurBlanche = {255, 255, 255, 0};
  int continuer = 1, gagnant;
  Mix_Music *musique; //Création d'un pointeur de type Mix_Music
  Mix_VolumeMusic(MIX_MAX_VOLUME / 3);
  musique = Mix_LoadMUS("../Music/Mini-jeux/nb_mysterieux.ogg"); //Chargement de la musique
  Mix_PlayMusic(musique, -1); //Jouer infiniment la musique

  //Chargement des images noir, orange et 4
  image = IMG_Load("../images/Mini-jeux/nb_mysterieux.jpg");

  //Chargement de la police
  police1 = TTF_OpenFont("../Police/chata.ttf", 50);
  police2 = TTF_OpenFont("../Police/chata.ttf", 25);

  //Initialisation du texte
  texte1 = TTF_RenderText_Shaded(police1, "Nombre Mysterieux", couleurNoire, couleurBlanche);
  texte2 = TTF_RenderText_Shaded(police2, "Appuyer sur entrer pour commencer", couleurNoire, couleurBlanche);

  SDL_SetColorKey(texte1, SDL_SRCCOLORKEY, SDL_MapRGB(texte1->format, 255, 255, 255));
  SDL_SetColorKey(texte2, SDL_SRCCOLORKEY, SDL_MapRGB(texte2->format, 255, 255, 255));

  //Remplissage de l'écran principal avec la couleur blanche
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 200, 100));

  //Initialisation des position des différentes surfaces et textes
  positiontexte1.x = (ecran->w - texte1->w) / 2;
  positiontexte1.y = 0;
  positiontexte2.x = (ecran->w - texte2->w) / 2;
  positiontexte2.y = 250 + (ecran->h - texte2->h) / 2;
  positionimage.x = (ecran->w / 2) - (image->w / 2);
  positionimage.y = (ecran->h / 2) - (image->h / 2);

  //Remplissage de l'écran principal avec la couleur blanche
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 200, 100));

  //Blit du texte de la page d'accueil
  SDL_BlitSurface(texte1, NULL, ecran, &positiontexte1);
  SDL_BlitSurface(texte2, NULL, ecran, &positiontexte2);

  //Blit des images
  SDL_BlitSurface(image, NULL, ecran, &positionimage);

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
      if(event.key.keysym.sym == SDLK_RETURN) gagnant = Jouer_Nb_Mysterieux(ecran,j1,j2);
      continuer = 0;
      break;
    default: break;
    }
  }

  //Libération de la mémoire occupée par les surfaces et les polices et arrêt de la SDL
  TTF_CloseFont(police1);
  TTF_CloseFont(police2);
  SDL_FreeSurface(image);
  SDL_FreeSurface(texte1);
  SDL_FreeSurface(texte2);
  Mix_FreeMusic(musique); //Libération de la musique

  return gagnant;
}
