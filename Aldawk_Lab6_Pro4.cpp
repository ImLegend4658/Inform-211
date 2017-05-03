/*
Author :Aziz Aldawk
Date :  2/24/2016
Language : C++
Purpose : This a program to print the multiplication table up to 10 for any numbers.

*/
#include <iostream>
using namespace std;
int main(){

	int num;
	int y = 1;
	int Result;
	const int Mult = 5;
	//declare variables

	for (num = 1; num <= 10; num++)
	{
		Result = (Mult*num);
		cout << " 5 " << "*" << " " << y++ << " = " << Result << endl;
		//will show user result every number multiplied with. 
	}
	//loop, everytimes program print multiply with.
	// it will print out result. 

	system("Pause");
	//Please pause program. 
}