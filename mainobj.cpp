#include "mainobj.h"
#include "basefunc.h"
#include "baseobj.h"
#include "vukhi.h"
#include <iostream>
#include <algorithm>
MainObject::MainObject()
{
    frame=0;
    x_pos=400;
    y_pos=400;
    x_step=0;
    y_step=0;

    width_frame=32;
    height_frame=39;
    status=-1;

    input_type.left=0;
	input_type.right=0;
	input_type.down=0;
	input_type.up=0;

    InitHP(500);

    money_earn=0;
}
MainObject::~MainObject(){}
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
void MainObject::HandleInputAction(SDL_Event events,SDL_Renderer* screen,Mix_Chunk* bullet_sound[2])
{
    Weapon* p_weapon=new Weapon();
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
            //Weapon* p_weapon=new Weapon();
            p_weapon->set_weapon_type(Weapon::MAGE_TYPE);
            p_weapon->LoadImgWeapon(screen);
            Mix_PlayChannel(-1,bullet_sound[0],0);
            switch (status)
            {
            case MOVE_LEFT:
                //p_weapon->LoadImage("image/Weapon/bladexleft.png",screen);
                p_weapon->set_weapon_direct(Weapon::IN_LEFT);
                p_weapon->SetRect(this->rect.x+width_frame/2,rect.y-0.1*height_frame);
                break;
            case MOVE_RIGHT:
                //p_weapon->LoadImage("image/Weapon/bladexright.png",screen);
                p_weapon->set_weapon_direct(Weapon::IN_RIGHT);
                p_weapon->SetRect(this->rect.x+width_frame/2,rect.y-0.1*height_frame);
                break;
            case MOVE_UP:
                //p_weapon->LoadImage("image/Weapon/bladexup.png",screen);
                p_weapon->set_weapon_direct(Weapon::IN_UP);
                p_weapon->SetRect(this->rect.x+width_frame/2-15,rect.y-0.1*height_frame);
                break;
            case MOVE_DOWN:
                //p_weapon->LoadImage("image/Weapon/bladexdown.png",screen);
                p_weapon->set_weapon_direct(Weapon::IN_DOWN);
                p_weapon->SetRect(this->rect.x+width_frame/2-15,rect.y-0.1*height_frame);
                break;
            }
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
    x_step = SPEED_MOVE;
    y_step = SPEED_MOVE;
    //di chuyen
    if(input_type.left==1)  x_pos -= x_step;
    if(input_type.right==1) x_pos += x_step;
    if(input_type.up==1)    y_pos -= y_step;
    if(input_type.down==1)  y_pos += y_step;
    //check va cham map
    PlayerGPS(map_data);
}

void MainObject::PlayerGPS(Map& map_data)
{
    int width_min = std::min(width_frame, TILE_SIZE);
    int height_min = std::min(height_frame, TILE_SIZE);
    ///ô mà player đang đứng
    int x1 = x_pos/TILE_SIZE;
    int x2 = (x_pos+width_min)/TILE_SIZE;
    int y1 = y_pos/TILE_SIZE;
    int y2 = (y_pos+height_min)/TILE_SIZE;
    ///Kiểm tra va chạm với cạnh trên và cạnh dưới của bản đồ
    if (y1<0)
    {
            y_pos=0;
    }
    if(y2>MAP_Y-2)
    {
            y_pos=(MAP_Y-1)*TILE_SIZE-height_frame;
    }
    ///Kiểm tra va chạm với cạnh trái và cạnh phải của bản đồ
    if (x1<0)
    {
            x_pos=0;
    }
    if(x2>MAP_X-2.5)
    {
         x_pos=MAP_X*TILE_SIZE-width_frame;
    }
}
void MainObject::InitHP(int initialHP) {
    hp=initialHP;
}
void MainObject::DecreaseHP(double amount) {
    hp -= amount;
    if (hp < 0) {
        hp = 0;
    }
}
void MainObject::DrawHPBar(SDL_Renderer* renderer) {
    ///Vẽ thanh HP
    SDL_Rect hpBarRect={x_pos+10,y_pos-10,hp/5,10};
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderFillRect(renderer, &hpBarRect);
}

void MainObject::DeleteBullet(const int& idx)
{
    int size=p_weapon_list.size();
    if(size>0 && idx <size)
    {
        Weapon* p_bullet=p_weapon_list.at(idx);
        p_weapon_list.erase(p_weapon_list.begin()+idx);
        if(p_bullet)
        {
            delete p_bullet;
            p_bullet=NULL;
        }
    }
}

SDL_Rect MainObject::GetRectFrame()
{
    SDL_Rect p_rect;
    p_rect.x=rect.x;
    p_rect.y=rect.y;
    p_rect.w=width_frame;
    p_rect.h=height_frame;
}

void MainObject::IncreaseMoney()
{
    money_earn++;
}
void MainObject::IncreaseHP()
{
    hp+=200;
    if(hp>=500)
    {
        hp=500;
    }
}
