#include "dropitem.h"
#include "baseobj.h"

DropItem::DropItem()
{
    frame_height=0;
    frame_width=0;
    time_exist=300;
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
void DropItem::Show(SDL_Renderer* screen)
{
    SDL_Rect* current_clip= &frame_clip[frame];
    SDL_Rect render_quad={rect.x,rect.y,frame_width,frame_height};
    if(current_clip!= NULL)
    {
        render_quad.w=current_clip->w;
        render_quad.h=current_clip->h;
    }
    SDL_RenderCopy(screen,p_object,current_clip,&render_quad);
}

void DropItem::set_clips()
{
    if(frame_width>0 && frame_height >0)
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
    }
}
void DropItem::Update(Uint32 time) {
    if (time_exist > 0) {
        time_exist -= time;
    }
}
