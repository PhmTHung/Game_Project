#include "basefunc.h"
#include "baseobj.h"

BaseObject gBackground;


bool InitData()
{
    bool flag=true;
    //thiet lap mt ban dau
    int ret=SDL_Init(SDL_INIT_VIDEO);
    if(ret<0) return false;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
    gWindow=SDL_CreateWindow("Game Window"
                             ,SDL_WINDOWPOS_UNDEFINED
                             ,SDL_WINDOWPOS_UNDEFINED
                             ,SCREEN_WIDTH,SCREEN_HEIGHT
                             ,SDL_WINDOW_SHOWN);
    if(gWindow==NULL)
    {
        flag=false;
    }
    else
    {
        gScreen=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
        if(gScreen==NULL)
        {
            flag=false;
        }
        else
        {
            SDL_SetRenderDrawColor(gScreen,RENDER_DRAW_COLOR
                                   ,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR
                                   ,RENDER_DRAW_COLOR);

            int imgFlags=IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags)&&imgFlags)) flag=false;

        }
    }
    return flag;
}
bool LoadBackground()
{
    bool ret =gBackground.LoadImage("image/ahead.png",gScreen);
    if(ret==false)return false;
    return true;
}
void close()
{
    gBackground.Free();

    SDL_DestroyRenderer(gScreen);
    gScreen=NULL;

    SDL_DestroyWindow(gWindow);
    gWindow=NULL;

    IMG_Quit();
    SDL_Quit();
}
int main (int argc,char* argv[])
{
    if(InitData()==false) return -1;
    if(LoadBackground()==false) return -1;

    bool is_quit=false;
    while(!is_quit)
    {
        while(SDL_PollEvent(&gEvent)!=0)
        {
            if(gEvent.type==SDL_QUIT)
            {
                is_quit=true;
            }
        }
        SDL_SetRenderDrawColor(gScreen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        SDL_RenderClear(gScreen);

        gBackground.Render(gScreen,NULL);
        SDL_RenderPresent(gScreen);
    }
    close();
    return 0;
}
