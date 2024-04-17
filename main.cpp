#include "basefunc.h"
#include "baseobj.h"
#include "mainobj.h"
#include "map.h"
#include "Threats.h"
#include "vukhi.h"
#include "FPS.h"
#include "text.h"
#include "explosion.h"
#include "dropitem.h"
#include<iostream>

std::vector<Threats*> MakeThreatsList()
{
    std::vector<Threats*>list_threats;
    Threats* threat_obj=new Threats[5];
    for(int i=0;i<5;i++)
    {
        Threats* p_threat=(threat_obj+i);
        if(p_threat!=NULL)
        {
            p_threat->LoadImage("image/Threats/threatleft.png", gScreen);
            p_threat->LoadImage("image/Threats/threatright.png", gScreen);
            p_threat->LoadImage("image/Threats/threatforward.png", gScreen);
            p_threat->LoadImage("image/Threats/threatback.png", gScreen);
            p_threat->set_clips();
            p_threat->set_x_pos(i*100+50);
            p_threat->set_y_pos(i*120);

            Weapon* p_bullet=new Weapon();
            p_threat->InitBullet(p_bullet,gScreen);

            list_threats.push_back(p_threat);
        }
    }
    return list_threats;
}
//Game *game = NULL;
TTF_Font* font_time=NULL;
bool InitData()
{
    bool flag=true;
    //thiet lap mt ban dau
    int ret=SDL_Init(SDL_INIT_VIDEO);
    if(ret<0) std::cout<<"ERROR->Init"<<std::endl;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
    gWindow=SDL_CreateWindow("Game Window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
     if(gWindow)
    {   std::cout<<"Create gWindow success"<<std::endl;
        gScreen=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
        if(gScreen)
        {
            std::cout<<"Create gScreen success"<<std::endl;
            SDL_SetRenderDrawColor(gScreen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
            int imgFlags=IMG_INIT_PNG;
            if((IMG_Init(imgFlags)&&imgFlags)) std::cout<<"Create init image.PNG"<<std::endl;
            flag=true;
        }
        if(TTF_Init()==-1) flag=false;
        else
        {
            font_time=TTF_OpenFont("textfont/Font.ttf",24);
            if(font_time == NULL)
            {
                flag=false;
                std::cout<<"TTF cannot Init"<<std::endl;
            }
        }
        if(Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096)==-1)
        {
            flag= false;
            std::cout<<"Mix cannot init";
        }
        get_theme=Mix_LoadWAV("gamesound/Desert_Theme.wav");
        g_sound_bullet[0]=Mix_LoadWAV("gamesound/gun_fire.wav");
        g_sound_bullet[1]=Mix_LoadWAV("gamesound/laser.wav");
        g_sound_exp=Mix_LoadWAV("gamesound/explosion.wav");
        get_coin=Mix_LoadWAV("gamesound/hit_coin.wav");
        char_talk=Mix_LoadWAV("gamesound/char_sound.wav");
        get_hurt=Mix_LoadWAV("gamesound/hurt_sound.wav");
        if(get_theme==NULL)
        {
            std::cout<<"Get theme fail"<<std::endl;
        }
        if(g_sound_exp==NULL)
        {
            std::cout<<"Get explo_sound fail"<<std::endl;
        }
         if(g_sound_bullet[0]==NULL)
        {
            std::cout<<"Get bullet[0]_sound fail"<<std::endl;
        }
         if(g_sound_bullet[1]==NULL)
        {
            std::cout<<"Get bullet[1]_sound fail"<<std::endl;
        }
        if(get_coin==NULL)
        {
            std::cout<<"Get coin_sound fail"<<std::endl;
        }
        if(char_talk==NULL)
        {
            std::cout<<"Get character agr fail"<<std::endl;
        }
    }
    return flag;
}

int main (int argc,char* argv[])
{

    ImpTimer fps_timer;
    if(InitData()==false) return -1;
    //
    Mix_PlayChannel(-1,get_theme,0);

    TextManager time;
    time.SetColorType(TextManager::WHITE_TEXT);

    GameMap G_Map;
    G_Map.LoadMap("map.txt");
    G_Map.LoadTiles(gScreen);

    MainObject player;
    player.LoadImage("image/MainCharacter/right.png",gScreen);
    player.LoadImage("image/MainCharacter/left.png",gScreen);
    player.LoadImage("image/MainCharacter/ahead.png",gScreen);
    player.LoadImage("image/MainCharacter/behind.png",gScreen);
    player.set_clips();

    std::vector<Threats*> threats_list = MakeThreatsList();

    //xu ly vu no
    Explosion exp_threat;
    Explosion exp_main;
    bool tRet=exp_threat.LoadImage("image/Explosion/explosionx8.png",gScreen);
    if(tRet)
    {
        std::cout<<"Init file Explo OK"<<std::endl;
    }
    exp_threat.set_clip();
    //drop item
    DropItem coins;
    bool cret=coins.LoadImage("image/DropItem/coin.png",gScreen);
    if(cret)
    {
        std::cout<<"Init file DropIt OK"<<std::endl;
    }
    coins.set_clips();
    //time text
    TextManager time_game;
    time_game.SetColorType(TextManager::RED_TEXT);


    Uint32 frameStart;
    int frameTime;

    bool is_quit=false;
     while(!is_quit)
    {
        fps_timer.start();
        while(SDL_PollEvent(&gEvent)!=0)
        {
            if(gEvent.type==SDL_QUIT)
            {
                is_quit=true;
            }
            player.HandleInputAction(gEvent,gScreen,g_sound_bullet);
        }

        SDL_SetRenderDrawColor(gScreen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        SDL_RenderClear(gScreen);

        G_Map.DrawMap(gScreen);
        Map map_data=G_Map.getMap();

        player.HandleWeapon(gScreen);
        player.player_move(map_data);
        player.PlayerGPS(map_data);
        player.FrameShow(gScreen);
        player.DrawHPBar(gScreen);

       //std::vector<Threats*> threats_list = MakeThreatsList();
       for (int i=0;i<threats_list.size();i++)
        {
            Threats* p_threat=threats_list.at(i);
            if(p_threat!=NULL)
            {
                p_threat->Threat_Move(map_data);
                //p_threat->SetMapXY(map_data.start_x,map_data.start_y);
                p_threat->MakeBullet(gScreen,SCREEN_WIDTH,SCREEN_HEIGHT);
                p_threat->FrameShow(gScreen);
                p_threat->DrawHPBar(gScreen);

                SDL_Rect rect_player=player.GetRect();
                SDL_Rect rect_threat=p_threat->GetRect();
                bool bCol1=false;
                std::vector<Weapon*> threat_bullet_list=p_threat->get_bullet_list();
                for(int b=0;b<threat_bullet_list.size();b++)
                {
                    Weapon* thr_bullet=threat_bullet_list.at(b);
                    SDL_Rect rect_threat_bullet=thr_bullet->GetRect();
//
                    if(thr_bullet!=NULL)
                    {
                        bCol1=SDLBaseFunc::CheckCollision(rect_threat_bullet,rect_player);
                        if(bCol1)
                        {
                            std::cout<<"Hit threat bullet"<<std::endl;
                            //p_threat->DeleteBullet(b);
                            player.DecreaseHP(thr_bullet->GetThBuDamage());
                            if(player.GetHP()<=0)
                            {
                               std::cout<<"I'm die!"<<std::endl;
                               Mix_PlayChannel(-1,get_hurt,0);
                            }
                            break;
                        }
                    }
                }
                bool bCol2=SDLBaseFunc::CheckCollision(rect_player,rect_threat);
                if(bCol2)
                {
                    std::cout<<"Hit the threat"<<std::endl;
                    player.DecreaseHP(p_threat->GetThreatDamage());
                    //Mix_PlayChannel(-1,get_hurt,0);
                    if(player.GetHP()<=0)
                    {
                        std::cout<<"I'm die!"<<std::endl;
                        Mix_PlayChannel(-1,get_hurt,0);
                    }
                    break;
                }
            }
        }

        int frame_exp_width=exp_threat.get_frame_width();
        int frame_exp_height=exp_threat.get_frame_height();

////        /*threat trung dan*/
        std::vector<Weapon*> bullet_arr=player.get_weapon_list();
        for(int r=0;r<bullet_arr.size();r++)
        {
            Weapon* p_weapon=bullet_arr.at(r);
            if(p_weapon!=NULL)
            {
                for(int t=0;t<threats_list.size();t++)
                {
                    Threats* obj_threat=threats_list.at(t);
                    if(obj_threat!=NULL)
                    {
                        SDL_Rect tRect;
                        tRect.x=obj_threat->GetRect().x;
                        tRect.y=obj_threat->GetRect().y;
                        tRect.w=obj_threat->get_width_frame();
                        tRect.h=obj_threat->get_height_frame();

                        SDL_Rect bRect=p_weapon->GetRect();

                        bool bCol=SDLBaseFunc::CheckCollision(bRect,tRect);
                        if(bCol)
                        {
                            //them weapon damge;
                            //threat trung dan bij tru mau
                            std::cout<<"Hit your bullet"<<std::endl;
                            obj_threat->DecreaseHP(p_weapon->GetWeaponDamage());
                            player.DeleteBullet(r);
                            if(obj_threat->GetHP()<=0)
                            {
                                std::cout<<"Kill"<<std::endl;
                                for(int i=0;i<NUM_FRAM_EXP;i++)
                                {
                                    int x_pos=p_weapon->GetRect().x-frame_exp_width*0.5;
                                    int y_pos=p_weapon->GetRect().y-frame_exp_height*0.5;
                                    //sinh vu no
                                    exp_threat.set_frame(i);
                                    exp_threat.SetRect(x_pos,y_pos);
                                    exp_threat.Show(gScreen);
                                }

                                     for(int i=0;i<4;i++)
                                   {
                                    int x_pos=p_weapon->GetRect().x-frame_exp_width*0.5;
                                    int y_pos=p_weapon->GetRect().y-frame_exp_height*0.5;
                                    //sinh xu,item
//                                    coin->set_frame(i);
//                                    coin->SetRect(x_pos,y_pos);
//                                    coin->Show(gScreen);
                                   }
                                //delete coin;
                                obj_threat->Free();
                                threats_list.erase(threats_list.begin()+t);
                                Mix_PlayChannel(-1,g_sound_exp,0);
                                if(t%2==0)
                                {
                                    Mix_PlayChannel(-1,char_talk,0);
                                    Mix_PlayChannel(-1,g_sound_exp,0);
                                }

                            }

                        }
                    }
                }
            }
        }

        //thoi gian
        std::string str_time="TIME: ";
        Uint32 time_val=SDL_GetTicks()/1000;
        Uint32 val_time=300-time_val;
        if(val_time<=0)
        {
            std::cout<<"Time out"<<std::endl;
        }
        else
        {
            std::string str_val_=std::to_string(val_time);
            str_time+=str_val_;
            time_game.SetText(str_time);
            time_game.LoadFromRenderText(font_time,gScreen);
            time_game.RenderText(gScreen,32,0);
        }

        SDL_RenderPresent(gScreen);

        int real_imp_time=fps_timer.get_ticks();
        int time_one_frame=1000/FRAME_PER_SECOND;

        if(real_imp_time<time_one_frame)
        {
            int delay_time=time_one_frame-real_imp_time;
            if(delay_time>=0)
            {
                 SDL_Delay(delay_time);
            }
        }
    }
    SDL_DestroyWindow(gWindow);
    gWindow=NULL;

    SDL_DestroyRenderer(gScreen);
    gScreen=NULL;

    IMG_Quit();
    SDL_Quit();

    return 0;
}

