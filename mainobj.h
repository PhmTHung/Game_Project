#ifndef MAIN_OBJ_H
#define MAIN_OBJ_H

#include <vector>

#include "basefunc.h"
#include "baseobj.h"
#include "map.h"
#include "vukhi.h"


class MainObject:public BaseObject
{
public:
    MainObject();
    ~MainObject();
    // tham khao them o lazy foo
    enum MoveType
    {
        MOVE_RIGHT =0,
        MOVE_LEFT  =1,
        MOVE_UP    =2,
        MOVE_DOWN  =3,
    };
    bool LoadImage(std::string path,SDL_Renderer* screen);
    void FrameShow(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events,SDL_Renderer* screen,Mix_Chunk* bullet_sound[2]);
    void set_clips();
    //ham xu ly di chuyen// se sua sau khi test
    void player_move(Map& map_data);
    //playercoordinate xu ly map
    void PlayerGPS(Map& map_data);

    SDL_Rect GetRectFrame();

    //xu ly vu khi
    void set_weapon_list(std::vector<Weapon*>weapon_list)
    {
        p_weapon_list=weapon_list;
    }
    void HandleWeapon(SDL_Renderer* des);
    std::vector<Weapon*>get_weapon_list() const{return p_weapon_list;}
    void DeleteBullet(const int& idx);

    void set_x_pos(const int &pos){x_pos=pos;}
    int get_x_pos() const {return x_pos;}
    void set_y_pos(const int &pos){y_pos=pos;}
    int get_y_pos() const {return y_pos;}
    void set_width_frame(const int &width){width_frame=width;}
    int get_width_frame() const {return width_frame;}
    void set_height_frame(const int &height){height_frame=height;}
    int get_height_frame() const {return height_frame;}
    //tao thanh HP
    void InitHP(int initialHP);
    void DecreaseHP(int amount);
    void DrawHPBar(SDL_Renderer* renderer);
    double GetHP()const{return hp;}
    //xu ly money
    void IncreaseMoney();
    int GetMoney()const {return(money_earn);}
private:
    //di chuyen trai phai x_step=x_val
    int x_step;
    int y_step;
    //vi tri hinh anh hien tai
    int x_pos;
    int y_pos;
    //kich thuoc frame cua h/a
    int width_frame;
    int height_frame;
    //luu so frame;
    SDL_Rect frame_clip[4];
    //key press
    Input input_type;
    //luu chi so frame dang hien
    int frame;
    //trang thai di chuyen
    int status;
    //vu khi
    std::vector<Weapon*> p_weapon_list;
    int money_earn;
    //them thanh HP
    double hp;
};
#endif // MAIN_OBJ_H
