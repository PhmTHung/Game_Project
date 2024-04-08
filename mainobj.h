#ifndef MAIN_OBJ_H
#define MAIN_OBJ_H

#include "basefunc.h"
#include "baseobj.h"
#include "map.h"


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
    void DoPlayer(Map& Map_data)
    void CheckToMap(Map& Map_data)
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
    //bien tren mat
};
#endif // MAIN_OBJ_H
