#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
 : TForm(Owner)
{
}
//Определение обработчика отображения формы
void __fastcall TForm2::FormShow(TObject *Sender)
{//Вывод результатов расчета
 Edit1->Text = FloatToStrF(Form1->n, ffGeneral, 2, 2);
 Edit2->Text = FloatToStrF(Form1->k, ffGeneral, 2, 2);
 Edit3->Text = FloatToStrF(Form1->d, ffGeneral, 2, 2);
 Edit4->Text = FloatToStrF(Form1->r, ffGeneral, 2, 2);
}
void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
 Form2->Close();
}
//---------------------------------------------------------------------------

