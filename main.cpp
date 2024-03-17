#include "basefunc.h"
#include "baseobj.h"
#include "xulygame.h"
#include "mainobj.h"
#include "map.h"
#include<iostream>

Game *game = NULL;
//BaseObject gBackground;

//bool LoadBackground()
//{
//    int ret=gBackground.LoadImage("dirt_03.png",gScreen);
//    if(ret==false) return false;
//    return true;
//}
int main (int argc,char* argv[])
{
    game=new Game();
    game->InitData();
//    if(LoadBackground()==false) std::cout<<"can load background"<<std::endl;
//    GameMap Map;
//    Map.LoadMap("maplv1.txt");
//    Map.LoadTiles(gScreen);
//
//    MainObject player;
//    player.LoadImage("player_left.png",gScreen);
//    player.set_clips();

    bool is_quit=false;
     while(!is_quit)
    {
        while(SDL_PollEvent(&gEvent)!=0)
        {
            if(gEvent.type==SDL_QUIT)
            {
                is_quit=true;
            }
            //player.HandleInputAction(gEvent,gScreen);
            game->handleEvents();
        }
        SDL_SetRenderDrawColor(gScreen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        game->render();
//        SDL_RenderClear(gScreen);
//        Map.DrawMap(gScreen);
//        gBackground.Render(gScreen,NULL);
//        player.FrameShow(gScreen);
//        SDL_RenderPresent(gScreen);
    }
    game->close();
    return 0;
}
