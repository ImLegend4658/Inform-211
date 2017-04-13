#include <iostream>
using namespace std;
/*===============================================================
Author: Aziz Aldawk 
Date: 4/13/2017
Homework #5
purpose: This program will be able to enterd the number
         of the month by user and it will display the letters that 
		 represent a month (1 for Jan, 2 for Feb....).
=================================================================*/
class Month
{
public: 
	Month(); // default constructor. 
	void Month1(int month); // constructor. 
	void setTheMonth();
	int getTheMonth();
	void DisplayTheMonth();
	int NextMonthIs();
 
private:
	int Themonth1;

};
/*
The purpose:
Month: this is object that called before class member.
setTheMonth: is function back to class member, that  
            will ask user to enter number of the month.
Displaythemonth: the function back to class member, It will display letters of the months	 
		after the user has enterd the number.
NextMonth: The function it will prompt the number of next month. 
*/
int main(){
	//object class member.
	Month Num1, num2, num3, num4;

	Num1.setTheMonth();
	Num1.DisplayTheMonth();
 	 cout << "The next month is: "<< Num1.NextMonthIs() << endl;
	 
	 num2.setTheMonth();
	 num2.DisplayTheMonth();
	 cout << "The next month is: " << num2.NextMonthIs() << endl;

	 num3.setTheMonth();
	 num3.DisplayTheMonth();
	 cout << "The next month is: " << num3.NextMonthIs() << endl;

	 num4.setTheMonth();
	 num4.DisplayTheMonth();
	 cout << "The next month is: " << num4.NextMonthIs() << endl;
 	 system("pause"); //please pause the program.
}
/*
The purpose:
This is default constructor 
*/
Month::Month(){
	Themonth1 = 1;
}
 /*
 The purpose:
 This constructor, this function make variables 
 back from private class members
 are allow to use anywhere else. 
  */
void Month::Month1(int month){

	Themonth1 = month;
}
/*
The purpose:
This function is set the month which mean
it will be able to ask user to enter the number
of the month. 
*/
void Month::setTheMonth()
{
	int month;

	cout << "please enter the month number" << endl;
	cin >> month;
	Month1(month);
}
/*
The purpose: 
it will return to the value that exsits 
on the private and save it on the memory. 
*/
int Month::getTheMonth()
{
	return Themonth1;
}
/*
The purpose: 
this function will prompt and display 
the tree letters of the months. 
*/
void Month::DisplayTheMonth()
{
	switch (getTheMonth())
	{
	case 1:
	cout << "Jan" << endl;
	break;
	case 2:
	cout << "Feb" << endl;
	break;
	case 3:
	cout << "Mar" << endl;
	break;
	case 4:
	cout << "Apr" << endl; 
	break;
	case 5:
	cout << "May" << endl;
	break;
	case 6:
	cout << "Jun" << endl; 
	break;
	case 7:
	cout << "Jul" << endl;
	break;
	case 8:
	cout << "Aug" << endl; 
	break;
	case 9:
	cout << "Sep" << endl; 
	break;
	case 10:
	cout << "Oct" << endl;
	break;
	case 11:
	cout << "Nov" << endl; 
	break;
	case 12:
	cout << "Dec" << endl;
	break;
	default:// if more then 12, the program will exit. 
	cout << "Error" << endl;
	exit(0);
	}
}
/*
The purpose: 
this function will be able display 
the next month. For example, if user
enterd 1 for jan, This funciton will say
next month is 2.
*/
int Month::NextMonthIs()
{

	if (getTheMonth() == 1)
	
		return getTheMonth() + 1;
	
 	else
	if ( getTheMonth() == 2)
		return getTheMonth() + 1;
	else 
	if (getTheMonth() == 3)
		
		return getTheMonth() + 1;
	else
	if (getTheMonth() == 4)

		return getTheMonth() + 1;
		
	if (getTheMonth() == 5)
		return getTheMonth() + 1;
	else 
		
	if (getTheMonth()== 6)
		return getTheMonth() + 1;

	if (getTheMonth() == 7)
		return getTheMonth() + 1;
	else

	if (getTheMonth() == 8)
		return getTheMonth() + 1;

	else
	if (getTheMonth() == 9)
		return getTheMonth() + 1;

	else
	if (getTheMonth() == 10)
		return getTheMonth() + 1;

	else
	if (getTheMonth() == 11)
		return getTheMonth() + 1;

	else
	if (getTheMonth() == 12)
		return getTheMonth() - 11;

		else
		exit(0);
 }
 