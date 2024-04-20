#include "explosion.h"

Explosion::Explosion()
{
    frame_height=30;
    frame_width=30;
    frame=0;
}
Explosion::~Explosion(){}
bool Explosion::LoadImage(std::string path,SDL_Renderer* screen)
{
    bool ret= BaseObject::LoadImage(path,screen);
    if(ret)
    {
        frame_width=rect.w/NUM_FRAM_EXP;
        frame_height=rect.h;
    }
    return ret;
}
void Explosion::set_clip()
{
     if(frame_width>0 && frame_height>0)
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
void Explosion::Show(SDL_Renderer* screen)
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
