/*
Author :Aziz Aldawk
Date :  4/14/2016
Language : C++
Purpose : a program that reads 10 numbers into an array
and determines the largest number that was stored in the array.
Problem # 1
lab #11
*/
#include <iostream>
using namespace std;

int main(){

	int num[10], largest;
	int i;
	//declare variables. 
	cout << "Enter 10 numbers" << endl;
	//Ask user to enter 10 numbers.
	cin >> num[0];
	//receive from the user. 

	largest = num[0];
	//lagrest number come from array num[];

	for (i = 1; i < 10; i++)
	{
		cout << "Enter next numbers "<<"<"<<i <<">"<< endl;
		cin >> num[i];
		//prompt and receive from user. 
		if (num[i]>largest)
			largest = num[i];
		//do for loop the array to show largest number.

	}

	cout << "The largest number is " << largest << endl;
	//prompt to user the result the largest number.

	system("Pause");
	//Please pause the program. 
}