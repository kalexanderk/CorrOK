//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu;
	TMenuItem *btnDatabase;
	TMenuItem *btnBrowse;
	TMenuItem *btnMenuKendall;
	TMenuItem *btnMenuSelect;
	TMenuItem *btnHelp;
	TMenuItem *btnAbout;
	TMenuItem *btnExit;
	TImageList *ImageList;
	TImage *imgKOMup;
	TImage *imgKOMdown;
	TLabel *lblLine;
	TLabel *lblMain1;
	TButton *btnMethodPearson;
	TButton *btnMethodKendall;
	TMenuItem *btnMenuPearson;
	TButton *btnShowExcel;
	TButton *btnSelect;
	TListBox *ListBoxMain;
	TLabel *lblMain2;
	TImage *imgMain;
	TImage *Image1;
	TStringGrid *StringGridExcel;
	TListBox *ListBoxNumbers;
	TLabel *lblHint1;
	TLabel *lblHint2;
	void __fastcall btnAboutClick(TObject *Sender);
	void __fastcall btnExitClick(TObject *Sender);
	void __fastcall btnHelpClick(TObject *Sender);
	void __fastcall btnShowExcelClick(TObject *Sender);
	void __fastcall btnBrowseClick(TObject *Sender);
	void __fastcall btnSelectClick(TObject *Sender);
	void __fastcall btnMenuSelectClick(TObject *Sender);
	void __fastcall btnMethodPearsonClick(TObject *Sender);
	void __fastcall btnMenuPearsonClick(TObject *Sender);
	void __fastcall btnMethodKendallClick(TObject *Sender);
	void __fastcall btnMenuKendallClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
