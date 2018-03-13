//---------------------------------------------------------------------------

#ifndef HelpUnitH
#define HelpUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class THelpForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *lblHelp1;
	TLabel *lblHelp2;
	TImage *imgExampleTable;
	TLabel *lblHelp4;
	TLabel *lblHelp3;
	TLabel *lblHelp7;
	TLabel *lblHelp5;
	TLabel *lblHelp6;
	TLabel *lblHelp8;
	TLabel *lblHelp9;
private:	// User declarations
public:		// User declarations
	__fastcall THelpForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THelpForm *HelpForm;
//---------------------------------------------------------------------------
#endif
