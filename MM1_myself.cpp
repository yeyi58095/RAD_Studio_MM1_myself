//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("STFormDialog.cpp", STForm);
USEFORM("Unit5.cpp", Form5);
USEFORM("ITFormDialog.cpp", ITForm);
USEFORM("CharterDialog.cpp", Charter);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm5), &Form5);
		Application->CreateForm(__classid(TITForm), &ITForm);
		Application->CreateForm(__classid(TSTForm), &STForm);
		Application->CreateForm(__classid(TSTForm), &STForm);
		Application->CreateForm(__classid(TCharter), &Charter);
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
