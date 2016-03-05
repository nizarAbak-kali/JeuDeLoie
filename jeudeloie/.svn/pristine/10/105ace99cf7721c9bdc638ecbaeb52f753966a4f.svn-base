#include "../headers/bibliotheque.h"


/********************  Affichage des règles du jeu  ********************/

void affiche_Regle(SDL_Surface *ecran,TTF_Font *police,TTF_Font *font1)
{

  /**********  Déclaration des variables SDL  *********/
  
  SDL_Surface *texte=NULL,*texte2=NULL,*fond=NULL;
  SDL_Rect position,postexte2;
  SDL_Event event;
  SDL_Color couleur;
  FILE* regle=NULL;
  char ligne[1024]="";
  int continuer=1;
  

  couleur.r=0;
  couleur.g=0;
  couleur.b=255;

  fond=IMG_Load("../images/regle.png");
  regle=fopen("../carte/regle.txt","r");
  
  /**********  Ecriture dans la surface texte2  **********/
  TTF_SetFontStyle(police,TTF_STYLE_UNDERLINE);
  texte2=TTF_RenderText_Blended(police,"REGLES DU JEU",couleur);
  TTF_SetFontStyle(police,TTF_STYLE_NORMAL);

  /**********  Remplissage de l'écran  **********/
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,100,100,100));
  SDL_BlitSurface(fond,NULL,ecran,NULL);

  /**********  Initialisation des positions  **********/
  
  position.x=100;
  position.y=75;
  postexte2.x=(ecran->w /2)-(texte2->w /2);
  postexte2.y=25;

  /**********  Boucle pour mettre le programme en pause  **********/
  
  while(continuer)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
	{
	case SDL_KEYDOWN:
	  if(event.key.keysym.sym == SDLK_BACKSPACE)
	    continuer=0;
	  break;
	}
      
      /********** Blittage de la règle du jeu **********/
      
      SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
      
      /**********  Boucle de lecture du fichier regle  **********/
      
      while(fgets(ligne,sizeof(ligne),regle) != NULL)
	{
	  texte=TTF_RenderText_Blended(font1,ligne,couleur);
	  SDL_BlitSurface(texte,NULL,ecran,&position);
	  position.y+=25;//espace entre chaque ligne
	}
      
      /*********  Nettoyage de l'ecran  **********/
      SDL_Flip(ecran);
    }
  
  /**********  Libération des espaces alloués  *********/
  
  fclose(regle);
  SDL_FreeSurface(fond);
  SDL_FreeSurface(texte2);
  SDL_FreeSurface(texte);
}


/**********  Affichage des commandes du jeu  **********/

void affiche_Commande(SDL_Surface *ecran,TTF_Font *police1,TTF_Font *police2)
{
  SDL_Surface *texte1=NULL,*texte2=NULL,*fond=NULL;
  SDL_Event event;
  SDL_Rect position1,position2;
  SDL_Color couleur;
  FILE* commande=NULL;
  char ligne[1024];
  int continuer=1;

  /**********  Initialisation des variables  **********/
  
  couleur.r=0;
  couleur.g=0;
  couleur.b=0;
  
  fond=IMG_Load("../images/regle.png");
  commande=fopen("../carte/commande.txt","r");
  TTF_SetFontStyle(police1,TTF_STYLE_UNDERLINE);
  texte1=TTF_RenderText_Blended(police1,"COMMANDES DU JEU",couleur);
  TTF_SetFontStyle(police1,TTF_STYLE_NORMAL);

  position1.x=(ecran->w / 2)-(texte1->w / 2);
  position1.y=25;
  position2.x=100;
  position2.y=75;

  /**********  Remplissage de l'ecran  **********/
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,100,100,100));
  SDL_BlitSurface(fond,NULL,ecran,NULL);

  while(continuer)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
	{
	case SDL_KEYDOWN:
	  if(event.key.keysym.sym == SDLK_BACKSPACE)
	    continuer=0;
	  break;
	}
  
      /**********  Blit des surfaces  **********/
      SDL_BlitSurface(texte1,NULL,ecran,&position1);
      
      /**********  Boucle de lecture du fichier commande  **********/
      
      while(fgets(ligne,1024,commande) != NULL)
	{
	  texte2=TTF_RenderText_Blended(police2,ligne,couleur);
	  SDL_BlitSurface(texte2,NULL,ecran,&position2);
	  position2.y+=25;//espace entre chaque ligne
	}
      
      /*********  Nettoyage de l'ecran  **********/
      SDL_Flip(ecran);
    }
  /**********  Libération des espaces alloués  *********/
  
  fclose(commande);
  SDL_FreeSurface(fond);
  SDL_FreeSurface(texte1);
  SDL_FreeSurface(texte2);
}
