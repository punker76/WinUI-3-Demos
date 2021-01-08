#include "pch.h"
#include "SeatLayout.h"

SDL_Window* window = NULL;
SDL_Renderer* Renderer = NULL;

#define NUMBER_OF_IMAGES 1
#define NO_SEAT -1
#define EMPTY_SEAT 0
#define OCCUPIED_SEAT 1
#define SELECTED_SEAT 2

// uncomment to run it as .exe
//int main(int argc, char* args[])
//{
//	RenderSeatLayout();
//	return 0;
//}

int RenderSeatLayout()
{
	int x = 0, y = 0;
	if (!Initialize())
	{
		cout << "not Initialize " << endl;
		return 0;
	}	
	string strFileName = SDL_GetBasePath();

	SDL_Texture* OccupiedSeatTexture = LoadOccupiedImage(strFileName);

	SDL_Texture* SelectedSeatTexture = LoadSelectedSeatImage(strFileName);

	SDL_Texture* EmptySeatTexture = LoadEmptySeatImage(strFileName);

	SDL_Texture* SeatLegendsTexture = LoadSeatLegends(strFileName);

	SDL_Texture* NextButtonTexture = LoadNextButtonTexture(strFileName);

	if ((OccupiedSeatTexture == NULL) || (SelectedSeatTexture == NULL))
	{
		cout << "Can not load texture cover..." << endl;
		return 0;
	}

	std::vector<std::vector<int>> seatMatrix = InitializeSeatMatrix();

	bool exit = false;
	bool bIsSelected = false;
	SDL_Event e;
	while (!exit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				exit = true;
			switch (e.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button)
				{
				case SDL_BUTTON_LEFT:
				{
					SDL_GetMouseState(&x, &y);
					bIsSelected = true;
					break;
				}
				case SDL_BUTTON_RIGHT:
				{
					SDL_GetMouseState(&x, &y);
					bIsSelected = true;
					break;
				}
				}
				break;
			case SDL_QUIT:
				Close();
				break;
			}
		}

		SDL_RenderClear(Renderer);

		// Select the color for drawing. It is set to red here.
		SDL_SetRenderDrawColor(Renderer, 240, 240, 240, 255);

		// Clear the entire screen to our selected color.
		SDL_RenderClear(Renderer);

		SDL_Rect screenRectangle = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

		// Render Legends
		int textureWidth = 0, textureHeight = 0;
		double scale = 0.4;
		SDL_QueryTexture(SeatLegendsTexture, NULL, NULL, &textureWidth, &textureHeight);
		SDL_Rect legendsRectangle = { seatMatrix.at(0).size() * 40 + 180, 60, textureWidth * scale, textureHeight * scale };
		SDL_RenderCopy(Renderer, SeatLegendsTexture, &screenRectangle, &legendsRectangle);

		// Render Next Button
		SDL_QueryTexture(NextButtonTexture, NULL, NULL, &textureWidth, &textureHeight);
		SDL_Rect nextButtonRectangle = { legendsRectangle.x, legendsRectangle.y + legendsRectangle.h + 60, textureWidth * 0.2, textureHeight * 0.2 };
		SDL_RenderCopy(Renderer, NextButtonTexture, &screenRectangle, &nextButtonRectangle);

		if (bIsSelected && ((y >= nextButtonRectangle.y && y <= (nextButtonRectangle.y + nextButtonRectangle.h)) && (x <= (nextButtonRectangle.x + nextButtonRectangle.w) && x >= (nextButtonRectangle.x))))
		{
			break;
		}

		// render seats
		exit = RenderCopy(Renderer, seatMatrix, EmptySeatTexture, OccupiedSeatTexture, SelectedSeatTexture, x, y, bIsSelected);
		SDL_RenderPresent(Renderer);

	}
	if (SeatLegendsTexture)
	{
		SDL_DestroyTexture(SeatLegendsTexture);
		SeatLegendsTexture = NULL;
	}
	if (OccupiedSeatTexture)
	{
		SDL_DestroyTexture(OccupiedSeatTexture);
		OccupiedSeatTexture = NULL;
	}
	if (SelectedSeatTexture)
	{
		SDL_DestroyTexture(SelectedSeatTexture);
		SelectedSeatTexture = NULL;
	}
	if (EmptySeatTexture)
	{
		SDL_DestroyTexture(EmptySeatTexture);
		EmptySeatTexture = NULL;
	}
	if (NextButtonTexture)
	{
		SDL_DestroyTexture(NextButtonTexture);
		NextButtonTexture = NULL;
	}
	return 1;
}

bool Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initilized" << SDL_GetError() << endl;
		return false;
	}

	window = SDL_CreateWindow("ContosoAirline", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		cout << "window could not creted" << SDL_GetError() << endl;
		return false;
	}

	Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	if (Renderer == NULL)
	{
		cout << "Renderer failed" << SDL_GetError() << endl;
		return false;
	}
	SDL_SetRenderDrawColor(Renderer, 0, 255, 255, 255);
	int imgFlages = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlages) & imgFlages))
	{
		cout << "IMG_Init failed" << IMG_GetError() << endl;
		return false;
	}
	return true;
}

void Close()
{
	SDL_DestroyRenderer(Renderer);
	Renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}

void LoadTexture(std::vector<Images> vecImages, std::vector< SDL_Texture*>& vecTextures)
{
	SDL_Surface* loadSurface = NULL;
	SDL_Texture* newTexture = NULL;
	string strBaseImageFileName = SDL_GetBasePath();
	strBaseImageFileName.append("img0.png");

	if (!strBaseImageFileName.empty())
	{
		loadSurface = IMG_Load(strBaseImageFileName.c_str());
		if (loadSurface == NULL)
		{
			cout << "loadSurface failed for file - " << strBaseImageFileName.c_str() << IMG_GetError() << endl;
			return;
		}
	}
	for (auto& itr : vecImages)
	{
		newTexture = SDL_CreateTextureFromSurface(Renderer, loadSurface);
		if (newTexture == NULL)
		{
			cout << "SDL_CreateTextureFromSurface failed for file - " << itr.image.c_str() << SDL_GetError() << endl;
		}
		else
		{
			vecTextures.push_back(newTexture);
		}
		newTexture = NULL;
	}
	SDL_FreeSurface(loadSurface);
	return;
}

void FillImageVector(std::string strFileName, std::vector<Images>& vecImages)
{
	if (!strFileName.empty())
	{
		Images imageObj;

		for (int i = 0; i < NUMBER_OF_IMAGES; i++)
		{
			string strLocalFileName = strFileName;
			char imageFileName[_MAX_DIR] = "img";
			char FileName[_MAX_DIR] = { 0 };
			char fileExt[6] = ".png";

			sprintf(FileName, "%d", i);
			strcat(imageFileName, FileName);
			strcat(imageFileName, fileExt);
			strLocalFileName.append(imageFileName);
			imageObj.image = strLocalFileName;
			strLocalFileName.empty();
			vecImages.push_back(imageObj);
		}
	}
}

std::vector<std::vector<int>> InitializeSeatMatrix()
{
	int seatConfig[] = { 2, 3, 2 };
	int rowsConfig[] = { 2, 5, 5 };

	std::vector<std::vector<int>> seatMatrix;

	/** Calculate total rows of seats*/
	int rowsPairSize = sizeof(rowsConfig) / sizeof(rowsConfig[0]);
	int totalRows = 0;

	/** Calculate total columns of seats*/
	int seatPairsSize = sizeof(seatConfig) / sizeof(seatConfig[0]);
	int totalColumns = 0;

	for (int rowPair = 0; rowPair < rowsPairSize; rowPair++)
	{
		for (int row = 0; row < rowsConfig[rowPair]; row++)
		{
			vector<int> singleRow;
			for (int columnPair = 0; columnPair < seatPairsSize; columnPair++)
			{
				int pairSize = seatConfig[columnPair];
				for (int i = 0; i < pairSize; i++)
				{
					int rnd = rand() % 10 + 1;
					// 7:3 empty seats to occupied seat ratio
					if (rnd <= 7)
						singleRow.push_back(EMPTY_SEAT);
					else
						singleRow.push_back(OCCUPIED_SEAT);
				}

				if (columnPair != seatPairsSize - 1)
				{
					singleRow.push_back(NO_SEAT);
				}
			}

			seatMatrix.push_back(singleRow);
		}

		// add empty row
		if (rowPair != rowsPairSize - 1)
		{
			vector<int> singleRow;
			for (int columnPair = 0; columnPair < seatPairsSize; columnPair++)
			{
				int pairSize = seatConfig[columnPair];
				for (int i = 0; i < pairSize; i++)
				{
					singleRow.push_back(NO_SEAT);
				}

				if (columnPair != seatPairsSize - 1)
				{
					singleRow.push_back(NO_SEAT);
				}
			}
			seatMatrix.push_back(singleRow);
		}
	}

	return seatMatrix;
}

bool RenderCopy(SDL_Renderer* Renderer, std::vector<std::vector<int>> seatMatrix, SDL_Texture* EmptyTexture, SDL_Texture* OccupiedTexture, SDL_Texture* SelectedTexture, int x, int y, bool bIsSelected)
{
	int totalColumns = 0, totalRows = 0;

	if (seatMatrix.size() > 0)
	{
		totalColumns = seatMatrix.at(0).size();
		totalRows = seatMatrix.size();
	}

	bool bRenderCopy = false;
	int iTextureIndex = 0;

	if (Renderer == NULL || (EmptyTexture == NULL) || (OccupiedTexture == NULL) || (SelectedTexture == NULL))
		bRenderCopy = true;

	SDL_Rect screenRectangle = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_Rect imageRectangle = { 0, 0, 50, 50 };

	int LEFT_PADDING = 60;
	int TOP_PADDING = 60;

	// draw border rectangle
	SDL_Rect borderRectangle = { LEFT_PADDING - 20, 0, 40 * totalColumns + 40, SCREEN_HEIGHT };
	SDL_SetRenderDrawColor(Renderer, 190, 190, 190, 255);
	SDL_RenderFillRect(Renderer, &borderRectangle);

	// draw wrapping rectangle
	SDL_Rect wrappingRectangle = { LEFT_PADDING - 10, 0, 40 * totalColumns + 20, SCREEN_HEIGHT };
	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(Renderer, &wrappingRectangle);

	for (int row = 0; row < totalRows; row++)
	{
		for (int col = 0; col < totalColumns; col++)
		{
			int seatType = seatMatrix.at(row).at(col);

			imageRectangle = { col * 40 + LEFT_PADDING, row * 40 + TOP_PADDING, 40, 40 };

			if (bIsSelected && ((y >= imageRectangle.y && y <= (imageRectangle.y + imageRectangle.h)) && (x <= (imageRectangle.x + imageRectangle.w) && x >= (imageRectangle.x))))
				SDL_RenderCopy(Renderer, SelectedTexture, &screenRectangle, &imageRectangle);
			else if (seatType == EMPTY_SEAT)
				SDL_RenderCopy(Renderer, EmptyTexture, &screenRectangle, &imageRectangle);
			else if (seatType == OCCUPIED_SEAT)
				SDL_RenderCopy(Renderer, OccupiedTexture, &screenRectangle, &imageRectangle);
		}
	}

	return bRenderCopy;
}

bool RenderSeletcedSeat(SDL_Renderer* Renderer, std::vector< SDL_Texture*> vecTextures, SDL_Texture* OccupiedTexture, SDL_Texture* SelectedTexture, int x, int y)
{
	bool bRenderCopy = false;
	int iTextureIndex = 0;

	if (Renderer == NULL || (vecTextures.size() == 0) || (OccupiedTexture == NULL))
		bRenderCopy = true;

	SDL_Rect screenRectangle = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	SDL_Rect imageRectangle = { 0,0,50,50 };


	for (int row = 0; row <= SCREEN_HEIGHT; row += 50)
	{
		for (int col = 0; col <= SCREEN_WIDTH; col += 40)
		{
			if (((row + col) % 3) == 0)
			{
				SDL_RenderCopy(Renderer, OccupiedTexture, &screenRectangle, &imageRectangle);
				imageRectangle = { col , row , 50,50 };
			}
			/*else if ( (x > 0 && y > 0 ) )
			{
				int nSelectedCol = x / 40;
				int nSelectedRow = y / 50;
				imageRectangle = { nSelectedCol*40,nSelectedRow*50,50,50 };
				SDL_RenderCopy(Renderer, SelectedTexture, &screenRectangle, &imageRectangle);
			}*/
			else
			{
				SDL_RenderCopy(Renderer, vecTextures[iTextureIndex], &screenRectangle, &imageRectangle);
				imageRectangle = { col , row , 50,50 };
			}
			//iTextureIndex++;

		}
	}



	return bRenderCopy;
}
SDL_Texture* LoadBackGroundCover(string strFileName)
{
	SDL_Surface* loadSurface = NULL;
	SDL_Texture* newTexture = NULL;

	string strBackGroundFileName = strFileName;
	strBackGroundFileName.append("BookFlightCover.jpg");

	if (!strBackGroundFileName.empty())
	{
		loadSurface = IMG_Load(strBackGroundFileName.c_str());
		if (loadSurface == NULL)
		{
			cout << "loadSurface failed for file for background- " << strBackGroundFileName.c_str() << IMG_GetError() << endl;
			return 0;
		}
	}
	newTexture = SDL_CreateTextureFromSurface(Renderer, loadSurface);

	SDL_FreeSurface(loadSurface);

	return newTexture;
}

SDL_Texture* LoadOccupiedImage(string strFileName)
{
	SDL_Surface* loadSurface = NULL;
	SDL_Texture* newTexture = NULL;

	string strOccupiedImgFileName = strFileName;
	
	strOccupiedImgFileName.append("OccupiedImg.png");

	if (!strOccupiedImgFileName.empty())
	{
		loadSurface = IMG_Load(strOccupiedImgFileName.c_str());
		if (loadSurface == NULL)
		{
			cout << "loadSurface failed for file for Occupied Image- " << strOccupiedImgFileName.c_str() << IMG_GetError() << endl;
			return 0;
		}
	}
	newTexture = SDL_CreateTextureFromSurface(Renderer, loadSurface);

	SDL_FreeSurface(loadSurface);

	return newTexture;
}

SDL_Texture* LoadSelectedSeatImage(string strFileName)
{
	SDL_Surface* loadSurface = NULL;
	SDL_Texture* newTexture = NULL;

	string strSelectedImgFileName = strFileName;
	
	strSelectedImgFileName.append("SelectedImg.png");

	if (!strSelectedImgFileName.empty())
	{
		loadSurface = IMG_Load(strSelectedImgFileName.c_str());
		if (loadSurface == NULL)
		{
			cout << "loadSurface failed for file for Selected Image- " << strSelectedImgFileName.c_str() << IMG_GetError() << endl;
			return 0;
		}
	}
	newTexture = SDL_CreateTextureFromSurface(Renderer, loadSurface);

	SDL_FreeSurface(loadSurface);

	return newTexture;
}

SDL_Texture* LoadEmptySeatImage(string strFileName)
{
	SDL_Surface* loadSurface = NULL;
	SDL_Texture* newTexture = NULL;

	string strOccupiedImgFileName = strFileName;
	
	strOccupiedImgFileName.append("EmptyImg.png");

	if (!strOccupiedImgFileName.empty())
	{
		loadSurface = IMG_Load(strOccupiedImgFileName.c_str());
		if (loadSurface == NULL)
		{
			cout << "loadSurface failed for file for Occupied Image- " << strOccupiedImgFileName.c_str() << IMG_GetError() << endl;
			return 0;
		}
	}
	newTexture = SDL_CreateTextureFromSurface(Renderer, loadSurface);

	SDL_FreeSurface(loadSurface);

	return newTexture;
}

SDL_Texture* LoadSeatLegends(string strFileName)
{
	SDL_Surface* loadSurface = NULL;
	SDL_Texture* newTexture = NULL;

	string strOccupiedImgFileName = strFileName;
	
	strOccupiedImgFileName.append("SeatLegends.png");

	if (!strOccupiedImgFileName.empty())
	{
		loadSurface = IMG_Load(strOccupiedImgFileName.c_str());
		if (loadSurface == NULL)
		{
			cout << "loadSurface failed for file for Occupied Image- " << strOccupiedImgFileName.c_str() << IMG_GetError() << endl;
			return 0;
		}
	}
	newTexture = SDL_CreateTextureFromSurface(Renderer, loadSurface);

	SDL_FreeSurface(loadSurface);

	return newTexture;
}

SDL_Texture* LoadNextButtonTexture(string strFileName)
{
	SDL_Surface* loadSurface = NULL;
	SDL_Texture* newTexture = NULL;

	string strOccupiedImgFileName = strFileName;
	
	strOccupiedImgFileName.append("NextButton.png");

	if (!strOccupiedImgFileName.empty())
	{
		loadSurface = IMG_Load(strOccupiedImgFileName.c_str());
		if (loadSurface == NULL)
		{
			cout << "loadSurface failed for file for Occupied Image- " << strOccupiedImgFileName.c_str() << IMG_GetError() << endl;
			return 0;
		}
	}
	newTexture = SDL_CreateTextureFromSurface(Renderer, loadSurface);

	SDL_FreeSurface(loadSurface);

	return newTexture;
}
