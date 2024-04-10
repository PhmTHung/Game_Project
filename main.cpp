#include "basefunc.h"
#include "baseobj.h"
#include "mainobj.h"
#include "map.h"
#include "Threats.h"
#include "FPS.h"
#include<iostream>

//Game *game = NULL;
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

int main (int argc,char* argv[])
{

    ImpTimer fps_timer;
    if(InitData()==false) return -1;
    GameMap G_Map;
    G_Map.LoadMap("map.txt");
    G_Map.LoadTiles(gScreen);

    MainObject player;

    player.LoadImage("image/MainCharacter/right.png",gScreen);
    player.LoadImage("image/MainCharacter/left.png",gScreen);
    player.LoadImage("image/MainCharacter/ahead.png",gScreen);
    player.LoadImage("image/MainCharacter/behind.png",gScreen);
    player.set_clips();

    Threats threats;

    threats.LoadImage("image/Threats/threatleft.png",gScreen);
    threats.LoadImage("image/Threats/threatright.png",gScreen);
    threats.LoadImage("image/Threats/threatforward.png",gScreen);
    threats.LoadImage("image/Threats/threatback.png",gScreen);
    threats.set_clips();

    const int FPS = 30;
    const int framDelay=1000/FPS;

    Uint32 frameStart;
    int frameTime;

    bool is_quit=false;
     while(!is_quit)
    {
        fps_timer.start();
        while(SDL_PollEvent(&gEvent)!=0)
        {
            if(gEvent.type==SDL_QUIT)
            {
                is_quit=true;
            }
            player.HandleInputAction(gEvent,gScreen);
        }

        SDL_SetRenderDrawColor(gScreen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        SDL_RenderClear(gScreen);

        G_Map.DrawMap(gScreen);
        Map map_data=G_Map.getMap();

        player.HandleWeapon(gScreen);
        player.player_move(map_data);
        player.PlayerGPS(map_data);
        player.FrameShow(gScreen);

        threats.Threat_Move(map_data,player);
        threats.FrameShow(gScreen);

        SDL_RenderPresent(gScreen);

        int real_imp_time=fps_timer.get_ticks();
        int time_one_frame=1000/FRAME_PER_SECOND;

        if(real_imp_time<time_one_frame)
        {
            int delay_time=time_one_frame-real_imp_time;
            if(delay_time>=0)
            {
                 SDL_Delay(delay_time);
            }
        }
    }
    SDL_DestroyWindow(gWindow);
    gWindow=NULL;

    SDL_DestroyRenderer(gScreen);
    gScreen=NULL;

    IMG_Quit();
    SDL_Quit();

    return 0;
}
//std::vector<Threats*> MakeThreatsList()
//{
//    std::vector<Threats*>list_threats;
//    Threats* threat_obj=new Threats[20];
//    for(int i=0;i<20;i++)
//    {
//        Threats* p_threat=(threat_obj+i);
//        if(p_threat!=NULL)
//        {
//            threat_obj->LoadImage("image/Threats/threatleft.png", screen);
//            threat_obj->LoadImage("image/Threats/threatright.png", screen);
//            threat_obj->LoadImage("image/Threats/threatforward.png", screen);
//            threat_obj->LoadImage("image/Threats/threatback.png", screen);
//            threat_obj->set_clips();
//            threat_obj->set_x_pos(i * 32 + 250);
//            threat_obj->set_y_pos(250);
//            list_threats.push_back(threat_obj);
//        }
//    }
//}
