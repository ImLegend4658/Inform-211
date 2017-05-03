/*
Author :Aziz Aldawk
Date :  2/24/2016
Language : C++
Purpose : This program to calculate the sum of number
from 1 to 10 using "While" Loop.
*/
#include <iostream>
using namespace std;
int main(){

	int i = 0;
	int X = 0;
	//declare variables.
	while (i <= 10)
	{
		X += i;
		i++;
		
	}
	//Calculate the sum of number from 1 to 10 by using While loop.

	cout << "Total:  " << X<< endl;
	//Show user Total after calculate the sum of numbers.

	system("Pause");
	//Please pause program.
}