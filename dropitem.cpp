#include "dropitem.h"
#include "baseobj.h"
#include "basefunc.h"
DropItem::DropItem()
{
    frame_height=15;
    frame_width=15;
}
DropItem::~DropItem(){}
bool DropItem::LoadImage(std::string path,SDL_Renderer* screen)
{
    bool ret=BaseObject::LoadImage(path,screen);
    if(ret==true)
    {
        frame_width=rect.w;
    }
    return ret;
}
