/*
Author :Aziz Aldawk
Date :  9/3/2016
Language : C++
Purpose : This program that uses a function myRound that rounds the number read from the console
*/
#include <iostream>
#include <cmath>
//Predefined function.
using namespace std;
double round(double result);
int main(){

	double X;
	char Hey;

	do
	{
		cout << "Please enter number " << endl;
		cin >> X;
		cout << "The number rounded  is :  " << round(X)<<endl;
		//prompt and receive

		cout << "Do you want to continue?(y/n) : " << endl;
		cin >> Hey;
		//ask user if he/she wants to contnue write numbers. 
	} while (Hey == 'y' || Hey == 'Y');

	//do loop until the user has no more numbers to be computed.


	system("pause");
	//Please pause program. 

	return 0;
}


double round(double result)

{

	return static_cast<int> (floor(result + 0.5));
}


