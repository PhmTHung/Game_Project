#ifndef MENU_H
#define MUNU_H
//#include "text.h"
#include "baseobj.h"
#include "basefunc.h"
class Menu:public BaseObject
{
public:
    Menu();
    ~Menu();
    bool LoadImage(std::string path,SDL_Renderer* screen);
    void set_x_pos(const int &pos){x_pos=pos;}
    int get_x_pos() const {return x_pos;}
    void set_y_pos(const int &pos){y_pos=pos;}
    int get_y_pos() const {return y_pos;}
    void FrameShow(SDL_Renderer* des);
    void set_clips();
private:
    int width_frame;
    int height_frame;
    int x_pos,y_pos;
    SDL_Rect frame_clip;
};
#endif // MENU_H
