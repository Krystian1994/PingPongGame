//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *Background;
        TImage *Ball;
        TTimer *BallTimer;
        TImage *PaddleLeft;
        TImage *PaddleRight;
        TTimer *PaddleLeftToUp;
        TTimer *PaddleLeftToDown;
        TTimer *PaddleRightToUp;
        TTimer *PaddleRightToDown;
        void __fastcall BallTimerTimer(TObject *Sender);
        void __fastcall PaddleLeftToUpTimer(TObject *Sender);
        void __fastcall PaddleLeftToDownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall PaddleRightToDownTimer(TObject *Sender);
        void __fastcall PaddleRightToUpTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
