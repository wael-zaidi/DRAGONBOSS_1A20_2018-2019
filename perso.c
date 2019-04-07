#include "perso.h"


void setrects(SDL_Rect* clip)
{
	//vers droite
clip[0].x=0;
clip[0].y=0;
clip[0].w=150;
clip[0].h=150;
int i=1;
for (i=1; i<nb_frames;i++)
{
clip[i].w=150;
clip[i].h=150;
clip[i].x=clip[i].w+clip[i-1].x;
clip[i].y=0;
}

//vers gauche
clip[15].x=0;
clip[15].y=150;
clip[15].w=150;
clip[15].h=150;
 i=16;
for (i=16;i<(2*nb_frames);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=150;
clip[i].h=150;
}
//stable right
clip[30].x=0;
clip[30].y=300;
clip[30].w=150;
clip[30].h=150;
i=31;
for (i=31;i<(3*nb_frames);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=300;
clip[i].h=150;
}

//stable right
clip[30].x=0;
clip[30].y=300;
clip[30].w=150;
clip[30].h=150;
i=31;
for (i=31;i<(3*nb_frames);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=300;
clip[i].h=150;
}

//stable right
clip[45].x=0;
clip[45].y=450;
clip[45].w=150;
clip[45].h=150;
i=46;
for (i=46;i<(4*nb_frames);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=450;
clip[i].h=150;
}

}

void initialiser_perssonage (perssonage *p)
{
p->personnage=IMG_Load("graphic/hero/dante-run.png");
p->frame=29;
p->stable_direction=0;
p->rect.x=0;
p->rect.y=300;
p->rect.w=150;
p->rect.h=150;
p->xvelocity=SPEED;
p->yvelocity=SPEED;
setrects (p->rects);
}

void afficher_perssonage (perssonage *p,SDL_Surface *screen)
{
	SDL_BlitSurface(p->personnage,&p->rects[p->frame],screen,&p->rect);
}

void animation_right (perssonage *p)
{
  p->stable_direction=0;
	if(p->frame<=0 || p->frame>=15)
		p->frame=0;
	p->frame++;
	if (p->frame>=nb_frames)
		p->frame=0;
}

void animation_left (perssonage *p)
{
  p->stable_direction=1;
	if(p->frame<=14 || p->frame>=30)
		p->frame=15;

	p->frame++;
	if (p->frame>=2*nb_frames)
		p->frame=16;
}

void animation_stable (perssonage *p)
{
  if (p->stable_direction==0)
  {
	if(p->frame<=29 || p->frame>=45)
		p->frame=30;

	p->frame++;
	if (p->frame>=3*nb_frames)
		p->frame=30;
  }
else if (p->stable_direction==1)
{
if(p->frame<=44 || p->frame>=60)
  p->frame=45;

p->frame++;
if (p->frame>=4*nb_frames)
  p->frame=45;
}

}

void mouvementright (perssonage *p)
{

if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=MAX_SPEED;
if (p->rect.x<350)
p->rect.x+=p->xvelocity;
}

void mouvementleft (perssonage *p)
{
if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=MAX_SPEED;
if (p->rect.x>150)
p->rect.x-=p->xvelocity;
}
