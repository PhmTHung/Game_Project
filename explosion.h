#include "basefunc.h"
#include "baseobj.h"

#define NUM_FRAM_EXP 8

class Explosion:public BaseObject
{
public:
    Explosion();
    ~Explosion();

    void set_clip();
    void set_frame(const int& fr){frame=fr;}
    virtual bool LoadImage(std::string path,SDL_Renderer* screen);
    void Show(SDL_Renderer* screen);
    int get_frame_width()const {return frame_width;}
    int get_frame_height()const {return frame_height;}
private:
    int frame_width,frame_height;
    int frame;
    SDL_Rect frame_clip[8];
};

