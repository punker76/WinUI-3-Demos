#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <tchar.h>

using namespace std;


#ifdef CONTOSOSEATBOOKING_EXPORTS
#define CONTOSOSEATBOOKING_API __declspec(dllexport)
#else
#define CONTOSOSEATBOOKING_API __declspec(dllimport)
#endif

extern "C" CONTOSOSEATBOOKING_API int RenderSeatLayout();
extern "C" CONTOSOSEATBOOKING_API void Close();


struct Images
{
	string image;
};
const int SCREEN_WIDTH = 920;
const int SCREEN_HEIGHT = 650;

bool Initialize();
void LoadTexture(std::vector<Images> vecImages, std::vector< SDL_Texture*>& vecTextures);
void FillImageVector(std::string strFileName, std::vector<Images>& vecImages);
std::vector<std::vector<int>> InitializeSeatMatrix();
bool RenderCopy(SDL_Renderer* Renderer, std::vector<std::vector<int>> seatMatrix, SDL_Texture* EmptyTexture, SDL_Texture* OccupiedTexture, SDL_Texture* SelectedTexture, int x, int y, bool bIsSelected);
SDL_Texture* LoadBackGroundCover(string strFileName);
SDL_Texture* LoadOccupiedImage(string strFileName);
SDL_Texture* LoadSelectedSeatImage(string strFileName);
SDL_Texture* LoadEmptySeatImage(string strFileName);
SDL_Texture* LoadSeatLegends(string strFileName);
SDL_Texture* LoadNextButtonTexture(string strFileName);
