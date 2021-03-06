//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ExcelUnit.h"
#include "MainUnit.h"
#include <ComObj.hpp>
#include <utilcls.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TExcelForm *ExcelForm;
extern Variant App, Sh;
extern bool checkbool;
extern int iRows, iColumns;
System::WideString FileAdress;


//---------------------------------------------------------------------------
__fastcall TExcelForm::TExcelForm(TComponent* Owner)
	: TForm(Owner)
{
    System::WideString filename = L"" + FileAdress;
	ExcelInit(filename);
	if (checkbool ==true) {
		iRows = Sh.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");
		iColumns = Sh.OlePropertyGet("UsedRange").OlePropertyGet("Columns").OlePropertyGet("Count");

		MainForm->StringGridExcel->ColCount=iColumns;
		MainForm->StringGridExcel->RowCount=iRows;
		for (int i = 0; i < iColumns; i++) {
			for (int j = 0; j < iRows; j++) {
				MainForm->StringGridExcel->Cells[i][j]=Sh.OlePropertyGet("Cells", j+1, i+1);
			}
		}
	}
}
//-------------------------------------------------------------------------

void __fastcall TExcelForm::ExcelInit(System::WideString File)
 {
  checkbool = true;
  // ���� Excel ������� - ������������ � ����
  try {
		App=Variant::GetActiveObject("Excel.Application");
	  }
  catch(...) {
	 // Excel �� ������� - ��������� ���
	 try {
		App=Variant::CreateObject("Excel.Application"); }
	 catch (...) {
		Application->MessageBox(L"It is unable to open Microsoft Excel!"
		"Maybe Excel is not installed on your PC.",L"Error",MB_OK+MB_ICONERROR);
		this->lblExcel->Visible = false;
		this->lblExcelError->Visible = true;
		checkbool = false;
	 }
  }
  try {
	if(File!="")
		App.OlePropertyGet("WorkBooks").OleProcedure("Open", File);
	else
		App.OlePropertyGet("WorkBooks").OleProcedure("add");

	Sh=App.OlePropertyGet("WorkSheets",1);
  }
  catch(...) {
	this->lblExcel->Visible = false;
	this->lblExcelError->Visible = true;
	checkbool = false;
 }
}
//---------------------------------------------------------------------------
void __fastcall TExcelForm::btnExcelClick(TObject *Sender)
{
	if (checkbool == true) {
		MainForm->StringGridExcel->Visible=true;
	}
	if (checkbool==true){
		try{
			App.OleProcedure("Quit");
		}
		catch(...){
		}
	}
	Close();
}
//---------------------------------------------------------------------------

