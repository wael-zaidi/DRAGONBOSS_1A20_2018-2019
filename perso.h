#ifndef DS1_H_INCLUDED
#define DS1_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct perssonage
{
SDL_Surface *personnage;
SDL_Rect rect;
SDL_Rect rects[60];
int frame;
float xvelocity,yvelocity;
int stable_direction;
float x1 , x2 , x3 , x4 , x5 , x6 , x7 , x8 , x9 , x10 , x11 , x12 , x13 , x14 , x15 , x16 ;  //points de verification de collision parfaite
float y1 , y2 , y3 , y4 , y5 , y6 , y7 , y8 , y9 , y10 , y11 , y12 , y13 , y14 , y15 , y16 ;  // points de verification de collision parfaite
}perssonage;

void setrects(SDL_Rect* clip);
void initialiser_perssonage (perssonage *p);
void afficher_perssonage (perssonage *p,SDL_Surface *screen);
void animation_right (perssonage *p);
void animation_left (perssonage *p);
void animation_stable (perssonage *p);
void mouvementright (perssonage *p);
void mouvementleft (perssonage *p);


  #endif // DS_H_INCLUDED
