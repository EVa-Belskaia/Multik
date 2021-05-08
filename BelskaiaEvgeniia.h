// {=====================================================================================
//! @brief     It's library of Belsaiia Evgeniia
//!
//!
//!
//! @author     Belskaia Evgegiia Valeriievna,
//!                 teacher of informatics,
//! @date                may 2021
//!
//! <img src="img/Planet.jpg">
//! <img src="img/Les.jpg">
//!
//! @mainpage
//!                Основные функции:
//!
//!             Space
//!           - @ref DrawStarNew  ()
//!           - @ref DrawStarBang ()
//!           - @ref DrawPlanet   ()<br>
//!              Оn the planet
//!           - @ref DrawGrass  ()
//!           - @ref DrawTree  ()
//!           - @ref DrawCat ()
//!           - @ref Les   ()
//!
//!
//} =====================================================================================

#include "TXLib.h"


void DrawStarNew  (int x, int y, int sizeR, COLORREF colorStar);
void DrawStarBang (int x, int y, int sizeX, int sizeY, COLORREF colorST);
void DrawPlanet   (int x, int y, int placeR, int PosPlanetX, int PosPlanetY, int R, COLORREF colorPL );
void DrawGrass    (int x, int y, int SizeX, int SizeY, int wind);
void DrawTree     (int x, int y, int sizeX, int sizeY, int wind);
void DrawCat      (int x, int y, int UpHvost, int GoNose, int sizeLeftEye, int sizeRightEye, int UhoLDown, int UhoRDown,int ZrachkiL, int ZrachkiR,
                   int LlapkaUp, int RlapkaUp, int Yazik, COLORREF colorCat, COLORREF colorNose, COLORREF colorLapki, COLORREF colorEyes);
void Les            (int wind);
void ThisStart      ( );
void PlanetRotates  ( );
void BackGround     ( );
void RostLes        ( );
void GoCat          ( );
void CatWashing     ( );


//===============================================================================================================================================

//{--------------------------------------------------------------------------------------------------------
//! Новая звезда (по сути круг с определенной заливкой)
//!
//! @param x         - x координата центра круга (планеты)
//! @param y         - y координата центра круга (планеты)
//! @param colorstar - цвет планеты. Задается стандартными для <a href="http://storage.ded32.net.ru/Lib/TX/TXUpdate/Doc/HTML.ru/a00082.htm">TXlib </a> способами
//!
//! @par    Пример:
//!
//! @code
//!        DrawStarNew   (600, 400, 8, RGB (  0, 255, 255));
//!
//! @endcode
//!}-------------------------------------------------------------------------------------------------------
void DrawStarNew (int x, int y, int sizeR, COLORREF colorStar)
    {
    txSetFillColor (colorStar);
    txCircle       (x, y, sizeR);

    }
//{--------------------------------------------------------------------------------------------------------
//! Взрывчик (звезда)
//!
//! @param x         - x координата центра звезды
//! @param y         - y координата центра звезды
//! @param sizeX     - задает размеры звезды по ширине. Может принимать отрицательные и положительные значения.
//! @param sizeY     - задает размеры звезды по высоте. Может принимать отрицательные и положительные значения.
//! @param colorST   - цвет звезды. Задается стандартными для <a href="http://storage.ded32.net.ru/Lib/TX/TXUpdate/Doc/HTML.ru/a00082.htm">TXlib </a> способами
//! @par    Пример:
//!
//! @code
//!        DrawStarBang (555, 502, 150, 150, TX_YELLOW);
//!
//! @endcode
//}----------------------------------------------------------------------------------------------------------

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
//{--------------------------------------------------------------------------------------------------------
//! Рисует нечто подобное строению Солнечной системы. Для каждой планеты рисуется орбита черного цвета, сама планета выбранного радиуса и цвета. (Для каждой планеты рисуется своё солнце в центре)
//!
//! @param x,y          - x и y координаты общего центра
//! @param placeR       - задает радиус орбиты для планеты
//! @param PosPlanetX   - X центра планеты
//! @param PosPlanetY   - Y центра планеты
//! @param R            - радиус планеты
//! @param colorPL      - цвет планеты
//!
//! @par    Пример:
//!
//! @code
//!        DrawPlanet (600, 400,  80,  680, 480, 12, RGB (165, 180, 180));
//!
//! @endcode
//}----------------------------------------------------------------------------------------------------------
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
//{--------------------------------------------------------------------------------------------------------
//! Рисует  траву, состоящую из трех травинок. Самая главная точка - верхушка средней травинки.
//!
//! <img src="img/Grass.png">
//!
//! @param x,y          - x и y логическая точка отсчета
//! @param SizeX        - изменяет ширину куста (от -5...)
//! @param SizeY        - изменяет высоту куста (от -10 до любого параметра... осторожнее с желаниями)
//! @param wind         - смещение верхушек травинок
//!
//! @par    Пример:
//!
//! @code
//!        DrawGrass (200, 400, 1, 1, 0);
//!
//! @endcode
//}----------------------------------------------------------------------------------------------------------
void DrawGrass (int x, int y, int SizeX, int SizeY, int wind)
     {
         txSetFillColor (RGB (0, 77, 19));
         POINT Tr[]=   {{x-(35+SizeX), y+85}, {x-(44+wind), y+38+SizeY},
                        {x-(20+SizeX), y+75}, {x+wind, y+SizeY},
                        {x+10+SizeX, y+75}, {x+40+wind, y+30+SizeY},
                        {x+20+SizeX, y+85}};
         txPolygon (Tr, 7);
     }
//{--------------------------------------------------------------------------------------------------------
//! Елочка. Рисует  елочку из трех ярусов с серединками.
//!
//! <img src="img/Tree.png">
//!
//! @param x,y          - x и y логическая точка отсчета (середина нижней границы нижнего яруса елочки)
//! @param SizeX        - изменяет ширину елочки (от -10...)
//! @param SizeY        - изменяет высоту елочки (от -10 до любого параметра... осторожнее с желаниями)
//! @param wind         - смещение верхушек ярусов елочки
//!
//! @par    Пример:
//!
//! @code
//!        DrawTree(300, 400, 1, 1, 0);
//!
//! @endcode
//}----------------------------------------------------------------------------------------------------------
void DrawTree(int x, int y, int sizeX, int sizeY, int wind)
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
//{----------------------------------------------------------------------------------------------------------
//! Котик.
//! Треугольный котик. Поскольку кот живет на другой планете, усов у него пока нет. <br>Зато уши, лапы и хвост (нос и глаза + зрачки) присутствуют и могут выражать настроение котика
//!
//! <img src="img/Cat.png">
//!
//! @param x,y
//! @param UpHvost
//! @param GoNose
//! @param sizeLeftEye
//! @param sizeRightEye
//! @param UhoLDown
//! @param UhoRDown
//! @param ZrachkiL
//! @param ZrachkiR
//! @param LlapkaUp
//! @param RlapkaUp
//! @param Yazik
//! @param colorCat
//! @param colorNose
//! @param colorLapki
//! @param colorEyes
//!
//! @par    Пример:
//!
//! @code
//!        DrawCat (600, 400, 7, 1, 2, 2,  0, 0, 0, 0, 0, 0, 0, TX_GREY, TX_RED, TX_BLACK, TX_GREEN);
//!
//! @endcode
//}----------------------------------------------------------------------------------------------------------
void DrawCat (int x, int y, int UpHvost, int GoNose, int sizeLeftEye, int sizeRightEye, int UhoLDown, int UhoRDown, int ZrachkiL, int ZrachkiR,
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
     txEllipse        (x - 3-Yazik, y - 3+Yazik, x + 5-Yazik, y - 7);

     txSetFillColor (colorNose);
     POINT N[]=      {{x    , y -  9+GoNose},  {x -  4-GoNose, y - 15-GoNose}, {x +  4+GoNose, y - 15-GoNose}};
     txPolygon (N, 3);

     txSetFillColor (colorLapki);
     txEllipse        (x - 16, y + 50-LlapkaUp, x - 1, y + 38-LlapkaUp);
     txEllipse        (x + 16, y + 50-RlapkaUp, x + 1, y + 38-RlapkaUp);
     }

//{----------------------------------------------------------------------------------------------------------
//! Это сцена. Рисует новую звезду, меняющую цвет и увеличивающуюся в размерах. Затем рисуются друг за другом три взрывчика разных цветов и размеров с небольшой задержкой между ними.
//! И спользует процедуры:  @ref DrawStarNew  и @ref DrawStarBang
//!
//! @par    Пример:
//!
//!
//}-----------------------------------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------------------------------------
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
void BackGround ()
    {
    txBegin ( );

    int i=1;
    while (i<=125)
        {
        txSetFillColor (RGB (128, 255, 255));
        txRectangle (1, 1, 1199, 350);
        txClear( );
        txSetFillColor (RGB (0, 190 ,50));
        txRectangle (1, 350, 1199, 799);

        Les ((i%3)*8);

        DrawCat (1200 - i*5, 400, 7*(i%2), 0, 2, 2, -3+3*(i%2), 3-3*(i%2), (i%3), (i%3),
                 (i%2)*7, 7-(i%2)*7, 0, TX_GREY, TX_RED, TX_BLACK, TX_GREEN);

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
        txSetFillColor (RGB (128, 255, 255));
        txRectangle (1, 1, 1199, 350);
        txClear( );
        txSetFillColor (RGB (0, 190 ,50));
        txRectangle (1, 350, 1199, 799);

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
void CatWashing ( )
    {
    txBegin ( );
    int t=1;
    while (t<20)
        {
        txSetFillColor (RGB (128, 255, 255));
        txRectangle (1, 1, 1199, 350);
        txClear( );
        txSetFillColor (RGB (0, 190 ,50));
        txRectangle (1, 350, 1199, 799);

        Les ((t%3)*8);

        DrawCat (600, 400, 7*(t%2), (t%4), 1, 1, -3+3*(t%2), 3-3*(t%2), 0, 0,
                  0,    0, 0, TX_GREY, TX_RED, TX_BLACK, TX_GREEN);

        txSleep (100);

        t++;
        }

    DrawCat     (600, 400, 7,       1,     2, 2,  3,         3,         1, 1,
                  50,  50, 0, TX_GREY, TX_RED, TX_BLACK, TX_GREEN);
    txSleep (200);
    t=21;
    while (t<40)
        {
        txSetFillColor (RGB (128, 255, 255));
        txRectangle (1, 1, 1199, 350);
        txClear( );
        txSetFillColor (RGB (0, 190 ,50));
        txRectangle (1, 350, 1199, 799);

        Les ((t%3)*8);
        DrawCat  (600, 400, 7,       1,     2, 2,  3,         3,         1, 1,
                    0, 45*(t%2), 2*(t%2), TX_GREY, TX_RED, TX_BLACK, TX_GREEN);
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
    while (i<=100)
        {
        BackGround ( );
        DrawCat (1200 - i*5, 400, 7*(i%2), 0, 2, 2, -3+3*(i%2), 3-3*(i%2), (i%3), (i%3),
                 (i%2)*7, 7-(i%2)*7, 0, TX_GREY, TX_RED, TX_BLACK, TX_GREEN);

        txSleep (100);
         i++;
        }
    txEnd ();
    }


