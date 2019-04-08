#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>

int main (void)
{

SDL_Init(SDL_INIT_EVERYTHING);
SDL_Surface *ecran,*image=NULL,*background=NULL,*pp=NULL;
int x=0,y=0,test=1;

background=IMG_Load("background.bmp");

//initiation de la camera Pour le scrolling
SDL_Rect camera;
camera.x=0;
camera.y=0;
camera.w=680;
camera.h=400;

//initiation de l'ecran fonction deja prete!	
ecran=SDL_SetVideoMode(640,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Rect positionecran;
positionecran.x=0;
positionecran.y=0;

//initiation joueur fonction deja prete!
pp=IMG_Load("detective.png");
SDL_Rect positionpp;
positionpp.x=200;
positionpp.y=170;

const int vitesse=10;
SDL_EnableKeyRepeat(30,30);
//Deplacement du joueur dans tous les sens avec le scrolling !!
while(test)
{

SDL_Event event;
while(SDL_PollEvent(&event))
{
switch (event.type)
{

 case SDL_KEYDOWN : 
{
//QUITTER
if(event.key.keysym.sym==SDLK_ESCAPE)
test=0;

//DROITE
if(event.key.keysym.sym==SDLK_RIGHT)
{
positionpp.x+=1;
camera.x+=vitesse;
//fin du jeu ne depasse pas le background (1600 longueur du bg , 600 tt depend du resultat de laffichage )
if(camera.x>=1600-660)
{
camera.x-=vitesse;
positionpp.x+=vitesse+1;
}


SDL_BlitSurface(background, NULL, ecran, &positionecran);
SDL_BlitSurface(background,&camera,ecran,NULL);
SDL_BlitSurface(pp,NULL, ecran, &positionpp);
SDL_Flip(ecran);
}

//GAUCHE
if(event.key.keysym.sym==SDLK_LEFT)
{
positionpp.x-=1;
/*en reculant la camera doit fonctionner que lorsque le joueur atteint le mileu de lecran!!!! Ca fonctionne pas */
if(camera.x/positionpp.x<=2)
camera.x-=vitesse;

//debut du jeu ne va pas a gauche
if(camera.x<=0)
{
positionpp.x+=1;
camera.x+=vitesse;
}

SDL_BlitSurface(background, NULL, ecran, &positionecran);
SDL_BlitSurface(background,&camera,ecran,NULL);
SDL_BlitSurface(pp,NULL, ecran, &positionpp);
SDL_Flip(ecran);
}
//HAUT
if(event.key.keysym.sym==SDLK_UP)
{
positionpp.y-=vitesse;
if(positionpp.y<150)
positionpp.y+=vitesse;

SDL_BlitSurface(background, NULL, ecran, &positionecran);
SDL_BlitSurface(background,&camera,ecran,NULL);
SDL_BlitSurface(pp,NULL, ecran, &positionpp);
SDL_Flip(ecran);

}

//BAS
if(event.key.keysym.sym==SDLK_DOWN)
{
positionpp.y+=vitesse;
if(positionpp.y>=190)
positionpp.y-=vitesse;

SDL_BlitSurface(background, NULL, ecran, &positionecran);
SDL_BlitSurface(background,&camera,ecran,NULL);
SDL_BlitSurface(pp,NULL, ecran, &positionpp);
SDL_Flip(ecran);
}


}
break;

}
}

SDL_BlitSurface(background, NULL, ecran, &positionecran);
SDL_BlitSurface(background,&camera,ecran,NULL);
SDL_BlitSurface(pp,NULL, ecran, &positionpp);
SDL_Flip(ecran);

}
}
