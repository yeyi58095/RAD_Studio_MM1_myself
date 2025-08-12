//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
                 #include "Unit5.h"
#include "ITFormDialog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TITForm *ITForm;
//---------------------------------------------------------------------------
__fastcall TITForm::TITForm(TComponent* Owner)
	: TForm(Owner)
{
Edit1->Text = 0;
Edit2->Text = 0;
}
//---------------------------------------------------------------------------

void __fastcall TITForm::FormShow(TObject *Sender)
{
     switch(Form5->ITComboBox->ItemIndex){ // 因為會用到另外一個視窗 (Form5)的內容，因此要在上面 #include "Unit5.h"
		case 0:
			Label2->Visible = true;
			Edit2->Visible = true;
			Label1->Caption = "Start";
			Label2->Caption = "End";
			break;
		case 1:
			Label1->Caption = "lambda";
			Label2->Visible = false;
			Edit2->Visible = false;
			break;

		case 2:
			Label2->Visible = true;
			Edit2->Visible = true;
			Label1->Caption = "mean";
			Label2->Caption = "variance";
			break;
		default:
			break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TITForm::Button1Click(TObject *Sender)
{
	Form5->updateParaIT(
		StrToFloat(Edit1->Text),
		StrToFloat(Edit2->Text)
	);
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TITForm::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

