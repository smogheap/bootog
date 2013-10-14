#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"


int main(int argc, char **argv) {
	SDL_Window *win;
	SDL_Renderer *ren;
	SDL_Surface *img;
	SDL_Texture *tex;
	SDL_Rect src;
	SDL_Rect dst;

	if(SDL_Init(SDL_INIT_EVERYTHING)) {
		printf("SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}

	if(!(win = SDL_CreateWindow("Bootog",
								SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED,
								0, 0,
								SDL_WINDOW_FULLSCREEN_DESKTOP))) {
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		return 1;
	}
	if(!(ren = SDL_CreateRenderer(win, -1,
								  SDL_RENDERER_ACCELERATED |
								  SDL_RENDERER_PRESENTVSYNC))) {
		printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		return 1;
	}
	SDL_RenderSetLogicalSize(ren, 1920, 1080);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	if(!(img = IMG_Load("work/test.png"))) {
		printf("IMG_Load Error: %s\n", SDL_GetError());
		return 1;
	}
	tex = SDL_CreateTextureFromSurface(ren, img);
	SDL_FreeSurface(img);
	if(!tex) {
		printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
		return 1;
	}

	SDL_RenderClear(ren);
	dst.x = 10;
	dst.y = 10;
	dst.w = 100;
	dst.h = 100;
	SDL_RenderCopy(ren, tex, NULL, &dst);
	SDL_RenderPresent(ren);
	SDL_Delay(2000);

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
