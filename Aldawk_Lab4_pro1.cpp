/*
Author :Aziz Aldawk
Date :  2/10/2016
Language : C++
Purpose : This program about reading in three numbers from 
          the console and output the largest of the three numbers.
*/

#include<iostream>
using namespace std;

int main()
{
	int num1, num2, num3, max;               //declare variable num1, num2, num3, max.

	cout << "Please enter value 1" << endl; //Ask user to enter first number is value. 
	cin >> num1;                            //receive from user.
	cout << "please enter value 2" << endl; // Ask user to enter second number is value.
	cin >> num2;                            //receive from user.
	cout << "Please enter value 3" << endl; //Ask user to enter third number is value.
	cin >> num3;                            //receive from user.


	max = num1;                             //calculate and find the largest number. 
	if (num2> max)
		max = num2;
	if (num3 > max)
		max = num3;

	cout << "The largest number is: " << max << endl; //Show resutl and largest number to user.

	system("Pause");                             //Please pause the program.
}
