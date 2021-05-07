#include <iostream>
#include "TXLib.h"

using namespace std;

void DrawStarNew  (int x, int y, int sizeR, COLORREF colorStar);
void DrawStarBang (int x, int y, int sizeX, int sizeY, COLORREF colorST);

void DrawPlanet (int x, int y, int placeR, int PosPlanetX, int PosPlanetY, int R, COLORREF colorPL );
void ThisStart ( );
void PlanetRotates ( );
void BackGround ( );
void DrawGrass (int x, int y, int SizeX, int SizeY, int wind);
void DrawTree(int x, int y, int sizeX, int sizeY);
void RostLes ( );
//void Earth ( );

int main()
    {

    ThisStart ( );
    PlanetRotates ( );
    BackGround ( );
   //Earth ( );

    return 0;
    }
//--------------------------------------------------------------------------------------------------------
void ThisStart ( )
   {
    txCreateWindow (1200, 800);
    txSetFillColor (RGB (85, 70, 145));

    int i=0;
    while (i<=25)
        {
        txClear ();

        DrawStarNew   (600, 400, 8 + i, RGB (  0, 255, 255));
        txSleep (50);
        i+=2 ;
        DrawStarNew   (600, 400, 8 + i, RGB (  0, 255,   0));
        txSleep (50);
        i+=2;
        DrawStarNew   (600, 400, 8 + i, RGB (255, 255,   0));
        txSleep (50);
        i+=2;
        txSetFillColor (RGB (85, 70, 145));
        }

    for (i=25; i<800; i+=20)
        {
         DrawStarBang (555, 502, 150 + i*2, 150 + i*2, TX_YELLOW);
         if (i>100)
             {
             DrawStarBang (590, 395,  50 + i*2,  30 + i*2, TX_RED);
             if (i>200)
                 {
                 DrawStarBang (610, 370,  -10 + i,     -10 + i, TX_ORANGE);
                 }
              }

         txSleep (5);
         }
   }

//--------------------------------------------------------------------------------------------------------
void DrawStarNew (int x, int y, int sizeR, COLORREF colorStar)
    {
    txSetFillColor (colorStar);
    txCircle       (x, y, sizeR);

    }
//--------------------------------------------------------------------------------------------------------
void DrawStarBang (int x, int y, int sizeX, int sizeY, COLORREF colorST)
    {
    txSetColor     (TX_RED, 3);
    txSetFillColor (colorST);
    POINT Star[]=   {{x - ( 35 + sizeX), y + ( 92 + sizeY  )}, {x - (30 + sizeX /2), y + (35 + sizeY /2)},
                     {x - ( 80 + sizeX), y + ( 65 + sizeY  )}, {x - (30 + sizeX /2), y + (10 + sizeY /4)},
                     {x - (110 + sizeX), y - ( 30 + sizeY/2)}, {x - (10 + sizeX /2), y - (20 + sizeY /2)},
                     {x + (  0        ), y - ( 96 + sizeY  )}, {x + (20 + sizeX /4), y - (30 + sizeY /2)},
                     {x + ( 80 + sizeX), y - ( 65 + sizeY  )}, {x + (30 + sizeX /2), y - (10 + sizeY /2)},
                     {x + (120 + sizeX), y - (  0          )}, {x + (60 + sizeX /2), y + (25 + sizeY /4)},
                     {x + (100 + sizeX), y + (110 + sizeY  )}, {x + (15 + sizeX /4), y + (50 + sizeY /2)}};
    txPolygon (Star, 14);
    }
void PlanetRotates ( )
    {
    txSetFillColor (RGB (25,  5, 100));
    txClear ();
    txBegin ();
    int i=1;
    while (i<=180)
        {
        txClear ();
        DrawPlanet (600, 400,  80,  ROUND ( 80*cos(  5+(i*0.02))+600), ROUND (400+ 80*sin(  5+(i*0.02))), 12, RGB (165, 180, 180));
        DrawPlanet (600, 400, 120,  ROUND (120*cos     (i*0.03) +600), ROUND (400-120*sin     (i*0.03)) , 20, RGB (256, 128,   0));
        DrawPlanet (600, 400, 160,  ROUND (160*cos(100-(i*0.04))+600), ROUND (400+160*sin(100-(i*0.04))), 15, RGB ( 90, 170, 255));
        DrawPlanet (600, 400, 200,  ROUND (200*cos     (i*0.06) +600), ROUND (400+200*sin     (i*0.06)) ,  9, RGB (255,   0,   0));
        DrawPlanet (600, 400, 240,  ROUND (240*cos(180+(i*0.06))+600), ROUND (400-240*sin(180+(i*0.06))), 28, RGB ( 60, 195, 135));
        DrawPlanet (600, 400, 280,  ROUND (280*cos     (i*0.07) +600), ROUND (400+280*sin     (i*0.07)) , 12, RGB ( 70, 205, 200));
        DrawPlanet (600, 400, 320,  ROUND (320*cos(270-(i*0.08))+600), ROUND (400+320*sin(270-(i*0.08))), 20, RGB ( 40, 125, 150));
        DrawPlanet (600, 400, 360,  ROUND (360*cos     (i*0.08) +600), ROUND (400+360*sin     (i*0.08)) , 20, RGB ( 20,  85, 170));

        txSleep (50);

        i++;
        }

     for (int t=1; t<=800; t+=5)
        {

        DrawStarNew (610, 240, 15 + t, RGB ( 90, 170, 255));
        txSleep ();
        }

     txEnd ();
    }

void DrawPlanet (int x, int y, int placeR, int PosPlanetX, int PosPlanetY, int R, COLORREF colorPL )
    {
    txSetColor     (RGB (255, 255,   0));
    txSetFillColor (RGB (255, 255,   0));
    txCircle       (x,    y,    30);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_TRANSPARENT);
    txCircle (x, y, placeR);

    txSetColor (TX_BLACK, 1);
    txSetFillColor (colorPL);
    txCircle       (PosPlanetX, PosPlanetY,  R);

    }
void BackGround ( )
    {
     txSetFillColor (RGB (128, 255, 255));
     txRectangle (1, 1, 1199, 350);
     txClear();

     txSetFillColor (RGB (0, 190 ,50));
     txRectangle (1, 350, 1199, 799);
     RostLes ( );
    }

//-------
void RostLes ( )
    {
    int t=0;
    while (t<10)
        {
        txSetFillColor (RGB (128, 255, 255));
        txRectangle (1, 1, 1199, 350);
        txClear();

        txSetFillColor (RGB (0, 190 ,50));
        txRectangle (1, 350, 1199, 799);


        DrawGrass ( 60, 480, -25 + t*2, 75 - t*8,  15 - (t%3*15));
        DrawGrass ( 90, 320, -20 + t-t*2, 75 - t*6, -10 + (t%3*10));
        DrawGrass (410, 580, -10 + t*2, 75 - t*7,  20 - (t%3*20));
        DrawGrass (600, 420, -20 + t*2, 75 - t*6, -10 + (t%3*10));

        DrawTree(350, 550, -10+t,   -10+t );
        DrawTree(170, 400, -10+t/2, -10+t/2);
        DrawTree(200, 700, -10+t, -10 + t+(t/4));

        txSleep (100);

        t++;
        }
      }
//---------
void DrawGrass (int x, int y, int SizeX, int SizeY, int wind)
     {
         txSetFillColor (RGB (0, 77, 19));
         POINT Tr[]=   {{x-(35+SizeX), y+85}, {x-(44+wind), y+38+SizeY},
                        {x-(20+SizeX), y+75}, {x+wind, y+SizeY},
                        {x+10+SizeX, y+75}, {x+40+wind, y+30+SizeY},
                        {x+20+SizeX, y+85}};
         txPolygon (Tr, 7);
     }
//---------
void DrawTree(int x, int y, int sizeX, int sizeY)
        {
        txSetFillColor (RGB (108, 0, 0));
        txRectangle (x- 27-sizeX*2, y+32+(32*sizeY/10), x+27+sizeX*2, y);

        txSetColor     (TX_GREY);
        txSetFillColor (TX_GREEN);
        POINT e1[]= {{x - 175-(175*sizeX/10), y                     }, {x + 175+(175*sizeX/10), y                     },
                     {x +  63+( 63*sizeX/10), y -  88-( 88*sizeY/10)}, {x -  63-( 63*sizeX/10), y -  88-( 88*sizeY/10)}};

        POINT e2[]= {{x - 150-(150*sizeX/10), y -  88-( 88*sizeY/10)}, {x + 150+(150*sizeX/10), y -  88-( 88*sizeY/10)},
                     {x +  27+( 27*sizeX/10), y - 184-(184*sizeY/10)}, {x -  27-( 27*sizeX/10), y - 184-(184*sizeY/10)}};

        POINT e3[]= {{x -  90-( 90*sizeX/10), y - 184-(184*sizeY/10)}, {x +  90+( 90*sizeX/10), y - 184-(184*sizeY/10)},
                     {x,                      y - 264-(264*sizeY/10)}};
        txPolygon (e1, 4);
        txPolygon (e2, 4);
        txPolygon (e3, 3);

        txSetFillColor (RGB (120, 240, 0));
        POINT ev1[]={{x -  90-( 90*sizeX/10), y -  24-( 24*sizeY/10)}, {x +  90+( 90*sizeX/10), y -  24-( 24*sizeY/10)},
                     {x,                      y -  72-(72*sizeY/10)}};
        POINT ev2[]={{x -  72-( 72*sizeX/10), y - 104-(104*sizeY/10)}, {x +  72+( 72*sizeX/10), y - 104-(104*sizeY/10)},
                     {x,                      y - 160-(160*sizeY/10)}};
        POINT ev3[]={{x -  36-( 36*sizeX/10), y - 200-(200*sizeY/10)}, {x +  36+( 36*sizeX/10), y - 200-(200*sizeY/10)},
                     {x,                      y - 232-(232*sizeY/10)}};
        txPolygon (ev1, 3);
        txPolygon (ev2, 3);
        txPolygon (ev3, 3);
        }
//-----------
