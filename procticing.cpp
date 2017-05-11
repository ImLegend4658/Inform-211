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