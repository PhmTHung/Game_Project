#ifndef GAME_MAP
#define GAME_MAP

#include "basefunc.h"
#include "baseobj.h"

#define MAP_TILE 20


class TileMap:public BaseObject
{
public:
    TileMap();
    ~TileMap();
};

class GameMap
{
public:
    GameMap();
    ~GameMap();

    void LoadMap(std::string path);
    void DrawMap(SDL_Renderer* screen);
    void LoadTiles(SDL_Renderer* screen);

private:
    //Map game_map;
    TileMap tile_map[3];
    SDL_Rect src,dest;
    BaseObject dirt;
    BaseObject water;

    int arr[MAP_X][MAP_Y];
};
#endif // GAME_MAP
