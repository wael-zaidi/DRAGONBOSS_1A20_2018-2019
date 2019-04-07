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

#include "perso.h"
#include "background.h"
#include "enemy.h"


SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y);
void update_points_de_collision(perssonage* hero);
int collision_player_map_droite(background* acteurs , perssonage* hero);
int collision_player_map_gauche(background* acteurs , perssonage* hero);
int collision_player_map_top(background* acteurs , perssonage* hero);
int collision_player_map_bas(background* acteurs , perssonage* hero);




  #endif // DS_H_INCLUDED
