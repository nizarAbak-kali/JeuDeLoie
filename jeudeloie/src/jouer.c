#include "../headers/bibliotheque.h"
#include "puissance_4.c"
#include "tictactoe.c"
#include "pendu.c"
#include "nb_mysterieux.c"
#include "pong.c"

/**********************Fichiers.c*********************************/

void nom_Fichier(SDL_Surface *ecran, char nom[]) {
  /******  Déclaration des variables  *****/

  SDL_Surface *fond=NULL,*texte=NULL,*_nom=NULL;
  SDL_Rect postexte,posnom;
  TTF_Font *font1=TTF_OpenFont("../Police/comicbd.ttf",35);
  TTF_Font *font2=TTF_OpenFont("../Police/comicbd.ttf",30);
  SDL_Color couleur = {0,0,0,0};
  SDL_Event event;
  int continuer=1;
  char c=' ';
  int k=0,i;

  /*****  Initialisation du nom  *****/  
  for(i=0;i<10;i++)
    nom[i]='_';
  nom[i]='\0';
  
  fond=IMG_Load("../images/ecran.png");
  texte=TTF_RenderText_Blended(font1,"Entrez le Nom du Fichier",couleur);
  _nom=TTF_RenderText_Blended(font1,nom,couleur);

  postexte.x=(ecran->w / 2)-(texte->w /2);
  postexte.y=50;
  posnom.x=(ecran->w /2 )-(_nom->w /2);
  posnom.y=250;

  /*****  Nettoyage de l'écran et des blits des surfaces  *****/
  
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,100,100,100));
  SDL_BlitSurface(fond,NULL,ecran,NULL);
  SDL_BlitSurface(texte,NULL,ecran,&postexte);
  SDL_BlitSurface(_nom,NULL,ecran,&posnom);
  SDL_Flip(ecran);
  
  /*****  Boucle de saisie des noms  *****/
  
  while(continuer) {
    SDL_WaitEvent(&event);
    switch(event.type){
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym) {
        case SDLK_RETURN:
	  if(k > 0) { 
	    k=10;
	    continuer=0;
	  }
	  break;	    
	  default:c=event.key.keysym.sym;break;
      }	    

      if((k < 10  && c >= 'a'  && c<='z')) {
	nom[k]=c;
	_nom=TTF_RenderText_Blended(font2,nom,couleur);
	k++;
      }
	    
      if(k > 0 && c == '\b') {
	nom[k-1]='_';
	_nom=TTF_RenderText_Blended(font2,nom,couleur);
	k--;
      }
      break;      
    default:break;
	
    }
      
      /*****  Raffraichissement de l'écran après saisie des premières lettres  *****/
      SDL_BlitSurface(fond,NULL,ecran,NULL);
      SDL_BlitSurface(texte,NULL,ecran,&postexte);
      SDL_BlitSurface(_nom,NULL,ecran,&posnom);
      SDL_Flip(ecran);
      
    }//fin de la boucle while

  for(i = 9; nom[i] == '_'; i--);
  nom[i+1] = '\0';
  
  /***** Libération des surfaces *****/
  SDL_FreeSurface(fond);
  SDL_FreeSurface(texte);
  SDL_FreeSurface(_nom);  
}

int sauvegarder_Partie(SDL_Surface *ecran, char nom_fichier[], Joueur joueurs[], int num_carte, int nb_joueurs) {
  FILE *fichier = NULL, *nb_parties = NULL;
  int i, nb;
  char ch1[10], ch2[10], ch3[10], ch4[10], ch5[10];

  nb_parties = fopen("nb_parties.txt","r+");
  fscanf(nb_parties,"%d\n",&nb);
  
  for(i = 1; i <= nb; i++) {
    switch(i) {
    case 1: fscanf(nb_parties,"%s\n",ch1); break;
    case 2: fscanf(nb_parties,"%s\n",ch2); break;
    case 3: fscanf(nb_parties,"%s\n",ch3); break;
    case 4: fscanf(nb_parties,"%s\n",ch4); break;
    case 5: fscanf(nb_parties,"%s\n",ch5); break;
    default : break;
    }
  }
  
  fclose(nb_parties);
  nb++;

  if(nb <= 5) {
    nb_parties = fopen("nb_parties.txt","w+");
    fprintf(nb_parties,"%d\n",nb);
  }

  if(nb <= 5) {
    nom_Fichier(ecran,nom_fichier);
    for(i = 1; i <= nb-1; i++) {
      switch(i) {
      case 1: fprintf(nb_parties,"%s\n",ch1); break;
      case 2: fprintf(nb_parties,"%s\n",ch2); break;
      case 3: fprintf(nb_parties,"%s\n",ch3); break;
      case 4: fprintf(nb_parties,"%s\n",ch4); break;
      case 5: fprintf(nb_parties,"%s\n",ch5); break;
      default : break;
      }
    }
    fprintf(nb_parties,"%s\n",nom_fichier);
    fichier = fopen(nom_fichier,"w+");
    fprintf(fichier,"%s\n",nom_fichier);
    fprintf(fichier,"%d\n",num_carte);
    fprintf(fichier,"%d\n",nb_joueurs);
    for (i = 0; i < nb_joueurs; i++) {
      fprintf(fichier,"%d\n",joueurs[i].pos);
      fprintf(fichier,"%s\n",joueurs[i].nom);
      fprintf(fichier,"%d\n",joueurs[i].prison);
      fprintf(fichier,"%d\n",joueurs[i].score);
    }
    fclose(fichier);
    return 1;
  }
  return 0;
}




void menu_Exit(SDL_Surface *ecran, Joueur joueurs[], int num_carte, int nb_joueurs) {
  SDL_Surface *option1 = NULL, *option2 = NULL, *exit = NULL;
  SDL_Rect positionexit = {150,20,0,0}, positionoption1, positionoption2;
  TTF_Font *font1=TTF_OpenFont("../Police/comicbd.ttf",20);
  TTF_Font *font2=TTF_OpenFont("../Police/comicbd.ttf",35);
  SDL_Color couleurtexte = {0,0,0,0};
  SDL_Event event;
  int continuer = 1, bool = 1;  
  char nom_fichier[15];

  exit = IMG_Load("../images/exit.jpg");

  positionoption1.x = 50;
  positionoption1.y = 350;
  positionoption2.x = 50;
  positionoption2.y = 450;
 
  while(continuer) {
    SDL_WaitEvent(&event);

    switch(event.type) {
      case SDL_KEYDOWN : 
        switch(event.key.keysym.sym) {
          case SDLK_UP : if(bool == 1) bool = 2; else bool = 1; break;
          case SDLK_DOWN : if(bool == 1) bool = 2; else bool = 1; break;
	  case SDLK_RETURN : if(bool == 1) {
	                       if(!sauvegarder_Partie(ecran,nom_fichier,joueurs,num_carte,nb_joueurs)) {
				 option1 = TTF_RenderText_Blended(font2,"5 Sauvegardes Maximum",couleurtexte);
				 SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
 				 SDL_BlitSurface(exit,NULL,ecran,&positionexit);
				 SDL_BlitSurface(option1,NULL,ecran,&positionoption1);
				 SDL_Flip(ecran);
                               }
			       else {
				 option1 = TTF_RenderText_Blended(font2,"Sauvegarde Reussie",couleurtexte);
				 SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
 				 SDL_BlitSurface(exit,NULL,ecran,&positionexit);
				 SDL_BlitSurface(option1,NULL,ecran,&positionoption1);
				 SDL_Flip(ecran);
			       }
			       continuer = 0;
			       SDL_Delay(1500);
	                   } 
	                   else continuer = 0; continue; break; 
          default : break;
	}
    default : break;
    }

    if (bool == 1) {
      option1 = TTF_RenderText_Blended(font2,"1 - Sauvegarder & Quitter",couleurtexte);
      option2 = TTF_RenderText_Blended(font1,"2 - Quitter Sans Sauvegarder",couleurtexte);
    }
    else {
      option1 = TTF_RenderText_Blended(font1,"1 - Sauvegarder & Quitter",couleurtexte);
      option2 = TTF_RenderText_Blended(font2,"2 - Quitter Sans Sauvegarder",couleurtexte);
    }
  
    if(continuer) {
      SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255)); 
      SDL_BlitSurface(exit,NULL,ecran,&positionexit);
      SDL_BlitSurface(option1,NULL,ecran,&positionoption1);
      SDL_BlitSurface(option2,NULL,ecran,&positionoption2);
    }
    SDL_Flip(ecran);
  }
  /* Libération des espaces alloués */
  
  SDL_FreeSurface(exit);
  SDL_FreeSurface(option1);
  SDL_FreeSurface(option2);
}




int menu_Chargement(SDL_Surface *ecran, int *num_cartechoisie, Joueur joueur[], int *nbre_joueur) {
  SDL_Surface *liste = NULL, *chargement = NULL, *sch1 = NULL, *sch2 = NULL, *sch3 = NULL, *sch4 = NULL, *sch5 = NULL;
  SDL_Rect positionchargement = {0,0,0,0}, positionliste, positionch1, positionch2, positionch3, positionch4, positionch5;
  TTF_Font *font1=TTF_OpenFont("../Police/comicbd.ttf",20);
  TTF_Font *font2=TTF_OpenFont("../Police/comicbd.ttf",35);
  SDL_Color couleurtexte = {0,0,0,0};
  SDL_Event event;
  int continuer = 1, bool = 1;
  FILE* fichier = NULL;

  /*********Chargement des Parties********/
  int i, nb;
  char ch1[10]="", ch2[10]="", ch3[10]="", ch4[10]="", ch5[10]="";
  FILE* nb_parties = nb_parties = fopen("nb_parties.txt","r+");
  fscanf(nb_parties,"%d\n",&nb);
  for(i = 1; i <= nb; i++) {
    switch(i) {
    case 1: fscanf(nb_parties,"%s\n",ch1); break;
    case 2: fscanf(nb_parties,"%s\n",ch2); break; 
    case 3: fscanf(nb_parties,"%s\n",ch3); break;
    case 4: fscanf(nb_parties,"%s\n",ch4); break;
    case 5: fscanf(nb_parties,"%s\n",ch5); break;
    default : break;
    }
  } 
  fclose(nb_parties);
  /********************************************/

  if(!nb) continuer = 0;

  chargement = IMG_Load("../images/chargement.jpg");
  liste = TTF_RenderText_Blended(font2,"Liste de Parties",couleurtexte);

  positionliste.x = 0; positionliste.y = 150;
  positionch1.x = 0; positionch1.y = 250;
  positionch2.x = 0; positionch2.y = 300;
  positionch3.x = 0; positionch3.y = 350;
  positionch4.x = 0; positionch4.y = 400;
  positionch5.x = 0; positionch5.y = 450;
 

  while(continuer) {
    SDL_WaitEvent(&event);
    switch(event.type) {
      case SDL_KEYDOWN : 
        switch(event.key.keysym.sym) {
 	  case SDLK_UP : if(bool > 1) bool--; else if(bool == 1) bool = nb; break;
	  case SDLK_DOWN : if(bool < nb) bool++; else if(bool == nb) bool = 1; break;
	  case SDLK_BACKSPACE :continuer = 0; return 0; break;
	  case SDLK_RETURN : 
	    switch(bool) {
	    case 1: fichier = fopen(ch1,"r+"); break;
	    case 2: fichier = fopen(ch2,"r+"); break;
	    case 3: fichier = fopen(ch3,"r+"); break;
	    case 4: fichier = fopen(ch4,"r+"); break;
	    case 5: fichier = fopen(ch5,"r+"); break;
	    default : break;
	    }
	    continuer = 0;
          default : break;
	}
    default : break;
    }
    sch1 = TTF_RenderText_Blended(font1,ch1,couleurtexte);
    sch2 = TTF_RenderText_Blended(font1,ch2,couleurtexte);
    sch3 = TTF_RenderText_Blended(font1,ch3,couleurtexte);
    sch4 = TTF_RenderText_Blended(font1,ch4,couleurtexte);
    sch5 = TTF_RenderText_Blended(font1,ch5,couleurtexte);    
    switch(bool) {
    case 1: sch1 = TTF_RenderText_Blended(font2,ch1,couleurtexte); break;
    case 2: sch2 = TTF_RenderText_Blended(font2,ch2,couleurtexte); break;
    case 3: sch3 = TTF_RenderText_Blended(font2,ch3,couleurtexte); break;
    case 4: sch4 = TTF_RenderText_Blended(font2,ch4,couleurtexte); break;
    case 5: sch5 = TTF_RenderText_Blended(font2,ch5,couleurtexte); break;
    default : break;
    }  
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255)); 
    SDL_BlitSurface(chargement,NULL,ecran,&positionchargement);
    SDL_BlitSurface(liste,NULL,ecran,&positionliste);
    SDL_BlitSurface(sch1,NULL,ecran,&positionch1);
    SDL_BlitSurface(sch2,NULL,ecran,&positionch2);
    SDL_BlitSurface(sch3,NULL,ecran,&positionch3);
    SDL_BlitSurface(sch4,NULL,ecran,&positionch4);
    SDL_BlitSurface(sch5,NULL,ecran,&positionch5); 
    SDL_Flip(ecran);
  }



  if(!nb) {
    liste = TTF_RenderText_Blended(font2,"Pas de Sauvegardes",couleurtexte);
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));  
    SDL_BlitSurface(chargement,NULL,ecran,&positionchargement);
    SDL_BlitSurface(liste,NULL,ecran,&positionliste);
    SDL_Flip(ecran);
    SDL_Delay(2000);
    return 0;
  }
  else {
    char chn[20];
    fscanf(fichier,"%s\n",chn);
    fscanf(fichier,"%d\n",num_cartechoisie);
    fscanf(fichier,"%d\n",nbre_joueur);
    for(i = 0; i < *nbre_joueur; i++) {
      fscanf(fichier,"%d\n",&joueur[i].pos);
      fscanf(fichier,"%s\n",joueur[i].nom);
      fscanf(fichier,"%d\n",&joueur[i].prison);
      fscanf(fichier,"%d\n",&joueur[i].score);
    }
    fclose(fichier);
    nb_parties = fopen("nb_parties.txt","w+");
    fprintf(nb_parties,"%d\n",nb-1);
    for(i = 1; i <= 5; i++) {
      if(i != bool) {
	switch(i) {
	case 1: fprintf(nb_parties,"%s\n",ch1); break;
	case 2: fprintf(nb_parties,"%s\n",ch2); break; 
	case 3: fprintf(nb_parties,"%s\n",ch3); break;
	case 4: fprintf(nb_parties,"%s\n",ch4); break;
	case 5: fprintf(nb_parties,"%s\n",ch5); break;
	default : break;
	}
      } 
    }
    fclose(nb_parties);
  }

  //Libération des espaces alloués
  SDL_FreeSurface(chargement);
  SDL_FreeSurface(liste);
  SDL_FreeSurface(sch1);
  SDL_FreeSurface(sch2);
  SDL_FreeSurface(sch3);
  SDL_FreeSurface(sch4);
  SDL_FreeSurface(sch5);
  TTF_CloseFont(font1);
  TTF_CloseFont(font2);
  return 1;
}

/******************************  Choix du nombre de joueur  ******************************/

void choix_Nb_Joueur (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2,int bool)
{
  /**********  Declaration des variables  **********/

  SDL_Surface *fond=NULL,*texte=NULL;
  SDL_Surface *nb1=NULL,*nb2=NULL,*nb3=NULL;
  SDL_Color couleur;
  SDL_Rect postexte,posnb1,posnb2,posnb3;
  
  couleur.r=0;
  couleur.g=0;
  couleur.b=0;
  
  fond=IMG_Load("../images/ecran.png");
  
  /**********  Ecriture dans les surfaces  **********/
  
  texte=TTF_RenderText_Blended(font2,"NOMBRE DE JOUEUR",couleur);
  nb1=TTF_RenderText_Blended(font1,"2",couleur);
  nb2=TTF_RenderText_Blended(font1,"3",couleur);
  nb3=TTF_RenderText_Blended(font1,"4",couleur);
  
  /**********  Positions des surfaces  *********/
  
  postexte.x=(ecran->w /2)-(texte->w / 2);
  postexte.y=50;
  posnb1.x=(ecran->w / 2)-(nb1->w /2);
  posnb1.y=200;
  posnb2.x=(ecran->w / 2)-(nb2->w /2);
  posnb2.y=300;
  posnb3.x=(ecran->w / 2)-(nb3->w /2);
  posnb3.y=400;

  /**********  Test pour l'agrandissement des surfaces  **********/
  
  if (bool == 0)
    nb1=TTF_RenderText_Blended(font2,"2",couleur);
  else if (bool == 1)
    nb2=TTF_RenderText_Blended(font2,"3",couleur);
  else
    nb3=TTF_RenderText_Blended(font2,"4",couleur);
  
  /**********  Blit des surfaces  **********/
  
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
  SDL_BlitSurface(fond,NULL,ecran,NULL);
  SDL_BlitSurface(texte,NULL,ecran,&postexte);
  SDL_BlitSurface(nb1,NULL,ecran,&posnb1);
  SDL_BlitSurface(nb2,NULL,ecran,&posnb2);
  SDL_BlitSurface(nb3,NULL,ecran,&posnb3);
  SDL_Flip(ecran);

  /**********  Liberation des surfaces  **********/

  SDL_FreeSurface(fond);
  SDL_FreeSurface(texte);
  SDL_FreeSurface(nb1);
  SDL_FreeSurface(nb2);
  SDL_FreeSurface(nb3);


}

/******************************  Gestion de la saisie des noms des joueurs  ******************************/

void saisie_Nom(SDL_Surface *ecran,int num_joueur,char *nom,TTF_Font *font1)
{
  /******  Declaration des variables  *****/

  SDL_Surface *fond=NULL,*texte=NULL,*tour_joueur=NULL,*_nom=NULL;
  SDL_Rect postexte,postour_joueur,posnom;
  SDL_Color couleur={0,0,0,0};
  SDL_Event event;
  
  int continuer=1;
  char tour[1000];
  char c=' ';
  int k=0,i;
  
  /*****  Initialisation du nom  *****/
  
  for(i=0;i<7;i++)
    nom[i]='_';
  nom[i]='\0';
  
  sprintf(tour,"Joueur %d,entrez votre nom",num_joueur + 1);
  
  fond=IMG_Load("../images/ecran.png");
  texte=TTF_RenderText_Blended(font1,"SAISIE DES NOMS",couleur);
  tour_joueur=TTF_RenderText_Blended(font1,tour,couleur);
  _nom=TTF_RenderText_Blended(font1,nom,couleur);

  postexte.x=(ecran->w / 2)-(texte->w /2);
  postexte.y=50;
  postour_joueur.x=(ecran->w /2)-(tour_joueur->w / 2);
  postour_joueur.y=150;
  posnom.x=(ecran->w /2 )-(_nom->w /2);
  posnom.y=250;

  /*****  Nettoyage de l'ecran et blits des surfaces  *****/
  
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,100,100,100));
  SDL_BlitSurface(fond,NULL,ecran,NULL);
  SDL_BlitSurface(texte,NULL,ecran,&postexte);
  SDL_BlitSurface(tour_joueur,NULL,ecran,&postour_joueur);
  SDL_BlitSurface(_nom,NULL,ecran,&posnom);
  SDL_Flip(ecran);
  
  /*****  Boucle de saisie des noms  *****/
  
  while(continuer)
    {
      SDL_WaitEvent(&event);
      switch(event.type){
	
      case SDL_KEYDOWN:
	switch(event.key.keysym.sym)
	  {
	  case SDLK_RETURN:
	    if(k > 0) { 
	      k=7;
	      continuer=0;
	    }
	    break;
	    
	  default:c=event.key.keysym.sym;break;
	  }
	
	    
	if((k < 7  && c >= 'a'  && c<='z'))
	  {
	    nom[k]=c;
	    _nom=TTF_RenderText_Blended(font1,nom,couleur);
	    k++;
	  }
	    
	if(k > 0 && c == '\b')
	  {
	    nom[k-1]='_';
	    _nom=TTF_RenderText_Blended(font1,nom,couleur);
	    k--;
	  }
	break;
	
      default:break;
	
      }
      
      /*****  Raffraichissement de l'ecran apres saisie des premieres lettres  *****/

      SDL_BlitSurface(fond,NULL,ecran,NULL);
      SDL_BlitSurface(texte,NULL,ecran,&postexte);
      SDL_BlitSurface(tour_joueur,NULL,ecran,&postour_joueur);
      SDL_BlitSurface(_nom,NULL,ecran,&posnom);
      SDL_Flip(ecran);
      
    }//fin de la boucle while
  
  /***** Liberation des surfaces *****/
  
  SDL_FreeSurface(fond);
  SDL_FreeSurface(texte);
  SDL_FreeSurface(tour_joueur);
  SDL_FreeSurface(_nom);
  
}


/********************  Fonction qui affiche un pion donne  ********************/

void aff_j(SDL_Rect pos,SDL_Surface *ecran,SDL_Surface*pion,int i)
{
  SDL_Rect posb;
  
  switch(i)
    {  
    case 0:posb.x=pos.x,posb.y=pos.y;break;
    case 1:posb.x=pos.x+30,posb.y=pos.y;break;
    case 2:posb.x=pos.x,posb.y=pos.y+25;break;
    case 3:posb.x=pos.x+30,posb.y=pos.y+25;break;
    }
  
  SDL_SetColorKey(pion, SDL_RLEACCEL |SDL_SRCCOLORKEY, SDL_MapRGB(pion->format,255,255,255));
  SDL_BlitSurface(pion, NULL, ecran, &posb); /* Blit du pion */

}

/****************************************  Visualisation et choix de carte  ****************************************/

int visualisation(SDL_Surface* ecran,SDL_Surface* carre,int *nb)
{
  int suiv=0;
  int nbcarte=0;
  int nbcartemax=*nb;
  SDL_Event event;
  char chemin[1024];
  SDL_Rect pos_sur_ecran[64];
  SDL_Rect pos_sur_image[64];
  SDL_Rect postxt;
  TTF_Font *police = NULL;
  SDL_Surface *txt;
  SDL_Color couleurnoire;
  
  couleurnoire.r=0;
  couleurnoire.g=0;
  couleurnoire.b=0;


  TTF_Init(); //initialisation du texte
  police = TTF_OpenFont("../Police/tanglewo.ttf",27);//Chargement de la police
  carre=SDL_LoadBMP("../images/ttcase.bmp");//chargement de tous les carres

  if(nbcartemax>0){//il faut au minimun une carte
    suiv=nb_Parcours(nbcarte);//la carte ne"nbcarte"
    charge_Sauvegarde_Edition(pos_sur_ecran,pos_sur_image,suiv);//Mise a jour des tableau contenant des coordonnees ncessaire a l'affichage
  }

  //Efface l'ecran en blanc
  SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format,255,255,255));
  /***** Affichage du parcours  *****/
  aff_Parcous( ecran,carre,pos_sur_ecran,pos_sur_image);

  sprintf(chemin,"Choix du parcours");
  //sprintf(chemin,"Fichier: %d.txt",suiv);//nom du fichier
  txt = TTF_RenderText_Blended(police, chemin,couleurnoire); 
  postxt.x=5; 
  postxt.y=450;
  SDL_BlitSurface(txt, NULL, ecran, &postxt); // Blit du texte

  sprintf(chemin,"Utiliser la fleche gauche ou droite pour continuer");
  txt= TTF_RenderText_Blended(police, chemin,couleurnoire); 
  postxt.x=5; 
  postxt.y=500;
  SDL_BlitSurface(txt, NULL, ecran, &postxt); // Blit du texte 
  SDL_Flip(ecran);

  /**********  Boucle qui oblige le joueur a choisir une carte  **********/
  
  while(SDL_WaitEvent(&event)){
    if(event.key.keysym.sym==SDLK_LEFT||
       event.key.keysym.sym==SDLK_RIGHT )
      break;
    if(event.type==SDL_QUIT)
      exit(0);
  }
  /**********  Fin de la boucle bloquante  **********/

  while(1){

    SDL_WaitEvent(&event);
    if(event.type==SDL_QUIT)
      exit(0);
    if(event.key.keysym.sym==SDLK_ESCAPE)
      break;
      
    if(event.key.keysym.sym==SDLK_RETURN)	
      break;
      
    /**  Ces deux if change de carte en fonction du choix de l'utilisateur **/
    
    if(event.key.keysym.sym==SDLK_RIGHT){	
      nbcarte++;
      if(nbcarte>nbcartemax-1)nbcarte=nbcartemax-1;
      suiv=nb_Parcours(nbcarte);
      charge_Sauvegarde_Edition(pos_sur_ecran,pos_sur_image,suiv);
    }

    if(event.key.keysym.sym==SDLK_LEFT){
      nbcarte--;
      if(nbcarte<0)nbcarte=0;
      suiv=nb_Parcours(nbcarte);
      charge_Sauvegarde_Edition(pos_sur_ecran,pos_sur_image,suiv);
    }     

    /* Efface l'ecran en blanc,reecrit dans les surfaces */
    
    SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format,255,255,255));
    aff_Parcous( ecran,carre,pos_sur_ecran,pos_sur_image);

    //je reutilse chemin txt et postxt de la meme maniere que creation

    sprintf(chemin,"Carte numero %d ",nbcarte+1);
    //sprintf(chemin,"Fichier: %d.txt",suiv);//nom du fichier
    txt = TTF_RenderText_Blended(police, chemin,couleurnoire); 
    postxt.x=5; 
    postxt.y=450;
    SDL_BlitSurface(txt, NULL, ecran, &postxt); // Blit du texte 

    sprintf(chemin,"Utiliser les fleches gauche et droite pour passer");
    txt= TTF_RenderText_Blended(police, chemin,couleurnoire); 
    postxt.x=5; 
    postxt.y=500;
    SDL_BlitSurface(txt, NULL, ecran, &postxt); // Blit du texte

    sprintf(chemin,"Appuyer 'Entrer' pour selectionner votre carte");
    txt= TTF_RenderText_Blended(police, chemin,couleurnoire); 
    postxt.x=5; 
    postxt.y=550;
    SDL_BlitSurface(txt, NULL, ecran, &postxt); // Blit du texte

    SDL_Flip(ecran);  
  }//fin de la boucle while
  
  // SDL_FreeSurface(txt);
  TTF_CloseFont(police);
  TTF_Quit();
  return suiv;
}  



void affNombreCase(SDL_Surface* ecran,SDL_Rect case_dans_ecran[64]){
  char ch[2];
  TTF_Font *police = NULL;
  SDL_Surface* txt;
  SDL_Color couleurnoire = {0,0,0,0};
  int i;

  TTF_Init(); //initialisation du texte
  police = TTF_OpenFont("../Police/tanglewo.ttf",12);//Chargement de la police
 
  for(i=0;i<64;i++){
    sprintf(ch,"%d",i);
    txt= TTF_RenderText_Blended(police, ch,couleurnoire); 
    SDL_BlitSurface(txt, NULL, ecran, &case_dans_ecran[i]); // Blit du texte
  }
  SDL_FreeSurface(txt);
  TTF_CloseFont(police);
  TTF_Quit();

}



int lancement_De(SDL_Surface *ecran, char j[]) {
  //Declaration des variables locales necessaires pour la fonction.
  SDL_Surface *texte = NULL, *joueur = NULL, *faces[6], *de_3D = NULL, *white = NULL;
  SDL_Rect positionjoueur, positionface, positiontexte, positionwhite = {0,450,0,0};
  SDL_Event event;
  TTF_Font *police1 = NULL, *police2 = NULL;
  SDL_Color couleurNoire = {0, 0, 0, 0};
  int continuer = 1, nb_aleatoire;
  char ch[50];
  Mix_Music *tambour; //Creation d'un pointeur de type Mix_Music
 

  //Reglage et lancement de la musique
  Mix_VolumeMusic(MIX_MAX_VOLUME);
  tambour = Mix_LoadMUS("../Music/tambour_suspense.wav"); //Chargement de la musique
  Mix_PlayMusic(tambour, -1); //Jouer infiniment la musique

  //Chargement des differentes faces du des
  faces[0] = IMG_Load("../images/de1.gif");
  faces[1] = IMG_Load("../images/de2.gif");
  faces[2] = IMG_Load("../images/de3.gif");
  faces[3] = IMG_Load("../images/de4.gif");
  faces[4] = IMG_Load("../images/de5.gif");
  faces[5] = IMG_Load("../images/de6.gif");
  de_3D = IMG_Load("../images/de_3d.jpg");
  white = IMG_Load("../images/white.png");

  //Chargement de la police
  police1 = TTF_OpenFont("../Police/chata.ttf", 50);
  police2 = TTF_OpenFont("../Police/chata.ttf", 15);

  //Initialisation du texte
  sprintf(ch,"A toi %s",j);
  joueur = TTF_RenderText_Blended(police1,ch,couleurNoire);
  sprintf(ch,"Appuie sur ESPACE pour obtenir un chiffre");
  texte = TTF_RenderText_Blended(police2,ch,couleurNoire);

  //Initialisation des position des differentes surfaces et textes
  positionface.x = 20;
  positionface.y = 480;
  positionjoueur.x = positionface.x + 150;
  positionjoueur.y = positionface.y;
  positiontexte.x = positionjoueur.x;
  positiontexte.y = positionjoueur.y + joueur->h;

  SDL_BlitSurface(white, NULL, ecran, &positionwhite);
  SDL_BlitSurface(de_3D, NULL, ecran, &positionface);
  SDL_BlitSurface(joueur, NULL, ecran, &positionjoueur);
  SDL_BlitSurface(texte, NULL, ecran, &positiontexte);
  SDL_Flip(ecran);

  /*Une boucle infine afin de maintenir l'affichage et quitter le programme quand l'utilisateur ferme la fenetre*/
  while (continuer) {
    SDL_PollEvent(&event);
    switch(event.type) {
    case SDL_QUIT:
      continuer = 0;
      break;
      //En cas d'apuui sur un bouton
    case SDL_KEYDOWN :
      //S'il s'agit du bouton "Entrer", appeler la fonction tictactoe
      if(event.key.keysym.sym == SDLK_SPACE) {
	sprintf(ch,"T'as obtenu %d",nb_aleatoire+1);
	joueur = TTF_RenderText_Blended(police1,ch,couleurNoire);
	SDL_BlitSurface(white, NULL, ecran, &positionwhite);
	SDL_BlitSurface(faces[nb_aleatoire], NULL, ecran, &positionface);
	SDL_BlitSurface(joueur, NULL, ecran, &positionjoueur);
	SDL_Flip(ecran);
      }
      continuer = 0;
      break;
    default: break;
    }
    if (continuer) {
      srand(time(NULL));
      nb_aleatoire = rand()%6;
    } 
  }

  //Liberation de la memoire occupee par les surfaces et les polices et arret de la SDL
  TTF_CloseFont(police1);
  TTF_CloseFont(police2);
  Mix_FreeMusic(tambour); //Liberation de la musique
  SDL_FreeSurface(joueur);
  SDL_FreeSurface(texte);
  for(continuer = 0; continuer < 6; continuer++)
    SDL_FreeSurface(faces[continuer]);
  return nb_aleatoire+1;
}

/********************  Gestion des bonus  ********************/

int gestion_Bonus (SDL_Surface *ecran,TTF_Font *font1,char *nom_joueur){
  SDL_Surface *texte=NULL,*masque=NULL;
  SDL_Rect postexte,posmasque;
  SDL_Color couleur;
  char information[1000];
  int bonus;
  
  couleur.r=0;
  couleur.g=0;
  couleur.b=0;
  
  masque=IMG_Load("../images/white.png");
  
  posmasque.x=0;
  posmasque.y=455;

  /**  Bonus aleatoire  **/
  srand(time(NULL));
  bonus=(rand()%3)+1;
  
  sprintf(information,"%s a un bonus de %d case(s)",nom_joueur,bonus);
  texte=TTF_RenderText_Blended(font1,information,couleur);
  
  postexte.x=(ecran->w/2)-(texte->w/2);
  postexte.y=500;
  
  SDL_BlitSurface(masque,NULL,ecran,&posmasque);
  SDL_BlitSurface(texte,NULL,ecran,&postexte);
  SDL_Flip(ecran);
  
  SDL_FreeSurface(masque);
  SDL_FreeSurface(texte);
  return bonus;
}

/********************  Gestion des malus  ********************/

int gestion_Malus(SDL_Surface *ecran,TTF_Font *font1,char *nom_joueur)
{
  SDL_Surface *texte=NULL,*masque=NULL;
  SDL_Rect postexte,posmasque;
  SDL_Color couleur;
  char information[1000];
  int malus;
  
  couleur.r=0;
  couleur.g=0;
  couleur.b=0;
  
  masque=IMG_Load("../images/white.png");
  
  posmasque.x=0;
  posmasque.y=455;

  /**  Malus aleatoire  **/
  srand(time(NULL));
  malus =-(rand()%3)-1;
  
  sprintf(information,"%s a un malus de %d case(s)",nom_joueur,malus);
  texte=TTF_RenderText_Blended(font1,information,couleur);
  
  postexte.x=(ecran->w/2)-(texte->w/2);
  postexte.y=500;
  
  SDL_BlitSurface(masque,NULL,ecran,&posmasque);
  SDL_BlitSurface(texte,NULL,ecran,&postexte);
  SDL_Flip(ecran);
  
  SDL_FreeSurface(masque);
  SDL_FreeSurface(texte);
  return malus;
}

/********************  Gestion de la prison  ********************/
int gestion_Prison(SDL_Surface *ecran,TTF_Font *font1,char *nom_joueur,int nb_joueur)
{
  SDL_Surface *texte=NULL,*masque=NULL;
  SDL_Rect postexte,posmasque;
  SDL_Color couleur;
  char information[1000];
  int prison;
  
  couleur.r=0;
  couleur.g=0;
  couleur.b=0;
  
  masque=IMG_Load("../images/white.png");
  
  posmasque.x=0;
  posmasque.y=455;

  /**  nb de tour en prison aleatoire aleatoire  **/
  srand(time(NULL));
  prison =(rand()%3)+nb_joueur;
  
  sprintf(information,"%s est tombe en prison pour %d tour(s)",nom_joueur,prison);
  texte=TTF_RenderText_Blended(font1,information,couleur);
  
  postexte.x=(ecran->w/2)-(texte->w/2);
  postexte.y=500;
  
  SDL_BlitSurface(masque,NULL,ecran,&posmasque);
  SDL_BlitSurface(texte,NULL,ecran,&postexte);
  SDL_Flip(ecran);
  
  SDL_FreeSurface(masque);
  SDL_FreeSurface(texte);
  return prison;
}

/********************  Gestion des minijeux  ********************/
void gestion_Mini_Jeux(SDL_Surface *ecran,TTF_Font *font1,Joueur* tabjoueur,int nb_joueur){
  
  SDL_Surface *texte=NULL,*masque=NULL,*texte2=NULL;
  SDL_Rect postexte,posmasque,postexte2;
  SDL_Color couleur;
  char information[1000];
  int winner;
  
  couleur.r=0;
  couleur.g=0;
  couleur.b=0;
  
  int indice_minijeu_j1,indice_minijeu_j2,minijeux;
  
  srand(time(NULL));
  
  /** joueur qui vont s'affronter en duel aleatoire  **/
  
  indice_minijeu_j1 = rand()%nb_joueur ;
  indice_minijeu_j2 = rand()%nb_joueur ;
  
  while (indice_minijeu_j2 == indice_minijeu_j1)
    indice_minijeu_j2 = rand()%nb_joueur ;
  
  masque=IMG_Load("../images/white.png");
  
  posmasque.x=0;
  posmasque.y=455;

  /**  choix aléatoire du mini-jeu  **/
  minijeux = rand()%5+1;
 
 switch(minijeux){
    
    //le pendu
  case 1:
    sprintf(information,"%s et %s vont s'affronter",tabjoueur[indice_minijeu_j1].nom,tabjoueur[indice_minijeu_j2].nom);
    texte=TTF_RenderText_Blended(font1,information,couleur);
    texte2=TTF_RenderText_Blended(font1,"lors d'un pendu",couleur);
    postexte.x=(ecran->w/2)-(texte->w/2);
    postexte.y=500;
    postexte2.x=(ecran->w/2)-(texte2->w/2);
    postexte2.y=550;
    SDL_BlitSurface(masque,NULL,ecran,&posmasque);
    SDL_BlitSurface(texte,NULL,ecran,&postexte);
    SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
    SDL_Flip(ecran);
    SDL_Delay(2000);
    winner = Accueil_Pendu(ecran,tabjoueur[indice_minijeu_j1].nom,tabjoueur[indice_minijeu_j2].nom);
    
    if(winner == 1){
      sprintf(information,"%s a gagner le pendu ",tabjoueur[indice_minijeu_j1].nom);
      texte=TTF_RenderText_Blended(font1,information,couleur);
      texte2=TTF_RenderText_Blended(font1,"il avance de 3 cases",couleur);
      tabjoueur[indice_minijeu_j1].pos += 3;
      tabjoueur[indice_minijeu_j2].pos -= 3;
    }
    else{
      sprintf(information,"%s a gagner le pendu",tabjoueur[indice_minijeu_j2].nom);
      texte=TTF_RenderText_Blended(font1,information,couleur);
      texte2=TTF_RenderText_Blended(font1,"il avance de 3 cases",couleur);
      tabjoueur[indice_minijeu_j2].pos += 3;
      tabjoueur[indice_minijeu_j1].pos -= 3;
    }
    postexte.x=(ecran->w/2)-(texte->w/2);
    postexte.y=500;
    postexte2.x=(ecran->w/2)-(texte2->w/2);
    postexte2.y=550;
    SDL_BlitSurface(masque,NULL,ecran,&posmasque);
    SDL_BlitSurface(texte,NULL,ecran,&postexte);
    SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
    SDL_Flip(ecran);
  
    break;
    
    //NB MYSTERIEUX
 
 case 2:
   sprintf(information,"%s et %s vont s'affronter",tabjoueur[indice_minijeu_j1].nom,tabjoueur[indice_minijeu_j2].nom);
   texte=TTF_RenderText_Blended(font1,information,couleur);
    texte2=TTF_RenderText_Blended(font1,"lors d'un nombre mysterieux",couleur);
    postexte.x=(ecran->w/2)-(texte->w/2);
    postexte.y=500;
    postexte2.x=(ecran->w/2)-(texte2->w/2);
    postexte2.y=550;
    SDL_BlitSurface(masque,NULL,ecran,&posmasque);
    SDL_BlitSurface(texte,NULL,ecran,&postexte);
    SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
    SDL_Flip(ecran);
    SDL_Delay(2000);
    winner = Accueil_Nb_Mysterieux(ecran,tabjoueur[indice_minijeu_j1].nom,tabjoueur[indice_minijeu_j2].nom);
    if(winner == 1){
      sprintf(information,"%s a gagner le Nb Mysterieux",tabjoueur[indice_minijeu_j1].nom);
      texte=TTF_RenderText_Blended(font1,information,couleur);
      texte2=TTF_RenderText_Blended(font1,"il avance de 3 cases",couleur);
      tabjoueur[indice_minijeu_j1].pos += 3;
      tabjoueur[indice_minijeu_j2].pos -= 3;
     
    }
    else{
      sprintf(information,"%s a gagner le Nb Mysterieux",tabjoueur[indice_minijeu_j2].nom);
      texte=TTF_RenderText_Blended(font1,information,couleur);
      texte2=TTF_RenderText_Blended(font1,"il avance de 3 cases",couleur);
      tabjoueur[indice_minijeu_j2].pos += 3;
      tabjoueur[indice_minijeu_j1].pos -= 3;
    }
    postexte.x=(ecran->w/2)-(texte->w/2);
    postexte.y=500;
    postexte2.x=(ecran->w/2)-(texte2->w/2);
    postexte2.y=550;
    SDL_BlitSurface(masque,NULL,ecran,&posmasque);
    SDL_BlitSurface(texte,NULL,ecran,&postexte);
    SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
    SDL_Flip(ecran);
   
    break;
    
    // puissance 4
    case 3:
    sprintf(information,"%s et %s vont s'affronter",tabjoueur[indice_minijeu_j1].nom,tabjoueur[indice_minijeu_j2].nom);
    texte=TTF_RenderText_Blended(font1,information,couleur);
    texte2=TTF_RenderText_Blended(font1,"lors d'un puissance 4",couleur);
    postexte.x=(ecran->w/2)-(texte->w/2);
    postexte.y=500;
    postexte2.x=(ecran->w/2)-(texte2->w/2);
    postexte2.y=550;
    SDL_BlitSurface(masque,NULL,ecran,&posmasque);
    SDL_BlitSurface(texte,NULL,ecran,&postexte);
    SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
    SDL_Flip(ecran);
    SDL_Delay(2000);
    winner = Accueil_Puissance_4(ecran,tabjoueur[indice_minijeu_j1].nom,tabjoueur[indice_minijeu_j2].nom);
    if(winner == 1){
      sprintf(information,"%s a gagner le Puissance 4",tabjoueur[indice_minijeu_j1].nom);
      texte=TTF_RenderText_Blended(font1,information,couleur);
      texte2=TTF_RenderText_Blended(font1,"il avance de 3 cases",couleur);
      tabjoueur[indice_minijeu_j1].pos += 3;
      tabjoueur[indice_minijeu_j2].pos -= 3;
    }
    else{
      sprintf(information,"%s a gagner le Puissance 4 ",tabjoueur[indice_minijeu_j2].nom);
      texte=TTF_RenderText_Blended(font1,information,couleur);
      texte=TTF_RenderText_Blended(font1,"il avance de 3 cases",couleur);
      tabjoueur[indice_minijeu_j2].pos += 3;
      tabjoueur[indice_minijeu_j1].pos -= 3;
    }
      postexte.x=(ecran->w/2)-(texte->w/2);
      postexte.y=500;
      postexte2.x=(ecran->w/2)-(texte2->w/2);
      postexte2.y=550;
      SDL_BlitSurface(masque,NULL,ecran,&posmasque);
      SDL_BlitSurface(texte,NULL,ecran,&postexte);
      SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
      SDL_Flip(ecran);
    break;
    
  case 4://Tictactoe
    sprintf(information,"%s et %s vont s'affronter",tabjoueur[indice_minijeu_j1].nom,tabjoueur[indice_minijeu_j2].nom);
    texte=TTF_RenderText_Blended(font1,information,couleur);
    texte2=TTF_RenderText_Blended(font1,"lors d'un tic tac toe",couleur);
    postexte.x=(ecran->w/2)-(texte->w/2);
    postexte.y=500;
    postexte2.x=(ecran->w/2)-(texte2->w/2);
    postexte2.y=550;
    SDL_BlitSurface(masque,NULL,ecran,&posmasque);
    SDL_BlitSurface(texte,NULL,ecran,&postexte);
    SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
    SDL_Flip(ecran);
    SDL_Delay(2000);
    winner = Accueil_TicTacToe(ecran,tabjoueur[indice_minijeu_j1].nom,tabjoueur[indice_minijeu_j2].nom);
    if(winner == 1){
      sprintf(information,"%s a gagner le tictactoe",tabjoueur[indice_minijeu_j1].nom);
      texte=TTF_RenderText_Blended(font1,information,couleur);
      texte2=TTF_RenderText_Blended(font1,"il avance de 3 cases",couleur);
      tabjoueur[indice_minijeu_j1].pos += 3;
      tabjoueur[indice_minijeu_j2].pos -= 3;
    }
    else{
      sprintf(information,"%s a gagner le tictactoe",tabjoueur[indice_minijeu_j2].nom);
      texte=TTF_RenderText_Blended(font1,information,couleur);
      texte2=TTF_RenderText_Blended(font1,"il avance de 3 cases",couleur);
      tabjoueur[indice_minijeu_j2].pos += 3;
      tabjoueur[indice_minijeu_j1].pos -= 3;
    }
    postexte.x=(ecran->w/2)-(texte->w/2);
    postexte.y=500;
    postexte2.x=(ecran->w/2)-(texte2->w/2);
    postexte2.y=550;
    SDL_BlitSurface(masque,NULL,ecran,&posmasque);
    SDL_BlitSurface(texte,NULL,ecran,&postexte);
    SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
    SDL_Flip(ecran);
    break;
    
   // pong 
  case 5:
    sprintf(information,"%s et %s vont s'affronter",tabjoueur[indice_minijeu_j1].nom,tabjoueur[indice_minijeu_j2].nom);
    texte=TTF_RenderText_Blended(font1,information,couleur);
    texte2=TTF_RenderText_Blended(font1,"lors d'un pong",couleur);
    postexte.x=(ecran->w/2)-(texte->w/2);
    postexte.y=500;
    postexte2.x=(ecran->w/2)-(texte2->w/2);
    postexte2.y=550;
    SDL_BlitSurface(masque,NULL,ecran,&posmasque);
    SDL_BlitSurface(texte,NULL,ecran,&postexte);
    SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
    SDL_Flip(ecran);
    SDL_Delay(2000);
    winner = jouer_pong(ecran,indice_minijeu_j1,indice_minijeu_j2);
    if(winner == indice_minijeu_j1){
      sprintf(information,"%s a gagner le pong",tabjoueur[indice_minijeu_j1].nom);
      texte=TTF_RenderText_Blended(font1,information,couleur);
      texte2=TTF_RenderText_Blended(font1,"il avance de 3 cases",couleur);
      tabjoueur[indice_minijeu_j1].pos += 3;
      tabjoueur[indice_minijeu_j2].pos -= 3;
    }
    else{
      sprintf(information,"%s a gagner le pong ",tabjoueur[indice_minijeu_j2].nom);
      texte=TTF_RenderText_Blended(font1,information,couleur);
      texte2=TTF_RenderText_Blended(font1,"il avance de 3 cases",couleur);
      tabjoueur[indice_minijeu_j2].pos += 3;
      tabjoueur[indice_minijeu_j1].pos -= 3;
    }
    postexte.x=(ecran->w/2)-(texte->w/2);
    postexte.y=500;
    postexte2.x=(ecran->w/2)-(texte2->w/2);
    postexte2.y=550;
    SDL_BlitSurface(masque,NULL,ecran,&posmasque);
    SDL_BlitSurface(texte,NULL,ecran,&postexte);
    SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
    SDL_Flip(ecran);
    break;
 default: break;
 }
 
 SDL_Delay(1500);
 SDL_FreeSurface(masque);
 SDL_FreeSurface(texte);
 SDL_FreeSurface(texte2);
}



/****************************************  Fonction principale du jeu  ****************************************/

void jouer (SDL_Surface *ecran,TTF_Font *font1,TTF_Font *font2, int charger)
{
  /**********  Declaration des variables  **********/
  
  int menu_id=1,continuer=1,bool=0;
  int nbre_joueur=0,indice_joueur ,compteur_joueur=0;
  int nbre_carte,num_cartechoisie,i;
  int tour_de_jeu = 1;
  SDL_Event event;
  SDL_Surface *carre=NULL,*texte=NULL,*pion[4];
  SDL_Rect position_chemin_dans_image[64];
  int position_evenement[64],bonus_malus;
  SDL_Rect position_chemin[64],postexte;
  SDL_Color couleur={0,0,0,0}; 
  Joueur *joueur;
  FILE *info;
  char information[100];

  SDL_Surface *message_gagnant ,*message_gagnant2 ,*message_gagnant3;
  //couleur du txt ,ici,noire
  SDL_Color couleurNoire = {0, 0, 0, 0};
  // position du texte dans la fenetre 
  SDL_Rect position_message_gagnant,position_message_gagnant2,position_message_gagnant3 ;
  position_message_gagnant.x = 20;
  position_message_gagnant.y = HAUTEUR_FENETRE/3;
  position_message_gagnant2.x = (LARGEUR_FENETRE/2)-100;
  position_message_gagnant2.y = (HAUTEUR_FENETRE/3)+50;
  position_message_gagnant3.x = 5;
  position_message_gagnant3.y = (HAUTEUR_FENETRE/3)+110;
  char text[LARGEUR_FENETRE];  
  char text2[LARGEUR_FENETRE]; 
  char text3[LARGEUR_FENETRE]; 
  
  sprintf(information,"Appuyez sur espace pour commencer");
  texte=TTF_RenderText_Blended(font1,information,couleur); 
  postexte.x=(ecran->w/2)-(texte->w/2);
  postexte.y=500;

  /**********  Recupere le nbre total de carte dans le fichier info.txt  **********/
  info=fopen("../carte/info.txt","r");
  if(info)
    fscanf(info,"%d",&nbre_carte);
  fclose(info);
  
  if(nbre_carte == 0) return;
 
  if(charger == 1) {
    joueur=(Joueur*)malloc(sizeof(Joueur)*5);
    menu_id  = menu_Chargement(ecran,&num_cartechoisie,joueur,&nbre_joueur);
    if(menu_id != 0) {
      pion[0]=SDL_LoadBMP("../images/pionr.bmp");
      pion[1]=SDL_LoadBMP("../images/pionv.bmp");
      pion[2]=SDL_LoadBMP("../images/pionb.bmp");
      pion[3]=SDL_LoadBMP("../images/piong.bmp");
    }
  }

  SDL_Flip(ecran);
  SDL_Delay(2000);
 
  if(!menu_id || charger == 0) {menu_id = 1;}
  else menu_id = 4;
  

  /**********  Chargement de tous les carres  **********/
  carre=SDL_LoadBMP("../images/ttcase.bmp");

  /********************  Boucle du jeu  ********************/
  
  while (continuer)
    {
      while(SDL_PollEvent(&event))
	{ 
	  switch(menu_id)
	    {
	      /**********  Choix du nombre de joueur  **********/
	    case 1:
	      choix_Nb_Joueur(ecran,font1,font2,bool);
	      switch(event.type)
		{

		case SDL_KEYDOWN:
		  switch(event.key.keysym.sym)
		    {
		    case SDLK_BACKSPACE:
		      continuer=0;//Retour sur le choix(Nvelle partie/Charger Partie)
		      break;
		      
		    case SDLK_RETURN:
  
		      if(bool == 0)
			{
			  nbre_joueur=2;
			  joueur=(Joueur*)malloc(sizeof(Joueur)*nbre_joueur);
			  menu_id=2;
			}
		      
		      if(bool == 1)
			{
			  nbre_joueur=3;
			  joueur=(Joueur*)malloc(sizeof(Joueur)*nbre_joueur);
			  menu_id=2;
			}

		      if (bool == 2)
			{
			  nbre_joueur=4;
			  joueur=(Joueur*)malloc(sizeof(Joueur)*nbre_joueur);
			  menu_id=2;
			}
		      break;

		    case SDLK_UP:
		      if(bool > 0)
			bool--;
		      else if(bool == 0)
			bool = 2;
		      break;
		      
		    case SDLK_DOWN:
		      if(bool <2 )
			bool++;
		      else if(bool == 2)
			bool = 0;
		      break;
		  
		    default:
		      break;
		    }
	      
		default:
		  break;
		}//fin du switch
	      break;
	      
	    case 2:
	      /********************  Saisie des noms des joueurs et initialisation des structures  ********************/
	      for (indice_joueur=0; indice_joueur< nbre_joueur; indice_joueur++)
		{
		  saisie_Nom(ecran,indice_joueur,joueur[indice_joueur].nom,font2);
		  switch(indice_joueur)
		    {
		    case 0:joueur[0].prison=0,joueur[0].score=0,joueur[0].pos=0, pion[0]=SDL_LoadBMP("../images/pionr.bmp");break;
		    case 1:joueur[1].prison=0,joueur[1].score=0,joueur[1].pos=0, pion[1]=SDL_LoadBMP("../images/pionv.bmp");break;
		    case 2:joueur[2].prison=0,joueur[2].score=0,joueur[2].pos=0, pion[2]=SDL_LoadBMP("../images/pionb.bmp");break;
		    case 3:joueur[3].prison=0,joueur[3].score=0,joueur[3].pos=0, pion[3]=SDL_LoadBMP("../images/piong.bmp");break;
		    }
		}
	      
	      /**********  Nettoyage des noms pour retirer les '_'  **********/
	      for (indice_joueur=0; indice_joueur< nbre_joueur; indice_joueur++){
		for(i=7;i>=0;i--){
		  if(joueur[indice_joueur].nom[i] == '_')
		    joueur[indice_joueur].nom[i]=' ';
		}
	      }
	      
	      menu_id=3;
	      break;
	      
	    case 3:
	      /********************  Visualisation et choix de la carte  ********************/
	      num_cartechoisie=visualisation(ecran,carre,&nbre_carte);
	      menu_id=4;
	      break;

	    case 4:
	      /***  Deroulement d'une partie  ***/
	      
	      /********** Initialisation des cases dans la fenetre **********/
	      charge_Sauvegarde_Edition(position_chemin,position_chemin_dans_image,num_cartechoisie);
	      
	      /****** Chargement des evements ******/
	      
	      for(i=0 ;i<64;i++){
		position_evenement[i]=transforme_Pos_Image_En_Val(position_chemin_dans_image[i]);
	      }
	      
	      /**********  Affichage du parcours  **********/
	      
	      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255,255,255)); 
	      aff_Parcous(ecran,carre,position_chemin,position_chemin_dans_image);//affichage du parcours
	      affNombreCase(ecran,position_chemin);
		  
	      /**********  Placement des joueurs sur la carte  **********/
	      
	      for(indice_joueur=0;indice_joueur<nbre_joueur;indice_joueur++){
		aff_j(position_chemin[joueur[indice_joueur].pos],ecran,pion[indice_joueur],indice_joueur);
	      }
	      
	      /**********  Instruction avant le debut du jeu  **********/
	      SDL_BlitSurface(texte,NULL,ecran,&postexte);
	      SDL_Flip(ecran);
	      
	      switch(event.type)
		{
		case SDL_KEYDOWN:
		  switch(event.key.keysym.sym)
		    {
		    case SDLK_ESCAPE:
		      
		      /** Arret d'une partie en cours,proposition de sauvegarde **/
		      menu_Exit(ecran,joueur,num_cartechoisie,nbre_joueur);
		      continuer=0;
		      break;
		      
		    case SDLK_SPACE:
		      tour_de_jeu +=1;
		      /** Lancement du minijeux **/
		      if((tour_de_jeu%(nbre_joueur+4))==0){
			gestion_Mini_Jeux(ecran,font1,joueur,nbre_joueur);
			continue;
		      }
		      /** Gestion des deplacements **/
		      if(0 < joueur[compteur_joueur].prison){
			joueur[compteur_joueur].prison -= 1;
			compteur_joueur++;
			if(compteur_joueur == nbre_joueur)
			  compteur_joueur=0;//tab de joueur circulaire	
			continue;
		      }
		      if(joueur[compteur_joueur].pos == 63)
			{
			  compteur_joueur++;
			  if(compteur_joueur == nbre_joueur)
			    compteur_joueur=0;//tab de joueur circulaire	
			  continue;
			}
			
		      joueur[compteur_joueur].pos += lancement_De(ecran,joueur[compteur_joueur].nom);
		      SDL_Delay(1500);
			
		      /******  Gestion des evenements  ******/
			
		      switch(position_evenement[joueur[compteur_joueur].pos])
			{
			  
			case 0:
			  break;
			  
			case 1: 
			  /*Bonus;*/
			  bonus_malus=gestion_Bonus(ecran,font1,joueur[compteur_joueur].nom);
			  SDL_Delay(1500);
			  joueur[compteur_joueur].pos +=bonus_malus;
			  break;
			  
			case 2: /*Malus;*/
			  bonus_malus=gestion_Malus(ecran,font1,joueur[compteur_joueur].nom);
			  SDL_Delay(1500);
			  joueur[compteur_joueur].pos +=bonus_malus;
			  break;
			  
			case 3: /*Prison;*/
			  bonus_malus= gestion_Prison(ecran,font1,joueur[compteur_joueur].nom,nbre_joueur);
			  SDL_Delay(1500);

			  joueur[compteur_joueur].prison += bonus_malus;
			  break;
			  
			case 4: //rejouer
			  compteur_joueur--;
			   break;
			    
			default:
			  break;
			}
			
		      if(joueur[compteur_joueur].pos>=63)
			{
			  joueur[compteur_joueur].pos=63;
			}
		      compteur_joueur++;//nv joueur
		      if(compteur_joueur == nbre_joueur)compteur_joueur=0;//tab de joueur circulaire
			
		      /*  Gestion de la fin de la partie  */
		      
		     if(joueur[compteur_joueur].pos==63) 
		       {
			 sprintf(text,"UN GRAND BRAVO");
			 sprintf(text2,"%s",joueur[compteur_joueur].nom);
			 sprintf(text3,"NOTRE GRAND GAGNANT");
			 message_gagnant = TTF_RenderText_Blended(font2,text,couleurNoire);
			 SDL_BlitSurface(message_gagnant, NULL, ecran, &position_message_gagnant);
			 SDL_Flip(ecran);
			 SDL_Delay(1000);
			 message_gagnant2 = TTF_RenderText_Blended(font2,text2,couleurNoire);
			 SDL_BlitSurface(message_gagnant2, NULL, ecran, &position_message_gagnant2);
			 SDL_Flip(ecran);
			 SDL_Delay(1000);
			 message_gagnant3 = TTF_RenderText_Blended(font2,text3,couleurNoire);
			 SDL_BlitSurface(message_gagnant3, NULL, ecran, &position_message_gagnant3);
			 SDL_Flip(ecran);
			 SDL_Delay(3000);
			 SDL_FreeSurface(carre);
			 return;
		       }
			  
		     sprintf(information,"Appuyez sur espace");
		     texte=TTF_RenderText_Blended(font2,information,couleur);
		     SDL_BlitSurface(texte,NULL,ecran,&postexte);
		     SDL_Flip(ecran);
		     
		      break;
		    default:
			break;
		    
		    }
		  break;
	
	      	}//switch(event.type) 
	      
	      //break du case 4
	      break;
	      
	    default:
	      break;
	    }
	}//fin while(SDL..)
     
      /** Cette accolade ferme la boucle while  **/
    }

  /**********  Liberation des surfaces  **********/
  SDL_FreeSurface(carre);
  SDL_FreeSurface(texte);
  
  for(indice_joueur=0;indice_joueur < nbre_joueur;indice_joueur++)
    SDL_FreeSurface(pion[indice_joueur]);
  
}
