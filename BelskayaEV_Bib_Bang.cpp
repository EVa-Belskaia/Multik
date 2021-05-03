#include <iostream>
#include "TXLib.h"
using namespace std;
void DrawStarNew (int x, int y, int sizeR, COLORREF colorStar);
void DrawStarBang (int x, int y);

int main()
    {
    txCreateWindow (1200, 800);
    txSetFillColor (RGB (85, 70, 145));
    txClear();

    DrawStarNew  (600, 400, 8, RGB (0, 0, 255));
    DrawStarBang (600, 400);

    return 0;
    }

void DrawStarNew (int x, int y, int sizeR, COLORREF colorStar)
    {
    txSetFillColor (colorStar);
    txCircle       (x, y, sizeR);

    }
void DrawStarBang (int x, int y)
    {
    txSetColor     (TX_RED, 3);
    txSetFillColor (TX_YELLOW);
    POINT Star[]=   {{x- 45, y+102}, {x-40, y+45}, {x-90, y+75}, {x-40, y+20}, {x-120, y-40}, {x-20, y-30},
                     {x+ 10, y-106}, {x+30, y-40}, {x+90, y-75}, {x+40, y-20}, {x+130, y-10}, {x+70, y+35},
                     {x+110, y+120}, {x+25, y+60}};
    txPolygon (Star, 14);


    }
