/*
Author :Aziz Aldawk
Date :  9/3/2016
Language : C++
Purpose : This program to read a number and raise the number to any power as requested by the user.
*/
#include <iostream>
#include <cmath>
//Predefined function.
using namespace std;

int main(){

	double num1, num2;
	double result;
	char Hey;



	do
	{
		cout << "Please enter number twice" << endl;
		cin >> num1;
		cin >> num2;
		//declare variables.
		result = pow(num1, num2);

		cout << "The result is: " << result << endl;

		cout << "Do you want to continue?(y/n) : " << endl;
		cin >> Hey;
	} while (Hey == 'y' || Hey == 'Y');

	//do loop until the user has no more numbers to be computed.


	system("pause");
	//Please pause program. 
}
