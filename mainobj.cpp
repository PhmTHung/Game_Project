#include "mainobj.h"
#include "basefunc.h"
#include "baseobj.h"
#include <iostream>
#include <algorithm>
MainObject::MainObject()
{   //hieu ung di chuyen
    frame=0;

    x_pos=400;
    y_pos=400;

    x_step=0;
    y_step=0;

    width_frame=0;
    height_frame=39;
    status=-1;
    //trang thai di chuyen
    //move_type

    input_type.left=0;
	input_type.right=0;
	input_type.down=0;
	input_type.up=0;
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
        LoadImage("image/MainCharacter/left.png",des);
        break;
     case MOVE_RIGHT:
        LoadImage("image/MainCharacter/right.png",des);
        break;
     case MOVE_UP:
        LoadImage("image/MainCharacter/behind.png",des);
        break;
     case MOVE_DOWN:
        LoadImage("image/MainCharacter/ahead.png",des);
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
                input_type.left=1;
                input_type.right=0;
            }
            break;
        case SDLK_d:
            {
                status=MOVE_RIGHT;
                input_type.right=1;
                input_type.left=0;
            }
            break;
        case SDLK_w:
            {
                status=MOVE_UP;
                input_type.up=1;
                input_type.down=0;
            }
            break;
        case SDLK_s:
            {
                status=MOVE_DOWN;
                input_type.down=1;
                input_type.up=0;
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
                input_type.left=0;
            }
            break;
        case SDLK_d:
            {
                status=MOVE_RIGHT;
                input_type.right=0;
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
                input_type.down=0;
            }
            break;
        default:
            break;
        }
    }
    // nhap space de tan cong
    if(events.type==SDL_KEYDOWN)
    {
        if(events.key.keysym.sym==SDLK_SPACE)
        {
            Weapon* p_weapon=new Weapon();
            //p_vukhi->LoadImage("image/dan.png",screen);

            switch (status)
            {
            case MOVE_LEFT:
                p_weapon->LoadImage("image/Weapon/bladexleft.png",screen);
                p_weapon->set_weapon_direct(Weapon::IN_LEFT);
                p_weapon->SetRect(this->rect.x+width_frame/2,rect.y-0.1*height_frame);
                break;
            case MOVE_RIGHT:
                p_weapon->LoadImage("image/Weapon/bladexright.png",screen);
                p_weapon->set_weapon_direct(Weapon::IN_RIGHT);
                p_weapon->SetRect(this->rect.x+width_frame/2,rect.y-0.1*height_frame);
                break;
            case MOVE_UP:
                p_weapon->LoadImage("image/Weapon/bladexup.png",screen);
                p_weapon->set_weapon_direct(Weapon::IN_UP);
                p_weapon->SetRect(this->rect.x+width_frame/2-15,rect.y-0.1*height_frame);
                break;
            case MOVE_DOWN:
                p_weapon->LoadImage("image/Weapon/bladexdown.png",screen);
                p_weapon->set_weapon_direct(Weapon::IN_DOWN);
                p_weapon->SetRect(this->rect.x+width_frame/2-15,rect.y-0.1*height_frame);
                break;
            }
            //p_vukhi->SetRect(this->rect.x+width_frame/2,rect.y-0.1*height_frame);
            p_weapon->set_x_val(20);
            p_weapon->set_is_move(true);

            p_weapon_list.push_back(p_weapon);
        }
    }
}
//ham thanh hien thi dan ban
void MainObject::HandleWeapon(SDL_Renderer* des)
{
    for(int i=0;i<p_weapon_list.size();i++)
    {
        Weapon* p_weapon=p_weapon_list.at(i);
        if(p_weapon!=NULL)
        {
            if(p_weapon->get_is_move()==true)
            {
                p_weapon->WeaponRange(SCREEN_WIDTH,SCREEN_HEIGHT);
                p_weapon->Render(des);
            }
            else
            {
                p_weapon_list.erase(p_weapon_list.begin()+i);
                if(p_weapon!=NULL)
                {
                    delete p_weapon;
                    p_weapon=NULL;
                }
            }
        }
    }
}
void MainObject::player_move(Map& map_data)
{
//    if(input_type.left==1)  x_step=-SPEED_MOVE;
//    if(input_type.right==1) x_step=+SPEED_MOVE;
//    if(input_type.up==1)    y_step=-SPEED_MOVE;
//    if(input_type.down==1)  y_step=+SPEED_MOVE;
//    PlayerGPS(map_data);
     x_step=SPEED_MOVE;
     y_step=SPEED_MOVE;
}

void MainObject::PlayerGPS(Map& map_data)
{
    int x1=0,x2=0;
    int y1=0,y2=0;

    //check chieu rong
    int height_min= std::min(height_frame,TILE_SIZE);
    x1=(x_pos+x_step)/TILE_SIZE;
    x2=(x_pos+x_step+width_frame-1)/TILE_SIZE;

    y1=(y_pos+y_step)/TILE_SIZE;
    y2=(y_pos+y_step+height_min-1)/TILE_SIZE;

    if(x1>0 && x2<MAP_X && y1>0 && y2< MAP_Y )
    {
        if(x_step >0 )
        {
            if(map_data.arr[y1][x2] == WALL || map_data.arr[y2][x2] == WALL )
            {
                x_pos=x2*TILE_SIZE;
                x_pos-=width_frame+1;
                x_step=0;
            }
        }
        else if(x_step < 0 )
            {
                if(map_data.arr[y1][x1] == WALL || map_data.arr[y2][x1] == WALL )
                {
                    x_pos=(x1+1)*TILE_SIZE;
                    x_step=0;
                }
            }
    }
    //check chieu dai
    int width_min=std::min(width_frame,TILE_SIZE);
    x1=(x_pos)/TILE_SIZE;
    x2=(x_pos+width_min)/TILE_SIZE;

    y1=(y_pos+y_step)/TILE_SIZE;
    y2=(y_pos+y_step+height_frame-1)/TILE_SIZE;

    if(x1>=0 && x2<MAP_X && y2>=0 && y2<MAP_Y)
    {
        if(y_step > 0 )
        {
            if(map_data.arr[y2][x1] == WALL || map_data.arr[y2][x2] == WALL )
            {
                y_pos=y2*TILE_SIZE;
                y_pos-=height_frame+1;
                y_step=0;
            }
        }
        else if(y_step < -1 )
        {
            if(map_data.arr[y1][x1] == WALL || map_data.arr[y1][x2] == WALL )
            {
                y_pos=(y1+1)*TILE_SIZE;
                y_step=0;
            }
        }
    }
    if(input_type.left==1)  x_pos-=x_step;
    if(input_type.right==1) x_pos+=x_step;
    if(input_type.up==1)    y_pos-=y_step;
    if(input_type.down==1)  y_pos+=y_step;
}




