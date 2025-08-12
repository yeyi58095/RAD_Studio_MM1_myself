//---------------------------------------------------------------------------

#ifndef CharterDialogH
#define CharterDialogH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VCLTee.TeeFunci.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
//---------------------------------------------------------------------------
class TCharter : public TForm
{
__published:	// IDE-managed Components
	TChart *Chart1;
	TFastLineSeries *Series1;
	TAverageTeeFunction *TeeFunction1;
	TFastLineSeries *Series2;
private:	// User declarations
public:		// User declarations
	__fastcall TCharter(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCharter *Charter;
//---------------------------------------------------------------------------
#endif
