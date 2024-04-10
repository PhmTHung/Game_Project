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
const int SCREEN_WIDTH =800;
const int SCREEN_HEIGHT=800;

const int COLOR_KEY_R =255;
const int COLOR_KEY_G =255;
const int COLOR_KEY_B =255;
const int COLOR_KEY_A =255;

const int RENDER_DRAW_COLOR = 0xFF;

const int FRAME_PER_SECOND = 25;

#define TILE_SIZE 32
#define SPEED_MOVE 8
#define WALL 1
#define MAP_X 25
#define MAP_Y 25
//input duong di chuyen
typedef struct Input
{
    int left;
    int right;
    int up;
    int down;
};

typedef struct Map
{
    int start_x;
    int start_y;

    int max_x;
    int max_y;

    int arr[MAP_X][MAP_Y];

};
#endif // BASE_H

