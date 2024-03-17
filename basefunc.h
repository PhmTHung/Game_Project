#ifndef BASE_H
#define BASE_H

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
//#include <>

static SDL_Window* gWindow =NULL;
static SDL_Renderer* gScreen=NULL;
static SDL_Event gEvent;

//screen size
const int SCREEN_WIDTH =1280;
const int SCREEN_HEIGHT=640;
const int SCREEN_BPP =32;

const int COLOR_KEY_R =255;
const int COLOR_KEY_G =255;
const int COLOR_KEY_B =255;
const int COLOR_KEY_A =255;

const int RENDER_DRAW_COLOR = 255;

#define TILE_SIZE 32

#define MAP_X 50
#define MAP_Y 25
//
typedef struct Map
{
    int max_x;
    int max_y;

    std::string file_name;
};
#endif // BASE_H

