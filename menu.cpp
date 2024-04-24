#include "menu.h"
#include "basefunc.h"
#include "baseobj.h"
Menu::Menu()
{
    width_frame=SCREEN_WIDTH;
    height_frame=SCREEN_HEIGHT;
    x_pos=0;
    y_pos=0;
}
Menu::~Menu(){}
bool Menu::LoadImage(std::string path,SDL_Renderer* screen)
{
    bool ret=BaseObject::LoadImage(path,screen);
    if(ret==true)
    {
        width_frame=rect.w;
        height_frame=rect.h;
    }
    return ret;
}
