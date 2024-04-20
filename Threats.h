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
    //chase main
    void Threat_GPS(int x,int y);
    int Threat_Bullet_Direc(Weapon* t_bullet, int x,int y);
    //void Threat_Action(SDL_Event events,SDL_Renderer* screen);

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
    void DecreaseHP(int damage);
    void DrawHPBar(SDL_Renderer* renderer);
    double GetHP()const{return hp;}

    std::vector<Weapon*>get_bullet_list() const{return t_bullet_list;}
    void set_bullet_list(const std::vector<Weapon*>& bl_list){t_bullet_list=bl_list;}

    void InitBullet(Weapon* p_bullet,SDL_Renderer* screen);
    void MakeBullet(SDL_Renderer* screen,const int& x_limit,const int& y_limit);
    void DeleteBullet(const int& idx);

    SDL_Rect GetRectFrame();

    double GetThreatDamage()const{return threat_damage;}
private:
    int x_step,y_step;

    int frame;
    SDL_Rect frame_clip[4];
    int width_frame,height_frame;

    int status;
    int x_pos,y_pos;
    int map_x,map_y;

    int type_move;

    int come_back_time;
    double hp;

    double threat_damage;

    std::vector<Weapon*>t_bullet_list;
};
#endif // THREATS_H
