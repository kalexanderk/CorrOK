//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SelectUnit.h"
#include "ExcelUnit.h"
#include "MainUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSelectForm *SelectForm;
int iRows, iColumns;
//---------------------------------------------------------------------------
__fastcall TSelectForm::TSelectForm(TComponent* Owner)
	: TForm(Owner)
{
	//TExcelForm *ExcelForm = new TExcelForm(this);
	this->ListBoxSelect->Clear();
	for (int j = 0; j < iColumns; j++) {
		this->ListBoxSelect->Items->Add(MainForm->StringGridExcel->Cells[j][0]);
	}
	//delete ExcelForm;
}
//---------------------------------------------------------------------------
void __fastcall TSelectForm::btnSelectSelectClick(TObject *Sender)
{
	int c = this->ListBoxSelect->Items->Count;
	this->ListBoxSelectSelected->Items->BeginUpdate();
	this->ListBoxSelectSelected->Clear();
	MainForm->ListBoxNumbers->Clear();
	for (int i = 0; i < c; i++) {
		if ( this->ListBoxSelect->Selected[i] ) {
			this->ListBoxSelectSelected->Items->Add(this->ListBoxSelect->Items->Strings[i]);
			MainForm->ListBoxNumbers->Items->Add(i);
		}
	}
	this->ListBoxSelectSelected->Items->EndUpdate();

}
//---------------------------------------------------------------------------
void __fastcall TSelectForm::btnSelectClearClick(TObject *Sender)
{
	this->ListBoxSelectSelected->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TSelectForm::btnSelectCloseClick(TObject *Sender)
{
	MainForm->btnMethodPearson->Enabled=false;
	MainForm->btnMenuPearson->Enabled=false;
	MainForm->btnMethodKendall->Enabled=false;
	MainForm->btnMenuKendall->Enabled=false;
	MainForm->lblHint1->Visible = true;
	MainForm->lblHint2->Visible  = true;
	MainForm->ListBoxMain->Clear();
	int count = this->ListBoxSelectSelected->Items->Count;
	for (int i = 0; i < count; i++) {
		MainForm->ListBoxMain->Items->Add(this->ListBoxSelectSelected->Items->Strings[i]);
	}
	if (count >= 2) {
		MainForm->btnMethodPearson->Enabled=true;
		MainForm->btnMenuPearson->Enabled=true;
		MainForm->lblHint1->Visible = false;
	}
	if (count == 2) {
		MainForm->btnMethodKendall->Enabled=true;
		MainForm->btnMenuKendall->Enabled=true;
		MainForm->lblHint2->Visible = false;
	}
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TSelectForm::btnSelectJustCloseClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

