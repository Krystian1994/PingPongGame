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
        else if(Ball->Top > Background->Top + 500)
        {
                y = -y;
        }
        //warunek odbicia lewej paletki
        if(Ball->Left <= PaddleLeft->Left + 24 && (
                Ball->Top + 16 >= PaddleLeft->Top &&
                Ball->Top + 43 < PaddleLeft->Top ||
                Ball->Top + 57 > PaddleLeft->Top &&
                Ball->Top + 16 <= PaddleLeft->Top + 100))
        {
                BallTimer->Interval-=2;
                x = -x;
        }
        //warunek scinania pi³ki lew¹ paletk¹
        if(Ball->Left <= PaddleLeft->Left + 24 &&
                Ball->Top + 43 >= PaddleLeft->Top &&
                Ball->Top + 57 <= PaddleLeft->Top)
        {
                BallTimer->Interval+=7;
                x = -x;
        }
        //warunek odbicia prawej paletki
        if(Ball->Left + Ball->Width + 4 >= PaddleRight->Left && (
                Ball->Top + 16 >= PaddleRight->Top &&
                Ball->Top + 43 < PaddleRight->Top ||
                Ball->Top + 57 > PaddleRight->Top &&
                Ball->Top + 16 <= PaddleRight->Top + 100))
        {
                BallTimer->Interval-=2;
                x = -x;
        }
        //warunek scinania pi³ki praw¹ paletk¹
        if(Ball->Left + Ball->Width + 4 >= PaddleRight->Left &&
                Ball->Top + 43 >= PaddleRight->Top &&
                Ball->Top + 57 <= PaddleRight->Top)
        {
                BallTimer->Interval+=7;
                x = -x;
        }
        // skucha z lewej
        if(Ball->Left < PaddleLeft->Left)
        {
                Ball -> Enabled = false;
                Ball -> Visible = false;
        }
        // skucha z prawej
       if(Ball->Left + 32 >= PaddleRight->Left + 20)
       {
                Ball -> Enabled = false;
                Ball -> Visible = false;
       }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PaddleLeftToUpTimer(TObject *Sender)
{
        if(PaddleLeft->Top > Background->Top + 6)PaddleLeft->Top -= 10;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PaddleLeftToDownTimer(TObject *Sender)
{
        if((PaddleLeft->Top + PaddleLeft->Height) < (Background->Top + Background->Height - 6))PaddleLeft->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
       if(Key == 'A') PaddleLeftToUp -> Enabled = true;
       if(Key == 'Z') PaddleLeftToDown -> Enabled = true;
       if(Key == VK_UP) PaddleRightToUp -> Enabled = true;
       if(Key == VK_DOWN) PaddleRightToDown -> Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      if(Key == 'A') PaddleLeftToUp -> Enabled = false;
      if(Key == 'Z') PaddleLeftToDown -> Enabled = false;
      if(Key == VK_UP) PaddleRightToUp -> Enabled = false;
      if(Key == VK_DOWN) PaddleRightToDown -> Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PaddleRightToDownTimer(TObject *Sender)
{
        if((PaddleRight->Top + PaddleRight->Height) < (Background->Top + Background->Height - 6))PaddleRight->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PaddleRightToUpTimer(TObject *Sender)
{
        if(PaddleRight->Top > Background->Top + 6)PaddleRight->Top -= 10;
}
//---------------------------------------------------------------------------


