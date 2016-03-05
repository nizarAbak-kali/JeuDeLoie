#include"../headers/bibliotheque.h"


/*Permet de trouver le 1er nom disponible pour une carte a partir de zero
  Astuce le nom d'une carte est "unnombre".txt donc j'ai juste besion d'avoir le nombre et j'aurais le nom complet
*/

int suiv_Parcours()
{
  FILE* parcours;
  int it=0;
  char chemin[1024];
  do
    {
      sprintf(chemin,"../carte/%d.txt",it);
      parcours=fopen(chemin,"r"); 
      if(!parcours){
	break;
      }else{
	fclose(parcours);
	it++;
      }
    }
  while(1);    
  
  return it;
}


/* Permet de trouver le nom de ieme carte */

int nb_Parcours(int ieme)
{
  FILE* parcours;
  int it=0,valide=0;
  char chemin[1024];
  
  for(;;)
    {
      sprintf(chemin,"../carte/%d.txt",it); 
      parcours=fopen(chemin,"r"); 
      if(parcours){
	valide++;
	fclose(parcours);
      }  
      if(valide==ieme+1)
	return it;
      it++;  
    }   
  return it;
}


/* Permet de creer une carte de jeu */

void creation(SDL_Surface *ecran,int*nb)
{
  SDL_Event event;
  TTF_Font *police = NULL;
  TTF_Font *police2 = NULL;
  SDL_Rect posline,postexte,posmsg;
  SDL_Surface* texte,*texte2,*msg,*carre;
  int continuer=1,compteur_case=0;
  SDL_Color couleurnoire;

  couleurnoire.r=0;
  couleurnoire.g=0;
  couleurnoire.b=0;
  
  SDL_Rect position_chemin[64],position_chemin_dans_image[64],pos_ij;
  char texte_compteur[1000]; 
  int i,j,msg_final=0;
  int nbparcours=*nb,prochaine_sauv=suiv_Parcours();
  
  carre=SDL_LoadBMP("../images/ttcase.bmp");/*chargement de tous les carrer*/
  
  posline.x=0;
  posline.y=382;
  
  postexte.x=140;
  postexte.y=405;
  
  TTF_Init(); //initialisation du texte
  
  police = TTF_OpenFont("../Police/Quickier_Demo.ttf",30);//Chargement de la police
  police2 = TTF_OpenFont("../Police/tanglewo.ttf",17);//Chargement de la police
  
  /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
  texte = TTF_RenderText_Blended(police, "-----------------------------------------------------------------------------------", couleurnoire);
  
  
  /*Initialisation des cases*/
  for(i=0;i<64;i++){
    position_chemin[i].x=-100;
    position_chemin[i].y=-100;
  }
  
 menu:
  posmsg.x=0;
  posmsg.y=430;

  /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
  texte2 = TTF_RenderText_Blended(police2, "Menu Creation('Entrer pour continuer')", couleurnoire);

  /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
  msg = TTF_RenderText_Blended(police2, "Bienvenue dans l'espace creation de l'editeur !", couleurnoire);

  /* Affichage des surfaces et nettoyage de l'écran */
  
  SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  aff_Cadre_Editer(ecran,carre);
  SDL_BlitSurface(texte, NULL, ecran, &posline); /* Blit du texte */
  SDL_BlitSurface(texte2, NULL, ecran, &postexte);
  SDL_BlitSurface(msg, NULL, ecran, &posmsg);

  /* j'ai affiché le 1e msg mtn j'affiche un nouveau et change les position*/
  posmsg.x=0;
  posmsg.y=450;
  msg = TTF_RenderText_Blended(police2, "L'utilisation est simple, pour editter votre propre carte, vous allez vous promener",couleurnoire);

  SDL_BlitSurface(msg, NULL, ecran, &posmsg); /* Blit du texte */

  /* j'ai affiché le 2e msg mtn j'affiche un nouveau et change les position*/
  posmsg.x=0;
  posmsg.y=470;
  msg = TTF_RenderText_Blended(police2, "avec les touches directionnelles (haut, bas, gauche, droite) sur le quadrillage rouge et", couleurnoire);
  SDL_BlitSurface(msg, NULL, ecran, &posmsg); /* Blit du texte */
  /*Permet de creer une carte de jeu*/

  /* j'ai affiché le 3e msg mtn j'affiche un nouveau et change les position*/
  posmsg.x=0;
  posmsg.y=490;
  msg = TTF_RenderText_Blended(police2, "selectionner une case avec la touche 'entrer'.", couleurnoire);
  SDL_BlitSurface(msg, NULL, ecran, &posmsg); /* Blit du texte */


  /* j'ai affiché le 4e msg mtn j'affiche un nouveau et change les position*/
  posmsg.x=0;
  posmsg.y=510;
  msg = TTF_RenderText_Blended(police2, "Une fois la case selectionnee, une liste de case possible a cette endroit va s'afficher", couleurnoire);
  SDL_BlitSurface(msg, NULL, ecran, &posmsg); /* Blit du texte */

  /* j'ai affiché le 5e msg mtn j'affiche un nouveau et change les position*/
  posmsg.x=0;
  posmsg.y=530;
  msg = TTF_RenderText_Blended(police2, "et vous effectuerez votre choix de la meme maniere que dans le quadrillage a l'aide", couleurnoire);
  SDL_BlitSurface(msg, NULL, ecran, &posmsg); /* Blit du texte */

  /* j'ai affiché le 6e msg mtn j'affiche un nouveau et change les position*/
  posmsg.x=0;
  posmsg.y=550;
  msg = TTF_RenderText_Blended(police2, "des touches directionnelles et 'entrer'.", couleurnoire);
  SDL_BlitSurface(msg, NULL, ecran, &posmsg); /* Blit du texte */
  SDL_Flip(ecran); /* Mise à jour de l'écran*/

  /* j'ai affiché le 7e msg mtn j'affiche un nouveau et change les position*/
  posmsg.x=0;
  posmsg.y=570;
  msg = TTF_RenderText_Blended(police2, "Pour effacer une case utiliser 'delete'. Pour revenir au menu utiliser 'm'.", couleurnoire);
  SDL_BlitSurface(msg, NULL, ecran, &posmsg); /* Blit du texte */


  aff_Parcous(ecran,carre,position_chemin,position_chemin_dans_image);/**affichage du parours*/
  SDL_Flip(ecran); /* Mise à jour de l'écran*/

  /*commentaire a supprimé une fois lu
    le but d'avoir mis c'est 7 action est répétitive est pour economiser le nb de variable
    si vous regarder bien le sdl_surface est msg, une fois collé a l'écran il n'est plus utilisé donc je le réutilise*/

  /*Tant que 'Entrer' n'est pas préssé le programme attend*/
  while(SDL_WaitEvent(&event)){
    if(event.key.keysym.sym==SDLK_RETURN)
      break;
    if(event.type==SDL_QUIT)
      exit(0);
  }


  /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
  texte2 = TTF_RenderText_Blended(police2, "Menu Creation('Echap pour quitter')", couleurnoire);

  posmsg.x=0;
  posmsg.y=430;
  
  i=-1;//j'affecte -1 pour eviter un appel direct a selec_aff_case_dispo() au premier tour de boucle  
  j=0;
  while(continuer)
    {
      
      SDL_WaitEvent(&event);
      if(event.type==SDL_QUIT)
	exit(0);
      if(event.key.keysym.sym==SDLK_ESCAPE)
	continuer=0;
      
      if(event.type==SDL_KEYUP){     
	if(event.key.keysym.sym==SDLK_m)
	  goto menu;
	if(event.key.keysym.sym==SDLK_s&&compteur_case==64){
	  sauvegarde_Edition(position_chemin,position_chemin_dans_image,prochaine_sauv);
	  msg_final=1; /*Booléen qui sert uniqueent a affiche le message final*/
	  nbparcours++;
	}
	/*i et j sert a donné la position de la case noir qui se déplace dans le quedrillage que j'appel fantome*/
	if(event.key.keysym.sym==SDLK_RIGHT)
	  i++;
	if(event.key.keysym.sym==SDLK_LEFT)
	  i--;
	if(event.key.keysym.sym==SDLK_DOWN)
	  j++;
	if(event.key.keysym.sym==SDLK_UP)
	  j--;
	if(event.key.keysym.sym==SDLK_BACKSPACE&&compteur_case-1>-1){
	  compteur_case--;
	  position_chemin[compteur_case].x=-100;
	  position_chemin[compteur_case].y=-100;
	}
	
	if(event.key.keysym.sym==SDLK_RETURN&&i!=-1&&possiblite_Case_Ij(pos_ij,position_chemin)&&compteur_case<64){
	  compteur_case+=selec_Aff_Case_Dispo(ecran,carre,compteur_case,pos_ij,position_chemin,position_chemin_dans_image);
	}
	
      }
      
      if(compteur_case<0)
	compteur_case=0;
      
      if(i<0)i=0;
      if(i>11)i=11;
      if(j<0)j=0;
      if(j>7)j=7;
      
      pos_ij.x=i*50;
      pos_ij.y=j*50;
      
      if(!msg_final){
	if(compteur_case<64)
	  sprintf(texte_compteur,"Il vous reste %d case(s) a choisir !",64-compteur_case);
	else
	  sprintf(texte_compteur,"Votre parcours est valide! Appuyer 's' pour sauvegarder!");
	/* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
	
      }
      else 
	sprintf(texte_compteur,"Votre parcours a ete sauvegarde sous le nom de %d.txt",prochaine_sauv);
      
      msg = TTF_RenderText_Blended(police2,texte_compteur, couleurnoire);
      
      
      
      /*Efface l'ecran en blanc*/
      SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
      aff_Cadre_Editer(ecran,carre);
      aff_Parcous(ecran,carre,position_chemin,position_chemin_dans_image);
      aff_Fantome(ecran,carre,pos_ij);
      SDL_BlitSurface(texte, NULL, ecran, &posline); /* Blit du texte */
      SDL_BlitSurface(texte2, NULL, ecran, &postexte); /* Blit du texte */
      SDL_BlitSurface(msg, NULL, ecran, &posmsg); /* Blit du texte */
      SDL_Flip(ecran);  
      if(msg_final==1){
	SDL_Delay(1500);
	break;
      }
    }
  
  /*Fermeture de la police et de TTF*/
  TTF_CloseFont(police2);
  TTF_CloseFont(police);
  TTF_Quit();
  SDL_FreeSurface(texte);
  SDL_FreeSurface(texte2);
  SDL_FreeSurface(msg);
  SDL_FreeSurface(carre);
  
  
  *nb=nbparcours;
}

void aff_Cadre_Editer(SDL_Surface* ecran,SDL_Surface* carre){
  /*affiche le quadrillage*/
  /*Astuce: Modifier les coordonnees des position dans l'image permet d'avoir une autre case en fond de quadrillage*/
  SDL_Rect pos,pos_dans_image;
  int i,j;  
  pos_dans_image.y=0;
  pos_dans_image.x=0;//(0,0) correspond a la 1er case dans l'image source
  pos_dans_image.h=50;//hauteur d'un bloc dans image source
  pos_dans_image.w=50;//largeur d'un bloc dans image source 
  for(i=0;i<12;i++)
    for(j=0;j<8;j++){
      pos.y=j*50;
      pos.x=i*50;
      SDL_BlitSurface(carre,&pos_dans_image , ecran, &pos); /* Blit du texte */
      
    }
}


void aff_Fantome(SDL_Surface* ecran,SDL_Surface* carre,SDL_Rect pos){
  /*affiche la case qui se deplace dans le quadrillage que j'appel fantome*/ 
  /*Astuce: Modifier les coordonnees des position dans l'image permet d'avoir une autre case en fantome*/
  
  SDL_Rect pos_dans_image;
  pos_dans_image.y=0;
  pos_dans_image.x=550;//(500,0) correspond a la dernier case et 1er ligne
  pos_dans_image.h=50;//hauteur d'un bloc dans image source
  pos_dans_image.w=50;//largeur d'un bloc dans image source 
  SDL_SetAlpha(carre, SDL_SRCALPHA, 120);
  SDL_BlitSurface(carre,&pos_dans_image , ecran, &pos); /* Blit du texte */
  SDL_SetAlpha(carre, SDL_SRCALPHA, 255);
}


int selec_Aff_Case_Dispo(SDL_Surface* ecran,SDL_Surface* carre,int nbcase,SDL_Rect pos_ij,SDL_Rect position_chemin[64],SDL_Rect position_chemin_dans_image[64]){
  
  /*Cette fonction sert a faire le choix de la case qu'on veut ajouté a telle ou telle endroit*/
  
  int it,compteur_dans_image=1,itmax=20,continuer=1,it2,case_ajouter=0;
  SDL_Rect tt_les_case_dans_image[20],case_a_ecran;
  SDL_Rect tt_les_case_dans_ecran[20];
  SDL_Event event;
  SDL_Surface *selected;
  
  selected=SDL_LoadBMP("../images/selected.bmp");
  if(!selected){
    printf("impossible d'editter\nL'image selected dans image/route/ est introuvable");
    return EXIT_FAILURE;
  }
  case_a_ecran.x=0;
  case_a_ecran.y=480;
  
  /*Premiere etape: affiche les cases disponible selon le nb de case restant a dessiner*/
  if(nbcase==0){
    
    compteur_dans_image=12;
    itmax=1;
    tt_les_case_dans_image[0].y=(compteur_dans_image/12)*50;
    tt_les_case_dans_image[0].x=(compteur_dans_image%12)*50;
    tt_les_case_dans_image[0].h=50;
    tt_les_case_dans_image[0].w=50;
    
  }
  
  if(nbcase==63){
    
    compteur_dans_image=17;
    itmax=1;
    tt_les_case_dans_image[0].y=(compteur_dans_image/12)*50;
    tt_les_case_dans_image[0].x=(compteur_dans_image%12)*50;
    tt_les_case_dans_image[0].h=50;
    tt_les_case_dans_image[0].w=50;
    
  }
  else if(nbcase>0&&nbcase<63){
    
    for(it=0;it<itmax;it++){
      if(compteur_dans_image==12||compteur_dans_image==17)compteur_dans_image++;
      tt_les_case_dans_image[it].y=(compteur_dans_image/12)*50;
      tt_les_case_dans_image[it].x=(compteur_dans_image%12)*50;
      tt_les_case_dans_image[it].h=50;
      tt_les_case_dans_image[it].w=50;
      compteur_dans_image++;
      
    }
  }//fin if(nbcase.....)
  
  /*dessin des cases disponible a l'ecran*/
  for(it=0;it<itmax;it++){
    tt_les_case_dans_ecran[it].x=case_a_ecran.x;
    tt_les_case_dans_ecran[it].y=case_a_ecran.y;
    //debut calcule de position
    case_a_ecran.x+=50;
    if(case_a_ecran.x==600){
      case_a_ecran.x=0;
      case_a_ecran.y+=50;
    }
    //fin calcule et affiche a l'endroit calculé
    SDL_BlitSurface(carre,&tt_les_case_dans_image[it], ecran, &tt_les_case_dans_ecran[it]); /* Blit du texte */   
  }
  it=0;
  case_a_ecran.x= tt_les_case_dans_ecran[it].x;
  case_a_ecran.y= tt_les_case_dans_ecran[it].y;
  
  SDL_SetColorKey(selected, SDL_SRCCOLORKEY, SDL_MapRGB(selected->format,255,255, 255));/*j'efface le blanc de l'image*/
  SDL_BlitSurface(selected,NULL, ecran,&case_a_ecran); /* Blit de la case grise*/   
  
  /*choix de la case a placé*/
  SDL_Flip(ecran);
  while(continuer){
    SDL_WaitEvent(&event);
    if(event.type==SDL_QUIT)
      exit(0); 
    if(event.type==SDL_KEYUP){
      if(event.key.keysym.sym==SDLK_ESCAPE||event.key.keysym.sym==SDLK_m||event.key.keysym.sym==SDLK_BACKSPACE){
	continuer=0;
      }
      
      if(event.key.keysym.sym==SDLK_RIGHT&&it+1<itmax)
	it++;
      if(event.key.keysym.sym==SDLK_LEFT&&it-1>=0)
	it--;
      if(event.key.keysym.sym==SDLK_DOWN&&it+12<itmax)
	it+=12;
      if(event.key.keysym.sym==SDLK_UP&&it-12>=0)
	it-=12;
      if(event.key.keysym.sym==SDLK_RETURN)
	{
	  case_ajouter=1;
	  position_chemin_dans_image[nbcase].x=tt_les_case_dans_image[it].x;
	  position_chemin_dans_image[nbcase].y=tt_les_case_dans_image[it].y;
	  position_chemin_dans_image[nbcase].w=50;
	  position_chemin_dans_image[nbcase].h=50;
	  position_chemin[nbcase].x=pos_ij.x;
	  position_chemin[nbcase].y=pos_ij.y;
	  break;
	}
    }

    case_a_ecran.x= tt_les_case_dans_ecran[it].x;
    case_a_ecran.y= tt_les_case_dans_ecran[it].y;
    for(it2=0;it2<itmax;it2++){
      SDL_BlitSurface(carre,&tt_les_case_dans_image[it2], ecran, &tt_les_case_dans_ecran[it2]); /* Blit de tt les carre */   
    }
    SDL_SetColorKey(selected, SDL_SRCCOLORKEY, SDL_MapRGB(selected->format,255,255, 255));/*j'efface le blanc de l'image*/
    SDL_BlitSurface(selected,NULL, ecran,&case_a_ecran); /* Blit de la grosse case grise*/   

    SDL_Flip(ecran);
  }
  SDL_FreeSurface(selected);
  return case_ajouter;
}//fin fonction

void aff_Parcous(SDL_Surface* ecran,SDL_Surface* carre,SDL_Rect position_chemin[64],SDL_Rect position_chemin_dans_image[64]){
  /*affiche un parcours*/
  int it;
 
  for(it=0;it<64;it++){
    if(position_chemin[it].x==-100)continue;
    SDL_BlitSurface(carre,&position_chemin_dans_image[it], ecran, &position_chemin[it]); 
    /* Blit case parcours 1 a 1 */   
  }
}


int possiblite_Case_Ij(SDL_Rect pos_ij,SDL_Rect chemin[64]){

  int it;
  /*retourne 1 quand la case dans laquelle on veut placer un evenement est libre*/
  for(it=0;it<64;it++)
    if(pos_ij.x==chemin[it].x&&pos_ij.y==chemin[it].y)
      return 0;
  return 1;
}
void sauvegarde_Edition(SDL_Rect pos_sur_ecran[64],SDL_Rect pos_sur_image[64],int iemeparcours){
  /*sauvegarde une carte*/
  char txt[1000];
  FILE *f;
  int it;
  sprintf(txt,"../carte/%d.txt",iemeparcours);

  f=fopen(txt,"w+");

  for(it=0;it<64;it++){
    fprintf(f,"%d %d %d %d\n",(int)pos_sur_ecran[it].x,(int)pos_sur_ecran[it].y,
	    (int)pos_sur_image[it].x,(int)pos_sur_image[it].y);
  }

  fclose(f);
}

void charge_Sauvegarde_Edition(SDL_Rect pos_sur_ecran[64],SDL_Rect pos_sur_image[64],int iemeparcours){
  /*charge une carte*/
  char txt[1000];
  FILE *f;
  int it,a,b,c,d;
  sprintf(txt,"../carte/%d.txt",iemeparcours);

  f=fopen(txt,"r");

  for(it=0;it<64;it++){
    fscanf(f,"%d %d %d %d",&a,&b,&c,&d);
    pos_sur_ecran[it].x=a;
    pos_sur_ecran[it].y=b;
    pos_sur_image[it].x=c;
    pos_sur_image[it].y=d;
    pos_sur_image[it].h=50;
    pos_sur_image[it].w=50;
  }

  fclose(f);
}

int transforme_Pos_Image_En_Val(SDL_Rect pos){
  /*fonction qui transforme une positon d'un carre dans une image en valeur
    qui sera utiliser pour la génération d'evenement
    je conseille d'utiliser cette fonction 64 fois et de stocker les valeur dans un tableau*/
  if(pos.x==50&&pos.y==50)
    return 1;/*bonus*/
  if(pos.x==100&&pos.y==50)
    return 2;/*malus*/
  if(pos.x==150&&pos.y==50)
    return 3;/*prison*/
  if(pos.x==200 &&pos.y==50)
    return 4;/*Rejouer*/
  return 0;//Pour toute les autres cases
}

void menu_Editer(SDL_Surface* ecran){
  SDL_Surface* menu;
  SDL_Surface* txt1,*txt2,*txt3,*titre;
  SDL_Event event;
  int continuer=1,cpt=0;
  TTF_Font *police = NULL,*police2=NULL,*police3 = NULL;
  SDL_Rect postxt1,postxt2,postitre,postxt3;
  SDL_Color couleurnoire;
  couleurnoire.r=0;
  couleurnoire.g=0;
  couleurnoire.b=0;
  int nbcarte=0;
  FILE* info;

  //lecture du nombre de carte disponible
  info=fopen("../carte/info.txt","r");
  if(info)
    fscanf(info,"%d",&nbcarte);
  else{
    info=fopen("../carte/info.txt","w+");
    fprintf(info,"0");
  }
  fclose(info);

  menu=SDL_LoadBMP("../images/img_menu_editter.bmp");

  if(!menu){
    printf("L'image au chemin: image/ecrantitre/img_menu_editter.bmp est innexistante\n");
    exit(0);
  }

  TTF_Init(); //initialisation du texte

  police = TTF_OpenFont("../Police/comicbd.ttf",25);//Chargement de la police
  police2 = TTF_OpenFont("../Police/comicbd.ttf",28);//Chargement de la police
  police3 = TTF_OpenFont("../Police/tanglewo.ttf",52);//Chargement de la police

  /*Chargement des position sur l'ecran*/
  postitre.x=120;
  postitre.y=70;	
 
  postxt1.x=5;
  postxt1.y=250;

  postxt2.x=5;
  postxt2.y=320;

  postxt3.x=5;
  postxt3.y=500;
 
  titre = TTF_RenderText_Blended(police3, "Menu editer",couleurnoire);
  txt3= TTF_RenderText_Blended(police, "Appuyer 'Delete' pour revenir au menu principale",couleurnoire);

  while(continuer){

    SDL_WaitEvent(&event);
    if(event.type==SDL_QUIT)
      exit(0);
      
    if(event.type==SDL_KEYDOWN){ 
      if(event.key.keysym.sym==SDLK_BACKSPACE)
	continuer=0; 

      if(event.key.keysym.sym==SDLK_RETURN){	
	if(!cpt)
	  creation(ecran,&nbcarte);
	else
	  visualisation_Suppression(ecran,&nbcarte);
      }   
      if(event.key.keysym.sym==SDLK_DOWN)
	cpt=1;
      if(event.key.keysym.sym==SDLK_UP)
	cpt=0;
    }
    if(!cpt){
      txt1 = TTF_RenderText_Blended(police2, "->Creation de parcours<-",couleurnoire);
      txt2 = TTF_RenderText_Blended(police, "  Visualisation,suppression de parcours",couleurnoire);

    }else{
      txt1 = TTF_RenderText_Blended(police, "  Creation de parcours",couleurnoire);
      txt2 = TTF_RenderText_Blended(police2, "->Visualisation,suppression de parcours<-",couleurnoire);    
    }
    txt3= TTF_RenderText_Blended(police, "Appuyer 'Delete' pour revenir au menu principale",couleurnoire);

    SDL_BlitSurface(menu,NULL, ecran, NULL); 
    SDL_BlitSurface(titre, NULL, ecran, &postitre); /* Blit du texte */
    SDL_BlitSurface(txt1, NULL, ecran, &postxt1); /* Blit du texte */
    SDL_BlitSurface(txt2, NULL, ecran, &postxt2); /* Blit du texte */
    SDL_BlitSurface(txt3, NULL, ecran, &postxt3); /* Blit du texte */

    txt3= TTF_RenderText_Blended(police, "Appuyer 'Entrer' pour confirmer votre choix",couleurnoire); 
    postxt3.x=5; /*changement de position*/
    postxt3.y=550;
    SDL_BlitSurface(txt3, NULL, ecran, &postxt3); /* Blit du texte */
  
    postxt3.x=5; /*retour au ancienne valeurs*/
    postxt3.y=500;
 
    SDL_Flip(ecran);

  }
  /*Fermeture de la police et de TTF*/
  TTF_CloseFont(police3);
  TTF_CloseFont(police2);
  TTF_CloseFont(police);
  TTF_Quit();
  SDL_FreeSurface(txt1);
  SDL_FreeSurface(txt2);
  SDL_FreeSurface(txt3);
  SDL_FreeSurface(titre);
  SDL_FreeSurface(menu);

  /*reeouverture du fichieer en ecriture pour y placé les nvelles données*/
  info=fopen("../carte/info.txt","w+");
  fprintf(info,"%d",nbcarte);
  fprintf(info,"\nCe fichier ne doit être en aucun cas modifié, il contient le nb de carte enregistrer.\nSi vous voulez supprimer une carte ou plusieurs veuillez remplacer le nombre ci-dessus par le nouveau nombre de carte.\n");
  fclose(info);
}



void visualisation_Suppression(SDL_Surface* ecran,int *nb){
  /*Permet de voir toutes les cartes disponibles et de supprimé celle que l'on veut*/
 if(*nb==0)
   return;

  SDL_Surface *carre;
  int continuer=1;
  int nbcarte=0;
  int suiv=0;
  int nbcartemax=*nb;
  SDL_Event event;
  char chemin[1024];
  SDL_Rect pos_sur_ecran[64];
  SDL_Rect pos_sur_image[64];
  SDL_Rect postxt;
  TTF_Font *police = NULL;
  SDL_Surface* txt;
  SDL_Color couleurnoire;
  couleurnoire.r=0;
  couleurnoire.g=0;
  couleurnoire.b=0;
  TTF_Init(); //initialisation du texte
  police = TTF_OpenFont("../Police/tanglewo.ttf",27);//Chargement de la police
  carre=SDL_LoadBMP("../images/ttcase.bmp");/*chargement de tout les carrer*/

  if(nbcartemax>0){//il faut au minimun une carte
    suiv=nb_Parcours(nbcarte);//la carte n°"nbcarte"
    charge_Sauvegarde_Edition(pos_sur_ecran,pos_sur_image,suiv);/*Mise a jour des tableau contenant des coordonnées ncessaire a l'affichage*/
  }
  //printf("le nombre de carte max est %d\n",*nb);
  while(continuer){
    SDL_WaitEvent(&event);
    if(event.type==SDL_QUIT)
      exit(0);
      
    if(event.type==SDL_KEYUP){ 
      if(event.key.keysym.sym==SDLK_ESCAPE)
	continuer=0; 

      if(event.key.keysym.sym==SDLK_s  && (*nb > 1)){	
	sprintf(chemin,"rm ../carte/%d.txt",suiv);
	system(chemin);
	nbcartemax--;
	break;
      }    
      
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
      
    } 
    /*Efface l'ecran en blanc*/
    SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    aff_Parcous( ecran,carre,pos_sur_ecran,pos_sur_image);

    /*je réutilse chemin txt et postxt dans la meme manière que création*/

    sprintf(chemin,"Carte numero %d ",nbcarte+1);
    //sprintf(chemin,"Fichier: %d.txt",suiv);//nom du fichier
    txt = TTF_RenderText_Blended(police, chemin,couleurnoire); 
    postxt.x=5; 
    postxt.y=450;
    SDL_BlitSurface(txt, NULL, ecran, &postxt); /* Blit du texte */

    sprintf(chemin,"Utiliser les fleches gauche et droite pour passer");
    txt= TTF_RenderText_Blended(police, chemin,couleurnoire); 
    postxt.x=5; 
    postxt.y=500;
    SDL_BlitSurface(txt, NULL, ecran, &postxt); /* Blit du texte */

    sprintf(chemin,"Appuyer 's' pour supprimer et 'echap' pour quitter");
    txt= TTF_RenderText_Blended(police, chemin,couleurnoire); 
    postxt.x=5; 
    postxt.y=550;
    SDL_BlitSurface(txt, NULL, ecran, &postxt); /* Blit du texte */

    SDL_Flip(ecran);

  
  }

  *nb=nbcartemax;
  SDL_FreeSurface(txt);
  TTF_CloseFont(police);
  TTF_Quit();
}  






