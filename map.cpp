#include "map.h"
#include "baseobj.h"
#include "basefunc.h"
#include <fstream>
#include <iostream>

GameMap::GameMap(){}
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
            fin>>game_map.arr[i][j];
          }
        }
    fin.close();
    }
}
void GameMap::LoadTiles(SDL_Renderer* screen)
{
     grass.LoadImage("image/MapTile/grass0.png",screen);
     brick.LoadImage("image/MapTile/brick.png",screen);
     sea.LoadImage("image/MapTile/sea.png",screen);
     flower.LoadImage("image/MapTile/flower.png",screen);
}
void GameMap::DrawMap(SDL_Renderer* screen)
{
    int type=0;
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            type=game_map.arr[i][j];
            // 1 pyxel
            int vt_x=i*TILE_SIZE;
            int vt_y=j*TILE_SIZE;
            switch(type)
            {
            case 1:
                brick.SetRect(vt_y,vt_x);
                brick.Render(screen);
                break;
            case 2:
                grass.SetRect(vt_y,vt_x);
                grass.Render(screen);
                break;
            case 3:
                sea.SetRect(vt_y,vt_x);
                sea.Render(screen);
                break;
            case 4:
                grass.SetRect(vt_y,vt_x);
                grass.Render(screen);
                flower.SetRect(vt_y,vt_x);
                flower.Render(screen);
                break;
            default:
                break;
            }
        }
    }
}
