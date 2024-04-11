#ifndef TEXT_H
#include "basefunc.h"
class TextManager
{
public:
    TextManager();
    ~TextManager();
    bool LoadFromFile(std::string path);

    bool LoadFromRenderedText(TTF_Font* font, SDL_Renderer* screen);
    void free();
    void setColor( Uint8 red, Uint8 green, Uint8 blue );
    int getWidth()const{return mWidth;}
    int getHeight()const{return mHeight;}
    void RenderText(SDL_Renderer* screen,int x,int y,
                    SDL_Rect* clip=NULL,double angle=0.0,
                    SDL_Point* center=NULL,
                    SDL_RendererFlip flip=SDL_FLIP_NONE);
    void setText(const std::string& text){str_val=text;}
    std::string getText()const {return str_val;}
private:
    std::string str_val;
    SDL_Texture* texture;
    SDL_Color text_color;
    int mWidth;
    int mHeight;
};
#endif // TEXT_H
