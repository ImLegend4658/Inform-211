/*
Author :Aziz Aldawk
Date :  2/17/2016
Language : C++
Purpose : This program about arithmetic calculations (addition, subtraction, multiplication, division)
*/
#include <iostream>
using namespace std;
int main() {

	int num, ad,add,result1;
	int sub, su, result2;
	int mult, mu, result3;
	int div, di, result4;
	//declare variables

	cout << "Please enter number 1 if you want addition\n"
		   "Please enter number 2 if you want subtraction\n"
		   "Please enter number 3 if you want multiplication\n"
		   "Please enter number 4 if you want division\n";
	cin >> num;
	//prompt and receive  
	switch (num)//switch that let user to get what he/she choose .
	{
	case 1:
		// if user choice number 1 than user choice to addition.
		cout << "Please enter two numbers to caluclate addition\n";
		//Ask user to enter number twice to calculate.
		cin >> ad;
		cin >> add;
		result1 = add + ad;
		//Calculate additions. 
		cout << "result is: " << result1 << endl;
		//prompt and receive
		break;
	case 2: 
		//if user choice number 2 than user choice to subtraction.
		cout << "Please enter two numbers to caluclate subtraction\n";
		//Ask user to enter number twice to calculate subtract.
		cin >> sub;
		cin >> su;
		result2 = sub - su;
		//Calculate subtraction.
		cout << "result is: " << result2 << endl;
		//prompt and receive.
		break;
	case 3:
		//if user choice number 3 than user choice to multipli.
		cout << "Please enter two numbers to calucalte multiplication\n";
		//Ask user to enter number twice to calculate multipli. 
		cin >> mult;
		cin >> mu;
		result3 = mult*mu;
		//Calculate multiplication. 
		cout << "result is: " << result3 << endl;
		//prompt and receive.
		break;
	case 4: 
		//if user choice number 4 than user choice to division.
		cout << "Please enter tow numbers to calucalte division\n";
		//Ask user to enter number twice to calcilate division.
		cin >> di;
		cin >> div;
		result4 = di / div;
		//Calculate division. 
		cout << "result is: " << result4 << endl;
		//prompt and receive.
		break;

	}

	system("Pause");
	//Please pause the program.



}