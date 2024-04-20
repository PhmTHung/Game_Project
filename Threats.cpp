#include "Threats.h"
#include "mainobj.h"
#include <cstdlib>


Threats::Threats()
{

    x_pos=0;
    y_pos=0;

    x_step=0;
    y_step=0;

    width_frame=60;
    height_frame=40;

    frame=0;

    threat_damage=1;

    status=-1;
    come_back_time=0;

	InitHP(50);
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
void Threats::Threat_GPS(int x,int y)
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
int Threats::Threat_Bullet_Direc(Weapon* t_bullet,int x,int y)
{
    if(x_pos==x)
    {
        if(y_pos<y) t_bullet->set_weapon_direct(Weapon::IN_RIGHT);
        if(y_pos>y) t_bullet->set_weapon_direct(Weapon::IN_LEFT);
    }
}
void Threats::InitHP(int initialHP)
{
    hp = initialHP;
}

void Threats::DecreaseHP(int damage)
{
    hp -= damage;
    if (hp < 0) hp=0;
}
void Threats::DrawHPBar(SDL_Renderer* renderer)
{
    SDL_Rect hpBarRect = { x_pos+30, y_pos-10,hp,10 };
    SDL_SetRenderDrawColor(renderer, 250, 150, 0, 255);
    SDL_RenderFillRect(renderer, &hpBarRect);
}

void Threats::InitBullet(Weapon* p_bullet,SDL_Renderer* screen)
{
    MainObject p_player;
    int x,y;
    x=p_player.get_x_pos();
    y=p_player.get_y_pos();
    Threat_GPS(x,y);
    if(p_bullet!=NULL)
    {
        p_bullet->set_weapon_type(Weapon::THREAT_BULLET);
        p_bullet->LoadImgWeapon(screen);
        p_bullet->set_is_move(true);
        switch (status)
            {
            case MOVE_LEFT:
                p_bullet->set_weapon_direct(Weapon::IN_LEFT);
                p_bullet->SetRect(this->rect.x+width_frame/2,rect.y-0.1*height_frame);
                break;
            case MOVE_RIGHT:
                p_bullet->set_weapon_direct(Weapon::IN_RIGHT);
                p_bullet->SetRect(this->rect.x+width_frame/2,rect.y-0.1*height_frame);
                break;
            case MOVE_UP:
                p_bullet->set_weapon_direct(Weapon::IN_UP);
                p_bullet->SetRect(this->rect.x+width_frame/2,rect.y-0.1*height_frame);
                break;
            case MOVE_DOWN:
                p_bullet->set_weapon_direct(Weapon::IN_DOWN);
                p_bullet->SetRect(this->rect.x+width_frame/2,rect.y-0.1*height_frame);
                break;
            default:
                break;
            }
        p_bullet->set_x_val(20);
//        p_bullet->set_is_move(true);
        t_bullet_list.push_back(p_bullet);
    }
}
void Threats::MakeBullet(SDL_Renderer* screen,const int& x_limit,const int& y_limit)
{
    for(int i=0;i<t_bullet_list.size();i++)
    {
        Weapon* t_bullet=t_bullet_list.at(i);
        if(t_bullet!=NULL)
        {
            if(t_bullet->get_is_move())
            {
                int bullet_dist=rect.x-t_bullet->GetRect().x;
                if(bullet_dist<=50)
                {
                     t_bullet->WeaponRange(x_limit,y_limit);
                     t_bullet->Render(screen);
                }
                else
                {
                    t_bullet->set_is_move(false);
                }
            }
            else
            {
                t_bullet->set_is_move(true);
                t_bullet->SetRect(this->x_pos-20,y_pos+10);
            }
        }
    }
}

void Threats::DeleteBullet(const int& idx)
{
    int size=t_bullet_list.size();
    if(size>0 && idx <size)
    {
        Weapon* t_bullet=t_bullet_list.at(idx);
        t_bullet_list.erase(t_bullet_list.begin()+idx);
        if(t_bullet)
        {
            delete t_bullet;
            t_bullet=NULL;
        }
    }
}
SDL_Rect Threats::GetRectFrame()
{
    SDL_Rect p_rect;
    p_rect.x=rect.x;
    p_rect.y=rect.y;
    p_rect.w=width_frame;
    p_rect.h=height_frame;
}

