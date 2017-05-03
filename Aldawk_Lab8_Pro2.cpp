/*
Author :Aziz Aldawk
Date :  3/23/2016
Language : C++
Purpose : This a program that uses a function to calculate the factorial of a number.
*/

#include <iostream>
using namespace std;

int factor(int& hernum);
//function definition.
int main(){

	int num;
	//declare varibales. 
	cout << "Please enter number you want to factor it" << endl;
	cin >> num;
	//Prompt and receive from user. 

	factor(num);
	//receive result from function definition. 
	cout << "factorial of a number: " << factor(num) << endl;
	//prompt from function definition. 

	system("pause");
	//Please pause the program. 
}// Call function. 

int factor(int& hernum)
{
	int Z;
	int S = 1;

	for (Z = 1; Z <= hernum; Z++)
	{
		S = S*Z;
	}

	return S;
}//function definition pass to call function.