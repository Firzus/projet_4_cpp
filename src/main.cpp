// std
#include <stdio.h>

// opengl
#include <GL/glew.h>

// sdl
#include <SDL2/SDL.h>

// maths
#include <math.h>

// text
#include "SDL2/SDL_ttf.h"

//
#include "include/Fonction.cpp"

#define WINDOW_W 600
#define WINDOW_H 600

int main(int argc, char *argv[])
{
    int done = 0;
    int x, y;
    SDL_Window *fenetre;
    SDL_Renderer *renderer; // Déclaration du renderer

    if (SDL_VideoInit(NULL) < 0) // Initialisation de la SDL
    {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    if (TTF_Init() == -1)
    {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }

    /* pas d'erreur sur l'initialisation */

    TTF_Font *font = NULL;
    font = TTF_OpenFont("OpenSans.ttf", 100);

    // Création de la fenêtre :
    fenetre = SDL_CreateWindow("Une fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, 0);
    if (fenetre == NULL) // Gestion des erreurs
    {
        printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Création du renderer :
    renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer
    if (renderer == NULL)                                                                             // gestion des erreurs
    {
        printf("Erreur lors de la creation d'un renderer : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // On met le fond en bleu
    SDL_SetRenderDrawColor(renderer, 182, 216, 242, 0);
    SDL_RenderClear(renderer);

    // dessine le bouton prise des biberons
    SDL_Rect r;
    r.x = 200;
    r.y = 200;
    r.w = 200;
    r.h = 200;
    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor(renderer, 244, 207, 223, 0);

    // Render rect
    SDL_RenderFillRect(renderer, &r);

    SDL_Surface *s = TTF_RenderText_Solid(font, "Bonjour", {0, 0, 0, 255});
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, s);
    SDL_FreeSurface(s);
    SDL_RenderCopy(renderer, tex, NULL, &r);

    // Toujours penser au rendu, sinon on n'obtient rien du tout

    while (done != 1)
    {
        SDL_RenderPresent(renderer);
        event(fenetre, renderer, done, x, y);
        SDL_Delay(100);
    }

    // Destruction du renderer et de la fenêtre :
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);

    TTF_CloseFont(font);
    TTF_Quit();

    SDL_Quit(); // On quitte la SDL
}