#pragma once
#pragma comment (lib, "winmm.lib")

#include <SDL.h>
#include <SDL_image.h>

#include "Classes.cpp"

#include <stdio.h>
#include <iostream>
#include <Windows.h>

using namespace std;

SDL_Texture* IMG_LoadTexture(SDL_Renderer* renderer, const char* file);
void Moving(Window& window, Player& player, BackGround& backGround, Comets& firstComet, Comets& secondComet, Comets& thirdComet, bool& podnim, int& kol, int& pos, bool& victory, SDL_Texture*& Ptexture, int level);
int mar(int x, int y);
int mar2(int x, int y);
int OurRoundf(float number);
int OurRound(float number);
void Paused(Window& window, PauseMenu& pause, bool& shutDown, bool& tomainMenu);
void ShowHearts(Player player, Window& window, SDL_Texture*& heart);