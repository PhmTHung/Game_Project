#include "mainobj.h"
#include "baseobj.h"
#include <iostream>
MainObject::MainObject()
{   //hieu ung di chuyen
    frame=0;
    x_pos=0;
    y_pos=0;
    x_step=0;
    y_step=0;
    width_frame=0;
    height_frame=40;
    status=-1;
    //trang thai di chuyen
    //move_type
    input_type_left=0
	input_type_right=0
	input_type_jump=0
	input_type_down=0
	input_type_up=0
}
MainObject::~MainObject(){}
// ke thua LoadImage tu BaseObject
bool MainObject::LoadImage(std::string path,SDL_Renderer* screen)
{
    bool ret=BaseObject::LoadImage(path,screen);
    if(ret==true)
    {
        width_frame=rect.w;
    }
    return ret;
}
void MainObject::set_clips()
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
void MainObject::FrameShow(SDL_Renderer* des)
{
   //trang thai thai doi khi di chuyen
   switch(status)
   {
     case MOVE_LEFT:
        LoadImage("image/left.png",des);
        break;
     case MOVE_RIGHT:
        LoadImage("image/right.png",des);
        break;
     case MOVE_UP:
        LoadImage("image/behind.png",des);
        break;
     case MOVE_DOWN:
        LoadImage("image/ahead.png",des);
        break;
   }
   //neu bam kb thi frame tang len
   //khong thi show frame0
   if(input_type.left==1||input_type.right==1||input_type.up==1||input_type.down==1)
   {
       ++frame;
   }else{frame=0;}
   //khi khung hinh chay den 4 thi quay ve 0
   if(frame>=4){frame=0;}
   //vi tri nhan vat
   rect.x=x_pos;
   rect.y=y_pos;
   //show clip
   SDL_Rect* current_clip =& frame_clip[frame];
   //vi tri, chieu cao, do rong
   SDL_Rect renderQuad={rect.x,rect.y,width_frame,height_frame};
   //day clip hien tai len man hinh
   SDL_RenderCopy(des,p_object,current_clip,&renderQuad);
}
void MainObject::HandleInputAction(SDL_Event events,SDL_Renderer* screen)
{
    if(events.type==SDL_KEYDOWN)
    {
        switch(events.key.keysym.sym)
        {
        case SDLK_a:
            {
                status=MOVE_LEFT;
                input_type.right=1;
            }
            break;
        case SDLK_d:
            {
                status=MOVE_RIGHT;
                input_type.left=1;
            }
            break;
        case SDLK_w:
            {
                status=MOVE_UP;
                input_type.up=1;
            }
            break;
        case SDLK_s:
            {
                status=MOVE_DOWN;
                input_type.right=1;
            }
            break;
        default:
            break;
        }
    }
    else if(events.type==SDL_KEYUP)
    {
     switch(events.key.keysym.sym)
        {
        case SDLK_a:
            {
                status=MOVE_LEFT;
                input_type.right=0;
            }
            break;
        case SDLK_d:
            {
                status=MOVE_RIGHT;
                input_type.left=0;
            }
            break;
        case SDLK_w:
            {
                status=MOVE_UP;
                input_type.up=0;
            }
            break;
        case SDLK_s:
            {
                status=MOVE_DOWN;
                input_type.right=0;
            }
            break;
        default:
            break;//ti lam sau

        }
    }
}
