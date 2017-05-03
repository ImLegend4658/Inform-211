/*
Author :Aziz Aldawk
Date :  3/10/2016
Language : C++
Purpose : This program to read in three numbers from the console and
          uses a function that returns the largest of the three numbers
*/

#include<iostream>
using namespace std;

int printLargest(int  x);
int main()
{
	int num1, num2, num3, max;               //declare variable num1, num2, num3, max.

	cout << "Please enter value 1" << endl; //Ask user to enter first number is value. 
	cin >> num1;                            //receive from user.
	cout << "please enter value 2" << endl;
	// Ask user to enter second number is value.
	cin >> num2;                            //receive from user.
	cout << "Please enter value 3" << endl; //Ask user to enter third number is value.
	cin >> num3;                            //receive from user.

	cout << "The largest number is: " << printLargest(num3) << endl;
	//Show resutl and largest number to user.

	system("Pause");                             //Please pause the program.
}
int printLargest(int x)
{
	int max1, num1, num22, num33;
	max1 = num1;
	if (num22> max1)
		max1 = num22;
	if (num33 > max1)
		max1 = num33;

	return 0;

}