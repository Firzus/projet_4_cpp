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

#define WINDOW_W 800
#define WINDOW_H 800

int main(int argc, char *argv[])
{
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
    font = TTF_OpenFont("include/Montserrat.ttf", 24);
    if (!font)
    {
        printf("Ya un pb\n");
    }

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

    // On met le fond en blanc
    SDL_SetRenderDrawColor(renderer, 87, 132, 186, 0);
    SDL_RenderClear(renderer);

    SDL_Surface *s = TTF_RenderText_Blended(font, "Bonjour!", {0, 0, 0, 255});
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, s);
    SDL_RenderCopy(renderer, tex, 0, 0);
    SDL_DestroyTexture(tex);
    SDL_FreeSurface(s);

    // Toujours penser au rendu, sinon on n'obtient rien du tout
    SDL_RenderPresent(renderer);

    SDL_Delay(5000); // pause de 20 secondes, pour admirer notre œuvre autant que l'on veut

    // Destruction du renderer et de la fenêtre :
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit(); // On quitte la SDL
}