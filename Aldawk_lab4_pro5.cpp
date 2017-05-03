/*
Author :Aziz Aldawk
Date :  2/10/2016
Language : C++
Purpose : This program about arithmetic calculations (addition, subtraction, multiplication, division)
*/

#include<iostream>
using namespace std;

int main()
{

	int value1 = 1, value2 = 2, value3 = 3, value4 = 4;
	int Num, add, sub, div, mult;
	int ad, su, di, mu;
	int result1, result2, result3, result4;
	//declare variables

	cout << "Please enter number 1 if you want to addition\n"
		"Please enter number 2 if you want to subtraction\n"
		"Please enter number 3 if you want to multiplication\n"
		"Please enter number 4 if you want to division\n";
	//Ask user to choice number if he/she wants 
	//addition, subtraction, multpli or division.
	cin >> Num;
	//receive from user. 

	if (Num == value1) 
		// if user choice number 1 than user choice to addition. 
	{
		cout << "Please enter number twice to calculate addition\n";
		//Ask user to enter number twice to calculate.
		cin >> ad;
		cin >> add;
		result1 = add + ad;
		//Calculate additions. 
		cout << "The result is: " << result1 << endl;
		//prompt and receive. 
	}

	if (Num == value2)
		//if user choice number 2 than user choice to subtraction.
	{
		cout << "Please enter number twice to calculate subtraction\n";
		//Ask user to enter number twice to calculate subtract. 
		cin >> sub;
		cin >> su;
		result2 = sub - su;
		//Calculate subtraction.
		cout << "The result is: " << result2 << endl;
		//prompt and receive.
	}

	if (Num == value3)
		//if user choice number 3 than user choice to multipli.
	{
		cout << "Please enter number twice to calculate multiplication\n";
		//Ask user to enter number twice to calculate multipli. 
		cin >> mult;
		cin >> mu;
		result3 = mult*mu;
		//Calculate multiplication. 
		cout << "The result is: " << result3 << endl;
		//prompt and receive.
	}

	if (Num == value4)
		//if user choice number 4 than user choice to division.
	{
		cout << "Please enter number twice to calculate division\n";
		//Ask user to enter number twice to calcilate division.
		cin >> di;
		cin >> div;
		result4 = di / div;
		//Calculate division. 
		cout << "The result is: " << result4 << endl;
		//propt and receive
	}

	system("Pause");     //Please pause program.
}