#ifndef MENU_H
#define MUNU_H
#include "basefunc.h"
#include "baseobj.h"

class Menu:public BaseObject
{
public:
    Menu();
    ~Menu();
    void Threat_Action(SDL_Event events,SDL_Renderer* screen);
    bool LoadImage(std::string path,SDL_Renderer* screen);
};
#endif // MENU_H
