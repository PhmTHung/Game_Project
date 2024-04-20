#ifndef MENU_H
#define MUNU_H
#include "text.h"
#include "baseobj.h"
#include "basefunc.h"

class Menu:public TextManager
{
public:
    Menu();
    ~Menu();
    void Threat_Action(SDL_Event events,SDL_Renderer* screen);
    bool LoadMenu(std::string path,SDL_Renderer* screen);
    bool MouseIn(int x,int y,SDL_Rect drec);
    int ShowMenu();
    int EndMenu(std::string path,SDL_Renderer* screen);
private:
    SDL_Texture* menu;
	SDL_Texture* play;
	SDL_Texture* exit;
	SDL_Texture* guide;
	SDL_Texture* shop;
	SDL_Texture* music;

	SDL_Texture* end_;
	SDL_Texture* exitButton;
	SDL_Texture* playAgain;
	SDL_Texture* backButton;

};
#endif // MENU_H
