#include "TXLib.h"


using namespace std;

void DrawStarNew  (int x, int y, int sizeR, COLORREF colorStar);
void DrawStarBang (int x, int y, int sizeX,  int sizeY, COLORREF colorST);
void DrawPlanet   (int x, int y, int placeR, int PosPlanetX, int PosPlanetY, int R, COLORREF colorPL );
void DrawGrass    (int x, int y, int SizeX,  int SizeY, int wind);
void DrawTree     (int x, int y, int sizeX,  int sizeY, int wind);
void DrawCat      (int x, int y, int UpHvost,  int GoNose, int sizeLeftEye, int sizeRightEye, int UhoLDown, int UhoRDown,int ZrachkiL, int ZrachkiR,
                   int LlapkaUp, int RlapkaUp, int Yazik, COLORREF colorCat, COLORREF colorNose, COLORREF colorLapki, COLORREF colorEyes);
void Bang         (int x, int y, int ShadowX, int ShadowY, const char* text, int sizeChar, int NewSizeCar, COLORREF colorText, COLORREF colorShadow);
void CatSays      (int x, int y, const char* text, int sizeChar, COLORREF colorText);
void Les          (int wind);
void TitrNachalo    ( );
void ThisStart      ( );
void PlanetRotates  ( );
void BackGround     ( );
void CatHello       ( );
void RostLes        ( );
void GoCat          ( );
void CatWashing     ( );
void TitrNotEnd     ( );
void TitrAboutMe    ( );

//-------------------------------------------------------------------------
int main( )
    {
    txCreateWindow (1200, 800);
    txSetFillColor (RGB (85, 70, 145));

    TitrNachalo    ( );
    ThisStart      ( );
    PlanetRotates  ( );

    BackGround     ( );
    txSleep        (200);

    RostLes        ( );
    CatHello       ( );
    CatWashing     ( );
    GoCat          ( );
    TitrNotEnd     ( );
    TitrAboutMe    ( );

    return 0;
    }
//--------------------------------------------------------------------------------------------------------
void TitrNachalo ( )
    {
    txBegin ( );
    for (int t = 0; t<=20; t++)
        {
        txClear ( );
        Bang (1+t*10, 1+t*10, 1+t*10, 1+t*10, "The Big Bang teory", 30+t*4, 0, TX_YELLOW, TX_BROWN);
        txSleep (50);
        }
    txEnd ( );
    txSleep (1000);
    }
//--------------------------------------------------------------------------------------------------------
void ThisStart ( )
   {
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
         Bang (550-i, 400-(i/4), 546-i, 404-(i/4), "Bang!!!", 30 + i/2, 0, TX_YELLOW, TX_BROWN);
         if (i>100)
             {
             DrawStarBang (590, 395,  50 + i*2,  30 + (i/2)*2, TX_RED);
             Bang (550-i/2, 400+(i/4), 546-i/2, 404+(i/4), "Bang!!!", 30 + i, 0, TX_YELLOW, TX_BROWN);
             if (i>200)
                 {
                 DrawStarBang (610, 370,  -10 + i,     -10 + i, TX_ORANGE);
                 Bang (550-i/4, 400-(i/2), 546-i/4, 404-(i/2), "Bang!!!", 30 + (i/4)*2, 0, TX_YELLOW, TX_BROWN);
                 }
              }

         txSleep (50);
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
//--------------------------------------------------------------------------------------------------------
void PlanetRotates ( )
    {

    txBegin ( );
    txSetFillColor (RGB (25,  5, 100));
    int i=1;
    while (i<=180)
        {
        txClear ( );
        DrawPlanet (600, 400,  80,  ROUND ( 80*cos(  5+(i*0.02))+600), ROUND (400+ 80*sin(  5+(i*0.02))), 12, RGB (165, 180, 180));
        DrawPlanet (600, 400, 120,  ROUND (120*cos     (i*0.03) +600), ROUND (400-120*sin     (i*0.03)) , 20, RGB (256, 128,   0));
        DrawPlanet (600, 400, 160,  ROUND (160*cos(100-(i*0.04))+600), ROUND (400+160*sin(100-(i*0.04))), 15, RGB ( 90, 170, 255));
        DrawPlanet (600, 400, 200,  ROUND (200*cos     (i*0.06) +600), ROUND (400+200*sin     (i*0.06)) ,  9, RGB (255,   0,   0));
        DrawPlanet (600, 400, 240,  ROUND (240*cos(180+(i*0.06))+600), ROUND (400-240*sin(180+(i*0.06))), 28, RGB ( 60, 195, 135));
        DrawPlanet (600, 400, 280,  ROUND (280*cos     (i*0.07) +600), ROUND (400+280*sin     (i*0.07)) , 12, RGB ( 70, 205, 200));
        DrawPlanet (600, 400, 320,  ROUND (320*cos(270-(i*0.08))+600), ROUND (400+320*sin(270-(i*0.08))), 20, RGB ( 40, 125, 150));
        DrawPlanet (600, 400, 360,  ROUND (360*cos     (i*0.08) +600), ROUND (400+360*sin     (i*0.08)) , 20, RGB ( 20,  85, 170));

        txSleep (50);
        txSetFillColor (RGB (25,  5, 100));
        i++;
        }

     txBegin ( );
     for (int t=1; t<=800; t+=5)
        {
        txSetFillColor (RGB (25,  5, 100));
        DrawStarNew (610, 240, 15 + t, RGB ( 90, 170, 255));
        txSleep (20);
        }

     txEnd ();
    }
//--------------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------------
void BackGround ( )
    {
    txSetFillColor (RGB (128, 255, 255));
    txRectangle (1, 1, 1199, 350);
    txClear( );
    txSetFillColor (RGB (0, 190 ,50));
    txRectangle (1, 350, 1199, 799);
    }
//--------------------------------------------------------------------------------------------------------
void CatHello ( )
    {
    txBegin ( );

    int i=1;
    while (i<=120)
        {
        BackGround ();
        if (i<50)
            {
            CatSays (1120 - i*5, 400, "Hello! I'm glad to see you!", 14, TX_YELLOW);
            }
        DrawCat     (1200 - i*5, 450, 7*(i%2), 0, 2, 2, -3+3*(i%2), 3-3*(i%2), (i%3), (i%3),
                    (i%2)*7, 7-(i%2)*7, 0, TX_GREY, TX_RED, TX_BLACK, TX_GREEN);
        Les ((i%3)*8);

        txSleep (100);

        i++;
        }
    txEnd ( );
    }
//--------------------------------------------------------------------------------------------------------
void Les (int wind)
    {

    DrawGrass ( 60, 480, - 5, -5, wind);
    DrawGrass ( 90, 320, -30, 15, wind);
    DrawGrass (410, 580,  10,  5, wind);
    DrawGrass (600, 420,   0, 15, wind);

    DrawTree  (350, 550,   0,  0, wind);
    DrawTree  (170, 400,  -5, -5, wind);
    DrawTree  (200, 700,   0,  2, wind);
    }
//--------------------------------------------------------------------------------------------------------
void RostLes ( )
    {
    txBegin ( );

    int t=0;
    while (t<10)
        {
        BackGround ( );

        DrawGrass ( 60, 480, -25 + t*2,   75 - t*8,  15 - (t%3*15));
        DrawGrass ( 90, 320, -20 + t-t*2, 75 - t*6, -10 + (t%3*10));
        DrawGrass (410, 580, -10 + t*2,   75 - t*7,  20 - (t%3*20));
        DrawGrass (600, 420, -20 + t*2,   75 - t*6, -10 + (t%3*10));

        DrawTree  (350, 550, -10+t,   -10+t         , 0);
        DrawTree  (170, 400, -10+t/2, -10+t/2       , 0);
        DrawTree  (200, 700, -10+t,   -10 + t+(t/4) , 0);

        txSleep (100);

        t++;
        }
    txEnd ();
      }
//--------------------------------------------------------------------------------------------------------
void DrawGrass (int x, int y, int SizeX, int SizeY, int wind)
     {
         txSetFillColor (RGB (0, 77, 19));
         POINT Tr[]=   {{x-(35+SizeX), y+85}, {x-(44+wind), y+38+SizeY},
                        {x-(20+SizeX), y+75}, {x+wind, y+SizeY},
                        {x+10+SizeX, y+75}, {x+40+wind, y+30+SizeY},
                        {x+20+SizeX, y+85}};
         txPolygon (Tr, 7);
     }
//--------------------------------------------------------------------------------------------------------
void DrawTree  (int x, int y, int sizeX, int sizeY, int wind)
        {
        txSetFillColor (RGB (108, 0, 0));
        txRectangle (x- 27-sizeX*2, y+32+(32*sizeY/10), x+27+sizeX*2, y);

        txSetColor     (TX_GREY);
        txSetFillColor (TX_GREEN);
        POINT e1[]= {{(x - 175-(175*sizeX/10))+wind, y                     }, {(x + 175+(175*sizeX/10))+wind, y                     },
                     { x +  63+( 63*sizeX/10),       y -  88-( 88*sizeY/10)}, { x -  63-( 63*sizeX/10),       y -  88-( 88*sizeY/10)}};

        POINT e2[]= {{(x - 150-(150*sizeX/10))+wind, y -  88-( 88*sizeY/10)}, {(x + 150+(150*sizeX/10))+wind, y -  88-( 88*sizeY/10)},
                     { x +  27+( 27*sizeX/10),       y - 184-(184*sizeY/10)}, { x -  27-( 27*sizeX/10),       y - 184-(184*sizeY/10)}};

        POINT e3[]= {{(x -  90-( 90*sizeX/10)), y - 184-(184*sizeY/10)}, {(x +  90+( 90*sizeX/10)), y - 184-(184*sizeY/10)},
                     { x + wind,                     y - 264-(264*sizeY/10)}};
        txPolygon (e1, 4);
        txPolygon (e2, 4);
        txPolygon (e3, 3);

        txSetFillColor (RGB (120, 240, 0));
        POINT ev1[]={{x -  90-( 90*sizeX/10), y -  24-( 24*sizeY/10)}, {x +  90+( 90*sizeX/10), y -  24-( 24*sizeY/10)},
                     {x + wind,                      y -  72-(72*sizeY/10)}};
        POINT ev2[]={{x -  72-( 72*sizeX/10), y - 104-(104*sizeY/10)}, {x +  72+( 72*sizeX/10), y - 104-(104*sizeY/10)},
                     {x + wind,                      y - 160-(160*sizeY/10)}};
        POINT ev3[]={{x -  36-( 36*sizeX/10), y - 200-(200*sizeY/10)}, {x +  36+( 36*sizeX/10), y - 200-(200*sizeY/10)},
                     {x + wind,                      y - 232-(232*sizeY/10)}};
        txPolygon (ev1, 3);
        txPolygon (ev2, 3);
        txPolygon (ev3, 3);
        }
//--------------------------------------------------------------------------------------------------------
void CatWashing ( )
    {
    txBegin ( );
    int t=1;
    while (t<20)
        {
        BackGround ( );

        if (t<19)
        {
        CatSays (550, 400, "Wow! What this?", 14, TX_YELLOW);
        }
        DrawCat (600, 450, 7*(t%2), (t%4), 1, 1, -3+3*(t%2), 3-3*(t%2), 0, 0,
                  0,    0, 0, TX_GREY, TX_RED, TX_BLACK, TX_GREEN);
        Les ((t%3)*8);

        txSleep (100);

        t++;
        }
    CatSays     (550, 400, "Frrr! My paw", 14, TX_YELLOW);
    DrawCat     (600, 450, 7,       1,     2, 2,  3,         3,         1, 1,
                  50,  50, 0, TX_GREY, TX_RED, TX_BLACK, TX_GREEN);
    txSleep (700);
    t=21;
    while (t<40)
        {
        BackGround ( );

        CatSays  (500, 350, "Oh! Mr-mr-mr...", 14, TX_YELLOW);
        DrawCat  (550, 400, 7,       1,     2, 2,  3,         3,         1, 1,
                    0, 45*(t%2), 2*(t%2), TX_GREY, TX_RED, TX_BLACK, TX_GREEN);
        Les ((t%3)*8);
        txSleep (500);
        t++;
        }
    txEnd ( );
    }

//--------------------------------------------------------------------------------------------------------
void GoCat( )
    {
    txBegin ();

    int i=1;
    while (i<=150)
        {
        BackGround ( );

        DrawCat (550 + i*5, 400, 7*(i%2), 1, 2, 2, -3+3*(i%2), 3-3*(i%2), (i%3), (i%3),
                 (i%2)*7, 7-(i%2)*7, 0, TX_GREY, TX_RED, TX_BLACK, TX_GREEN);
        Les ((i%3)*5);
        txSleep (100);
         i++;
        }
    txEnd ();
    }

//--------------------------------------------------------------------------------------------------------
void CatSays   (int x, int y, const char* text, int sizeChar, COLORREF colorText)
    {
    txSetColor (colorText);
    txSelectFont ("Arial Black", sizeChar);
    txTextOut (x, y, text);
    }
//--------------------------------------------------------------------------------------------------------
void DrawCat   (int x, int y, int UpHvost, int GoNose, int sizeLeftEye, int sizeRightEye, int UhoLDown, int UhoRDown, int ZrachkiL, int ZrachkiR,
              int LlapkaUp, int RlapkaUp, int Yazik, COLORREF colorCat, COLORREF colorNose, COLORREF colorLapki, COLORREF colorEyes)
    {
     txSetColor     (colorCat);
     txSetFillColor (colorCat);
     POINT hvost[] = {{x - 45, y + 50-UpHvost}, {x - 22, y + 50}, {x - 35, y + 40-UpHvost}};
     POINT body [] = {{x - 22, y + 50}, {x -  2, y     }, {x +  2, y},    {x + 18, y + 50}};
     POINT Luho [] = {{x - 11, y - 26}, {x -  4+UhoLDown, y - 26}, {x - 10+UhoLDown, y - 40}};
     POINT Ruho [] = {{x +  3-UhoLDown, y - 26}, {x + 10, y - 26}, {x +  9+UhoRDown, y - 40}};
     txPolygon (hvost, 3);
     txPolygon (body , 4);
     txPolygon (Luho , 3);
     txPolygon (Ruho , 3);
     txEllipse        (x + 15, y,        x - 15, y - 30);

     txSetFillColor (colorEyes);
     txEllipse        (x - 4+sizeLeftEye , y - 16+sizeLeftEye ,    x - 10-sizeLeftEye , y - 22-sizeLeftEye);
     txEllipse        (x + 5-sizeRightEye, y - 16+sizeRightEye,    x + 11+sizeRightEye, y - 22-sizeRightEye);

     txSetFillColor (TX_BLACK);
     txCircle         (x - 8+ZrachkiL, y - 19, 2);
     txCircle         (x + 7+ZrachkiR, y - 19, 2);

     txSetFillColor (TX_RED);
     txEllipse        (x - 3-Yazik, y - 3+Yazik, x + 3-Yazik, y - 7);

     txSetFillColor (colorNose);
     POINT N[]=      {{x    , y -  9+GoNose},  {x -  4-GoNose, y - 15-GoNose}, {x +  4+GoNose, y - 15-GoNose}};
     txPolygon (N, 3);

     txSetFillColor (colorLapki);
     txEllipse        (x - 16, y + 50-LlapkaUp, x - 1, y + 38-LlapkaUp);
     txEllipse        (x + 16, y + 50-RlapkaUp, x + 1, y + 38-RlapkaUp);
     }
//--------------------------------------------------------------------------------------------------------
void Bang (int x, int y, int ShadowX, int ShadowY, const char* text, int sizeChar, int NewSizeCar, COLORREF colorText, COLORREF colorShadow)
    {
    txSetColor (colorShadow);
    txSelectFont ("Arial Black", sizeChar+NewSizeCar);
    txTextOut (ShadowX, ShadowY, text);
    txSetColor (colorText);
    txSelectFont ("Arial Black", sizeChar+NewSizeCar);
    txTextOut (x, y, text);
    }

//--------------------------------------------------------------------------------------------------------
void TitrNotEnd ( )
    {
    txBegin ( );
    for (int t = 0; t<=20; t++)
        {
        BackGround ( );
        Les ((t%3)*6);

        Bang (900-t*25, 10+t*10, 896-t*25, 14+t*10, "To be continued...", 30+t*4, 0, TX_YELLOW, TX_BROWN);
        txSleep (50);
        }
    txEnd ( );
    txSleep (1000);
    }
void TitrAboutMe ( )
    {

    txSetColor (TX_BLUE);
    txSelectFont ("Arial Black", 22);
    txTextOut (800, 600, "Film by Belskaia Evgeniia");
    txSleep   (300);
    txTextOut (800, 640, "teacher of informatics");
    txSleep   (300);
    txTextOut (800, 680, "scholl ¹2 of Pavlovskiy Posad");
    txSleep   (300);
    txTextOut (550, 750, "may, 2021");
    }

