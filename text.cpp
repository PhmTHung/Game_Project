#include "text.h"

TextManager::TextManager()
{
    text_color.r=255;
    text_color.g=255;
    text_color.b=255;
    texture=NULL;
}
TextManager::~TextManager(){}
//bool TextManager::LoadFromFile(std::string path)
//{
//    bool ret=TextManager::LoadFromFile(path);
//    if(ret==true)
//    {
//        //mWidth=rect.w;
//    }
//    return ret;
//}
bool TextManager::LoadFromRenderedText(TTF_Font* font, SDL_Renderer* screen)
{
    SDL_Surface* text_surface=TTF_RenderText_Solid(font,str_val.c_str(),text_color);
    if(text_surface)
    {
        texture=SDL_CreateTextureFromSurface(screen,text_surface);
        mWidth=text_surface->w;
        mHeight=text_surface->h;

        SDL_FreeSurface(text_surface);
    }
    return texture!=NULL;
}
void TextManager::Free()
{
    if(texture!=NULL)
    {
        SDL_DestroyTexture(texture);
        texture=NULL;
    }
}
void TextManager::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    text_color.r=red;
    text_color.g=green;
    text_color.b=blue;
}
void TextManager::setColorType(int type)
{
    switch(type)
    {
    case RED_TEXT:
        {
            SDL_Color red={255,0,0};
            text_color=red;
        }
    case WHITE_TEXT:
        {
            SDL_Color white={255,255,255};
            text_color=white;
        }
    case BLACK_TEXT:
        {
            SDL_Color black={0,0,0};
            text_color=black;
        }
    }
}

//void TextManager::RenderText(SDL_Renderer* screen,int x,int y,
//                    SDL_Rect* clip=NULL,double angle=0.0,
//                    SDL_Point* center=NULL,
//                    SDL_RendererFlip flip=SDL_FLIP_NONE)
//{
//    SDL_Rect renderQuad={x,y,mWidth,mHeight};
//    if(!clip=NULL)
//    {
//        renderQuad.w=clip->w;
//        renderQuad.h=clip->h;
//    }
//    SDL_RenderCopyEx(screen,texture,clip,&renderQuad,angle,center,flip);
//}
