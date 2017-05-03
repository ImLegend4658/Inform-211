/*
Author :Aziz Aldawk
Date :  3/23/2016
Language : C++
Purpose : This  a program that perform s arithmetic
           calculations using inputs from the user

*/


#include <iostream>
using namespace std;

void calculations(int result1, int result2, int result3, int result4, int Num);
int main(){

	int Num;
	int result1, result2, result3, result4; 

	cout << "Please enter number 1 if you want to addition\n"
		"Please enter number 2 if you want to subtraction\n"
		"Please enter number 3 if you want to multiplication\n"
		"Please enter number 4 if you want to division\n";
	//Ask user to choice number if he/she wants 
	//addition, subtraction, multpli or division.
	cin >> Num;


	calculations(result1, result2, result3, result4, Num);
}

void calculations(int result1, int result2, int result3, int result4, int Num)
{
	int chose1, chose2, chose3, chose4;
	int Plus1, plus2, Muiltplay1, Muiltplay2, Substract1, Substract2;
	int Divison1, Divison2;

	if (Num == chose1)
		// if user choice number 1 than user choice to addition. 
	{
		cout << "Please enter number twice to calculate addition\n";
		//Ask user to enter number twice to calculate.
		cin >> Plus1;
		cin >> plus2;
		result1 = Plus1 + plus2;
		//Calculate additions. 
		cout << "The result is: " << result1 << endl;
		//prompt and receive. 
	}

	if (Num == chose2)
		//if user choice number 2 than user choice to subtraction.
	{
		cout << "Please enter number twice to calculate subtraction\n";
		//Ask user to enter number twice to calculate subtract. 
		cin >> Substract1;
		cin >> Substract2;
		result2 = Substract1 - Substract2;
		//Calculate subtraction.
		cout << "The result is: " << result2 << endl;
		//prompt and receive.
	}

	if (Num == chose3)
		//if user choice number 3 than user choice to multipli.
	{
		cout << "Please enter number twice to calculate multiplication\n";
		//Ask user to enter number twice to calculate multipli. 
		cin >> Muiltplay1;
		cin >> Muiltplay2;
		result3 = Muiltplay1*Muiltplay2;
		//Calculate multiplication. 
		cout << "The result is: " << result3 << endl;
		//prompt and receive.
	}

	if (Num == chose4)
		//if user choice number 4 than user choice to division.
	{
		cout << "Please enter number twice to calculate division\n";
		//Ask user to enter number twice to calcilate division.
		cin >> Divison1;
		cin >> Divison2;
		result4 = Divison1 / Divison2;
		//Calculate division. 
		cout << "The result is: " << result4 << endl;
		//propt and receive
	}


}