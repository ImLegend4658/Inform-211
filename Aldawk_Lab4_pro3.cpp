/*
Author :Aziz Aldawk
Date :  2/10/2016
Language : C++
Purpose : This program will ask user to enter number and 
          it will show user number is even or odd. 
*/

#include<iostream>
using namespace std;

int main()
{

	int num;  //declare variable num. 

	cout << "Please enter number" << endl;
	//Ask user to enter number that will show user number is even or odd.
	cin >> num;
	//prompt and receive from user. 

	if (num % 2) //Calculate and show result to user number is even or odd. 
	{
		cout << "Odd number\n";
	}
	else{
		cout << "Even number\n";
	}

	system("pause");    //Please pause program.

}