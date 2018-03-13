//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("MainUnit.cpp", MainForm);
USEFORM("HelpUnit.cpp", HelpForm);
USEFORM("SelectUnit.cpp", SelectForm);
USEFORM("PearsonUnit.cpp", PearsonForm);
USEFORM("AboutUnit.cpp", AboutForm);
USEFORM("ExcelUnit.cpp", ExcelForm);
USEFORM("KendallUnit.cpp", KendallForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TAboutForm), &AboutForm);
		Application->CreateForm(__classid(THelpForm), &HelpForm);
		Application->CreateForm(__classid(TSelectForm), &SelectForm);
		Application->CreateForm(__classid(TPearsonForm), &PearsonForm);
		Application->CreateForm(__classid(TKendallForm), &KendallForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
