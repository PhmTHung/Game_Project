#include "basefunc.h"
#include "baseobj.h"
#include "xulygame.h"
//#include "map.h"

Game *game = NULL;

int main (int argc,char* argv[])
{
    game=new Game();
    game->InitData();

    bool is_quit=false;
     while(!is_quit)
    {
        while(SDL_PollEvent(&gEvent)!=0)
        {
            if(gEvent.type==SDL_QUIT)
            {
                is_quit=true;
            }
        }
        SDL_SetRenderDrawColor(gScreen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        game->render();
    }
    game->close();
    return 0;
}
