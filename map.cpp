#include "map.h"
//the
#include "baseobj.h"
#include "basefunc.h"
//m
#include <fstream>
#include <iostream>

GameMap::GameMap(){};
GameMap::~GameMap(){};

void GameMap::LoadMap(std::string path)
{
    std::ifstream fin(path);
    if(!fin.is_open())std::cout<<"FILE CAN'T OPEN"<<std::endl;
    else
    {
        for(int i=0;i<MAP_Y;i++)
     {
        for(int j=0;j<MAP_X;j++)
        {
            fin>>MAP[i][j];
            int val=MAP[i][j];
//            if(j>game_map.max_x) game_map.max_x=j;
//            if(i>game_map.max_y) game_map.max_y=i;
        }
     }
//    game_map.max_x=(game_map.max_x+1)*TILE_SIZE;
//    game_map.max_y=(game_map.max_y+1)*TILE_SIZE;
    game_map.file_name=path;
    fin.close();
    }
}
void GameMap::LoadTiles(SDL_Renderer* screen)
{
    dirt.LoadImage("image/dirt_01.png",screen);
    water.LoadImage("image/water.png",screen);
}
void GameMap::DrawMap(SDL_Renderer* screen)
{
    int type=0;
    for(int i=0;i<MAP_Y;i++)
    {
        for(int j=0;j<MAP_X;j++)
        {
            type=MAP[i][j];
            // 1 pyxel
//            dest.x=column*32;
//            dest.y=row*32;
            int vitri_x=i*32;
            int vitri_y=j*32;
            switch(type)
            {
            case 1:
                dirt.SetRect(vitri_x,vitri_y);
                dirt.Render(screen);
                break;
            case 2:
                dirt.SetRect(vitri_x,vitri_y);
                water.Render(screen);
                break;
            default:
                break;
            }
        }
    }
}
