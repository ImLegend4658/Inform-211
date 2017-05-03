/*
Author :Aziz Aldawk
Date :  2/24/2016
Language : C++
Purpose : This program to calculate the sum of number
from 1 to 10 using "do while" Loop.
*/
#include <iostream> 
using namespace std;
int main(){

	int i = 0;
	int X = 0;
	//delare varibales.

	do
	{
		X += i;
		i++;
	} while (i <= 10);
	////Calculate the sum of number from 1 to 10 by using do while.

	cout << "Total:  " << X << endl;
	//Show Total to user after calculate the sum of numbers.

	system("pause");
	//Please pause program. 
}