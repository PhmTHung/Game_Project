#ifndef BASE_OBJ_H
#define BASE_OBJ_H

#include "basefunc.h"
class BaseObject
{
public:
    BaseObject();
    ~BaseObject();
    void SetRect(const int &x, const int &y){rect.x=x,rect.y=y;}
    SDL_Rect GetRect() const {return rect;}
    SDL_Texture* GetObject() const {return p_object;}

    bool LoadImage(std::string path,SDL_Renderer* screen);
    void Render(SDL_Renderer* des,const SDL_Rect* clip=NULL);
    void Free();
protected:
    SDL_Texture* p_object;
    SDL_Rect rect;
};
#endif // BASE_OBJ_H
