/*
Author :Aziz Aldawk
Date :  2/3/2016
Language : C++
Purpose : Program will Convert height of a person that is read from
          feet and inches to cm. 
*/

#include<iostream>
using namespace std;

int main()
{
	double feet, inches, CM;            //declare variables feet, inches, CM

	cout << "Enter your feet \n";      //Ask user to enter feet
	cin >> feet;                       //prompt and receive
	feet = feet * 12;                  //calculate feet with 12 

	cout << "Enter your inches \n";   //Ask user to enter inches.
	cin >> inches;                    //prompt and receive
	CM = inches+feet;                 //calculate inches with feet. 
	inches = inches*2.54;             //calculate inches with 2.54

	cout << "The highest in cm is: " << CM << endl;
	//print out the result that convert feet and inches to centimeters.
	system("pause");
	//Please pause program. 
	return 0;
}
