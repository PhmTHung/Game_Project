#include "Threats.h"
#include "mainobj.h"
#include <cstdlib>


int randomNum()
{
    int n;
    n=rand()%100+1;
    return n;
}
int randomDirect()
{
    int n;
    n=rand()%10+1;
    return n;
}
Threats::Threats()
{
    int n=randomNum();
    int m=randomNum();

    x_pos=((SCREEN_WIDTH/n)+100);
    y_pos=((SCREEN_HEIGHT/m)+100);

    x_step=0;
    y_step=0;

    width_frame=60;
    height_frame=40;

    frame=0;

    status=-1;

    come_back_time=0;

    input_type.left=0;
	input_type.right=0;
	input_type.down=0;
	input_type.up=0;
}
Threats::~Threats(){}
bool Threats::LoadImage(std::string path,SDL_Renderer* screen)
{
    bool ret=BaseObject::LoadImage(path,screen);
    if(ret==true)
    {
        width_frame=rect.w;
    }
    return ret;
}
void Threats::FrameShow(SDL_Renderer* des)
{
    if(come_back_time==0)
    {
        switch(status)
        {
            case MOVE_LEFT:
              LoadImage("image/Threats/threatleft.png",des);
              break;
            case MOVE_RIGHT:
              LoadImage("image/Threats/threatright.png",des);
              break;
            case MOVE_UP:
              LoadImage("image/Threats/threatback.png",des);
              break;
            case MOVE_DOWN:
              LoadImage("image/Threats/threatforward.png",des);
              break;
         }
        ++frame;
        if(frame>=4){frame=0;}
        rect.x=x_pos;
        rect.y=y_pos;
        SDL_Rect* current_clip =& frame_clip[frame];
        SDL_Rect renderQuad={rect.x,rect.y,width_frame,height_frame};
        SDL_RenderCopy(des,p_object,current_clip,&renderQuad);
    }
}
void Threats::set_clips()
{
    if(width_frame>0 && height_frame >0)
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
void Threats::Threat_Move(Map& map_data,MainObject player)
{
    bool appeared=false;
    if (!appeared)
    {
        // Xuất hiện ngẫu nhiên
        int n = randomNum();
        int m = randomNum();
        x_pos = (SCREEN_WIDTH / n) + 100;
        y_pos = (SCREEN_HEIGHT / m) + 100;
        appeared = true; // Đánh dấu quái vật đã xuất hiện
    }
    else
    {
        // Di chuyển bám theo nhân vật chính
        if (x_pos < player.GetPosX())
        {
            x_pos += SPEED_MOVE;
            status = MOVE_RIGHT;
            input_type.right = 1;
        }
        else if (x_pos > player.GetPosX())
        {
            x_pos -= SPEED_MOVE;
            status = MOVE_LEFT;
            input_type.left = 1;
        }

        if (y_pos < player.GetPosY())
        {
            y_pos += SPEED_MOVE;
            status = MOVE_DOWN;
            input_type.down = 1;
        }
        else if (y_pos > player.GetPosY())
        {
            y_pos -= SPEED_MOVE;
            status = MOVE_UP;
            input_type.up = 1;
        }
    }
}
