#include "Fonction.hpp"

void event(SDL_Window *window, SDL_Renderer *renderer, int &done, int &x, int &y)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {

        int x, y;
        SDL_GetMouseState(&x, &y);

        switch (event.type)
        {
        case SDL_WINDOWEVENT_CLOSE: // clique sur le bouton croix en haut à droite de la fenêtre
            if (window)
            {
                done = 1;
            }
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE: // touche échap préssée
                done = 1;
                break;
            }
            break;

        case SDL_MOUSEBUTTONDOWN:
            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:

                // BOUGE LE BOUTON //

                break;

            case SDL_QUIT:
                done = 1;
                break;
            }
        };
    };
}