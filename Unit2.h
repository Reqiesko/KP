#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published: // IDE-managed Components
 TPanel *Panel1;
 TGroupBox *GroupBox2;
 TLabel *Label3;
 TLabel *Label4;
 TEdit *Edit2;
 TEdit *Edit3;
 TLabel *Label1;
 TEdit *Edit1;
 TLabel *Label2;
 TEdit *Edit4;
 TBitBtn *BitBtn1;
        TLabel *Label5;
        TLabel *Label6;
 void __fastcall FormShow(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
private: // User declarations
public: // User declarations
 __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
