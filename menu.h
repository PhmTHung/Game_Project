#ifndef MENU_H
#define MUNU_H
#include "text.h"
#include "baseobj.h"
#include "basefunc.h"

class Menu:public BaseObject
{
public:
    Menu();
    ~Menu();
    bool LoadMenu(std::string path,SDL_Renderer* screen);
    bool MouseIn(int x,int y,SDL_Rect drec);
    bool LoadItem(std::string path,int x,int y);
    int EndMenu(std::string path,SDL_Renderer* screen);
private:
    SDL_Texture* menu;
	SDL_Texture* play;
	SDL_Texture* exit;
};
#endif // MENU_H
