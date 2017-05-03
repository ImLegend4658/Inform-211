/*
Author :Aziz Aldawk
Date :  3/30/2016
Language : C++
Purpose : This a program to reads in two numbers from
the console and uses a function output the larger of the two numbers
*/

#include <iostream>
using namespace std;

void FindMAX(int number, int number2, int& MAX);
void PrindMax(int& FinalResult);
//Argument function. 
int main(){


	int num1, num2;
	int Max;
	//Declare variables. 

	cout << "Please enter number twice to find the larger number" << endl;
	cin >> num1;
	cin >> num2;
	//prompt and receive from user. 

	FindMAX(num1, num2, Max);
	PrindMax(Max);
	//Receive from argument function. 

	system("Pause");
	//Please pause program.
}//end of call function. 

void FindMAX(int number, int number2, int& MAX)
{

	MAX = number;
	if (number2 > MAX)
		MAX = number2;
	//find largest number. 

}//argument function. 

void PrindMax(int& FinalResult){

	cout << "The largest number is: " << FinalResult << endl;
	//show user the largest number. 
}//argument function.