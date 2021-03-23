#include <vcl.h>
#include <fstream>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//Определение конструктора формы
__fastcall TForm1::TForm1(TComponent* Owner)
 : TForm(Owner), k(0.0), n(0.0), r(0.0), d(0.0)
{
}
//Определение инициализации формы
void __fastcall TForm1::FormCreate(TObject *Sender)
{
//Задание полей заголовка таблицы
 StringGrid1->Cells[0][0] = "Ca, моль/л";
 StringGrid1->Cells[1][0] = "t, с";
 StringGrid1->Cells[0][1] = 2.2; StringGrid1->Cells[1][1] = 0;
 StringGrid1->Cells[0][2] = 1.7; StringGrid1->Cells[1][2] = 1.7;
 StringGrid1->Cells[0][3] = 1.5; StringGrid1->Cells[1][3] = 2.5;
 StringGrid1->Cells[0][4] = 1.2; StringGrid1->Cells[1][4] = 3.4;
 StringGrid1->Cells[0][5] = 1.1; StringGrid1->Cells[1][5] = 4;
 StringGrid1->Cells[0][6] = 1.0; StringGrid1->Cells[1][6] = 4.6;
 StringGrid1->Cells[0][7] = 0.9; StringGrid1->Cells[1][7] = 5.2;
 StringGrid1->Cells[0][8] = 0.8; StringGrid1->Cells[1][8] = 6;
 Memo1->Lines->Clear();
//Заполнение таблицы с точками
 StringGrid2->Cells[0][0] = "t, с";
 StringGrid2->Cells[1][0] = "Ca расч., моль/л";
 StringGrid2->Cells[2][0] = "Cb, моль/л";
 StringGrid2->Cells[3][0] = "Cc, моль/л";
}
//Определение обработчика нажатия на кнопку для изменения количества строк
//таблицы
void __fastcall TForm1::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
 StringGrid1->RowCount = UpDown1->Position + 1;
 StringGrid2->RowCount = UpDown1->Position + 1;
}
//Определение обработчика кнопки расчета и построения графиков
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
//Инициализация переменных необходимых для решения задачи кинетики
 d = 0.0;
 int i, reg_up(0), reg_down(0);
 double *y, *x, s1(UpDown1->Position - 1),
 s2(0.0), s3(0.0), s4(0.0), s5(0.0), s6(0.0), ca, cb, cc, t;
 //Очистка графиков после предыдущего расчета
 Series1->Clear();
 Series2->Clear();
 Series3->Clear();
 Series4->Clear();
 Memo1->Lines->Clear();
 try
 {
//Создание в динамической памяти массива для хранения экспериментальных данных
 y = new double[UpDown1->Position - 1];
 x = new double[UpDown1->Position - 1];
 if(!y || !x) ShowMessage("НЕТ свободной памяти");
 //Задание начальных значений концентраций
 ca = StringGrid1->Cells[0][1].ToDouble();
 cb = Edit2->Text.ToDouble();
 cc = Edit3->Text.ToDouble();
 //Проверка входных данных на допустимость значений
 if(!ca || cb < 0.0 || cc < 0.0)
ShowMessage("Начальные концентрации компонентов должны быть больше 0");
 for(i = 0; i < UpDown1->Position - 1; i++)
 {
 if(StringGrid1->Cells[0][i + 1].ToDouble() > StringGrid1->Cells[0][i + 2].ToDouble())
 reg_down++;
 else reg_up++;
 if(StringGrid1->Cells[0][i + 1].ToDouble() == StringGrid1->Cells[0][i + 2].ToDouble())
ShowMessage("Концентрация в соседних точках должна быть различна");
 if(StringGrid1->Cells[1][i + 1].ToDouble() >= StringGrid1->Cells[1][i + 2].ToDouble())
ShowMessage("Нарушение последовательности ввода времени");
 if(StringGrid1->Cells[1][i+1].ToDouble()< 0||StringGrid1->Cells[0][i + 1].ToDouble()<0)
ShowMessage("Время и концентрация не могут быть отрицательными");
 }

//Расчет значений локальных переменных, необходимых для решения задачи
for(i = 0; i < UpDown1->Position - 1; i++)
{
y[i] = log(fabs(StringGrid1->Cells[0][i + 2].ToDouble() - StringGrid1->Cells[0][i + 1].ToDouble()) / (StringGrid1->Cells[1][i + 2].ToDouble() - StringGrid1->Cells[1][i + 1].ToDouble()));
x[i] = log(StringGrid1->Cells[0][i + 1].ToDouble());
s2 += x[i];
s3 += y[i];
s4 += x[i] * x[i];
s5 += x[i] * y[i];
s6 += y[i] * y[i];
}

//Расчет константы скорости реакции, порядка реакции, коэффициента корреляции
k = exp((s3 * s4 - s2 * s5) / (s1 * s4 - s2 * s2));
n = (s1 * s5 - s2 * s3) / (s1 * s4 - s2 * s2);
r = (s1 * s5 - s2 * s3) / sqrt((s1 * s4 - s2 * s2) * (s1 * s6 - s3 * s3));
//Построение графиков и расчет концентраций компонентов реакции
 for(int i = 1; i <= UpDown1->Position; i++)
 {
 Series1->AddXY(StringGrid1->Cells[1][i].ToDouble(),
 StringGrid1->Cells[0][i].ToDouble());
 StringGrid2->Cells[1][1] = StringGrid1->Cells[0][1];
 if(ca < 0) ShowMessage("Модель невозможно описать линейной регрессией");
 StringGrid2->Cells[0][i] = StringGrid1->Cells[1][i];
 if(i == 1)
 {
 Series2->AddXY(StringGrid1->Cells[1][i].ToDouble(), ca );
 StringGrid2->Cells[1][i] = FloatToStrF(ca, ffGeneral, 2, 2);
 Series3->AddXY(StringGrid1->Cells[1][i].ToDouble(), cb );
 StringGrid2->Cells[2][i] = FloatToStrF(cb, ffGeneral, 2, 2);
 Series4->AddXY(StringGrid1->Cells[1][i].ToDouble(), cc );
 StringGrid2->Cells[3][i] = FloatToStrF(cc, ffGeneral, 2, 2);
 }
 else
 {
 t = StringGrid1->Cells[1][i].ToDouble() - StringGrid1->Cells[1][i - 1].ToDouble();
 Series3->AddXY(StringGrid1->Cells[1][i].ToDouble(), cb = cb + k * pow(ca, n) * t);
 StringGrid2->Cells[2][i] = FloatToStrF(cb, ffGeneral, 2, 2);
 Series4->AddXY(StringGrid1->Cells[1][i].ToDouble(), cc = cc + k * pow(ca, n)*t/2);
 StringGrid2->Cells[3][i] = FloatToStrF(cc, ffGeneral, 2, 2);
 if(reg_down > reg_up) {
Series2->AddXY(StringGrid1->Cells[1][i].ToDouble(), ca =ca-k*pow(ca, n) * t);
StringGrid2->Cells[1][i] = FloatToStrF(ca, ffGeneral, 2, 2);
} else{
Series2->AddXY(StringGrid1->Cells[1][i].ToDouble(), ca =ca+k*pow(ca, n) * t);
StringGrid2->Cells[1][i] = FloatToStrF(ca, ffGeneral, 2, 2);
}
 }
 double minimleft = StringGrid1->Cells[0][1].ToDouble();
 double minimbottom = StringGrid1->Cells[1][1].ToDouble();
 for(int i = 1; i <= UpDown1->Position; i++)
 {
  if(minimleft < StringGrid1->Cells[0][i].ToDouble())
    minimleft = StringGrid1->Cells[0][i].ToDouble();
  if(minimbottom < StringGrid1->Cells[1][i].ToDouble())
    minimbottom = StringGrid1->Cells[1][i].ToDouble();
 }
 Chart1->BottomAxis->Maximum = minimbottom;
 Chart1->LeftAxis->Maximum = minimleft;
//расчет дисперсии
 d += pow(StringGrid1->Cells[0][i].ToDouble() - ca, 2);
 }
 Memo1->Lines->Add("Порядок реакции: " + FloatToStrF(n, ffGeneral, 2, 2));
 Memo1->Lines->Add("Константа скорости: " + FloatToStrF(k, ffGeneral, 2, 2) + " 1/с");
 Memo1->Lines->Add("Дисперсия: " + FloatToStrF(d, ffGeneral, 2, 2) + " (моль/л)^2");
 Memo1->Lines->Add("Корреляция: " + FloatToStrF(r, ffGeneral, 2, 2));
 Memo1->Lines->Add("t,с \t Ca расч., моль/л \t Cb, моль/л \t Cc, моль/л");
 for(int i = 1; i <= UpDown1->Position; i++)
 {
 Memo1->Lines->Add(FloatToStrF(StringGrid2->Cells[0][i].ToDouble(), ffGeneral, 2, 2) + "\t" + "\t" + FloatToStrF(StringGrid2->Cells[1][i].ToDouble(), ffGeneral, 2, 2) +  "\t" + "\t" +
 FloatToStrF(StringGrid2->Cells[2][i].ToDouble(), ffGeneral, 2, 2) + "\t" + "\t" + FloatToStrF(StringGrid2->Cells[3][i].ToDouble(), ffGeneral, 2, 2));
 }
 //Создание формы отображения результатов
 Application->CreateForm(__classid(TForm2), &Form2);
 //Отображение формы
 Form2->ShowModal();
 delete[]y;
 delete[]x;
 }
 catch(char*str)
 {
 Series1->Clear();
 Series2->Clear();
 Series3->Clear();
 Series4->Clear();
 //Вывод сообщения об ошибке
 Application->MessageBox(str, "Ошибка", MB_ICONERROR | MB_OK);
 }
 catch(EConvertError&)
 {
//Вывод сообщения об ошибке
 Application->MessageBox("Неправильный тип данных", "Ошибка",
MB_ICONERROR | MB_OK);
 delete[]y;
 delete[]x;
 }
 catch(...)
 {
//Вывод сообщения об ошибке
 Application->MessageBox("Неизвестная ошибка", "Ошибка",
MB_ICONERROR | MB_OK);
 }
}



void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
 Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
Application->Title="Справка";
  ShowMessage("Данная программа расчитывает порядок и константу скорости химической реакции.\n"
"Для начала работы введите исходные данные, а именно: начальные концентрации Cb и Cc\n"
"заполните таблицу с изменением концентрации Ca во времени.\nПосле этого нажмите кнопку «Графики» и получите результат.\n"
"Автор: Нерадовский Артемий Андреевич\n"
"Группа: 494\n"
"Учебное заведение: СПбГТИ (ТУ)");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
 if( Memo1->Lines->Text.IsEmpty()) {
 ShowMessage("Перед сохранением результатов необходимо их рассчитать, нажав кнопку «Графики»");
} else {
 if( SaveDialog1->Execute() )
{
 Memo1->Lines->SaveToFile( SaveDialog1->FileName );
}
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
if( Memo1->Lines->Text.IsEmpty()) {
ShowMessage("Перед сохранением результатов необходимо их рассчитать, нажав кнопку «Графики»");
} else {
if( SavePictureDialog1->Execute() )
{
Chart1->SaveToBitmapFile(SavePictureDialog1->FileName);
}
}
}
//---------------------------------------------------------------------------

