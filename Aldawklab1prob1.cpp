/*
Author :Aziz Aldawk
Date :  20/1/2016
Language : C++
Purpose : Greetings: First cpp program
*/
#include<iostream>
using namespace std;

int main(double Fahrenheit, double Celsius)
{


	cout << "Please enter the number in Celsius and press enter";
     cin >>  Celsius;
	 Fahrenheit = (Celsius * 9.0) / 5.0 + 32;
	 cout << "The Temperature in Celsius is: " << Celsius;
	 cout << "The Temperature in Fahrenheit is : " << Fahrenheit;

	system("pause");
	return EXIT_SUCCESS;
}