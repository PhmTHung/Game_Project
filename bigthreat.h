#ifndef B_THREAT_H
#define B_THREAT_H
#include "basefunc.h"
#include "baseobj.h"
#include "mainobj.h"
class BThreats:public BaseObject
{
public:
    BThreats();
    ~BThreats();
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
    void Threat_GPS(int x,int y);
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

    void InitHP(int initialHP);
    void DecreaseHP(int damage);
    void DrawHPBar(SDL_Renderer* renderer);
    double GetHP()const{return hp;}
    SDL_Rect GetRectFrame();
    double GetThreatDamage()const{return threat_damage;}
    double IncreaseDamage();
private:
    int x_step,y_step;

    int frame;
    SDL_Rect frame_clip[3];
    int width_frame,height_frame;

    int status;
    int x_pos,y_pos;
    int type_move;
    double hp;

    double threat_damage;
    double threat_speed;
};
#endif // B_THREAT_H
