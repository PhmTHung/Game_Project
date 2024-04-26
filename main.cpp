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
#include "menu.h"
#include "bigthreat.h"
#include<iostream>
#include<cstdlib>
int tg =50;
int random()
{
    int n=rand() % 100 + 1;
    return n;
}
int random_x(int n)
{
    int x=(n*100+random()*50-1000)%800;
    if(x<=32)
    {
        x=32;
    }
    if(x>=800)
    {
        x=768;
    }
    return x;
}
int random_y(int n)
{
    int y=(n*150+random()*50-1000)%800;
    if(y<=32)
    {
        y=32;
    }
    if(y>=768)
    {
        y=768;
    }
    return y;
}
std::vector<Threats*> MakeThreatsList()
{
    std::vector<Threats*>list_threats;
    Threats* threat_obj=new Threats[10];
    for(int i=0;i<10;i++)
    {
        Threats* p_threat=(threat_obj+i);
        if(p_threat!=NULL)
        {
            p_threat->LoadImage("image/Threats/threatleft.png", gScreen);
            p_threat->LoadImage("image/Threats/threatright.png", gScreen);
            p_threat->LoadImage("image/Threats/threatforward.png", gScreen);
            p_threat->LoadImage("image/Threats/threatback.png", gScreen);
            p_threat->set_clips();
            p_threat->set_x_pos((i*100+random()*50-1000)%800);
            p_threat->set_y_pos((i*100+random()*100-1000)%800);

            Weapon* p_bullet=new Weapon();
            p_threat->InitBullet(p_bullet,gScreen);

            list_threats.push_back(p_threat);
        }
    }
    return list_threats;
}
std::vector<BThreats*> MakeBigThreatsList()
{
    std::vector<BThreats*>list_bigthreat;
    BThreats* big_thr=new BThreats[2];
    for(int i=0;i<2;i++)
    {
        BThreats* p_bthreat=(big_thr+i);
        if(p_bthreat!=NULL)
        {
            p_bthreat->LoadImage("image/Threats/left.png", gScreen);
            p_bthreat->LoadImage("image/Threats/right.png", gScreen);
            p_bthreat->LoadImage("image/Threats/forward.png", gScreen);
            p_bthreat->LoadImage("image/Threats/back.png", gScreen);
            p_bthreat->set_clips();
            p_bthreat->set_x_pos(random_x(i));
            p_bthreat->set_y_pos(random_y(i));
            list_bigthreat.push_back(p_bthreat);
        }
    }
    return list_bigthreat;
}
std::vector<DropItem*>MakeCoins()
{
    std::vector<DropItem*>list_coins;
    DropItem* Coins=new DropItem[5];
    for(int i=0;i<5;i++)
    {
        DropItem* coins=(Coins+i);
        if(coins!=NULL)
        {
            coins->LoadImage("image/DropItem/coinsprite.png",gScreen);
        }
        coins->set_clips();
        coins->set_x_pos(random_x(i));
        coins->set_y_pos(random_y(i));
        list_coins.push_back(coins);
    }
    return list_coins;
}

std::vector<DropItem*>MakeHeal()
{
    std::vector<DropItem*>list_heal;
    DropItem* Heal_pick=new DropItem[1];
    for(int i=0;i<1;i++)
    {
        DropItem* heal=(Heal_pick+i);
        if(heal!=NULL)
        {
            heal->LoadImage("image/DropItem/heal.png",gScreen);
        }
        heal->set_clips();
        heal->set_x_pos(random_x(i));
        heal->set_y_pos(random_y(i));
        list_heal.push_back(heal);
    }
    return list_heal;
}

std::vector<DropItem*>MakeMushroom()
{
    std::vector<DropItem*>list_mushroom;
    DropItem* mushroom_pick=new DropItem[1];
    for(int i=0;i<1;i++)
    {
        DropItem* mushroom=(mushroom_pick+i);
        if(mushroom!=NULL)
        {
            mushroom->LoadImage("image/DropItem/mushroom.png",gScreen);
        }
        mushroom->set_clips();
        mushroom->set_x_pos(random_x(i));
        mushroom->set_y_pos(random_y(i));
        list_mushroom.push_back(mushroom);
    }
    return list_mushroom;
}
TTF_Font* font_time=NULL;
TTF_Font* font_game=NULL;
TTF_Font* font_title=NULL;
//SDL_Texture* gMenu=NULL;
BaseObject menu;
BaseObject GOver;
bool InitData()
{
    bool flag=true;
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
            font_game=TTF_OpenFont("textfont/Font.ttf",60);
            font_title=TTF_OpenFont("textfont/BigFont.ttf",72);
            if(font_time == NULL)
            {
                flag=false;
                std::cout<<"font time cannot Init"<<std::endl;
            }
            if(font_game == NULL)
            {
                flag=false;
                std::cout<<"font game cannot Init"<<std::endl;
            }
            if(font_title == NULL)
            {
                flag=false;
                std::cout<<"font title cannot Init"<<std::endl;
            }
        }
        if(Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096)==-1)
        {
            flag= false;
            std::cout<<"Mix cannot init";
        }
        ///sound
        get_theme=Mix_LoadWAV("gamesound/Desert_Theme.wav");
        g_sound_bullet[0]=Mix_LoadWAV("gamesound/gun_fire.wav");
        g_sound_bullet[1]=Mix_LoadWAV("gamesound/laser.wav");
        g_sound_exp=Mix_LoadWAV("gamesound/explosion.wav");
        get_coin=Mix_LoadWAV("gamesound/hit_coin.wav");
        char_talk=Mix_LoadWAV("gamesound/char_sound.wav");
        get_hurt=Mix_LoadWAV("gamesound/hurt_sound.wav");
        GameOver=Mix_LoadWAV("gamesound/GO_sound.wav");
        Heal=Mix_LoadWAV("gamesound/healsound.wav");
        eat=Mix_LoadWAV("gamesound/eatsound.wav");
    }
    return flag;
}

int main (int argc,char* argv[])
{



    int count_threat_kill=0;

    ImpTimer fps_timer;
    if(InitData()==false) return -1;
    //PLAY THEME MUSIC
    Mix_PlayChannel(-1,get_theme,-1);
    //GAME MAP
    GameMap G_Map;
    G_Map.LoadMap("map.txt");
    G_Map.LoadTiles(gScreen);

    //PLAYER IMAGE
    MainObject player;
    player.LoadImage("image/MainCharacter/right.png",gScreen);
    player.LoadImage("image/MainCharacter/left.png",gScreen);
    player.LoadImage("image/MainCharacter/ahead.png",gScreen);
    player.LoadImage("image/MainCharacter/behind.png",gScreen);
    player.set_clips();

    std::vector<Threats*>threats_list=MakeThreatsList();
    std::vector<BThreats*>bthreat_list=MakeBigThreatsList();
    std::vector<DropItem*>coins_list=MakeCoins();
    std::vector<DropItem*>heal_list=MakeHeal();
    std::vector<DropItem*>mushroom_list=MakeMushroom();

    ///EXPLOSION
    Explosion exp_threat;
    bool expl_init=exp_threat.LoadImage("image/Explosion/explosionx8.png",gScreen);
    if(expl_init)
    {
        std::cout<<"Init file Explo OK"<<std::endl;
    }
    exp_threat.set_clip();
    ///TEXT
    TextManager time;
    time.SetColorType(TextManager::WHITE_TEXT);
    TextManager time_game;
    time_game.SetColorType(TextManager::RED_TEXT);
    TextManager score;
    score.SetColorType(TextManager::RED_TEXT);
    TextManager money_count;
    money_count.SetColorType(TextManager::YELLOW_TEXT);
    TextManager game_over;
    game_over.SetColorType(TextManager::WHITE_TEXT);

    TextManager last_time_game,money_earn_persecond;
    last_time_game.SetColorType(TextManager::RED_TEXT);

    //
    int money_earn=0;
    Uint32 frameStart;
    int frameTime;
    //bool is_quit=false;

    menu.LoadImage("image/background5.png",gScreen);
    GOver.LoadImage("image/background.png",gScreen);

    const int kMenu=2;
	SDL_Rect pos_arr[kMenu];
	pos_arr[0].x=450;
	pos_arr[0].y=400;

	pos_arr[1].x=550;
	pos_arr[1].y=600;

    TextManager text_menu[kMenu],title_menu;
	text_menu[0].SetText("PLAY GAME");
	text_menu[0].SetColorType(TextManager::WHITE_TEXT);
	text_menu[0].SetRect(pos_arr[0].x,pos_arr[0].y);

	text_menu[1].SetText("EXIT");
	text_menu[1].SetColorType(TextManager::WHITE_TEXT);
	text_menu[1].SetRect(pos_arr[1].x,pos_arr[1].y);
	title_menu.SetColorType(TextManager::RED_TEXT);



    bool menu1=true;
    bool is_quit=true;
    bool isSelect[kMenu]={0,0};
    SDL_Event mouse_event;
    std::string titlemenu=" ~ SURVIVOR ~ ";
    while(menu1)
    {
       menu.Render(gScreen,NULL);
       title_menu.SetText(titlemenu);
       title_menu.LoadFromRenderText(font_title,gScreen);
       title_menu.RenderText(gScreen,100,100);

       for(int i=0;i<kMenu;i++)
		{
			text_menu[i].LoadFromRenderText(font_game,gScreen);
			text_menu[i].RenderText(gScreen,pos_arr[i].x,pos_arr[i].y);
		}
        int xm=0,ym=0;
        while (SDL_PollEvent(&mouse_event))
         {
             switch(mouse_event.type)
               {
                    case SDL_MOUSEMOTION:
				    {
					   xm=mouse_event.motion.x;
					   ym=mouse_event.motion.y;

					for(int i=0;i<kMenu;i++)
					{
					    bool menu_select=SDLBaseFunc::CheckFocusRect(xm,ym,text_menu[i].GetRect());
						if(SDLBaseFunc::CheckFocusRect(xm,ym,text_menu[i].GetRect()))
						{
							if(isSelect[i]==false)
							{
							    isSelect[i]=true;
							    text_menu[i].SetColorType(TextManager::RED_TEXT);
							}
						}
						else
						 {
							if(isSelect[i]==true)
							{
							    isSelect[i]=false;
							    text_menu[i].SetColorType(TextManager::WHITE_TEXT);
							}
						 }
					  }
                }
                break;
                    case SDL_MOUSEBUTTONDOWN:
                    {
                       SDL_GetMouseState(&xm, &ym);
                       if (xm>430&&xm<550 && ym>400 && ym<800)
                       {
                           menu1 = false;
                           is_quit = false;
                       }
                       if (xm>550 && xm <600 &&ym>600&&ym<800)
                       {
                           is_quit=true;
                           menu1=false;
                       }
                    }
             }
         }
       SDL_RenderPresent(gScreen);
      }
    ///vong lap chinh
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


        ///hien thi so dong xu dang co
        int money_earn=player.GetMoney();
        std::string s="COINS:  ";
        std::string money_str;
        money_str=s+ std::to_string(money_earn);
        ///Hien thi so tien hien co
        money_count.SetText(money_str);
        money_count.LoadFromRenderText(font_time,gScreen);
        money_count.RenderText(gScreen,SCREEN_WIDTH-300,3);

        ///Hien thi so score
        std::string s2="KILL:  ";
        std::string score_str;
        score.SetText(score_str);
        score_str=s2+std::to_string(count_threat_kill);
        score.SetText(score_str);
        score.LoadFromRenderText(font_time,gScreen);
        score.RenderText(gScreen,SCREEN_WIDTH-500,3);

        ///Hien thi va check va cham dong xu
        for (int i=0;i<coins_list.size();i++)
        {
            DropItem* coins = coins_list.at(i);
            if(coins!=NULL)
            {
                coins->FrameShow(gScreen);
            }
            SDL_Rect rect_player=player.GetRect();
            SDL_Rect rect_coin=coins->GetRect();
            bool coinCols=SDLBaseFunc::CheckCollision(rect_player,rect_coin);
             if(coinCols)
             {
                std::cout<<"Get Coin"<<std::endl;
                player.IncreaseMoney();
                Mix_PlayChannel(-1,get_coin,0);
                coins->Free();
                coins_list.erase(coins_list.begin()+i);
             }
        }
        ///va cham vs Heal Item
        for (int i=0;i<heal_list.size();i++)
        {
            DropItem* heal = heal_list.at(i);
            if(heal!=NULL)
            {
                heal->FrameShow(gScreen);
            }
            SDL_Rect rect_player=player.GetRect();
            SDL_Rect rect_heal=heal->GetRect();
            bool it1Cols=SDLBaseFunc::CheckCollision(rect_player,rect_heal);
             if(it1Cols)
             {
                std::cout<<"Get heal"<<std::endl;
                player.IncreaseHP();
                Mix_PlayChannel(-1,Heal,-1);
                heal->Free();
                heal_list.erase(heal_list.begin()+i);
             }
        }
        ///va cham nam
        for (int i=0;i<mushroom_list.size();i++)
        {
            DropItem* mushroom = mushroom_list.at(i);
            if(mushroom!=NULL)
            {
                mushroom->FrameShow(gScreen);
            }
            SDL_Rect rect_player=player.GetRect();
            SDL_Rect rect_mushroom=mushroom->GetRect();
            bool it2Cols=SDLBaseFunc::CheckCollision(rect_player,rect_mushroom);
             if(it2Cols)
             {
                std::cout<<"Get mushroom to increase speed"<<std::endl;
                player.IncreaseSpeed();
                Mix_PlayChannel(-1,eat,0);
                mushroom->Free();
                mushroom_list.erase(mushroom_list.begin()+i);
             }
        }
       for (int i=0;i<threats_list.size();i++)
        {
            Threats* p_threat=threats_list.at(i);
            if(p_threat!=NULL)
            {
                ///SHOW THREAT ANIMATION,MOVE
                Weapon* t_bullet;
                p_threat->Threat_GPS(player.get_x_pos(),player.get_y_pos());
                p_threat->MakeBullet(gScreen,SCREEN_HEIGHT,SCREEN_WIDTH,player.get_x_pos(),player.get_y_pos());
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
                            player.DecreaseHP(p_threat->GetThreatDamage());
                        }
                    }
                }
                bool bCol2=SDLBaseFunc::CheckCollision(rect_player,rect_threat);
                if(bCol2)
                {
                    std::cout<<"Hit the threat"<<std::endl;
                    player.DecreaseHP(p_threat->GetThreatDamage());
                    std::cout<<player.GetHP()<<std::endl;
                    Mix_PlayChannel(-1,get_hurt,0);
                    //break;
                }
            }
        }
         for (int i=0;i<bthreat_list.size();i++)
        {
            BThreats* p_bthreat=bthreat_list.at(i);
            if(p_bthreat!=NULL)
            {
                p_bthreat->Threat_GPS(player.get_x_pos(),player.get_y_pos());
                p_bthreat->FrameShow(gScreen);
                p_bthreat->DrawHPBar(gScreen);

                SDL_Rect rect_player=player.GetRect();
                SDL_Rect rect_bthreat=p_bthreat->GetRect();
                bool bCol3=SDLBaseFunc::CheckCollision(rect_player,rect_bthreat);
                if(bCol3)
                {
                    std::cout<<"Hit the threat"<<std::endl;
                    player.DecreaseHP(p_bthreat->GetThreatDamage());
                    std::cout<<player.GetHP()<<std::endl;
                    Mix_PlayChannel(-1,get_hurt,0);
                    //break;
                }
            }
        }

        ///LAY CHIEU DAI,RONG FRAME
        int frame_exp_width=exp_threat.get_frame_width();
        int frame_exp_height=exp_threat.get_frame_height();

        ///THREAT TRUNG DAN CUA NGUOI CHOI
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
                            ///them weapon damge;
                            ///threat trung dan bi tru mau
                            std::cout<<"Hit your bullet"<<std::endl;
                            obj_threat->DecreaseHP(p_weapon->GetWeaponDamage());
                            player.DeleteBullet(r);
                            if(obj_threat->GetHP()<=0)
                            {
                                count_threat_kill++;
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
                for(int t=0;t<bthreat_list.size();t++)
                {
                    BThreats* obj_bthreat=bthreat_list.at(t);
                    if(obj_bthreat!=NULL)
                    {
                        SDL_Rect btRect=obj_bthreat->GetRect();
                        SDL_Rect bRect=p_weapon->GetRect();
                        bool bgCol=SDLBaseFunc::CheckCollision(bRect,btRect);
                        if(bgCol)
                        {
                            ///them weapon damge;
                            ///threat trung dan bi tru mau
                            std::cout<<"Hit your bullet"<<std::endl;
                            obj_bthreat->DecreaseHP(p_weapon->GetWeaponDamage());
                            player.DeleteBullet(r);
                            if(obj_bthreat->GetHP()<=0)
                            {
                                count_threat_kill++;
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
                                obj_bthreat->Free();
                                bthreat_list.erase(bthreat_list.begin()+t);
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


        ///thoi gian
        std::string str_time="SURVIVOR TIME: ";
        Uint32 time_val=SDL_GetTicks()/1000;
        Uint32 val_time=time_val;
        std::string str_val_=std::to_string(val_time);
        str_time+=str_val_;
        time_game.SetText(str_time);
        time_game.LoadFromRenderText(font_time,gScreen);
        time_game.RenderText(gScreen,32,0);
        ///tao moi coins,threats,heal item theo thoi gian
        if(time_val%10==0)
        {
            if(coins_list.size()<3)
             {
                 coins_list=MakeCoins();
             }
        }
        if(time_val%10==0 && time_val>0)
        {
            if(threats_list.size()<1)
            {
                threats_list=MakeThreatsList();
            }
        }
        if(time_val%5==0 && time_val>0)
        {
            if(heal_list.size()<1)
            {
                heal_list=MakeHeal();
            }
        }
        if(time_val%5==0 && time_val>0)
        {
            if(mushroom_list.size()<1)
            {
                mushroom_list=MakeMushroom();
            }
        }
        if((time_val%15==0 && time_val>1))
        {
            if(bthreat_list.size()<1)
            {
                 bthreat_list=MakeBigThreatsList();
            }

        }
        bool go=false;
        if(player.GetHP()<=0)
        {
            go=true;
        }
        if(time_val>20 && time_val<30)
        {
            std::string game_str=" GOOD JOB !";
            game_over.SetText(game_str);
            game_over.LoadFromRenderText(font_game,gScreen);
        }
        else if(time_val<5)
        {
            std::string game_str="SO BAD";
            game_over.SetText(game_str);
            game_over.LoadFromRenderText(font_game,gScreen);
        }
        else if(time_val>30)
        {
            std::string game_str="EXCELLENT";
            game_over.SetText(game_str);
            game_over.LoadFromRenderText(font_game,gScreen);
        }

        std::string last_time="TIME SURIVIVOR :"+str_val_;
        last_time_game.SetText(last_time);
        last_time_game.LoadFromRenderText(font_game,gScreen);
        ///time_game.
        if(go)
        {
            std::cout<<"I'm die!"<<std::endl;

            menu.Render(gScreen,NULL);
            SDL_RenderPresent(gScreen);
            Mix_PlayChannel(-1,GameOver,0);

            last_time_game.RenderText(gScreen,100,SCREEN_HEIGHT/2-100);
            game_over.RenderText(gScreen,SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
            SDL_RenderPresent(gScreen);
            SDL_Delay(9000);
            //Mix_PausedMusic();
            is_quit=true;
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
