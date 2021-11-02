//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x = -8;
int y = -8;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BallTimerTimer(TObject *Sender)
{
        Ball->Top += y;
        Ball->Left += x;
        // odbicie od góry
        if(Ball->Top < Background->Top + 4)
        {
                y = -y;
        }
        // odbicie od do³u
        else if(Ball->Top > Background->Top + 454)
        {
                y = -y;
        }
        //warunek odbicia lewej paletki
        if(Ball->Left <= PaddleLeft->Left + 24 &&
                Ball->Top + 16 >= PaddleLeft->Top &&
                Ball->Top + 16 <= PaddleLeft->Top + 100)
        {
                x = -x;
        }
        //warunek odbicia prawej paletki
        if(Ball->Left >= PaddleRight->Left - 4 &&
                Ball->Top + 16 >= PaddleRight->Top &&
                Ball->Top + 16 <= PaddleRight->Top + 100)
        {
                x = -x;
        }
        // skucha z lewej
        if(Ball->Left < PaddleLeft->Left + 6)
        {
                Ball -> Enabled = false;
                Ball -> Visible = false;
        }
        // skucha z prawej
       if(Ball->Left + 32 >= PaddleRight->Left +  14)
       {
                Ball -> Enabled = false;
                Ball -> Visible = false;
       }
}
//---------------------------------------------------------------------------
