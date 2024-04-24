#include "basefunc.h"
bool SDLBaseFunc::CheckCollision(const SDL_Rect& object1,const SDL_Rect& object2)
{
    int left_a = object1.x;
    int right_a = object1.x + object1.w;
    int top_a = object1.y;
    int bottom_a = object1.y + object1.h;

    int left_b = object2.x;
    int right_b = object2.x + object2.w;
    int top_b = object2.y;
    int bottom_b = object2.y + object2.h;

    if(left_a>left_b && left_a<right_b)
    {
        if (top_a>top_b && top_a<bottom_b) return true;
    }

    if(left_a>left_b && left_a<right_b)
    {
        if (bottom_a>top_b && bottom_a<bottom_b) return true;
    }

    if(right_a>left_b && right_a<right_b)
    {
        if (top_a>top_b && top_a<bottom_b)
        {
            return true;
        }
    }
    if (right_a>left_b && right_a<right_b)
    {
        if (bottom_a>top_b && bottom_a<bottom_b)
        {
            return true;
        }
    }

    if (left_b>left_a && left_b<right_a)
    {
        if (top_b>top_a && top_b<bottom_a)
        {
            return true;
        }
    }
    if (left_b>left_a && left_b<right_a)
    {
        if (bottom_b>top_a && bottom_b<bottom_a)
        {
            return true;
        }
    }
    if (right_b>left_a && right_b<right_a)
    {
        if (top_b>top_a && top_b<bottom_a)
        {
            return true;
        }
    }
    if (right_b>left_a && right_b<right_a)
    {
        if (bottom_b>top_a && bottom_b<bottom_a)
        {
            return true;
        }
    }
    if (top_a==top_b && right_a==right_b && bottom_a==bottom_b)
    {
        return true;
    }
    return false;
}

bool CheckFocusRect(int& x, int& y,const SDL_Rect rect)
{
    if(x>=rect.x && x<= rect.x+rect.w && y>=rect.y && y <= rect.y+rect.h)
    {
        return true;
    }
    return false;
}

//int SDLBaseFunc::ShowMenu(SDL_Surface* des,TTF_Font* font)
//{
//	g_img_menu=LoadImage("start_img.png");
//	if(g_img_menu!=NULL)
//	{
//		std::cout<<""<<std::endl;
//	}
//	const int kMenuItemNum=3;
//	SDL_Rect pos_arr[kMenuItemNum];
//	pos_arr[0].x=200;
//	pos_arr[0].y=400;
//
//	pos_arr[1].x=200;
//	pos_arr[1].y=200;
//
//
//	TextObject text_menu[kMenuItemNum];
//
//	text_menu[0].SetText("Play Game");
//	text_menu[0].SetColor(TextObject::BlackText);
//	text_menu[0].SetRect(pos_arr[0].x,pos_arr[0].y);
//
//	text_menu[1].SetText("Exit");
//	text_menu[1].SetColor(TextObject::BlackText);
//	text_menu[1].SetRect(pos_arr[1].x,pos_arr[1].y);
//
//	bool isSelect[kMenuItemNum]={0,0};
//	int xm=0,ym=0;
//	SDL_Event mouse_event;
//	while(true)
//	{
//		SDLCommonFunc::ApplySurface(g_img_menu,des,0,0);
//		for(int i=0;i<kMenuItemNum;i++)
//		{
//			text_menu[i].CreatGameText(font,des);
//		}
//		while(SDL_PollEvent(&mouse_event))
//		{
//			switch(mouse_event.type)
//			{
//				case SDL_Quit:
//				return 1;
//				case SDL_MOUSEMOTION:
//				{
//					xm=mouse_event.motion.x;
//					ym=mouse_event.motion.y;
//
//					for(int i=0i<kMenuItemNum;i++)
//					{
//						if(CheckFocusRect(x,y,text_menu[i].GetRect()))
//						{
//							if(isSelect==false)
//							{
//							    isSelect[i]=1;
//							    text_menu[i].SetColor(TextObject::RED_TEXT);
//							}
//						}
//						else
//						{
//							if(isSelect==true)
//							{
//							    isSelect[i]=0;
//							    text_menu[i].SetColor(TextObject::BLACK_TEXT);
//							}
//						}
//					}
//				}
//
//			}
//		}
//	}
//}

