#include "head.h"

SDL_Texture* IMG_LoadTexture(SDL_Renderer* renderer, const char* file)
{
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(file);
    if (surface) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
    return texture;
}

/*
1 - ground
2 - acceleration
3 - jump boost

5 - end

7 - ledder

9 - death
*/


//450 x 180 - rocket


int mar(int x, int y)
{
    int arg[13][109]{
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9, 0, 0, 0, 9, 9, 9, 0, 0, 0, 0, 3, 3, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 1, 9, 1, 1, 1, 1, 0, 0, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9, 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};
    return arg[y][x];
}

int mar2(int x, int y)
{
    int arg[9][179]{
    //{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    return arg[y][x];
}

void Moving(Window& window, Player& player, BackGround& backGround, Comets& firstComet, Comets& secondComet, Comets& thirdComet, bool& podnim, int& kol, int& pos, bool& victory, SDL_Texture*& Ptexture, int level)
{
    SDL_Texture* texturePlayer = IMG_LoadTexture(window.renderer, "C:/mario/pictures/mario_49x69.png");

    //    SDL_Texture* texturePlayer = IMG_LoadTexture(window.renderer, "C:/mario/pictures/rocket_launch.png");

    SDL_Texture* textureJump = IMG_LoadTexture(window.renderer, "C:/mario/pictures/mar_jump.png");
    SDL_Texture* textureBack = IMG_LoadTexture(window.renderer, "C:/mario/pictures/beg_nazad1.png");
    SDL_Texture* textureBack2 = IMG_LoadTexture(window.renderer, "C:/mario/pictures/beg_nazad2.png");
    SDL_Texture* textureForward = IMG_LoadTexture(window.renderer, "C:/mario/pictures/beg1.png");
    SDL_Texture* textureForward2 = IMG_LoadTexture(window.renderer, "C:/mario/pictures/beg2.png");

    int x, x1, x2, x3, y, y1, y2, y3;
    if (level == 1 || level == 3)
    {
        x = roundf(float(backGround.texr.x * (-1) + player.texr.x + 10) / 64.1),
        x1 = OurRound(float(backGround.texr.x * (-1) + player.texr.x + 10) / 64.1),
        y = roundf(float(player.texr.y + 30) / 64);
    }
    else
    {
        x = roundf(float(backGround.texr.x * (-1) + player.texr.x + 400) / 90);
        x1 = roundf(float(backGround.texr.x * (-1) + player.texr.x + 90) / 90);
        x2 = roundf(float(backGround.texr.x * (-1) + player.texr.x + 380) / 90);
        x3 = roundf(float(backGround.texr.x * (-1) + player.texr.x + 40) / 90);
        y = roundf(float(player.texr.y + 140) / 90);
        y1 = roundf(float(player.texr.y - 20) / 90);
        y2 = roundf(float(player.texr.y + 80) / 90);
        y3 = roundf(float(player.texr.y + 40) / 90);
        //cout << x << " " << y << endl;
    }


    if (level == 1 || level == 3)
    {
        if (mar(x, y + 1) == 5) {
            victory = true;
            //cout << "game over";
            return;
        }
        if (mar(x, y + 2) == 9 || mar(x, y + 1) == 9) {
            int count = 4 - player.Hearts();
            if (level == 1)
            {
                player = Player(Ptexture, 120, 500, 49, 60);
                backGround = BackGround(backGround.texture, 0, -16, 5000, 704);
            }


            for (int i = 0; i < count; i++) {
                player.HealthRemove();
            }
            if (!player.Alive()) {
                return;
            }
        }


        if (podnim == true && (mar(x, y + 1) != 1 && mar(x, y + 1) != 2 && mar(x, y + 1) != 3) && (level == 1 || level == 3)) {
            player.texr.y -= 5;
            player.texture = textureJump;
            int x = roundf(float(backGround.texr.x * (-1) + player.texr.x) / 64.1),
                x1 = roundf(float(backGround.texr.x * (-1) + player.texr.x + 20) / 64.1),
                y = roundf(float(player.texr.y + 30) / 64);
            if (player.texr.y <= pos - 180 || mar(x, y + 1) == 1 || mar(x1, y + 1) == 1) {
                podnim = false;
            }
        }

        if (podnim == false && (mar(x, y + 2) != 1 && mar(x, y + 2) != 2 && mar(x, y + 2) != 3) && (mar(x1, y + 2) != 1 && mar(x1, y + 2) != 2 && mar(x1, y + 2) != 3) && mar(x, y + 2) != 7 && mar(x1, y + 2) != 7 && (level == 1 || level == 3))
        {
            player.texture = textureJump;
            player.texr.y += 5;
        }

        if (podnim == false && (mar(x, y + 2) != 0) || (mar(x1, y + 2) != 0))
            player.texture = texturePlayer;



        if (GetKeyState('W') & 0x8000 && player.texr.y >= 5)
        {
            int x = roundf(float(backGround.texr.x * (-1) + player.texr.x + 10) / 64.1),
                x1 = OurRound(float(backGround.texr.x * (-1) + player.texr.x) / 64.1),
                y = roundf(float(player.texr.y + 30) / 64);
            if (mar(x, y + 1) == 7)
            {
                player.texr.y -= 5;
            }

            else
            {
                player.texture = textureJump;
                if ((mar(x, y + 2) == 1 || mar(x, y + 2) == 2 || mar(x, y + 2) == 3) || (mar(x1, y + 2) == 1 || mar(x1, y + 2) == 2 || mar(x1, y + 2) == 3)) {
                    if (mar(x, y + 2) == 3)
                        pos = player.texr.y - 100;
                    else
                        pos = player.texr.y;
                    podnim = true;


                    player.texr.y -= 5;
                }
            }

        }
        if (GetKeyState('A') & 0x8000 && backGround.texr.x < 0)
        {
            if (kol % 70 > 35) {
                player.texture = textureBack;
            }
            else {
                player.texture = textureBack2;
            }
            int x = roundf(float(backGround.texr.x * (-1) + player.texr.x - 27) / 64.1),
                y = OurRoundf(float(player.texr.y + 70) / 64),
                y1 = OurRoundf(float(player.texr.y) / 64);
            if (backGround.texr.x <= -5700 && player.texr.x > 120) {
                if ((mar(x, y + 1) != 1 && mar(x, y + 1) != 2 && mar(x, y + 1) != 3) && (mar(x, y1 + 1) != 1 && mar(x, y1 + 1) != 2 && mar(x, y1 + 1) != 3))
                    player.texr.x -= 5;
            }

            else {


                if ((mar(x, y + 1) != 1 && mar(x, y + 1) != 2 && mar(x, y + 1) != 3) && (mar(x, y1 + 1) != 1 && mar(x, y1 + 1) != 2 && mar(x, y1 + 1) != 3)) {
                    if (mar(x, y + 2) == 2) {
                        backGround.texr.x += 2;
                    }
                    else {
                        backGround.texr.x += 5;
                    }
                }
            }
        }

        if (GetKeyState('S') & 0x8000)
        {
            int x = roundf(float(backGround.texr.x * (-1) + player.texr.x + 10) / 64.1),
                x1 = OurRound(float(backGround.texr.x * (-1) + player.texr.x) / 64.1),
                y = OurRoundf(float(player.texr.y + 80) / 64);
            if (mar(x, y + 1) == 7 || mar(x1, y + 1) == 7)
            {
                player.texr.y += 5;
            }

        }

        if (GetKeyState('D') & 0x8000 && backGround.texr.x >= -7000 && player.texr.x <= 1100)
        {
            if (kol % 70 > 35) {
                player.texture = textureForward;
            }
            else {
                player.texture = textureForward2;
            }
            int x = roundf(float(backGround.texr.x * (-1) + player.texr.x + 23) / 64.1),
                y = OurRoundf(float(player.texr.y + 70) / 64),
                y1 = OurRoundf(float(player.texr.y) / 64);
            if (backGround.texr.x <= -5700/* && Ptexr.x >= 120 */) {
                if ((mar(x, y + 1) != 1 && mar(x, y + 1) != 2 && mar(x, y + 1) != 3) && (mar(x, y1 + 1) != 1 && mar(x, y1 + 1) != 2 && mar(x, y1 + 1) != 3))
                    player.texr.x += 3;
            }
            else {
                /*           int x = roundf(float(backGround.texr.x * (-1) + player.texr.x + 20) / 64.1),
                               y = OurRoundf(float(player.texr.y + 70) / 64);*/
                if ((mar(x, y + 1) != 1 && mar(x, y + 1) != 2 && mar(x, y + 1) != 3) && (mar(x, y1 + 1) != 1 && mar(x, y1 + 1) != 2 && mar(x, y1 + 1) != 3)) {
                    if (mar(x, y + 2) == 2)
                        backGround.texr.x -= 15;
                    /*else if (backGround.texr.x <= -5700)
                        backGround.texr.x -= 5;*/
                    else
                        backGround.texr.x -= 5;
                }
            }
        }
    }

    else
    {
        if (mar2(x, y) == 5) {
            victory = true;
            //cout << "game over";
            return;
        }
        if (mar2(x, y) == 1 || mar2(x1, y3) == 1  || mar2(x2, y2) == 1 || mar2(x3, y1) == 1 || (thirdComet.texr.x <= player.texr.x + 400  && thirdComet.texr.x >= player.texr.x && player.texr.y + 140 >= thirdComet.texr.y && player.texr.y + 80 <= thirdComet.texr.y + 90) || (thirdComet.texr.x <= player.texr.x + 80 && thirdComet.texr.x >= player.texr.x && player.texr.y <= thirdComet.texr.y + 90 && player.texr.y + 80 >= thirdComet.texr.y))
        {
            int count = 4 - player.Hearts();

            player = Player(Ptexture, 120, 100, 450, 175);
            backGround = BackGround(backGround.texture, 0, -16, 5000, 704);
            firstComet = Comets(firstComet.texture, 400, -100, 90, 90);
            secondComet = Comets(secondComet.texture, 500, 820, 90, 90);
            thirdComet = Comets(thirdComet.texture, 1000, -100, 90, 90);

            for (int i = 0; i < count; i++) {
                player.HealthRemove();
            }
            if (!player.Alive()) {
                return;
            }
        }

        if (backGround.texr.x < -4000 && firstComet.texr.y < 800)
        {
            firstComet.texr.y = (firstComet.texr.x - 600) * 1.5;
            //cout << comet.texr.x - 200 << endl;
            firstComet.texr. x += 7;
            //cout << comet.texr.x - 200 << endl << comet.texr.y << endl << kol << endl << endl;
            //SDL_RenderCopy(window.renderer, comet.texture, NULL, &comet.texr);
            //SDL_RenderPresent(window.renderer);
        }



        if (backGround.texr.x < -4500 && secondComet.texr.y > -100)
        {
            secondComet.texr.y -= (secondComet.texr.x) / 100;
            secondComet.texr.x += 3;
        }


        if (backGround.texr.x < -5000 && thirdComet.texr.y < 800)
        {
            thirdComet.texr.y = (thirdComet.texr.x - 1000) * -0.4;
            thirdComet.texr.x -= 10;
            
        }

        //cout << x << " " << y << endl << mar2(x, y) << endl;

        backGround.texr.x -= 5;
        if (GetKeyState('W') & 0x8000 && player.texr.y >= 5)
        {
            y = roundf(float(player.texr.y + 60) / 90);

            if (mar2(x, y) == 0 && mar2(x - 1, y) == 0 && mar2(x - 2, y) == 0 && mar2(x - 3, y) == 0 && mar2(x - 4, y - 1) == 0)
                player.texr.y -= 5;
        }
        if (GetKeyState('S') & 0x8000 && player.texr.y < 526)
        {
            y = roundf(float(player.texr.y + 145) / 90);

            if (mar2(x, y) == 0 && mar2(x - 1, y) == 0 && mar2(x - 2, y) == 0 && mar2(x - 3, y) == 0 && mar2(x - 4, y) == 0)
                player.texr.y += 5;
        }
    }
}

int OurRoundf(float number)
{
    if ((int)(number * 10) % 10 > 1) return (int)number + 1;
    else return roundf(number);
}

int OurRound(float number)
{
    if ((int)(number * 10) % 10 < 9) return (int)number;
    else return roundf(number);
}

int main(int argc, char* argv[])
{
    //Creating a window
    Window window = Window(1280, 704);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return 1;
    }

    //Uploading images
    setlocale(LC_NUMERIC, "Russian");
    SDL_Texture* textureMap1 = IMG_LoadTexture(window.renderer, "C:/mario/pictures/new_map1.png");
    SDL_Texture* textureMap2 = IMG_LoadTexture(window.renderer, "C:/mario/pictures/map2.png");
    SDL_Texture* textureSpace = IMG_LoadTexture(window.renderer, "C:/mario/pictures/space.png");
    SDL_Texture* textureSpace_end = IMG_LoadTexture(window.renderer, "C:/mario/pictures/space_end.png");


//    SDL_Texture* textureIMG = IMG_LoadTexture(window.renderer, "C:/mario/pictures/m1.png");

    SDL_Texture* texturePlayer = IMG_LoadTexture(window.renderer, "C:/mario/pictures/mario_49x69.png");
    SDL_Texture* texturePlayerRocket = IMG_LoadTexture(window.renderer, "C:/mario/pictures/rocket.png");
    SDL_Texture* texturePauseMenu = IMG_LoadTexture(window.renderer, "C:/mario/pictures/PauseMenu.png");
    SDL_Texture* textureMenu = IMG_LoadTexture(window.renderer, "C:/mario/pictures/menu.png");
    SDL_Texture* textureMenuStart = IMG_LoadTexture(window.renderer, "C:/mario/pictures/menu_start.png");
    SDL_Texture* textureHeart = IMG_LoadTexture(window.renderer, "C:/mario/pictures/heart.png");
    SDL_Texture* textureWasted = IMG_LoadTexture(window.renderer, "C:/mario/pictures/Wasted.png");
    SDL_Texture* textureVictory = IMG_LoadTexture(window.renderer, "C:/mario/pictures/victory2.png");
    SDL_Texture* textureRocket_launch = IMG_LoadTexture(window.renderer, "C:/mario/pictures/rocket_launch.png");
    SDL_Texture* textureRules = IMG_LoadTexture(window.renderer, "C:/mario/pictures/rules.png");
    SDL_Texture* textureComet = IMG_LoadTexture(window.renderer, "C:/mario/pictures/comet.png");
    SDL_Texture* textureEnd = IMG_LoadTexture(window.renderer, "C:/mario/pictures/lvl2_end.png");

    //Checking if everything is OKw
    if (textureMap1 == nullptr) {
        cout << "IMG_LoadTexture img Error: " << SDL_GetError() << "\n";
        return 1;
    }
    else if (textureMap2 == nullptr) {
        cout << "IMG_LoadTexture player Error: " << SDL_GetError() << "\n";
        return 1;
    }
    else if (texturePlayer == nullptr) {
        cout << "IMG_LoadTexture player Error: " << SDL_GetError() << "\n";
        return 1;
    }
    else if (texturePauseMenu == nullptr) {
        cout << "IMG_LoadTexture PauseMenu Error: " << SDL_GetError() << "\n";
        return 1;
    }
    else if (textureMenu == nullptr) {
        cout << "IMG_LoadTexture menu Error: " << SDL_GetError() << "\n";
        return 1;
    }
    else if (textureWasted == nullptr) {
        cout << "IMG_LoadTexture Wasted Error: " << SDL_GetError() << "\n";
        return 1;
    }
    else if (textureRules == nullptr) {
        cout << "IMG_LoadTexture Rules Error: " << SDL_GetError() << "\n";
        return 1;
    }

    //Creating a character and a background
    Player player = Player(texturePlayer, 120, 500, 49, 60);
    Player rocket = Player(texturePlayerRocket, 120, 100, 339, 650);
    BackGround backGround1 = BackGround(textureMap1, 0, -16, 5000, 704);
    BackGround backGround2 = BackGround(textureMap2, 0, -16, 16020, 720);
    BackGround space = BackGround(textureSpace, 0, -16, 1280, 704);
    BackGround space_end = BackGround(textureSpace_end, 0, -16, 1280, 704);

    PauseMenu pause = PauseMenu(texturePauseMenu, 384, 200, 512, 290);
    MainMenu menu = MainMenu(textureMenu, 0, 0, 1280, 704);
    Comets firstComet = Comets(textureComet, 200, -100, 90, 90);
    Comets secondComet = Comets(textureComet, 200, -100, 90, 90);
    Comets thirdComet = Comets(textureComet, 200, -100, 90, 90);
    
    unsigned int lastUpdateTime = 0;
    bool podnim = false;
    int pos = player.texr.y;
    int wastedW = 1280, wastedH = 704, victoryW = 1280, victoryH = 704, rocketW = 650, rocketH = 339, endW = 1280, endH = 720 ;
    int mouseX, mouseY;
    int kol = 0, level = 1;
    bool shutDown = false, toMainMenu, victory;
    SDL_Event e;
    SDL_Rect heartTexr, wastedTexr, victoryTexr, victoryRocket, end_rect;
    end_rect.x = 0;
    end_rect.y = 0;
    wastedTexr.x = 0;
    wastedTexr.y = 0;
    victoryTexr.x = 0;
    victoryTexr.y = 0;
    victoryRocket.x = 618;
    victoryRocket.y = 238;

    //Infinity loop
    while (!shutDown) {
        podnim = false;
        shutDown = false;
        victory = false;
        toMainMenu = false;
        victoryRocket.x = 618;
        victoryRocket.y = 238;
        int x = 175;
        SDL_GetMouseState(&mouseX, &mouseY);
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT ||
                (menu.InExit(mouseX, mouseY) && (GetKeyState(VK_LBUTTON) & 0x8000) != 0)) {
                shutDown = true;
                break;
            }
        }

        if (menu.InStart(mouseX, mouseY)) {
            menu.texture = textureMenuStart;
            if ((GetKeyState(VK_LBUTTON) & 0x8000) != 0) {
                int a = 0;
                /*while (a < 700)
                {
                    menu.texture = textureRules;
                    SDL_RenderCopy(window.renderer, menu.texture, NULL, &menu.hitbox);
                    SDL_RenderPresent(window.renderer);
                    Sleep(10);
                    a++;
                }*/
                if (level == 1)
                {
                    menu.texture = textureMenu;
                    backGround1 = BackGround(textureMap1, 0, -16, 5000, 704);
                    player = Player(texturePlayer, 120, 430, 49, 60);
                }
                if (level == 2)
                {
                    menu.texture = textureMenu;
                    backGround2 = BackGround(textureMap2, 0, -16, 16020, 704);
                    player = Player(texturePlayerRocket, 120, 100, x * 2.57, x);
                    firstComet = Comets(textureComet, 400, -100, 90, 90);
                    secondComet = Comets(textureComet, 500, 820, 90, 90);
                    thirdComet = Comets(textureComet, 1000, -100, 90, 90);
                }
                
//                PlaySound(TEXT("C:/mario/sounds/soundtrek.wav"), NULL, SND_ASYNC | SND_LOOP);
                while (player.Alive() && !shutDown && !toMainMenu && !victory) {
                    if (SDL_PollEvent(&e)) {
                        if (e.type == SDL_QUIT) {
                            shutDown = true;
                            break;
                        }
                        else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE) {
                            Paused(window, pause, shutDown, toMainMenu);
                            if (shutDown || toMainMenu) {
                                break;
                            }
                            SDL_RenderPresent(window.renderer);
                        }
                    }

                    if (level == 2) {
                        //Moving our character
                        Moving(window, player, backGround2, firstComet, secondComet, thirdComet, podnim, kol, pos, victory, texturePlayerRocket, level);
                    }

                    else
                        Moving(window, player, backGround1, firstComet, secondComet, thirdComet, podnim, kol, pos, victory, texturePlayer, level);

                    if (lastUpdateTime + 30 < SDL_GetTicks()) {
                        lastUpdateTime = SDL_GetTicks();

                        SDL_RenderClear(window.renderer);
                        if (level == 2)
                        {
                            SDL_RenderCopy(window.renderer, space.texture, NULL, &space.texr);
                            SDL_RenderCopy(window.renderer, backGround2.texture, NULL, &backGround2.texr);
                        }
                        else
                        {
                            SDL_RenderCopy(window.renderer, backGround1.texture, NULL, &backGround1.texr);
                        }
                        SDL_RenderCopy(window.renderer, player.texture, NULL, &player.texr);
                        SDL_RenderCopy(window.renderer, firstComet.texture, NULL, &firstComet.texr);
                        SDL_RenderCopy(window.renderer, secondComet.texture, NULL, &secondComet.texr);
                        SDL_RenderCopy(window.renderer, thirdComet.texture, NULL, &thirdComet.texr);
                        ShowHearts(player, window, textureHeart);
                        SDL_RenderPresent(window.renderer);
                    }
                    //Making a small delay
                    Sleep(10);
                    kol++;
                }
                PlaySound(NULL, NULL, 0);
                if (!player.Alive()) {
                    level = 1;
                    SDL_QueryTexture(textureWasted, NULL, NULL, &wastedW, &wastedH);
                    wastedTexr.w = wastedW;
                    wastedTexr.h = wastedH;
//                    PlaySound(TEXT("C:/mario/sounds/wasted.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    while (!shutDown) {
                        SDL_PollEvent(&e);
                        if (e.type == SDL_QUIT) {
                            shutDown = true;
                        }
                        else if ((GetKeyState(VK_LBUTTON) & 0x8000) != 0) {
                            break;
                        }
                        SDL_RenderCopy(window.renderer, textureWasted, NULL, &wastedTexr);
                        SDL_RenderPresent(window.renderer);
                    }
                }
                else if (victory) {
                    if (level == 1)
                    {
                        SDL_QueryTexture(textureVictory, NULL, NULL, &victoryW, &victoryH);
                        victoryTexr.w = victoryW;
                        victoryTexr.h = victoryH;
                        SDL_QueryTexture(textureRocket_launch, NULL, NULL, &rocketW, &rocketH);
                        victoryRocket.w = rocketW;
                        victoryRocket.h = rocketH;
                        for (int k = 0; k < 650; k++) {
                            SDL_PollEvent(&e);
                            if (e.type == SDL_QUIT) {
                                break;
                            }
                            SDL_RenderCopy(window.renderer, textureVictory, NULL, &victoryTexr);
                            SDL_RenderCopy(window.renderer, textureRocket_launch, NULL, &victoryRocket);
                            SDL_RenderPresent(window.renderer);
                            victoryRocket.y -= 1;
                            Sleep(10);
                        }
                        level++;
                    }
                    else if (level == 2)
                    {
                        int y = 250;
                        //SDL_RenderCopy(window.renderer, space.texture, NULL, &space.texr);
                        for (int k = 0; k < 175; k++)
                        {
                            
                            player = Player(texturePlayerRocket, y * 1.5, y, x * 2.57, x);
                            //SDL_RenderCopy(window.renderer, player.texture, NULL, &player.texr);
                            SDL_RenderCopy(window.renderer, space_end.texture, NULL, &space_end.texr);
                            SDL_RenderCopy(window.renderer, player.texture, NULL, &player.texr);
                            SDL_RenderPresent(window.renderer);
                            y++;
                            x -= 1;
                            Sleep(10);
                        }
                        SDL_QueryTexture(textureEnd, NULL, NULL, &endW, &endH);
                        end_rect.w = endW;
                        end_rect.h = endH;
                        while (!shutDown) {
                            SDL_PollEvent(&e);
                            if (e.type == SDL_QUIT) {
                                shutDown = true;
                            }
                            else if ((GetKeyState(VK_LBUTTON) & 0x8000) != 0) {
                                break;
                            }
                            SDL_RenderCopy(window.renderer, textureEnd, NULL, &end_rect);
                            SDL_RenderPresent(window.renderer);
                        }
                        level = 1;
                    }
                    
                    
//                    PlaySound(TEXT("C:/mario/sounds/victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    /*while (!shutDown) {
                        SDL_PollEvent(&e);
                        if (e.type == SDL_QUIT) {
                            shutDown = true;
                        }
                        else if ((GetKeyState(VK_LBUTTON) & 0x8000) != 0) {
                            break;
                        }
                        SDL_RenderCopy(window.renderer, textureVictory, NULL, &victoryTexr);
                        SDL_RenderPresent(window.renderer);
                    }*/
                }
            }
        }

        else {
            menu.texture = textureMenu;
        }

        SDL_RenderCopy(window.renderer, menu.texture, NULL, &menu.hitbox);
        SDL_RenderPresent(window.renderer);
        Sleep(10);
    }
    SDL_DestroyTexture(textureRules);
    SDL_DestroyTexture(textureMap1);
    SDL_DestroyTexture(textureMap2);
    SDL_DestroyTexture(texturePlayer);
    SDL_DestroyTexture(texturePauseMenu);
    SDL_DestroyTexture(textureMenu);
    SDL_DestroyTexture(texturePauseMenu);
    SDL_DestroyTexture(textureHeart);
    SDL_DestroyTexture(textureWasted);
    SDL_DestroyTexture(textureVictory);


    SDL_DestroyRenderer(window.renderer);
    SDL_DestroyWindow(window.window);
    
    return 0;
}
