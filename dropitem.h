#ifndef DROP_ITEM
#include "baseobj.h"
#include "basefunc.h"

class DropItem:public BaseObject
{
public:
    DropItem();
    ~DropItem();

    bool LoadImage(std::string path,SDL_Renderer* screen);
    void FrameShow(SDL_Renderer* des);
    void set_clips();

    void set_x_pos(const int &pos){x_pos=pos;}
    int get_x_pos() const {return x_pos;}
    void set_y_pos(const int &pos){y_pos=pos;}
    int get_y_pos() const {return y_pos;}

    int get_width_frame() const {return width_frame;}
    int get_height_frame() const {return height_frame;}

    std::vector<DropItem*>get_coins_list() const{return coins_list;}
    void DeleteCoins(const int& index);
private:
    int frame;
    SDL_Rect frame_clip[8];
    int width_frame,height_frame;

    int status;
    int x_pos,y_pos;
    std::vector<DropItem*>coins_list;

};
#endif // DROP_ITEM
