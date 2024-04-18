#ifndef DROP_ITEM
#include "baseobj.h"
#include "basefunc.h"

class DropItem:public BaseObject
{
public:
    DropItem();
    ~DropItem();

    virtual bool LoadImage(std::string path,SDL_Renderer* screen);
    int get_frame_width()const {return frame_width;}
    int get_frame_height()const {return frame_height;}
private:
    int frame_width,frame_height;
};
#endif // DROP_ITEM
