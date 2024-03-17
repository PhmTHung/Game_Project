#ifndef MAIN_OBJ_H
#define MAIN_OBJ_H

#include "basefunc.h"
#include "baseobj.h"


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
private:
    //di chuyen trai phai x_step=x_val
    int x_step;
    int y_step;
    //vi tri hinh anh
    int x_pos;
    int y_pos;
    //kich thuoc frame cua h/a
    int width_frame;
    int height_frame;
    //se sua su dung 4;
    SDL_Rect frame_clip[4];
    Input input_type;
    //luu chi so frame dang hien
    int frame;
    //trang thai di chuyen
    int status;
};
#endif // MAIN_OBJ_H
