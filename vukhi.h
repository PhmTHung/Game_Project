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

    void set_x_val(const int &xVal){x_val=xVal;}
    int get_x_val() const {return x_val;}

    void set_y_val(const int &yVal){y_val=yVal;}
    int get_y_val() const {return y_val;}

    void set_is_move(const bool& isMove){is_move=isMove;}
    bool get_is_move() const {return is_move;}

    void set_weapon_direct(const int & weaponDirect){weapon_direct=weaponDirect;}
    int  get_weapon_direct()const {return weapon_direct;}
    //void HandleMove(const int& x_border,const int& y_border);
    void WeaponRange(int x_border,int y_border);
    int get_x_range() const{return x_border;}
    int get_y_range() const{return y_border;}
private:
    int x_val;
    int y_val;
    //tam xa cua vu khi
    int x_border;
    int y_border;
    //trang thai trong man hinh de xoa
    bool is_move;
    //hướng bắn
    int weapon_direct;
};
#endif // VU_KHI_H
