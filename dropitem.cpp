#include "dropitem.h"
#include "baseobj.h"
#include "basefunc.h"
DropItem::DropItem()
{
    height_frame=32;
    width_frame=32;
//    x_pos=0;
//    y_pos=0;
    frame=0;
    status=-1;
}
DropItem::~DropItem(){}
bool DropItem::LoadImage(std::string path,SDL_Renderer* screen)
{
    bool ret=BaseObject::LoadImage(path,screen);
    if(ret==true)
    {
        height_frame=rect.h;
        width_frame=rect.w/8;
    }
    return ret;
}
void DropItem::FrameShow(SDL_Renderer* des)
{
    ++frame;
    if(frame>=8){frame=0;}
    rect.x=x_pos;
    rect.y=y_pos;
    SDL_Rect* current_clip =& frame_clip[frame];
    SDL_Rect renderQuad={rect.x,rect.y,width_frame,height_frame};
    SDL_RenderCopy(des,p_object,current_clip,&renderQuad);
}
void DropItem::set_clips()
{
    if(width_frame>0 && height_frame>0)
    {
        frame_clip[0].x=0;
        frame_clip[0].y=0;
        frame_clip[0].w=32;
        frame_clip[0].h=64;

        frame_clip[1].x=32;
        frame_clip[1].y=0;
        frame_clip[1].w=32;
        frame_clip[1].h=64;

        frame_clip[2].x=64;
        frame_clip[2].y=0;
        frame_clip[2].w=32;
        frame_clip[2].h=64;

        frame_clip[3].x=96;
        frame_clip[3].y=0;
        frame_clip[3].w=32;
        frame_clip[3].h=64;

        frame_clip[4].x=128;
        frame_clip[4].y=0;
        frame_clip[4].w=32;
        frame_clip[4].h=64;

        frame_clip[5].x=160;
        frame_clip[5].y=0;
        frame_clip[5].w=32;
        frame_clip[5].h=64;

        frame_clip[6].x=192;
        frame_clip[6].y=0;
        frame_clip[6].w=32;
        frame_clip[6].h=64;

        frame_clip[7].x=224;
        frame_clip[7].y=0;
        frame_clip[7].w=32;
        frame_clip[7].h=64;
    }
}

