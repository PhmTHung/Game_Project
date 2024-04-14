#ifndef DROP_ITEM
#include "baseobj.h"
#include "basefunc.h"
class DropItem:public BaseObject
{
public:
    DropItem();
    ~DropItem();
    int GetTimeExist()const {return time_exist;}

    void set_clips();
    void set_frame(const int& fr){frame=fr;}
    virtual bool LoadImage(std::string path,SDL_Renderer* screen);
    void Show(SDL_Renderer* screen);
    int get_frame_width()const {return frame_width;}
    int get_frame_height()const {return frame_height;}
    void Update(Uint32 time);
private:

    SDL_Rect frame_clip[4];
    int frame_width,frame_height;
    int frame;

    int time_exist;
};
#endif // DROP_ITEM
