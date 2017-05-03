/*
Author :Aziz Aldawk
Date :  2/3/2016
Language : C++
Purpose : This program about two whole numbers into two variables of type int and
          then output both the whole number part and remainder when the first number is 
		  divided by the second.
*/

#include<iostream>
using namespace std;

int main()
{

	int num1, num2, Total, Total2;                                //declare variables num1, num2, total, and total2

	cout << "Please enter first number"<< endl;                   //Ask user to enter first number
	cin >> num1;								                 //prompt and receive
	cout << "Please enter second number"<< endl;                 //Ask use r to enter second number
	cin >> num2;								                 //prompt and receive
	Total = (num1 / num2);					                	 //divided by two numbers
	cout << "Two numbers are divided to: " << Total << endl;    //print out the result. 
	Total2 = (num1% num2);									   //integer divison.
	cout << "With a remainder is: " << Total2 << endl;        //print out the result.


	system("pause");                                          //Please pause program.

}
