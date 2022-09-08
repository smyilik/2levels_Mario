#include "head.h"

void Paused(Window& window, PauseMenu& pause, bool& shutDown, bool& tomainMenu)
{
    SDL_Event e;
    int x, y;
    pause.Query();
    while (1) {
        SDL_PollEvent(&e);
        SDL_GetMouseState(&x, &y);
        if ((e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE) ||
            ((GetKeyState(VK_LBUTTON) & 0x8000) != 0 && pause.InContinue(x, y))) {
            break;
        }

        else if (pause.InQuit(x, y) && (GetKeyState(VK_LBUTTON) & 0x8000) != 0) {
            tomainMenu = true;
            break;
        }

        else if (e.type == SDL_QUIT) {
            shutDown = true;
            break;
        }

        else {
            SDL_RenderCopy(window.renderer, pause.texture, NULL, &pause.hitbox);
            SDL_RenderPresent(window.renderer);
        }
    }
}

void ShowHearts(Player player, Window& window, SDL_Texture*& heart)
{
    SDL_Rect texr;
    for (int i = 0; i < player.Hearts(); i++) {
        texr.x = (i * 70) + 10;
        texr.y = 10;
        texr.w = 64;
        texr.h = 61;
        SDL_RenderCopy(window.renderer, heart, NULL, &texr);
    }
}