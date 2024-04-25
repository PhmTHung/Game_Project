#ifndef VU_KHI_H
#define VU_KHI_H
#include "basefunc.h"
#include "baseobj.h"

class Weapon:public BaseObject
{
public:
    Weapon();
    ~Weapon();

    enum WeaponDirect
    {
        IN_RIGHT =1,
        IN_LEFT  =2,
        IN_UP    =3,
        IN_DOWN  =4,
    };
    enum WeaponType
    {
        MAGE_TYPE=50,
        LASER_TYPE=51,
        THREAT_BULLET=52
    };

    void set_x_val(const int &xVal){x_val=xVal;}
    int get_x_val() const {return x_val;}

    void set_y_val(const int &yVal){y_val=yVal;}
    int get_y_val() const {return y_val;}

    void set_is_move(const bool& isMove){is_move=isMove;}
    bool get_is_move() const {return is_move;}

    void set_weapon_direct(const int & weaponDirect){weapon_direct=weaponDirect;}
    int  get_weapon_direct()const {return weapon_direct;}
    void WeaponRange(int x_border,int y_border);

//    int get_x_range() const{return x_border;}
//    int get_y_range() const{return y_border;}

    void set_weapon_type(const unsigned int& weaponType){weapon_type=weaponType;}
    int get_weapon_type()const{return weapon_type;}

    void LoadImgWeapon(SDL_Renderer* des);

    int GetWeaponDamage()const{return weapon_damage;}
    int GetThBuDamage()const{return thr_bul_damge;}

    SDL_Rect GetRectFrame();
    void set_width_frame(const int &width){width_frame=width;}
    int get_width_frame() const {return width_frame;}
    void set_height_frame(const int &height){height_frame=height;}
    int get_height_frame() const {return height_frame;}
private:
    int x_val;
    int y_val;
    //tam xa cua vu khi
    int x_border;
    int y_border;
    bool is_move;
    int weapon_direct;
    int weapon_type;
    int weapon_damage;
    int thr_bul_damge;

    int width_frame;
    int height_frame;
};
#endif // VU_KHI_H
