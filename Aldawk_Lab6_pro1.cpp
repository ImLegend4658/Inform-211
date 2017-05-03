/*
Author :Aziz Aldawk
Date :  2/24/2016
Language : C++
Purpose : This program  read numbers from the user 
          and calculate the sum of the numbers until the user inputs 
		  a negative number.
*/
#include <iostream>
using namespace std;
int main(){

	int count = 0;
	//declare variable.
	cout << "Please enter number \n";
	cin >> count;
	//prompt and receive from user

	while (count > 0)
	{
		count++;
		cout << "Please enter number again \n";
		cin >> count;
	}
	//Ask user to enter numbers untile user enter 
	//negative number than program will stop. 

	return 0;

	system("pause");
	//Please pause program. 
}