#ifndef XU_LY_GAME_H
#define XU_LY_GAME_H
#include <SDL.h>
#include <stdio.h>

class Game{
public:
    Game();
    ~Game();
    void InitData();//
    bool running(){return isRunning;}
    void handleEvents();//
    void render();
    void close();
private:
    bool isRunning;
    SDL_Window* gWindow;
    SDL_Renderer* gScreen;
};
#endif // XU_LY_GAME_H
