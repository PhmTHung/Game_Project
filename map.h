#ifndef GAME_MAP
#define GAME_MAP

#include "basefunc.h"
#include "baseobj.h"

#define MAP_TILE 20

class GameMap
{
public:
    GameMap();
    ~GameMap();

    void LoadMap(std::string path);
    void DrawMap(SDL_Renderer* screen);
    void LoadTiles(SDL_Renderer* screen);

private:
    Map game_map;
    SDL_Rect src,dest;
    BaseObject dirt;
    BaseObject water;

    int MAP[MAP_X][MAP_Y];
};
#endif // GAME_MAP
