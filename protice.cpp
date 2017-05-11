#include <iostream>
using namespace std; 
/*
protice with simple codes of fractions 


*/
int main(){

	double demon;
	double numon;
	double enter;
	int choicNum;

	cout << "welcome to our program fruction :)"<<endl
		<< "please choice the number what you need" << endl
		<< " Addition, press number <1>" << endl
		<< "Subtruction, press number <2>" << endl
		<< "Mulity, press number <3>" << endl
		<< "divition, press number <4>" << endl;
	cin >> choicNum;

	cout << "please enter demon number" << endl;
	cin >> demon;

	cout << "please enter numon number" << endl;
	cin >> numon;


	switch (choicNum)
	{
	case 1:
		enter = (demon / numon) + (numon / demon);

		cout << enter<< " Fraction on addtion is: " << endl;
		break;
	case 2:
		enter = (demon / numon) - (numon / demon);
		cout << enter << " Fraction on substract is: " << endl;
		break;
	case 3:
		enter = (demon / numon) * (numon / demon);
		cout << enter << " Fraction on multi is: " << endl;
		break;
	case 4:
		enter = (demon / numon) / (numon / demon);
		cout << enter << " Fraction on multi is: " << endl;
		break;
	default:
		cout << "error" << endl; 
		exit(1);
	}

	system("pause"); 

}


====================================================================================================
	=======================================================================================================
	========================================================================================
	
	with functions <><><>
	
	#include <iostream>
using namespace std; 
/*
protice with functions codes of fractions 
#2
*/
int SomeCulclate(double &demon,  double &numon, float result);
void addTwoNum(double &demon, double &numon);
int main(){

	double demon=0;
	double numon=0;
	float result=0;

	addTwoNum(demon, numon);
	SomeCulclate(demon, numon, result);

	system("pause"); 

}

void addTwoNum(double &demon, double &numon){

	cout << "please enter the Demonater number" << endl; 
	cin >> demon;

	cout << "please enter the numonator number" << endl; 
	cin >> numon;
}

int SomeCulclate(double &demon, double &numon, float result){

	int choicNum;
	cout << "welcome to our program fruction :)" << endl
		<< "please choice the number what you need" << endl
		<< " Addition, press number <1>" << endl
		<< "Subtruction, press number <2>" << endl
		<< "Mulity, press number <3>" << endl
		<< "divition, press number <4>" << endl;
	cin >> choicNum;

	switch (choicNum)
	{
	case 1:
		result = (demon / numon) + (numon / demon);

		cout << result << " Fraction on addtion is: " << endl;
		break;
	case 2:
		result = (demon / numon) - (numon / demon);
		cout << result << " Fraction on substract is: " << endl;
		break;
	case 3:
		result = (demon / numon) * (numon / demon);
		cout << result << " Fraction on multi is: " << endl;
		break;
	case 4:
		result = (demon / numon) / (numon / demon);
		cout << result << " Fraction on multi is: " << endl;
		break;
	default:
		cout << "error" << endl;
		exit(1);
	}
	return result;

}


=====================================================================================================================================================================
	
	===================================
	===========================================
	
	====================
	#include <iostream>
using namespace std; 
/*
protice with functions codes of fractions 
#3
in the structer way. 
*/
struct myFract
{
	double demon =0;
	double numon =0;
	float result=0;
};
void addTwoNum(myFract &num);
int  SomeCulclate(myFract &iam);

 int main(){
	 myFract IamID;
	 // has to use same name structer in oder to call varible from structer.
	 addTwoNum(IamID);
	 SomeCulclate(IamID);

	system("pause"); 
}

 void addTwoNum(myFract &num){

	 cout << "please enter the Demonater number" << endl;
	 cin >> num.demon;
	 

	 cout << "please enter the numonator number" << endl;
	 cin >> num.numon;
 }

 int  SomeCulclate(myFract &iam){
 	 int choicNum;
	 cout << "welcome to our program fruction :)" << endl
		 << "please choice the number what you need" << endl
		 << " Addition, press number <1>" << endl
		 << "Subtruction, press number <2>" << endl
		 << "Mulity, press number <3>" << endl
		 << "divition, press number <4>" << endl;
	 cin >> choicNum;

	 switch (choicNum)
	 {
	 case 1:
		 iam.result = (iam.demon / iam.numon) + (iam.numon / iam.demon);

		 cout << iam.result << " Fraction on addtion is: " << endl;
		 break;
	 case 2:
		 iam.result = (iam.demon / iam.numon) - (iam.numon / iam.demon);
		 cout << iam.result << " Fraction on substract is: " << endl;
		 break;
	 case 3:
		 iam.result = (iam.demon / iam.numon) * (iam.numon / iam.demon);
		 cout << iam.result << " Fraction on multi is: " << endl;
		 break;
	 case 4:
		 iam.result = (iam.demon / iam.numon) / (iam.numon / iam.demon);
		 cout << iam.result << " Fraction on multi is: " << endl;
		 break;
	 default:
		 cout << "error" << endl;
		 exit(1);
	 }
	 return iam.result;

 }
===============================================================
	======================================================
	#include <iostream>
using namespace std; 
/*
protice with functions codes of fractions 
#4
class 
all copy right@ 2017
Aziz Aldawk
5/10/2017
*/
class mine
{
public:
	mine();
	void fraction1(double &demonnew);
	void fraction2(double &numonu);
	void setDemon();
	double getDemon();
	void setNum();
	double getNum();
	void Display();
 private:
	double demon;
	double numon;
};

/*==========================================================
here is the main: usually here where complier will start. 

mine: is object of the class.

thieme.display;: compiler will prompt and display to the user. 

pause: it will pause program after compiler done::

====================================================================== */
 int main(){
	 mine thieme;
	
		 thieme.Display();

	system("pause"); 
}

 mine::mine()
 {
	 demon = 1;
	 numon = 0;
 }/// default constructor. 

 void mine::fraction1(double &demonew)
 {
	 demon = demonew;
 }// automatically called from private;

 void mine::fraction2(double &numonu){
	 numon = numonu;
 }// atomatically called from private

 void mine::setDemon(){
	 double num1;

	 cout << "please enter demon" << endl;
	 cin >> num1;

	 fraction1(num1);
 }// ask user to enter denomnateor.

 double mine::getDemon(){
	 return demon;
 }// return to vaule in the private:

 void mine::setNum(){
	 double num2;

	 cout << "please enter numon sir" << endl;
	 cin >> num2;

	 fraction2(num2);
 }// ask user to enter nomnatoer

 double mine::getNum(){
	 return numon;
 }// return to the value in the private

 /*==========================================================
 Display" it will display and prompt to the user after calcluating. 
 and also it will prompt to user to chose a methed multiplay, additicon.....
 
====================================================================== */
 void mine::Display(){

	 setNum();    // it will ask user to enter namnoator.
	 setDemon(); // it will ask user to enter denamonator.
	 double enter;  // collect the calcul

	 int choicNum;

	 cout << "welcome to our program fruction :)" << endl
		 << "please choice the number what you need" << endl
		 << " Addition, press number <1>" << endl
		 << "Subtruction, press number <2>" << endl
		 << "Mulity, press number <3>" << endl
		 << "divition, press number <4>" << endl;
	 cin >> choicNum;
	 // prompt and ask user what kind of methad wants before calclating.


	 switch (choicNum)
	 {
	 case 1:
		 enter = (getDemon() / getNum()) + (getDemon() / getNum());

		 cout << enter << " Fraction on addtion is: " << endl;
		 break;
	 case 2:
		 enter = (getDemon() / getNum()) - (getDemon() / getNum());
		 cout << enter << " Fraction on substract is: " << endl;
		 break;
	 case 3:
		 enter = (getDemon() / getNum()) * (getDemon() / getNum());
		 cout << enter << " Fraction on multi is: " << endl;
		 break;
	 case 4:
		 enter = (getDemon() / getNum()) / (getDemon() / getNum());
		 cout << enter << " Fraction on multi is: " << endl;
		 break;
	 default:
		 cout << "error" << endl;
		 exit(1); // if Error please exit the program. 
	 }
 }
