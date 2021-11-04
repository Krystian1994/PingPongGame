//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"
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
        // odbicie od g�ry
        if(Ball->Top < Background->Top + 4)
        {
                y = -y;
        }
        // odbicie od do�u
        else if(Ball->Top > Background->Top + 500)
        {
                y = -y;
        }
        //warunek odbicia lewej paletki
        if(Ball->Left <= PaddleLeft->Left + PaddleLeft->Width && (
                (Ball->Top + Ball->Height/2 >= PaddleLeft->Top &&
                Ball->Top + Ball->Height/2 < PaddleLeft->Top + PaddleLeft->Height/4) ||
                (Ball->Top + Ball->Height/2 > PaddleLeft->Top + 75 &&
                Ball->Top + Ball->Height/2 <= PaddleLeft->Top + PaddleLeft->Height)))
        {
                sndPlaySound("snd/dzwiek.wav", SND_ASYNC);
                x = -x;
                BallTimer->Interval-=2;
        }
        else if(Ball->Left <= PaddleLeft->Left + PaddleLeft->Width &&           //warunek scinania pi�ki lew� paletk�
                Ball->Top + Ball->Height/2 >= PaddleLeft->Top + PaddleLeft->Height/4 &&
                Ball->Top + Ball->Height/2 <= PaddleLeft->Top + 75)
        {
                sndPlaySound("snd/d1.wav", SND_ASYNC);
                x = -x;
                BallTimer->Interval-=7;
        }
        //warunek odbicia prawej paletki
        if(Ball->Left + Ball->Width >= PaddleRight->Left && (
                (Ball->Top + Ball->Height/2 >= PaddleRight->Top &&
                Ball->Top + Ball->Height/2 < PaddleRight->Top + PaddleRight->Height/4) ||
                (Ball->Top + Ball->Height/2 > PaddleRight->Top + 75 &&
                Ball->Top + Ball->Height/2 <= PaddleRight->Top + PaddleRight->Height)))
        {
                x = -x;
                sndPlaySound("snd/dzwiek.wav", SND_ASYNC);
                BallTimer->Interval-=2;
        }else  if(Ball->Left + Ball->Width >= PaddleRight->Left &&    //warunek scinania pi�ki praw� paletk�
                Ball->Top + Ball->Height/2 >= PaddleRight->Top + PaddleRight->Height/4 &&
                Ball->Top + Ball->Height/2 <= PaddleRight->Top + 75)
        {
                sndPlaySound("snd/d1.wav", SND_ASYNC);
                x = -x;
                BallTimer->Interval-=7;
        }
        // skucha z lewej
        if(Ball->Left < PaddleLeft->Left)
        {
                Ball -> Enabled = false;
                Ball -> Visible = false;
        }
        // skucha z prawej
        if(Ball->Left >= PaddleRight->Left + PaddleRight->Width)
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


