#ifndef THREATS_H
#define THREATS_H
#include "basefunc.h"
#include "baseobj.h"
#include "mainobj.h"
#include "vukhi.h"
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

    //check va cham
    void Threat_Move(Map& map_data);
    void Threat_GPS(Map& map_data);

    void Threat_Action(SDL_Event events,SDL_Renderer* screen);

    void set_x_step(const int &step){x_step=step;}
    int get_x_step() const {return x_step;}
    void set_y_step(const int &step){y_step=step;}
    int get_y_step() const {return y_step;}


    void set_x_pos(const int &pos){x_pos=pos;}
    int get_x_pos() const {return x_pos;}
    void set_y_pos(const int &pos){y_pos=pos;}
    int get_y_pos() const {return y_pos;}

    void set_width_frame(const int &widframe){width_frame=widframe;}
    int get_width_frame() const {return width_frame;}
    void set_height_frame(const int &heiframe){height_frame=heiframe;}
    int get_height_frame() const {return height_frame;}

    void set_type_move(const int& typeMove){ type_move=typeMove;}
    void SetMapXY(const int& mp_x,const int& mp_y)
    {
        map_x=mp_x;
        map_y=mp_y;
    }

    void InitHP(int initialHP);
    void DecreaseHP(int amount);
    void DrawHPBar(SDL_Renderer* renderer);

    std::vector<Weapon*>get_bullet_list() const{return bullet_list;}
    void set_bullet_list(const std::vector<Weapon*>& bl_list){bullet_list=bl_list;}

    void InitBullet(Weapon* p_bullet,SDL_Renderer* screen);
    void MakeBullet(SDL_Renderer* screen,const int& x_limit,const int& y_limit);
private:
    int x_step,y_step;
    int frame;
    int status;
    int x_pos,y_pos;
    int map_x,map_y;
    int width_frame,height_frame;
    int type_move;
    Input input_type;
    SDL_Rect frame_clip[4];
    int come_back_time;
    int hp;

    std::vector<Weapon*>bullet_list;
};
#endif // THREATS_H
