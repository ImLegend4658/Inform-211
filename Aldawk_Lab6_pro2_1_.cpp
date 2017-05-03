/*
Author :Aziz Aldawk
Date :  2/24/2016
Language : C++
Purpose : This program to calculate the sum of number 
           from 1 to 10 using "for" Loop.
*/

#include <iostream>
using namespace std;
int main(){

	int i;
	int X=0;
	//declare variables.

	for (i = 0; i <= 10; i++)
	{
		X += i;
	}
	//Calculate the sum of number from 1 to 10 by using loop.
	
	cout << "Total: " <<X<< endl;
	//Show user result after calculate the sum of numbers. 
	
	system("pause");
	//Please pause program. 
}