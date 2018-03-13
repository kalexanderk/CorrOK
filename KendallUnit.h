//---------------------------------------------------------------------------

#ifndef KendallUnitH
#define KendallUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TKendallForm : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGridKendall;
	TImage *imgKendall;
	TImage *imgKendallUp;
private:	// User declarations
public:		// User declarations
	__fastcall TKendallForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKendallForm *KendallForm;
//---------------------------------------------------------------------------
#endif
