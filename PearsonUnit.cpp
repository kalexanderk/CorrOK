//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PearsonUnit.h"
#include "MainUnit.h"
#include "ExcelUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPearsonForm *PearsonForm;
bool metod;

//---------------------------------------------------------------------------
double cov_func(int i, int j, int n){
	double xm = 0;
	double ym = 0;
	for (int count = 0; count < n; count++) {
		xm += StrToFloat(MainForm->StringGridExcel->Cells[i][count+1]);
		ym += StrToFloat(MainForm->StringGridExcel->Cells[j][count+1]);
	}
	xm=xm/n;
	ym=ym/n;

	double cov = 0;
	for (int count = 0; count < n; count++) {
		cov += (StrToFloat(MainForm->StringGridExcel->Cells[i][count+1]) -
		xm)*(StrToFloat(MainForm->StringGridExcel->Cells[j][count+1]) - ym);
    }

	return cov/(n-1);
}
//---------------------------------------------------------------------------

double Pearson (int i, int j, int n){
	double s=cov_func(i, i, n)*cov_func(j, j, n);
	return cov_func(i, j, n)/sqrt(s);
}
//---------------------------------------------------------------------------

__fastcall TPearsonForm::TPearsonForm(TComponent* Owner)
	: TForm(Owner)
{
	this->ChartPearson->ShowHint=true;
	int count = MainForm->ListBoxMain->Items->Count;
	this->StringGridResult->ColCount = count+1;
	this->StringGridResult->RowCount = count+1;
	for (int j = 0; j < count; j++) {
		this->StringGridResult->Cells[j+1][0] = MainForm->ListBoxMain->Items->Strings[j];
		this->StringGridResult->Cells[0][j+1] = MainForm->ListBoxMain->Items->Strings[j];
	}
	try{
	for (int i = 0; i < MainForm->ListBoxNumbers->Items->Count; i++) {
		for (int j = 0; j < i+1; j++){
			double res = Pearson(StrToInt(MainForm->ListBoxNumbers->Items->Strings[i]), StrToInt(MainForm->ListBoxNumbers->Items->Strings[j]), MainForm->StringGridExcel->RowCount - 1);
			this->StringGridResult->Cells[i+1][j+1]= FloatToStr(res);
			this->StringGridResult->Cells[j+1][i+1]= FloatToStr(res);
		}
	}
	if (count == 2) {
		int c1 = StrToInt(MainForm->ListBoxNumbers->Items->Strings[1]);
		int c2 = StrToInt(MainForm->ListBoxNumbers->Items->Strings[0]);
		Series1->Clear();
		for (int i = 0; i < MainForm->StringGridExcel->RowCount-1 ; i++) {
			double y_series = StrToFloat(MainForm->StringGridExcel->Cells[c1][i+1]);
			double x_series = StrToFloat(MainForm->StringGridExcel->Cells[c2][i+1]);
			this->Series1->AddXY( y_series, x_series, "",clBlue);
		}
		ChartPearson->Refresh();
		this->ChartPearson->ShowHint=false;
	}
	}
	catch(...){
		Application->MessageBox(L"Try another data!!",
		L"Error",MB_OK+MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------

