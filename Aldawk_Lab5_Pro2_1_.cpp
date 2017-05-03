/*
Author :Aziz Aldawk
Date :  2/17/2016
Language : C++
Purpose : this a program to calculate grade based on the grade assignment, switch statement.

*/

#include <iostream>
using namespace std;
int main(){

	int yourgrade;
	//declare variable.

	cout << "Please enter your grade\n";
	//Ask user to enter grade number. 
	cin >> yourgrade;
	//Prompt and receive 

	switch (yourgrade / 10)
		//show user result what he/she got of grade.
	{

	case 10:
	case 9:
		cout << "you got an A \n";
		break;

	case 8:
		cout << "you got a B \n";
		break;
	case 7:
		cout << "you got a C \n";
		break;
	case 6:
		cout << "you got a D \n";
		break;
	case 5:
		cout << "you got an F \n";
		break;


	}

	system("Pause");
	//Please pause program.

}