/*
Author :Aziz Aldawk
Date :  2/24/2016
Language : C++
Purpose : This program calculate the sum of odd numbers from 1 to 100
*/

#include <iostream>
using namespace std;
int main(){

	int X = 0;
	int I;
	//declare variables

	for (I = 1; I <= 100;I++)
	{

		if (I % 2 ==1)
		{
			X += I;
		}
		
	}
	 // calculate the sum of odd numbers from 1 to 100 by loop. 

	cout << "Total:  " << X << endl;
	//show uesr what is result. 
	system("Pause");
	//please pause program.
	
}