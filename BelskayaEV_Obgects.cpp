#include <iostream>
#include "TXLib.h"
using namespace std;


//void TreeUp (int x, int y);

void BackGround (int x, int y);
void DrawGrass (int x, int y, int SizeX, int SizeY);
void DrawTree  (int x, int y, int sizeX, int sizeY);
void DrawPlanet(int x, int y) ;
void DrawHous  (int x, int y);
void DrawCat   (int x, int y);
void DrawWell  ();

int main()
    {
    BackGround (60, 400) ;


    DrawTree (200, 500, 90, 80);
    DrawTree (300, 400, 60, 40);
    //DrawTree (400,  300);
    //DrawTree (180,  200);
    //DrawTree (1050, 250);

    DrawPlanet (400, 150) ;
    DrawHous   (740, 320);
    DrawCat    (900, 550);
    DrawWell   ();

    return 0;
    }

void BackGround (int x, int y)
    {
     txCreateWindow (1200, 800);
     txSetFillColor (RGB (128, 255, 255));
     txClear();


     txSetFillColor (RGB (0, 190 ,50));
     txRectangle (1, 350, 1199, 799);

     DrawGrass (60, 400, -18, -35);
     DrawGrass (200, 430, -15, -45);
     DrawGrass (350, 480, -5, -40);
     DrawGrass (80, 500, -10, -30);




     }


void DrawGrass (int x, int y, int SizeX, int SizeY)
     {
         txSetFillColor (RGB(0, 77, 19));
         POINT Tr[]=   {{x-35-SizeX, y+85+SizeY}, {x-44-SizeX, y+38+SizeY}, {x-20-SizeX, y+75+SizeY}, {x, y},
                        {x+20+SizeX, y+75+SizeY}, {x+40+SizeX, y+30+SizeY}, {x+30+SizeX, y+85+SizeY}};
         txPolygon (Tr, 7);
     }

void DrawPlanet (int x, int y)
    {
        txSetColor (TX_BLACK, 2);
        txSetFillColor (TX_TRANSPARENT);
        for ( int i=2; i<=4; i++ )
            {
            txCircle (x, y, i*20);
             }
        txSetColor     (TX_YELLOW);
        txSetFillColor (TX_YELLOW);
        txCircle       (x,    y,    10);
        txSetFillColor (TX_BROWN);
        txCircle       (x-30, y+25,  8);
        txSetFillColor (TX_LIGHTBLUE);
        txCircle       (x+40, y+40,  8);
        txSetFillColor (TX_GREEN);
        txCircle       (x+60, y-50,  9);
    }

void DrawTree(int x, int y, int sizeX, int sizeY)
    {
         txSetFillColor (RGB (108, 0, 0));
         txRectangle (x- 0.3*sizeX, y+3.7*sizeY, x+0.3*sizeX, y+3.3*sizeY);

        txSetColor (TX_GREY);
        txSetFillColor (TX_GREEN);
        POINT e1[]= {{x-2  *sizeX, y+3.3*sizeY}, {x+2  *sizeX, y+3.3*sizeY}, {x+0.7*sizeX, y+2.2*sizeY}, {x-0.7*sizeX, y+2.2*sizeY}};
        POINT e2[]= {{x-1.7*sizeX, y+2.2*sizeY}, {x+1.7*sizeX, y+2.2*sizeY}, {x+0.3*sizeX, y+    sizeY}, {x-0.3*sizeX, y+    sizeY}};
        POINT e3[]= {{x-    sizeX, y+    sizeY}, {x+    sizeX, y+    sizeY}, {x,    y}};
        txPolygon (e1, 4);
        txPolygon (e2, 4);
        txPolygon (e3, 3);

        txSetFillColor (RGB (120, 240, 0));
        POINT ev1[]={{x-    sizeX, y+3  *sizeY}, {x+     sizeX, y+3  *sizeY}, {x,    y+2.4*sizeY}};
        POINT ev2[]={{x-0.8*sizeX, y+2  *sizeY}, {x+ 0.8*sizeX, y+2  *sizeY}, {x,    y+1.3*sizeY}};
        POINT ev3[]={{x-0.4*sizeX, y+0.8*sizeY}, {x+ 0.4*sizeX, y+0.8*sizeY}, {x,    y+0.4*sizeY}} ;
        txPolygon (ev1, 3);
        txPolygon (ev2, 3);
        txPolygon (ev3, 3);
    }
/*void TreeUp (int x, int y)
    {
     DrawTree (x, y, sizeX, sizeY);
      txBegin();

      int n = 0;
      while (n < 5)
        {
        DrawTree(x, y-n*10, );

        txSleep(100);

        n++;
        }
    txEnd();
     }       */

void DrawHous(int x, int y)
    {
     txSetColor     (RGB (  0,   0, 0));
     txSetFillColor (RGB (255, 200, 0));
     txRectangle (x-105, y+310, x+105, y+120);
     txSetFillColor (TX_YELLOW);
     txRectangle (x- 60, y+255, x+ 30, y+150) ;
     txSetFillColor (RGB (128, 255, 0));
     txRectangle (x+ 40, y+310, x+105, y+145);
     txSetFillColor (RGB (128,   0, 0));
     POINT dv[]={{x+140, y+120}, {x-140, y+120}, {x, y}};
     txPolygon (dv, 3);
     txLine      (x- 60, y+180, x+ 30, y+180);
     txLine      (x- 15, y+150, x- 15, y+255) ;
     }

void DrawCat(int x, int y)
    {
     txSetColor     (RGB (255, 108, 11));
     txSetFillColor (RGB (255, 127, 39));
     POINT hv[]=  {{x-45, y+50}, {x-22, y+50}, {x-35, y+40}};
     txPolygon (hv, 3);
     POINT body[]={{x-22, y+50}, {x- 2, y},    {x+ 1, y},  {x+18, y+50}};
     txPolygon (body, 4);
     txEllipse (x+15, y,    x-15, y-30);
     POINT L[]=   {{x-15, y-26}, {x- 5, y-26}, {x-10, y-40}};
     txPolygon (L, 3);
     POINT R[]=   {{x+ 2, y-26}, {x+12, y-26}, {x+ 7, y-40}};
     txPolygon (R, 3);
     txSetFillColor (TX_LIGHTBLUE);
     txEllipse (x- 4, y-16, x-10, y-22);
     txEllipse (x+ 5, y-16, x+11, y-22);
     txSetFillColor (RGB (205, 92, 92));
     POINT N[]=   {{x,    y- 9}, {x- 4, y-15}, {x+ 4, y-15}};
     txPolygon (N, 3);
     }

void DrawWell()
    {
    txSetColor     (RGB (  0,   0, 0));
    txSetFillColor (RGB (255, 200, 0));
    POINT kr[]={{715, 115}, {920, 115}, {818,51}};
    txPolygon (kr, 3);
    txRectangle (750, 320, 890, 220);
    txRectangle (750, 220, 755, 115);
    txRectangle (885, 220, 890, 115);
    txRectangle (755,145, 885, 142);
     txSetFillColor (RGB (150, 125, 135));
    txRectangle (780, 152, 860, 135);
     txSetFillColor (RGB (0, 0 ,0));
    txRectangle (838, 220, 840, 135);
    }

