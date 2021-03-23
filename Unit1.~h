//Задание стражей включения, обеспечивающих дублирования заголовочного файла
#ifndef MainInterpolH
#define MainInterpolH
//Подключение заголовочных файлов
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Graphics.hpp>
#include <Series.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//Объявление класса формы
class TForm1 : public TForm
{
__published: //Объявление визуальных компонентов на форме
 TPanel *Panel1;
 TPanel *Panel2;
 TChart *Chart1;
 TGroupBox *GroupBox1;
 TStringGrid *StringGrid1;
 TLabel *Label1;
 TBitBtn *BitBtn1;
 TBitBtn *BitBtn2;
 TEdit *Edit1;
 TUpDown *UpDown1;
        TLineSeries *Series1;
 TLineSeries *Series3;
 TLineSeries *Series4;
        TPointSeries *Series2;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *Edit2;
        TEdit *Edit3;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TSaveDialog *SaveDialog1;
        TMemo *Memo1;
        TStringGrid *StringGrid2;
        TSavePictureDialog *SavePictureDialog1;
        TButton *Button1;
//Объявление обработчиков событий
 void __fastcall FormCreate(TObject *Sender);
 void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
 void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private: // User declarations
public: // User declarations
 double k, n, d, r;
 __fastcall TForm1(TComponent* Owner);
};
extern PACKAGE TForm1 *Form1;
#endif
