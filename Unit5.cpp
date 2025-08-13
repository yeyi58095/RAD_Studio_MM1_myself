//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ITFormDialog.h"
#include "STFormDialog.h"
#include "CharterDialog.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
double end_time = 0;
double exponential(double);
double normal(double, double);
double uniform(double, double);
int event_ID();

enum {ARRIVAL=0, SERVICE=1, DEPARTURE=2 };
int event_ID();

//---------------------------------------------------------------------------
//=========================
// LinkedList �`�I
//=========================
class LinkedList {
public:
	int eventID;        // �ƥ� ID
	double time;        // �ƥ�ɶ�
	LinkedList* next;   // �U�@�Ӹ`�I

	// �u���`�I
	LinkedList(int eventID, double time)
		: eventID(eventID), time(time), next(NULL) {}

	// Dummy �`�I�]���s�ƥ�^
	LinkedList()
		: eventID(-1), time(0.0), next(NULL) {}

	// ��X��
	AnsiString toString() const {
		return "event: " + IntToStr(eventID) +
			   ", time: " + FloatToStrF(time, ffFixed, 7, 3) + " -> ";
	}
};

//=========================
// �C�L�]�q dummy->next �}�l�^
//=========================
void printLinkedList(LinkedList* head) {
	LinkedList* current = head;
	AnsiString result = "";
	while (current != NULL) {
		result += current->toString();
		current = current->next;
	}
	ShowMessage(result);
}

//=========================
// ���J�G�ɶ����W�A�P�ɶ��ƫ᭱
//=========================
void LinkedList_push(LinkedList* dummy, int event, double time) {
	LinkedList* node = new LinkedList(event, time);
	LinkedList* cur = dummy;
	while (cur->next != NULL && cur->next->time <= time) {
		cur = cur->next;
	}
	node->next = cur->next;
	cur->next = node;
}


void LinkedList_push(LinkedList* dummy, LinkedList* node) {
	if (!node) return;
	node->next = NULL;
	LinkedList_push(dummy, node->eventID, node->time);
}

//=========================
// �u�X�Ĥ@�ӡ]�t�^�Ǩƥ��ơ^
//=========================
bool LinkedList_pop(LinkedList* dummy, int& eventID, double& time) {
	if (dummy->next == NULL) return false;
	LinkedList* n = dummy->next;
	dummy->next = n->next;
	eventID = n->eventID;
	time = n->time;
	delete n;
	return true;
}

// ���^�Ǹ��
bool LinkedList_pop(LinkedList* dummy) {
	if (dummy->next == NULL) return false;
	LinkedList* n = dummy->next;
	dummy->next = n->next;
	delete n;
	return true;
}

//=========================
// ���ե�
LinkedList* dummy;
//=========================
void DebugWindows() {
	//dummy = new LinkedList(); // Dummy �Y�`�I
	/*
	LinkedList_push(dummy, 2, 4.0);
	LinkedList_push(dummy, 3, 4.5);
	LinkedList_push(dummy, 1, 5.0);
	printLinkedList(dummy->next); // 4.0 -> 4.5 -> 5.0

	LinkedList_pop(dummy);
	printLinkedList(dummy->next); // 4.5 -> 5.0

	LinkedList_pop(dummy);
	printLinkedList(dummy->next); // 5.0

	LinkedList_pop(dummy);
	printLinkedList(dummy->next); // ��

	// �A���J
	LinkedList_push(dummy, 9, 7.0);
	printLinkedList(dummy->next); // 7.0   */
	ShowMessage(ARRIVAL);
}
//--------------------------------
int next_event;
//----------------------------------------------

double mean_queue_size = 0;
double mean_system_size = 0;
int queue_size, system_size;  // queue_size is the number of the current queueing people, and system_size is including the people serving
double sum_queue, sum_system; // sum_queue = (now - previous_time) * queue_size (the concept of weightwing)

double next_time;
double previous_time;  // for calculating the queue_size
int top;
double now;

void statics(){
   sum_queue += (now-previous_time)*queue_size;
   sum_system += (now-previous_time)*system_size;
   if (now>0) {
	  mean_queue_size = sum_queue/now;
	  mean_system_size = sum_system/now;
   }
   Form5->MQSize->Text = FloatToStrF(mean_queue_size,ffFixed,7,6);
   Form5->MSSize->Text = FloatToStrF(mean_system_size,ffFixed,7,6);
}

void initial(){
	now = 0;
	queue_size = 0;
	system_size = 0;
	sum_queue = 0;
	sum_system = 0;
	next_time = 0;
	next_event = 0;
	previous_time = 0;
	dummy = new LinkedList();
}

void arrival(){
	double deltaTime, next_arrival;
	now = next_time;
	switch(Form5->ITComboBox->ItemIndex){
		case 0:
			deltaTime = uniform(Form5->paraIT1, Form5->paraIT2);
			break;
		case 1:
			deltaTime = exponential(Form5->paraIT1);
			break;
		case 2:
			deltaTime = normal(Form5->paraIT1, Form5->paraIT2);
			break;

		default:
			break;
	}
	/*Uniform R.V
	Exponential R.V
	Normal R.V
	Pareto R.V
	*/
	next_arrival = now + deltaTime;
	LinkedList_push(dummy, ARRIVAL, next_arrival);  // the upon part is for deciding the next arrival time
	// the following part is for determining  whether the system is empty available
	if(system_size == 0){
		next_event = SERVICE;
		next_time = now;
	}else{
		LinkedList_pop(dummy, next_event, next_time);
	}
	previous_time = now;

	Charter->Series1->AddXY(now, queue_size, "", clRed);
	queue_size ++;
	system_size ++;
	Charter->Series1->AddXY(now, queue_size, "", clRed);
}
void service(){
	now = next_time;

	double serviceTime = 0;
	switch(Form5->STComboBox->ItemIndex){
		case 0:
			serviceTime = uniform(Form5->paraST1, Form5->paraST2);
			break;
		case 1:
			serviceTime = exponential(Form5->paraST1);
			break;
		case 2:
			serviceTime = normal(Form5->paraST1, Form5->paraST2);
			break;
		default:
			break;
	}

	LinkedList_push(dummy, DEPARTURE, now + serviceTime);

	statics();
	previous_time = now;
	//�@�ӤH�q�ƶ��ର�A�Ȥ�
	Charter->Series1->AddXY(now, queue_size, "", clRed);
	if (queue_size > 0) queue_size--;
	LinkedList_pop(dummy, next_event, next_time);
	Charter->Series1->AddXY(now, queue_size, "", clRed);
}
void departure(){
    now = next_time;

	// �έp...
	statics();
	previous_time = now;

	// �@�ӤH���}�t��
	Charter->Series1->AddXY(now, queue_size, "", clRed);
	if (system_size > 0) system_size--;
	Charter->Series1->AddXY(now, queue_size, "", clRed);
	Charter->Series2->AddXY(now, mean_queue_size, "", clBlue); // �Y�A�n�e�����u

    // �Y�٦��H�b�ƶ��A�U�@�ӪA�ȡu�ߨ�v�}�l�]�P�@�ɶ��^
    if (queue_size > 0){
        next_event = SERVICE;
        next_time  = now;   // �ߨ�}�l
    } else {
        // �S�H�� �� �q FEL ���U�@�ӳ̦��ƥ�
        LinkedList_pop(dummy, next_event, next_time);
    }
}

int event_ID() {
	return next_event;   // 0=ARRIVAL, 1=SERVICE, 2=DEPARTURE
}

/*int event_ID()
{
  if (next_event == "arrival")
	  return 0;
  else if (next_event == "service")
	  return 1;
  else if (next_event == "departure")
	  return 2;
}

int event_ID(AnsiString event){
   if (event == "arrival")
	  return 0;
  else if (event == "service")
	  return 1;
  else if (event == "departure")
	  return 2;
}*/
//-------------------------------
double uniform(double a, double b)
{ int n;
  double x;

  n=rand()%(int)pow(2.0,15);
  x=a+(b-a)*n/pow(2.0,15);
  return x;
}

double exponential(double r)
{ double x,y;
  //srand(1);
  x=uniform(0,1);
  if (x<=1e-10)
	  x=1e-10;
  y=-log(1-x)/r;
  return(y);
}

double normal(double m, double v)
{ double x1, x2, y;
  double pi = 3.14159;
  //srand(1);
  x1=uniform(0,1);
  x2=uniform(0,1);
  if (x2<=1e-10)
	  x2=1e-10;
  y=m+v*cos(2*pi*x1)*sqrt((-2)*log(x2));
  return(y);
}


 //---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
	SimulationTEdit->Text = 10000;
	end_time = 10000;

}
//---------------------------------------------------------------------------

void __fastcall TForm5::updateParaIT(double p1, double p2){
	this->paraIT1 = p1;
	this->paraIT2 = p2;

	Label5->Caption = paraIT1;
	return ;
}

void __fastcall TForm5::updateParaST(double p1, double p2){
	this->paraST1 = p1;
	this->paraST2 = p2;

	Label5->Caption = FloatToStr(paraST1) + " " + FloatToStr(paraST2);
	return ;
}

void __fastcall TForm5::SimulationTEditChange(TObject *Sender)
{
	if(SimulationTEdit->Text == ""){
		end_time = 0;
		return ;
	}
	end_time = StrToFloat(SimulationTEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::MQSizeChange(TObject *Sender)
{
	if(MQSize->Text == ""){
		mean_queue_size = 0;
		return ;
	}
	mean_queue_size = StrToFloat(MQSize->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::MSSizeChange(TObject *Sender)
{
	if(MSSize->Text == ""){
		mean_system_size = 0;
		return ;
	}
	mean_system_size = StrToFloat(MSSize->Text);
}
//---------------------------------------------------------------------------



void __fastcall TForm5::ITComboBoxChange(TObject *Sender)
{
	ITForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::STComboBoxChange(TObject *Sender)
{
	STForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::RunClick(TObject *Sender)
{
	Charter->Series1->Pen->Width = 3;
	Charter->Series2->Pen->Width = 3;
	Charter->Series1->Clear();
	Charter->Series2->Clear();
	Charter->Chart1->BottomAxis->Automatic=true;
	Charter->Chart1->LeftAxis->Automatic=true;
	Charter->Chart1->Title->Caption="";
	Charter->Chart1->LeftAxis->Title->Caption="Queue Size";
	Charter->Chart1->BottomAxis->Title->Caption="Time (sec)";

	/*for(int i = 0; i <  end_time; i+= 100){

		Charter->Series1->AddXY(i, normal(5,10));
		//Charter->Series1->AddXY(i, exponential(1));
	}

	for(int i = 0; i < end_time; i+= 100){
		Charter->Series2->AddXY(i, normal(5,10));
	}     */
   initial();

  Edit5->Text = "";
  Edit6->Text = "";
  //end_time = StrToFloat(Edit->Text);
  while (now < end_time) {
	  switch (event_ID()) {
			 case 0:
				  arrival();
				  break;
			 case 1:
				  service();
				  break;
			 case 2:
				  departure();
				  break;
	  }
	  Charter->Chart1->Refresh();
	  Application->ProcessMessages();
	  if (int(now)%100==0)    ;
		  Edit6->Text = FloatToStrF(now,ffFixed,7,3);
  }
  //fclose(pi);
  Edit5->Text = "End";	//DebugWindows();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::PlotClick(TObject *Sender)
{
	Charter->Show();
}
//---------------------------------------------------------------------------



void __fastcall TForm5::FormShow(TObject *Sender)
{
	ITComboBox->ItemIndex = 1;
	STComboBox->ItemIndex = 1;
}
//---------------------------------------------------------------------------




