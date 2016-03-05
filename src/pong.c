
/**
 * \file pong.c
 * \brief Code source du Mini-jeu pong en SDL.
 * \author Abak-kali Nizar
 * \date 11 mars 2013
 *
 */
 
 #include "../headers/bibliotheque_mini_jeux.h"
/*Fonction principale du jeu du Pong. Elle va gérer les différents évènement d'une partie de Pong | Elle renvoie l'indice du gagnant à la fin de la partie*/
int jouer_pong(SDL_Surface* screen,int _indicej1 , int _indicej2){
  //creation des principales surfaces
  SDL_Surface  *raquette1, *raquette2, *balle ,*ligne_du_milieu;

  //creation des position de ces surfaces
  SDL_Rect praquette1, praquette2, pballe,pligne_du_milieu;
  SDL_Event event;
  int continuer = 1;
  int x = 1;
  int y = 0;
  int score_j1 = 0;
  int score_j2 = 0;


 balise_restart:
  //creation des raquettes
  raquette1 = SDL_CreateRGBSurface(SDL_HWSURFACE, TAILLE_RAQUETTE_LARGEUR, TAILLE_RAQUETTE_LONGUEUR, 32, 0, 0, 0, 0);
  SDL_FillRect(raquette1, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  praquette1.y = (TAILLE_FENETRE_Y - TAILLE_RAQUETTE_LONGUEUR)/2;
  praquette1.x = 0;
  SDL_BlitSurface(raquette1, NULL, screen, &praquette1);

  raquette2 = SDL_CreateRGBSurface(SDL_HWSURFACE, TAILLE_RAQUETTE_LARGEUR,TAILLE_RAQUETTE_LONGUEUR, 32, 0, 0, 0, 0);
  SDL_FillRect(raquette2, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  praquette2.y = (TAILLE_FENETRE_Y - TAILLE_RAQUETTE_LONGUEUR)/2;
  praquette2.x = TAILLE_FENETRE_X-TAILLE_RAQUETTE_LARGEUR;
  SDL_BlitSurface(raquette2, NULL, screen, &praquette2);

  // creation de la ligne du milieu
  ligne_du_milieu = SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_LIGNE_DU_MILIEU, TAILLE_FENETRE_Y, 32, 0, 0, 0, 0);
  SDL_FillRect(ligne_du_milieu, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  pligne_du_milieu.y = 0;
  pligne_du_milieu.x = (TAILLE_FENETRE_X)/2;
  SDL_BlitSurface(ligne_du_milieu, NULL, screen, &pligne_du_milieu);

  //creation de la balle
  balle = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 30, 32, 0, 0, 0, 0);
  SDL_FillRect(balle, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  pballe.x = (TAILLE_FENETRE_X - TAILLE_BALLE)/2;//position de la
  pballe.y = (TAILLE_FENETRE_Y - TAILLE_BALLE)/2;// BALLE INITIALE
  SDL_BlitSurface(balle, NULL, screen, &pballe);

  //Ajustements
  SDL_EnableKeyRepeat(10,10);

  // BOUCLE PRINCIPALE
  while (continuer)
    {
      SDL_PollEvent(&event);
      // gestion des controle des raquettes
      switch(event.type) {
        case SDL_QUIT:
	  continuer = 0;
	  break;

        case SDL_KEYDOWN:// debut gestion clavier
	  switch(event.key.keysym.sym)
            {
	      // POUR QUITTER LE JEU
            case SDLK_ESCAPE:
	      continuer = 0;
	      break;

	      // BOUTON DU RESTART
            case SDLK_r:
	      y = 0;
	      x = 1;
	      goto balise_restart;
	      break;

	      // Flèche haut pour raquette 1
            case SDLK_UP:
	      praquette2.y = praquette2.y - 1;
	      break;

	      // Flèche bas pour raquette 1
            case SDLK_DOWN:
	      praquette2.y = praquette2.y + 1;
	      break;
	      // Flèche haut pour raquette 2
            case SDLK_v:
	      praquette1.y = praquette1.y - 1;
	      break;

	      // Flèche bas pour raquette 2
            case SDLK_SPACE:
	      praquette1.y = praquette1.y + 1;
	      break;

            default:
	      break;
            }//fin gestion clavier
	  break;
        
	default:
	  break;
        }//fin gestion des controles generale 
      
      //gestion de collision de le raquette 1 avec le mur du haut et celui du bas
      if(praquette1.y<0){
	praquette1.y = 0;
      }
      if(praquette1.y+TAILLE_RAQUETTE_LONGUEUR > TAILLE_FENETRE_Y){
	praquette1.y = TAILLE_FENETRE_Y-TAILLE_RAQUETTE_LONGUEUR;
      }
      //idem pour la raquette 2
      if(praquette2.y<0){
	praquette2.y = 0;
      }
      if(praquette2.y+TAILLE_RAQUETTE_LONGUEUR > TAILLE_FENETRE_Y){
	praquette2.y = TAILLE_FENETRE_Y-TAILLE_RAQUETTE_LONGUEUR;
      }

      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0)); /* On efface l'écran */
      SDL_BlitSurface(raquette1, NULL, screen, &praquette1);//on recolle la raquette 1 avec la position renouveller
      SDL_BlitSurface(raquette2, NULL, screen, &praquette2);//on recolle la raquette 2 avec la position renouveller
      SDL_BlitSurface(ligne_du_milieu, NULL, screen, &pligne_du_milieu);

      // gestion des mouvements de la balle mur gauche ,droite , et raquette(1,2)
      switch (pballe.x)
        {

        case 0:
	  x=1;
	  y=0;
	  score_j2++;
	  if (score_j2 == SCORE_MAX)
	    return _indicej2;
	  else
	    goto balise_restart;
           
	  //quand abscisse pballe est a un distance d'une largeur de raquette du mur gauche
        case TAILLE_RAQUETTE_LARGEUR:
           
	  /*on decoupe la raquette en trois les deux extremite et le milieu
            les effets donner a la balle seront different selon la zone ou elle se trouvera
	  */

	  if((pballe.y > (praquette1.y - 20)) && (pballe.y < (praquette1.y + 20))){
	    x =  1;
	    y = -1;
	  }
	  if((pballe.y > (praquette1.y + 20)) && (pballe.y < (praquette1.y+80))){
	    x = 1;
	  }
	  if((pballe.y > praquette1.y+80) && (pballe.y < (praquette1.y+120))){
	    x = 1;
	    y = 1;
	  }
	  break;

        case ((TAILLE_FENETRE_X-(TAILLE_RAQUETTE_LARGEUR+TAILLE_BALLE))):
	  //quand abscisse pballe est a un distance d'une largeur de raquette du mur droit sur une fentre de 600*600

	  if((pballe.y > (praquette2.y - 20)) && (pballe.y < (praquette2.y + 20))){
	    x =  -1;
	    y = 1;
	  }
	  if((pballe.y > (praquette2.y + 20)) && (pballe.y < (praquette2.y+80))){
	    x = -1;
	  }
	  if((pballe.y > praquette2.y+80) && (pballe.y < (praquette2.y+120))){
	    x = -1;
	    y = -1;
	  }
	  break;

        case TAILLE_FENETRE_X-TAILLE_BALLE:
	  x=-1;
	  y=0;
	  score_j1++;
	  if (score_j1 == SCORE_MAX)
	    return _indicej1;
	  else
	    goto balise_restart;
        }//fin gestion de mouvement de la balle 

      // gestion des collision du haut et du bas de la  fenetre
      // on juste besoin de changer la direction horizontale
      if (pballe.y == 0)
	y = -y;
      if (pballe.y > (TAILLE_FENETRE_Y-TAILLE_BALLE))
	y = -y;

      // les nouveles position de la balle sont calculer
      pballe.x = pballe.x + x;
      pballe.y = pballe.y + y;

      // on blitte  l'image de la balle en boucle
      SDL_BlitSurface(balle, NULL, screen, &pballe);
      SDL_Flip(screen); /* On met à jour l'affichage */
      //  SDL_Delay(1);
    }//fin du while

  SDL_FreeSurface(ligne_du_milieu);
  SDL_FreeSurface(raquette1);
  SDL_FreeSurface(raquette2);
  SDL_FreeSurface(balle);

  return 0;
}//fin du jeux

