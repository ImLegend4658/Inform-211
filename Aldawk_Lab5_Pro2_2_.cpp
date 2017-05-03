
/*
Author :Aziz Aldawk
Date :  2/17/2016
Language : C++
Purpose : This program Write a program to calculate grade based on the grade assignment, if statement way, 

*/

#include <iostream>
using namespace std;
int main(){

	int mygrade;
	//Declare variable

	cout << "Please enter grade \n";
	cin >> mygrade;
	//prompt and receive. 

	if ((mygrade<=100) && (mygrade >=90))
	{
		cout << "you got an A "<<endl;
	}

	if ((mygrade<=89) && (mygrade >=80))
	{
		cout << "you got a B "<<endl;
	}
	if ((mygrade<=79) && (mygrade>=70))
	{
		cout << "you got a C " << endl;;
	}
	if ((mygrade<=69) && (mygrade>=60))
	{
		cout << "you got a D " << endl;;
	}
	if ((mygrade<=59) && (mygrade>=0))
	{
		cout << "you got an F " << endl;;
	}
	//show user result what he/she got.

	system("Pause");
	//Please pause program.
}