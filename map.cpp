#include "map.h"
//the
#include "baseobj.h"
#include "basefunc.h"
//m
#include <fstream>
#include <iostream>

GameMap::GameMap()
{
//    dirt.LoadImage("image/dirt_01.png",screen);
//    water.LoadImage("image/water.png",screen);
//
//    src.x=src.y=0;
//    src.w=dest.w=32;
//    src.h=dest.h=32;
//
//    dest.x=dest.y=0;
}
GameMap::~GameMap(){}

void GameMap::LoadMap(std::string path)
{
    std::ifstream fin(path);
    if(!fin.is_open()) std::cout<<"FILE CAN'T OPEN"<<std::endl;
    else
    {
        for(int i=0;i<25;i++)
        {
          for(int j=0;j<25;j++)
          {
            fin>>arr[i][j];
//            if(j>game_map.max_x) game_map.max_x=j;
//            if(i>game_map.max_y) game_map.max_y=i;
          }
        }
//    game_map.max_x=(game_map.max_x+1)*TILE_SIZE;
//    game_map.max_y=(game_map.max_y+1)*TILE_SIZE;
//    game_map.file_name=path;
    fin.close();
    }
}
void GameMap::LoadTiles(SDL_Renderer* screen)
{
    tile_map[i].LoadImage(std::string path,screen);
}
void GameMap::DrawMap(SDL_Renderer* screen)
{
    int type=0;
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            type=arr[i][j];
            // 1 pyxel
//            dest.x=i*32;
//            dest.y=j*32;
            int vt_x=i*TILE_SIZE;
            int vt_y=j*TILE_SIZE;
            switch(type)
            {
            case 1:
                dirt.SetRect(vt_y,vt_x);
                dirt.Render(screen);
                  //dirt.Draw(screen,src,dest);
                break;
            case 2:
                water.SetRect(dest.x,dest.y);
                water.Render(screen);
//                water.Draw(screen,src,dest);
                break;
            default:
                break;
            }
        }
    }
}
