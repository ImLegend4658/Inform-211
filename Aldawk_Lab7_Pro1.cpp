/*
Author :Aziz Aldawk
Date :  9/3/2016
Language : C++
Purpose : This program  to read a number and output the result of the cube root of the number.
*/
#include <iostream>
#include <cmath>
//Predefined function.
using namespace std;

int main(){

	double num1;
	double result;
	char Hey;



	do
	{
		cout << "Please enter number " << endl;
		cin >> num1;

		//declare variables.
		result = sqrt(num1);

		cout << "The result is: " << result << endl;

		cout << "Do you want to continue?(y/n) : " << endl;
		cin >> Hey;
	} while (Hey == 'y' || Hey == 'Y');

	//do loop until the user has no more numbers to be computed.


	system("pause");
	//Please pause program. 
}
