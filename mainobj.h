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
    void HandleInputAction(SDL_Event events,SDL_Renderer* screen);
    void set_clips();
    //ham xu ly di chuyen// se sua sau khi test
    void player_move(Map& map_data);
    //playercoordinate xu ly map
    void PlayerGPS(Map& map_data);
    //xu ly vu khi
    void set_weapon_list(std::vector<Weapon*>weapon_list)
    {
        p_weapon_list=weapon_list;
    }
    void HandleWeapon(SDL_Renderer* des);
    std::vector<Weapon*>get_weapon_list() const{return p_weapon_list;}

private:
    //di chuyen trai phai x_step=x_val
    int x_step;//trai phai
    int y_step;//len xuong
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
    //
    //vu khi
    std::vector<Weapon*> p_weapon_list;
};
#endif // MAIN_OBJ_H
