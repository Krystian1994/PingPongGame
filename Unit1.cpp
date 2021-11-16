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
int pLeft = 0;
int pRight = 0;
int NumberOfReflection = 0;
void whenGetPoint()
{
        Form1->Result->Caption = IntToStr(pLeft) + ":" + IntToStr(pRight);
        Form1->Result->Visible = true;
        Form1->ReflectionNumber->Caption = "Liczba odbic: " + IntToStr(NumberOfReflection);
        Form1->ReflectionNumber->Visible = true;
        Form1->NextRound->Visible = true;
        Form1->NextRound->Enabled = true;
        Form1->NewGame2->Visible = true;
        Form1->NewGame2->Enabled = true;
        Form1->Ball -> Enabled = false;
        Form1->Ball -> Visible = false;
        Form1->BallTimer->Enabled = false;
}
void whenClickButtonNextOrNewGame()
{
        Form1->NewGame->Enabled = false;
        Form1->NewGame->Visible = false;
        Form1->NextRound->Visible = false;
        Form1->NextRound->Enabled = false;
        Form1->NewGame2->Visible = false;
        Form1->NewGame2->Enabled = false;
        Form1->PaddleLeft->Top = 214;
        Form1->PaddleRight->Top = 214;
        Form1->Ball->Left = Form1->Background->Width/2 - Form1->Ball->Width/2;
        Form1->Ball->Top = Form1->Background->Height/2 - Form1->Ball->Height/2;
        Form1->BallTimer->Interval = 20;
        Form1->BallTimer->Enabled = true;
        Form1->Result->Visible = false;
        Form1->ReflectionNumber->Visible = false;
        Form1->Ball->Enabled = true;
        Form1->Ball->Visible = true;
        Form1->LeftPoint->Visible = false;
        Form1->RightPoint->Visible = false;
}
void startNewGame()
{
        Form1->LetsStart->Visible = false;
        pLeft = 0;
        pRight = 0;
        NumberOfReflection = 0;
        whenClickButtonNextOrNewGame();
}
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
        // odbicie od gÛry
        if(Ball->Top < Background->Top + 4)
        {
                y = -y;
        }
        // odbicie od do≥u
        else if(Ball->Top > Background->Top + 500)
        {
                y = -y;
        }
        //warunek odbicia lewej paletki
        if(Ball->Left < PaddleLeft->Left + PaddleLeft->Width && (
                (Ball->Top + Ball->Height/2 >= PaddleLeft->Top &&
                Ball->Top + Ball->Height/2 < PaddleLeft->Top + PaddleLeft->Height/4) ||
                (Ball->Top + Ball->Height/2 > PaddleLeft->Top + 75 &&
                Ball->Top + Ball->Height/2 <= PaddleLeft->Top + PaddleLeft->Height)))
        {
                sndPlaySound("snd/dzwiek.wav", SND_ASYNC);
                if(x<0) x = -x;
                BallTimer->Interval-=2;
                NumberOfReflection++;
        }
        else if(Ball->Left <= PaddleLeft->Left + PaddleLeft->Width &&           //warunek scinania pi≥ki lewπ paletkπ
                Ball->Top + Ball->Height/2 >= PaddleLeft->Top + PaddleLeft->Height/4 &&
                Ball->Top + Ball->Height/2 <= PaddleLeft->Top + 75)
        {
                sndPlaySound("snd/d1.wav", SND_ASYNC);
                if(x<0) x = -x;
                BallTimer->Interval-=7;
                NumberOfReflection++;
        }
        //warunek odbicia prawej paletki
        if(Ball->Left + Ball->Width > PaddleRight->Left && (
                (Ball->Top + Ball->Height/2 >= PaddleRight->Top &&
                Ball->Top + Ball->Height/2 < PaddleRight->Top + PaddleRight->Height/4) ||
                (Ball->Top + Ball->Height/2 > PaddleRight->Top + 75 &&
                Ball->Top + Ball->Height/2 <= PaddleRight->Top + PaddleRight->Height)))
        {
                sndPlaySound("snd/dzwiek.wav", SND_ASYNC);
                if(x>0) x = -x;
                BallTimer->Interval-=2;
                NumberOfReflection++;
        }
        else  if(Ball->Left + Ball->Width >= PaddleRight->Left &&    //warunek scinania pi≥ki prawπ paletkπ
                Ball->Top + Ball->Height/2 >= PaddleRight->Top + PaddleRight->Height/4 &&
                Ball->Top + Ball->Height/2 <= PaddleRight->Top + 75)
        {
                sndPlaySound("snd/d1.wav", SND_ASYNC);
                if(x>0) x = -x;
                BallTimer->Interval-=7;
                NumberOfReflection++;
        }
        // skucha z lewej
        if(Ball->Left <= PaddleLeft->Left - Ball->Width - 15)
        {
                RightPoint->Visible = true;
                pRight++;
                whenGetPoint();

        }
        // skucha z prawej
        if(Ball->Left >= PaddleRight->Left + PaddleRight->Width + 15)
        {
                LeftPoint->Visible = true;
                pLeft++;
                whenGetPoint();
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




void __fastcall TForm1::FormCreate(TObject *Sender)
{
        BallTimer->Enabled = false;
        NewGame->Visible = true;
        NewGame->Enabled = true;
        LetsStart->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NewGameClick(TObject *Sender)
{
        startNewGame();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NextRoundClick(TObject *Sender)
{
        whenClickButtonNextOrNewGame();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NewGame2Click(TObject *Sender)
{
        if(Application->MessageBox("Czy na pewno chcesz zaczπÊ od nowa?","Potwierdü", MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
                startNewGame();
        }
}
//---------------------------------------------------------------------------

