#include "ClassHeader.h"

class Player
{
    private:
        int health = 3;
    public:
        SDL_Texture *texture;
        SDL_Rect texr;
        Player(SDL_Texture *&texture, int x, int y, int w, int h) {
            this->texture = texture;
            texr = { x,y,h,w };
            texr.x = x;
            texr.y = y;
            texr.w = w;
            texr.h = h;
            //texr = {texr.x, texr.y, texr.w, texr.h};
            //SDL_QueryTexture(texture, NULL, NULL, &texr.w, &texr.h);
        }

        void HealthNull() {
            health = 3;
        }

        void HealthRemove() {
            health--;
        }

        int Hearts() {
            return health;
        }

        bool Alive() {
            if (health < 1) {
                return false;
            }
            return true;
        }
};

class Comets
{
    public:
        SDL_Texture* texture;
        SDL_Rect texr;

        Comets(SDL_Texture *&texture, int x, int y, int w, int h)
        {
            this->texture = texture;
            texr.x = x;
            texr.y = y;
            texr.w = w;
            texr.h = h;
            SDL_QueryTexture(texture, NULL, NULL, &texr.w, &texr.h);
        }
};

class BackGround
{
    public:
        SDL_Texture* texture;
        SDL_Rect texr;
    
        BackGround(SDL_Texture *&texture, int x, int y, int w, int h)
        {
            this->texture = texture;
            texr.x = x;
            texr.y = y;
            texr.w = w;
            texr.h = h;
            SDL_QueryTexture(texture, NULL, NULL, &texr.w, &texr.h);
        }
};

class Window
{
    public:
        SDL_Window* window;
        SDL_Renderer* renderer;

        Window(int width, int height)
        {
            window = SDL_CreateWindow("Mario", 0, 50, width, height, 0);
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        }
};

class PauseMenu
{
    public:
        SDL_Texture* texture;
        SDL_Rect hitbox;
        PauseMenu(SDL_Texture*& texture, int x, int y, int w, int h)
        {
            this->texture = texture;
            hitbox.x = x;
            hitbox.y = y;
            hitbox.w = w;
            hitbox.h = h;
        }

        void Query()
        {
            SDL_QueryTexture(texture, NULL, NULL, &hitbox.w, &hitbox.h);
        }

        bool InContinue(int x, int y)
        {
            if (x >= (int)hitbox.x + 81 && x <= (int)hitbox.x + 325 &&
                y >= (int)hitbox.y + 71 && y <= (int)hitbox.y + 118) {
                return true;
            }
            return false;
        }
        bool InQuit(int x, int y)
        {
            if (x >= (int)hitbox.x + 81 && x <= (int)hitbox.x + 173 &&
                y >= (int)hitbox.y + 177 && y <= (int)hitbox.y + 220) {
                return true;
            }
            return false;
        }
};

class MainMenu
{
public:
    SDL_Texture* texture;
    SDL_Rect hitbox;
    MainMenu(SDL_Texture*& texture, int x, int y, int w, int h)
    {
        this->texture = texture;
        hitbox.x = x;
        hitbox.y = y;
        hitbox.w = w;
        hitbox.h = h;
    }

    void Query()
    {
        SDL_QueryTexture(texture, NULL, NULL, &hitbox.w, &hitbox.h);
    }

    bool InStart(int x, int y)
    {
        if (x >= (int)hitbox.x + 170 && x <= (int)hitbox.x + 440 &&
            y >= (int)hitbox.y + 200 && y <= (int)hitbox.y + 260) {
            return true;
        }
        return false;
    }
    bool InExit(int x, int y)
    {
        if (x >= (int)hitbox.x + 125 && x <= (int)hitbox.x + 295 &&
            y >= (int)hitbox.y + 510 && y <= (int)hitbox.y + 570) {
            return true;
        }
        return false;
    }
};