//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit5.h"
#include "STFormDialog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSTForm *STForm;
//---------------------------------------------------------------------------
__fastcall TSTForm::TSTForm(TComponent* Owner)
	: TForm(Owner)
{
	Edit1->Text = 1.5;
	Edit2->Text = 2;
	Form5->updateParaST(
		StrToFloat(Edit1->Text),
		StrToFloat(Edit2->Text)
	);
}
//---------------------------------------------------------------------------
void __fastcall TSTForm::FormShow(TObject *Sender)
{
	switch(Form5->STComboBox->ItemIndex){ // �]���|�Ψ�t�~�@�ӵ��� (Form5)�����e�A�]���n�b�W�� #include "Unit5.h"
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
void __fastcall TSTForm::Button1Click(TObject *Sender)
{
	Form5->updateParaST(
		StrToFloat(Edit1->Text),
		StrToFloat(Edit2->Text)
	);
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TSTForm::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
