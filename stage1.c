#include "stage1.h"

#define GRAVITY 10
#define SPEED 5
#define MAX_SPEED 20

int ground = 480;

void stage_1(SDL_Surface *screen, bool *success, int *action)
{
	TTF_Init();
	SDL_Surface *trait = NULL;
	trait = IMG_Load("graphic/stages/ligne.png");
	SDL_Rect poss;
	poss.x = 500;
	poss.y = 80;
	poss.h = trait->h;
	poss.w = trait->w;

	enemie f1, f2;
	perssonage p1, p2;
	background b1, b2;
	bool running = true;
	SDL_Event event;
	Input I, I2;
	//partage d'ecran
	initialiser_backround(&b1);
	b1.camera.x = 0;
	b1.camera.y = -80;
	b1.camera.w = 500;
	b1.camera.h = 600;
	b1.pos.x = 0;
	b1.pos.y = -80;
	//b1.pos.w = 500;
	//b1.pos.h = 300;
	initialiser_backround(&b2);
	b2.camera.x = 0;
	b2.camera.y = -80;
	b2.camera.w = 500;
	b2.camera.h = 600;
	b2.pos.x = 500;
	b2.pos.y = -80;
	//	b2.pos.w = 500;
	//	b2.pos.h = 300;
	initialiser_perssonage(&p1);
	p1.rect.x = 0;
	initialiser_perssonage(&p2);
	p2.rect.x = 500;

	inisialiser_enemie(&f1);
	f1.rect.x = 1100;
	inisialiser_enemie(&f2);
	f2.rect.x = 1600;

	initialiser_input(&I);
	initialiser_input(&I2);

	stat st1, st2;
	initialiser_stats(&st1);
	st1.health_pos.x = 150;
	st1.health_pos.y = 22;
	st1.mana_pos.x = 170;
	st1.mana_pos.y = 40;
	st1.lives_pos.x = 80;
	st1.lives_pos.y = 18;
	st1.icon_pos.x = 20;
	st1.icon_pos.y = 18;
	st1.score_pos.x = 130;
	st1.score_pos.y = 100;
	initialiser_stats(&st2);
	st2.health_pos.x = 650;
	st2.health_pos.y = 22;
	st2.mana_pos.x = 670;
	st2.mana_pos.y = 40;
	st2.lives_pos.x = 580;
	st2.lives_pos.y = 18;
	st2.icon_pos.x = 520;
	st2.icon_pos.y = 18;
	st2.score_pos.x = 680;
	st2.score_pos.y = 100;
	int rp;

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_Music *musique;
	musique = Mix_LoadMUS("graphic/stages/stage1.mp3");
	Mix_PlayMusic(musique, -1);
	SDL_EnableKeyRepeat(200, 0);
	while (running)
	{
		rp = -1;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				(*action) = 0;
				running = false;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					//PREMIER JOUEUR DEPLACEMENT
				case SDLK_ESCAPE:
					rp = pause(screen);
					if (rp == 0)
						running = false;
					break;
				case SDLK_RIGHT:
					I2.right = 1;
					break;

				case SDLK_LEFT:
					I2.left = 1;
					break;

				case SDLK_UP:
					I2.jump = 1;
					if (p2.rect.y == ground) //collision with ground
						p2.yvelocity = -60;
					p2.xvelocity = MAX_SPEED;
					break;

				case SDLK_DOWN:
					I2.down = 1;
					p1.yvelocity = 1;
					break;
				//DEUXIEME JOUEUR DEPLACEMENT
				case SDLK_d:
					I.right = 1;

					break;
				case SDLK_q:
					I.left = 1;
					break;
				case SDLK_z:
					I.jump = 1;
					if (p1.rect.y == ground) //collision with ground
						p1.yvelocity = -60;
					//collision with stairs -1 au lieu de -30
					p1.xvelocity = MAX_SPEED;
					break;
				case SDLK_s:
					I.down = 1;

					p2.yvelocity = 1;
					break;
				}
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
				case SDLK_RIGHT:
					I2.right = 0;
					break;
				case SDLK_LEFT:
					I2.left = 0;
					break;
				case SDLK_UP:
					I2.jump = 0;
				case SDLK_DOWN:
					I2.down = 0;
					if (p1.yvelocity > 0)
						p1.yvelocity = 0;
					//DEUXIEME JOUEUR
				case SDLK_d:
					I.right = 0;
					break;
				case SDLK_q:
					I.left = 0;
					break;
				case SDLK_z:
					I.jump = 0;
					break;
				case SDLK_s:
					I.down = 0;

					if (p2.yvelocity > 0)
						p2.yvelocity = 0;
					break;
				}
				break;
			}
		}

		if (I.right == 1)
		{
			p1.xvelocity += SPEED;

			scrolling_right(&b1, &p1, screen);
			animation_right(&p1);
			mouvementright(&p1);
		}
		else if (I.left == 1)
		{
			p1.xvelocity += SPEED;
			animation_left(&p1);
			mouvementleft(&p1);
			scrolling_left(&b1, &p1, screen);
		}

		else if (I.left == 0 && I.down == 0 && I.jump == 0 && I.right == 0)
		{
			animation_stable(&p1);
		}

		if (I2.right == 1)
		{
			p2.xvelocity += SPEED;
			scrolling_right(&b2, &p2, screen);
			animation_right(&p2);
			mouvementright2(&p2);
		}

		else if (I2.left == 1)
		{
			p2.xvelocity += SPEED;
			animation_left(&p2);
			mouvementleft2(&p2);
			scrolling_left2(&b2, &p2, screen);
		}

		else if (I2.left == 0 && I2.down == 0 && I2.jump == 0 && I2.right == 0)
		{
			animation_stable(&p2);
		}

		p1.yvelocity += GRAVITY;
		p1.rect.y += p1.yvelocity;
		p2.yvelocity += GRAVITY;
		p2.rect.y += p2.yvelocity;
		if (p1.rect.y >= ground)
		{
			p1.rect.y = ground;
			p1.yvelocity = 0;
		}
		p1.xvelocity = SPEED;
		if (p2.rect.y >= ground)
		{
			p2.rect.y = ground;
			p2.yvelocity = 0;
		}
		p2.xvelocity = SPEED;

		SDL_Rect relcoord_perssonage1 = {p1.rect.x + b1.x_relative, p1.rect.y, p1.rect.w, p1.rect.h};
		SDL_Rect relcoord1 = {f1.rect.x - b1.x_relative, f1.rect.y};
		SDL_Rect relcoord_perssonage2 = {p2.rect.x + b2.x_relative, p2.rect.y, p2.rect.w, p2.rect.h};
		SDL_Rect relcoord2 = {f2.rect.x - b2.x_relative, f2.rect.y};

		update_points_de_collision(&p1);
		update_points_de_collision(&p2);
		if (collision_player_map_bas(&b1, &p1) != 1)
			st1.val_score++;
		if (collision_player_map_bas(&b2, &p2) != 1)
			st2.val_score++;
		if (b1.camera.x >= 8000) // end map = 3000
		{
			(*success) = true;
			running = 0;
		}

		if (b2.camera.x >= 8000) // end map = 3000
		{
			(*success) = true;
			running = 0;
		}
		afficher_background(screen, &b1);
		afficher_background(screen, &b2);
		afficher_stats(&st1, screen);
		afficher_stats(&st2, screen);

		animation_health_up(&st1);
		animation_mana_down(&st1);
		animation_health_up(&st2);
		animation_mana_down(&st2);
		afficher_perssonage(&p2, screen);
		afficher_perssonage(&p1, screen);
		update_ennemi(&f1, screen, relcoord_perssonage1);
		update_ennemi(&f2, screen, relcoord_perssonage2);
		animation(&f1);
		animation(&f2);
		if (f1.rect.x <= b1.camera.x + 360)
			afficher_enemie(&f1, screen, relcoord1);
		if (f2.rect.x >= b2.camera.x + 500)
			afficher_enemie(&f2, screen, relcoord2);
		SDL_BlitSurface(trait, NULL, screen, &poss);
		SDL_Flip(screen);
		SDL_Delay(16);
	}
	TTF_Quit();
}
