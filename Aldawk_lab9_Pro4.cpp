/*
Author :Aziz Aldawk
Date :  3/30/2016
Language : C++
Purpose : this a program to calculate the permutation
of n objects taken r at a time using a void function.
*/

void Permutation(int num);

#include <iostream>
using namespace std;
int main(){

	int num;
	//declare variables. 

	cout << "Please enter number" << endl;
	cin >> num;
	//prompt and receive from user. 

	Permutation(num);
	//receive from argument function. 

	system("pause");
	//please pause program.

}//end of call function. 

void Permutation(int num){//the beginning of argument function.

	int max = 1;
	int Min = 1;
	//declare variables. 

	while (max < num)
	{
		max++;
		Min = Min*max;
	}//Loop.

	cout << "number is: " << Min << endl;
	//Show result to user. 

}//end of argument function. 