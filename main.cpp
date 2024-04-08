#include "basefunc.h"
#include "baseobj.h"
//#include "xulygame.h"
#include "mainobj.h"
#include "map.h"
#include<iostream>

//Game *game = NULL;
//BaseObject gBackground;
bool InitData()
{
    bool flag=true;
    //thiet lap mt ban dau
    int ret=SDL_Init(SDL_INIT_VIDEO);
    if(ret<0) std::cout<<"ERROR->Init"<<std::endl;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
    gWindow=SDL_CreateWindow("Game Window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
     if(gWindow)
    {   std::cout<<"Create gWindow success"<<std::endl;
        gScreen=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
        if(gScreen)
        {
            std::cout<<"Create gScreen success"<<std::endl;
            SDL_SetRenderDrawColor(gScreen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
            int imgFlags=IMG_INIT_PNG;
            if((IMG_Init(imgFlags)&&imgFlags)) std::cout<<"Create init image.PNG"<<std::endl;
            flag=true;
        }
    }
    return flag;
}

//bool LoadBackground()
//{
//    int ret=gBackground.LoadImage("image/dirt_03.png",gScreen);
//    if(ret==false) return false;
//    return true;
//}
int main (int argc,char* argv[])
{
    //game=new Game();
    //game->InitData();
    if(InitData()==false) return -1;
    //if(LoadBackground()==false) std::cout<<"can load background"<<std::endl;
    GameMap Map;
    Map.LoadMap("map.txt");
    Map.LoadTiles(gScreen);

    MainObject player;
    player.LoadImage("image/right.png",gScreen);
    player.LoadImage("image/left.png",gScreen);
    player.LoadImage("image/ahead.png",gScreen);
    player.LoadImage("image/behind.png",gScreen);
    player.set_clips();

    const int FPS = 60;
    const int framDelay=1000/FPS;

    Uint32 frameStart;
    int frameTime;

    bool is_quit=false;
     while(!is_quit)
    {
        while(SDL_PollEvent(&gEvent)!=0)
        {
            if(gEvent.type==SDL_QUIT)
            {
                is_quit=true;
            }
            player.HandleInputAction(gEvent,gScreen);
            //game->handleEvents();
        }
//        while(game->running())
//        {
//            frameStart =SDL_GetTicks();
//
//            game->handleEvents();
//            game->update();
//            game->render();
//
//            frameTime=SDL_GetTicks()-frameStart;
//
//            if(framDelay>frameTime)
//            {
//            SDL_Delay(framDelay-frameTime);
//            }
//        }

        //frameStart =SDL_GetTicks();

        SDL_SetRenderDrawColor(gScreen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        //game->render();
        SDL_RenderClear(gScreen);

        Map.DrawMap(gScreen);
        //gBackground.Render(gScreen,NULL);
        player.FrameShow(gScreen);

        SDL_RenderPresent(gScreen);


//        frameTime=SDL_GetTicks()-frameStart;
//
//        if(framDelay>frameTime)
//        {
//            SDL_Delay(framDelay-frameTime);
//        }
    }
//    game->close();
    SDL_DestroyWindow(gWindow);
    gWindow=NULL;

    SDL_DestroyRenderer(gScreen);
    gScreen=NULL;

    IMG_Quit();
    SDL_Quit();

    return 0;
}
