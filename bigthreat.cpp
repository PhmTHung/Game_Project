#include "bigthreat.h"
#include "mainobj.h"
#include <cstdlib>
#include <math.h>

BThreats::BThreats()
{
    x_pos=0;
    y_pos=0;
    x_step=0;
    y_step=0;
    width_frame=64;
    height_frame=64;
    frame=0;
    threat_damage=20;
    status=-1;
	InitHP(1000);
}
BThreats::~BThreats(){}
bool BThreats::LoadImage(std::string path,SDL_Renderer* screen)
{
    bool ret=BaseObject::LoadImage(path,screen);
    if(ret==true)
    {
        width_frame=rect.w;
    }
    return ret;
}
void BThreats::FrameShow(SDL_Renderer* des)
{
        switch(status)
        {
            case MOVE_LEFT:
              LoadImage("image/Threats/left.png",des);
              break;
            case MOVE_RIGHT:
              LoadImage("image/Threats/right.png",des);
              break;
            case MOVE_UP:
              LoadImage("image/Threats/back.png",des);
              break;
            case MOVE_DOWN:
              LoadImage("image/Threats/forward.png",des);
              break;
         }
        ++frame;
        if(frame>=3){frame=0;}
        rect.x=x_pos;
        rect.y=y_pos;
        SDL_Rect* current_clip =& frame_clip[frame];
        SDL_Rect renderQuad={rect.x,rect.y,width_frame,height_frame};
        SDL_RenderCopy(des,p_object,current_clip,&renderQuad);
}
void BThreats::set_clips()
{
    if(width_frame>0 && height_frame >0)
    {
        frame_clip[0].x=0;
        frame_clip[0].y=0;
        frame_clip[0].w=64;
        frame_clip[0].h=64;

        frame_clip[1].x=64;
        frame_clip[1].y=0;
        frame_clip[1].w=64;
        frame_clip[1].h=64;

        frame_clip[2].x=128;
        frame_clip[2].y=0;
        frame_clip[2].w=64;
        frame_clip[2].h=64;
    }
}
void BThreats::Threat_GPS(int x,int y)
{
    x_step = THREAT_SPEED;
    y_step = THREAT_SPEED;
    if(x_pos!=x)
    {
        if(x_pos<x)
        {
           x_pos+=x_step;
           status=MOVE_RIGHT;
        }
        else if(x_pos>x)
        {
           x_pos-=x_step;
           status=MOVE_LEFT;
        }
    }
    if(y_pos!=y)
    {
         if(y_pos<y)
        {
           y_pos+=y_step;
           status=MOVE_DOWN;
        }
        else if(y_pos>y)
        {
           y_pos-=y_step;
           status=MOVE_UP;
        }
    }
}
void BThreats::InitHP(int initialHP)
{
    hp = initialHP;
}
void BThreats::DecreaseHP(int damage)
{
    hp -= damage;
    if (hp < 0) hp=0;
}
void BThreats::DrawHPBar(SDL_Renderer* renderer)
{
    SDL_Rect hpBarRect = {x_pos+30,y_pos-10,hp/10,10 };
    SDL_SetRenderDrawColor(renderer,250,150,0,255);
    SDL_RenderFillRect(renderer,&hpBarRect);
}
SDL_Rect BThreats::GetRectFrame()
{
    SDL_Rect p_rect;
    p_rect.x=rect.x;
    p_rect.y=rect.y;
    p_rect.w=width_frame;
    p_rect.h=height_frame;
}

