#include "mainobj.h"
#include "baseobj.h"
#include <iostream>
MainObject::MainObject()
{
    frame=0;
    x_pos=0;
    y_pos=0;
    //step tuong ung voi val
    x_step=0;
    y_step=0;

    width_frame=0;
    height_frame=0;

    status=-1;
}
MainObject::~MainObject(){}
// sua ve void
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
    if(width_frame>0 & height_frame >0)
    {
        frame_clip[0].x=0;
        frame_clip[0].y=0;
        frame_clip[0].w=width_frame;
        frame_clip[0].h=height_frame;

        frame_clip[1].x=width_frame;
        frame_clip[1].y=0;
        frame_clip[1].w=width_frame;
        frame_clip[1].h=height_frame;

        frame_clip[2].x=2*width_frame;
        frame_clip[2].y=0;
        frame_clip[2].w=width_frame;
        frame_clip[2].h=height_frame;

        frame_clip[3].x=3*width_frame;
        frame_clip[3].y=0;
        frame_clip[3].w=width_frame;
        frame_clip[3].h=height_frame;
    }
}
void MainObject::FrameShow(SDL_Renderer* des)
{
   switch(status)
   {
     case 1:
        LoadImage("image/left.png",des);
        break;
     case 2:
        LoadImage("image/right.png",des);
        break;
     case 3:
        LoadImage("image/behind.png",des);
        break;
     case 4:
        LoadImage("image/ahead.png",des);
        break;
   }
   //thu voi left right
   //neu bam kb thi frame tang len
   //khong thi show frame0
   if(input_type.left==1||input_type.right==1)
   {
       frame++;
   }else{frame=0;}

   if(frame>=8){frame=0;}

   rect.x=x_pos;
   rect.y=y_pos;

   SDL_Rect* current_clip =& frame_clip[frame];

   SDL_Rect renderQuad={rect.x,rect.y,width_frame,height_frame};
   //day frame hien tai len man hinh
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
                status=MOVE_RIGHT;
                input_type.right=1;
            }
            break;
        case SDLK_d:
            {
                status=MOVE_LEFT;
                input_type.left=1;
            }
            break;
//        case SDLK_w:
//            {
//                status=MOVE_UP;
//                input_type.up=1;
//            }
//            break;
//        case SDLK_a:
//            {
//                status=MOVE_RIGHT;
//                input_type.right=1;
//            }
//            break;
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
                status=MOVE_RIGHT;
                input_type.right=0;
            }
            break;
        case SDLK_d:
            {
                status=MOVE_LEFT;
                input_type.left=0;
            }
            break;
//        case SDLK_w:
//            {
//                status=MOVE_UP;
//                input_type.up=1;
//            }
//            break;
//        case SDLK_a:
//            {
//                status=MOVE_RIGHT;
//                input_type.right=1;
//            }
//            break;
        default:
            break;//ti lam sau

        }
    }
}
