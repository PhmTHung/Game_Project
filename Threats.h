#ifndef THREATS_H
#define THREATS_H
#include "basefunc.h"
#include "baseobj.h"
#include "mainobj.h"
#define THREATS_WIDTH 20
#define THREATS_HEIGHT 20
class Threats:public BaseObject
{
public:
    Threats();
    ~Threats();
    enum MoveType
    {
        MOVE_RIGHT =0,
        MOVE_LEFT  =1,
        MOVE_UP    =2,
        MOVE_DOWN  =3,
    };
    bool LoadImage(std::string path,SDL_Renderer* screen);
    void FrameShow(SDL_Renderer* des);
    void set_clips();

    void Threat_Move(Map& map_data,MainObject player);
    void Threat_Action(SDL_Event events,SDL_Renderer* screen);

    void set_x_step(const int &step){x_step=step;}
    int get_x_step() const {return x_step;}

    void set_y_step(const int &step){y_step=step;}
    int get_y_step() const {return y_step;}


    void set_x_pos(const int &pos){x_pos=pos;}
    int get_x_pos() const {return x_pos;}

    void set_y_pos(const int &pos){y_pos=pos;}
    int get_y_pos() const {return y_pos;}

    //void set_type_move(const int& typeMove){return type_move=typeMove;}

private:
    int x_step;
    int y_step;

    int frame;

    int status;

    int x_pos;
    int y_pos;

    int width_frame;
    int height_frame;

    int type_move;
    Input input_type;

    SDL_Rect frame_clip[4];

    int come_back_time;
};
#endif // THREATS_H
