/* Réalsation de programme 
   Version du 05/03/2013 22:00
*/


#include "../headers/bibliotheque.h"

/*
 *menu_1=Acceuil
 *menu_2=Menu Principal
 *menu_3=Menu_Jouer
 *menu_4=Option
 *menu_5=Règles
 *menu_6=Gestion Son
 */
  



/********************  Chargement de la fenêtre d'accueil  ********************/

void charge_Menu1(SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2)
{
  
  SDL_Surface *acceuil=IMG_Load("../images/accueil.png");
  SDL_Surface *texte=NULL ,*texte2=NULL;
  SDL_Rect positiontexte,positiontexte2;
  SDL_Color couleurtexte;
  
  /* Initialisation de la couleur */
  couleurtexte.r = 0;
  couleurtexte.g = 0;
  couleurtexte.b = 0;
  
  /* Ecriture du texte dans la fenêtre d'acceuil */
  
  texte=TTF_RenderText_Blended(font2,"JEU DE L'OIE REVISITE",couleurtexte);
  texte2=TTF_RenderText_Blended(font1,"Appuyez sur entree pour continuer",couleurtexte);
  
  /* Initialisation des positions */

  positiontexte.x=(ecran->w / 2)-(texte->w / 2);
  positiontexte.y=50;
  positiontexte2.x=(ecran->w / 2)-(texte2->w / 2);
  positiontexte2.y=450;

  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
  SDL_BlitSurface(acceuil,NULL,ecran,NULL);
  SDL_BlitSurface(texte,NULL,ecran,&positiontexte);
  SDL_BlitSurface(texte2,NULL,ecran,&positiontexte2);  
  SDL_Flip(ecran);
  
  
  /* Libération des espaces alloués */

  SDL_FreeSurface(acceuil);
  SDL_FreeSurface(texte);
  SDL_FreeSurface(texte2);
}


/********************  Chargement du menu Principal  ********************/

void charge_Menu2 (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2)
{
  SDL_Surface *menuprincipal=IMG_Load("../images/accueil.png");
  SDL_Surface *jouer=NULL,*options=NULL,*regles=NULL,*editer=NULL,*quitter=NULL,*textemenu=NULL;
  SDL_Rect posjouer,posoption,posregle,posediter,posquitter,posmenu;
  SDL_Color couleurtexte;
  
  /* Initialisation de la couleur */
  couleurtexte.r = 0;
  couleurtexte.g = 0;
  couleurtexte.b = 0;

  /**********  Ecriture dans les différentes surfaces  **********/
  
  TTF_SetFontStyle(font2,TTF_STYLE_UNDERLINE);
  textemenu=TTF_RenderText_Blended(font2,"MENU PRINCIPAL",couleurtexte);
  TTF_SetFontStyle(font2,TTF_STYLE_NORMAL);
  
  jouer=TTF_RenderText_Blended(font1,"JOUER",couleurtexte);
  options=TTF_RenderText_Blended(font1,"OPTIONS",couleurtexte);
  regles=TTF_RenderText_Blended(font1,"REGLES",couleurtexte);
  editer=TTF_RenderText_Blended(font1,"EDITER",couleurtexte);
  quitter=TTF_RenderText_Blended(font1,"QUITTER",couleurtexte);
 
  /* Teste de la police en fonction des choix de l'utilisateur */
  
  if (Bool == 0)
    {
      jouer=TTF_RenderText_Blended(font2,"JOUER",couleurtexte);
    }
  else if (Bool == 1)
    {
      options=TTF_RenderText_Blended(font2,"OPTIONS",couleurtexte);
    }
  else if(Bool == 2)
    {
      regles=TTF_RenderText_Blended(font2,"REGLES",couleurtexte);
    }
  else if(Bool == 3)
    {
      editer=TTF_RenderText_Blended(font2,"EDITER",couleurtexte);
    }
  
  else
    {
      quitter=TTF_RenderText_Blended(font2,"QUITTER",couleurtexte);
    }
  
  /* Initialisation des positions des textes */
  
  posmenu.x=(ecran->w /2)-(textemenu->w / 2);
  posmenu.y=25;
  posjouer.x=(ecran->w / 2)-(jouer->w / 2);
  posjouer.y=105;
  posoption.x=(ecran->w / 2)-(options->w / 2);
  posoption.y=200;
  posregle.x=(ecran->w / 2)-(regles->w / 2);
  posregle.y=295;
  posediter.x=(ecran->w / 2)-(editer->w / 2);
  posediter.y=390;
  posquitter.x=(ecran->w / 2)-(quitter->w / 2);
  posquitter.y=485;

  /* Affichage des surfaces */

  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
  
 
  SDL_BlitSurface(menuprincipal,NULL,ecran,NULL);
  SDL_BlitSurface(textemenu,NULL,ecran,&posmenu);
  SDL_BlitSurface(jouer,NULL,ecran,&posjouer);
  SDL_BlitSurface(options,NULL,ecran,&posoption);
  SDL_BlitSurface(regles,NULL,ecran,&posregle);
  SDL_BlitSurface(editer,NULL,ecran,&posediter);
  SDL_BlitSurface(quitter,NULL,ecran,&posquitter);
  SDL_Flip(ecran);

  /* Libération des espaces alloués */
  
  SDL_FreeSurface(textemenu);
  SDL_FreeSurface(menuprincipal);
  SDL_FreeSurface(jouer);
  SDL_FreeSurface(options);
  SDL_FreeSurface(regles);
  SDL_FreeSurface(editer);
  SDL_FreeSurface(quitter);
}
  
/********************  Chargement du menu jouer  ********************/

void charge_Menu3 (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2)
{
  SDL_Surface *menujouer=IMG_Load("../images/ecran.png");//Par défault en attendant les autres images
  SDL_Surface *texte=NULL,*texte2=NULL;
  SDL_Color couleurtexte;
  SDL_Rect postexte,postexte2;

  /* Initialisation de la couleur */
  couleurtexte.r=0;
  couleurtexte.g=0;
  couleurtexte.b=0;

  /**********  Ecriture du texte dans les différentes surfaces  **********/
  
  texte=TTF_RenderText_Blended(font1,"Nouvelle Partie",couleurtexte);
  texte2=TTF_RenderText_Blended(font1,"Charger Partie",couleurtexte);
  
  /*Teste pour l'agrandissement de la police en fonction du choix de l'utilisateur */
  
  if (Bool == 0)
    {
      texte=TTF_RenderText_Blended(font2,"Nouvelle Partie",couleurtexte);
    }
  else
    {
      texte2=TTF_RenderText_Blended(font2,"Charger Partie",couleurtexte);
    }
  
  /* Initialisation des positions */
  
  postexte.x=(ecran->w / 2)- (texte->w / 2);
  postexte.y=200;
  postexte2.x=(ecran->w / 2)- (texte2->w / 2);
  postexte2.y=400;
  
  /* Affichage des images */
  
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
  SDL_BlitSurface(menujouer,NULL,ecran,NULL);
  SDL_BlitSurface(texte,NULL,ecran,&postexte);
  SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
  SDL_Flip(ecran);

  /* Libération des espaces alloués */

  SDL_FreeSurface(menujouer);
  SDL_FreeSurface(texte);
  SDL_FreeSurface(texte2);
}


/********************  Chargement du menu options  ********************/

void charge_Menu4 (SDL_Surface *ecran,TTF_Font *font2)
{
  SDL_Surface *options=IMG_Load("../images/ecran.png");//en attendant...
  SDL_Surface *texte=NULL;
  SDL_Color couleurtexte;
  SDL_Rect postexte;

  /* Initialisation de la couleur */
  couleurtexte.r=0;
  couleurtexte.g=0;
  couleurtexte.b=0;

  
  texte=TTF_RenderText_Blended(font2,"Gestion du Son",couleurtexte);

  /* Initialisation des positions */
  
 
  postexte.x=(ecran->w / 2)- (texte->w / 2);
  postexte.y=(ecran->h / 2)- (texte->h / 2);

  /* Affichage des images */
  
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
  SDL_BlitSurface(options,NULL,ecran,NULL);
  SDL_BlitSurface(texte,NULL,ecran,&postexte);
  SDL_Flip(ecran);

  /* Libération des espaces alloués */

  SDL_FreeSurface(options);
  SDL_FreeSurface(texte);
  
}


/********************  Chargement du menu règles *******************/

void charge_Menu5 (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2)
{
  SDL_Surface *regles=IMG_Load("../images/ecran.png");
  SDL_Surface *texte1=NULL,*texte2=NULL,*txt=NULL;
  SDL_Color couleurtexte,couleur;
  SDL_Rect postxt,postexte1,postexte2;

  /* Initialisation de la couleur */
  couleurtexte.r=0;
  couleurtexte.g=0;
  couleurtexte.b=0;

  couleur.r=100;
  couleur.g=100;
  couleur.b=100;

  /**********  Ecriture du texte  **********/
  
  TTF_SetFontStyle(font2,TTF_STYLE_UNDERLINE);
  txt=TTF_RenderText_Blended(font2,"REGLE ET COMMANDES",couleur);
  TTF_SetFontStyle(font2,TTF_STYLE_NORMAL);
  texte1=TTF_RenderText_Blended(font1,"Commandes du jeu",couleurtexte);
  texte2=TTF_RenderText_Blended(font1,"Regles du jeu",couleurtexte);

  /*Teste pour l'agrandissement de la police en fonction du choix de l'utilisateur */

  if (Bool == 0)
    {
      texte1=TTF_RenderText_Blended(font2,"Commandes du jeu",couleurtexte);
    }
  else
    {
      texte2=TTF_RenderText_Blended(font2,"Regles du jeu",couleurtexte);
    }
  
  /* Initialisation des positions */
  
  postxt.x=(ecran->w / 2)-(txt->w /2);
  postxt.y=50;
  postexte1.x=(ecran->w / 2)- (texte1->w / 2);
  postexte1.y=200;
  postexte2.x=(ecran->w / 2)- (texte2->w / 2);
  postexte2.y=400;

  /* Affichage des images */
  
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
  
  SDL_BlitSurface(regles,NULL,ecran,NULL);
  SDL_BlitSurface(txt,NULL,ecran,&postxt);
  SDL_BlitSurface(texte1,NULL,ecran,&postexte1);
  SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
  SDL_Flip(ecran);

  /* Libération des espaces alloués */

  SDL_FreeSurface(txt);
  SDL_FreeSurface(regles);
  SDL_FreeSurface(texte1);
  SDL_FreeSurface(texte2);
  
}


/********************  Gestionnaire du Son *******************/

void charge_Menu6 (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2,int *ptr)
{
  /**********  Déclaration des variables  **********/
  
  SDL_Surface *fond=NULL,*texte1=NULL,*texte2=NULL,*txt=NULL;
  SDL_Color couleur,couleur2;
  SDL_Rect postxt,position1,position2;
 
  /**********  Initialisation des variables  **********/
  
  couleur.r=0;
  couleur.g=0;
  couleur.b=0;

  couleur2.r=100;
  couleur2.g=100;
  couleur2.b=100;

  fond=IMG_Load("../images/ecran.png");
  
  /**********  Ecriture dans les différentes surfaces  **********/
  
  TTF_SetFontStyle(font2,TTF_STYLE_UNDERLINE);
  txt=TTF_RenderText_Blended(font2,"GESTION DU SON",couleur2);
  TTF_SetFontStyle(font2,TTF_STYLE_NORMAL);
  
  texte1=TTF_RenderText_Blended(font1,"Son      < ON >",couleur);
  texte2=TTF_RenderText_Blended(font1," Volume ",couleur);
  
  /**********  Initialisation des positions  **********/
  
  postxt.x=(ecran->w / 2)-(txt->w / 2);
  postxt.y=50;
  position1.x=(ecran->w / 2)-(texte1->w / 2);
  position1.y=250;
  position2.x=(ecran->w / 2)-(texte1->w / 2);
  position2.y=350;


  /* Teste pour l'agrandissement de la police et modification des surfaces */
  
  if (Bool == 0)
    {
      if (*ptr == 1)
	{
	  texte1=TTF_RenderText_Blended(font2,"Son      < ON >",couleur);
	}
      else
	{
	  texte1=TTF_RenderText_Blended(font2,"Son      < OFF >",couleur);
	}
    }
  else
    {
      if(*ptr == 1)
	{
	  texte1=TTF_RenderText_Blended(font1,"Son      < ON >",couleur);
	  texte2=TTF_RenderText_Blended(font2," Volume ",couleur);
	}
      else
	{
	  texte1=TTF_RenderText_Blended(font1,"Son      < OFF >",couleur);
	  texte2=TTF_RenderText_Blended(font2," Volume ",couleur);
	}
    }
  
  
  /********** Remplissage de l'écran  ********/
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
  
  
  /********** Blit des surfaces  **********/
  
  SDL_BlitSurface(fond,NULL,ecran,NULL);
  SDL_BlitSurface(txt,NULL,ecran,&postxt);
  SDL_BlitSurface(texte1,NULL,ecran,&position1);
  SDL_BlitSurface(texte2,NULL,ecran,&position2);
  SDL_Flip(ecran);

  /*********  Libération des surfaces  ***********/
  
  SDL_FreeSurface(fond);
  SDL_FreeSurface(txt);
  SDL_FreeSurface(texte1);
  SDL_FreeSurface(texte2);
  
}


/******************************  Gestion_Du_volume  ******************************/

void charge_Menu7(SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2)
{
  /**********  Initialisation des surfaces  **********/
  
  SDL_Surface *fond=NULL,*texte1=NULL,*texte2=NULL,*texte3=NULL,*txt=NULL;
  SDL_Color couleur,couleur2;
  SDL_Rect postxt,postexte1,postexte2,postexte3;

  couleur.r=0;
  couleur.g=0;
  couleur.b=0;

  couleur2.r=0;
  couleur2.g=0;
  couleur2.b=0;
  
  /*********  Ecriture dans les surfaces  **********/
  
  TTF_SetFontStyle(font2,TTF_STYLE_UNDERLINE);
  txt=TTF_RenderText_Blended(font2,"GESTION DU VOLUME",couleur2);
  TTF_SetFontStyle(font2,TTF_STYLE_NORMAL);
  
  texte1=TTF_RenderText_Blended(font1,"FAIBLE",couleur);
  texte2=TTF_RenderText_Blended(font1,"MOYEN",couleur);
  texte3=TTF_RenderText_Blended(font1,"FORT",couleur);
  

  /********* Initialisation des positions  **********/

  postxt.x=(ecran->w / 2)-(txt->w / 2);
  postxt.y=50;
  postexte1.x=(ecran->w / 2)-(texte1->w / 2);
  postexte1.y=250;
  postexte2.x=(ecran->w / 2)-(texte2->w / 2);
  postexte2.y=350;
  postexte3.x=(ecran->w / 2)-(texte3->w / 2);
  postexte3.y=450;

  /********** Test pour l'agrandissement en fonction du choix de l'utilisateur  **********/

  if(Bool == 0)
    {
      texte1=TTF_RenderText_Blended(font2,"FAIBLE",couleur);
    }
  else if(Bool == 1)
    {
      texte2=TTF_RenderText_Blended(font2,"MOYEN",couleur);
    }
  else
    {
      texte3=TTF_RenderText_Blended(font2,"FORT",couleur);
    }

  
  fond=IMG_Load("../images/ecran.png");
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
  
  /**********  Blit des surfaces  **********/
  SDL_BlitSurface(fond,NULL,ecran,NULL);
  SDL_BlitSurface(txt,NULL,ecran,&postxt);
  SDL_BlitSurface(texte1,NULL,ecran,&postexte1);
  SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
  SDL_BlitSurface(texte3,NULL,ecran,&postexte3);
  SDL_Flip(ecran);

  /**********  Libération des surfaces  **********/

  SDL_FreeSurface(fond);
  SDL_FreeSurface(txt);
  SDL_FreeSurface(texte1);
  SDL_FreeSurface(texte2);
  SDL_FreeSurface(texte3);
  
}
