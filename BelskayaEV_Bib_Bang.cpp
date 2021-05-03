#include <iostream>
#include "TXLib.h"

using namespace std;

void DrawStarNew (int x, int y, int sizeR, COLORREF colorStar);
void DrawStarBang (int x, int y, double par, int sizeX, int sizeY, COLORREF colorST);

void ThisStart ( );

int main()
    {

    //txClear ();

    ThisStart ( );

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

    for (i=25; i<300; i+=10)
        {
         DrawStarBang (555, 502, 0,   1 * i, 1 * i, TX_YELLOW);
         DrawStarBang (590, 395, 0.4, 2 * i, 2 * i, TX_RED);
         DrawStarBang (610, 370, 0.8, 2 * i, 2 * i, TX_ORANGE);

         txSleep (10);
         }
    }
//--------------------------------------------------------------------------------------------------------
void DrawStarNew (int x, int y, int sizeR, COLORREF colorStar)
    {
    txSetFillColor (colorStar);
    txCircle       (x, y, sizeR);

    }
//no whitespace, because of the long string length---------------------------------------------------------
void DrawStarBang (int x, int y, double par, int sizeX, int sizeY, COLORREF colorST)
    {
    txSetColor     (TX_RED, 3);
    txSetFillColor (colorST);
    POINT Star[]= { {x-sizeX%2,                 y+sizeY},                 {x+ 5-( 5 * par) - sizeX%2, y- 57+( 57*par) + sizeY}, {x- 45-( 45*par) - sizeX, y- 27+( 27*par)+sizeY}, {x+ 5-( 5*par)-sizeX, y- 82+(82*par)},          {x- 75-( 75*par) - sizeX, y-142-(142*par)-sizeY},   {x+ 25-( 25*par)-sizeX%2, y-132-(132*par)-sizeY},
                    {x+ 35-( 35 * par)-sizeX%2, y-208-(208 * par)-sizeY}, {x+75+(75 * par) + sizeX%2, y-142-(142*par) - sizeY}, {x+135+(135*par) + sizeX, y-177-(177*par)-sizeY}, {x+85+(85*par)+sizeX, y-122-(122*par)-sizeY%2}, {x+175+(175*par) + sizeX, y-112-(112*par)-sizeY%2}, {x+115+(115*par)+sizeX,   y- 67-( 67*par)-sizeY%2},
                    {x+155+(155 * par)+sizeX,   y+ 18+( 18 * par)+sizeY}, {x+70+(70 * par),           y- 42+( 42*par) + sizeY}};
    txPolygon (Star, 14);


    }
