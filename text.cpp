#include "text.h"

TextManager::~TextManager(){}
TextManager::TextManager()
{
    text_color.r=255;
    text_color.g=255;
    text_color.b=255;
    texture=NULL;
}
void TextManager::SetColorType(int type)
{
    switch(type)
    {
    case RED_TEXT:
        {
            SDL_Color red={255,0,0};
            text_color=red;
            break;
        }
    case WHITE_TEXT:
        {
            SDL_Color white={255,255,255};
            text_color=white;
            break;
        }
    case BLACK_TEXT:
        {
            SDL_Color black={0,0,0};
            text_color=black;
            break;
        }
    }
}
bool TextManager::LoadFromRenderText(TTF_Font* font,SDL_Renderer* screen)
{
    SDL_Surface* text_surface=TTF_RenderText_Solid(font,str_val.c_str(),text_color);
    if(text_surface)
    {
        texture=SDL_CreateTextureFromSurface(screen,text_surface);
        width=text_surface->w;
        height=text_surface->h;

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
void TextManager::SetColor(Uint8 red,Uint8 green, Uint8 blue)
{
    text_color.r=red;
    text_color.g=green;
    text_color.b=blue;
}
void TextManager::RenderText(SDL_Renderer* screen,int x, int y, SDL_Rect* clip,double angle, SDL_Point* center,SDL_RendererFlip flip)
{
    SDL_Rect renderQuad={x,y,width,height};
    if(clip!=NULL)
    {
        renderQuad.w=clip->w;
        renderQuad.h=clip->h;
    }
    SDL_RenderCopyEx(screen,texture,clip,&renderQuad,angle,center,flip);
}
