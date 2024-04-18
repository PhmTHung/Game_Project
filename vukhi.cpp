#include "vukhi.h"
#include "baseobj.h"
#define WeaponSpeed 20
Weapon::Weapon()
{
    x_val=WeaponSpeed;
    y_val=WeaponSpeed;

    x_border=100;
    y_border=100;

    width_frame=40;
    height_frame=40;

    is_move=false;

    weapon_type=-1;

    weapon_damage=20;
    thr_bul_damge=10;

    enum
    {
        MAGE_TYPE=50,
        LASER_TYPE=51,
        THREAT_BULLET=52
    };
}
Weapon::~Weapon(){}
void Weapon::LoadImgWeapon(SDL_Renderer* des)
{
    switch(weapon_type)
    {
    case MAGE_TYPE:
        {
            LoadImage("image/Weapon/mage.png",des);
            break;
        }
    case LASER_TYPE:
        {
            LoadImage("image/Weapon/laser.png",des);
            break;
        }
    case THREAT_BULLET:
        {
            LoadImage("image/Weapon/threatbullet.png",des);
        }
    }
}
void Weapon::WeaponRange(int x_border,int y_border)
{
    switch (weapon_direct)
    {
    case IN_RIGHT:
        rect.x +=x_val;
        if(rect.x>x_border) is_move=false;
        break;
    case IN_LEFT:
        rect.x -=x_val;
        if(rect.x>x_border) is_move=false;
        break;
    case IN_UP:
        rect.y -=y_val;
        if(rect.y>y_border) is_move=false;
        break;
    case IN_DOWN:
        rect.y +=y_val;
        if(rect.y>y_border) is_move=false;
        break;
    }
}
SDL_Rect Weapon::GetRectFrame()
{
    SDL_Rect p_rect;
    p_rect.x=rect.x;
    p_rect.y=rect.y;
    p_rect.w=width_frame;
    p_rect.h=height_frame;
}
