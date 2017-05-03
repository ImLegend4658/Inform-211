/*
Author :Aziz Aldawk
Date :  2/3/2016
Language : C++
Purpose : This program will Compute the values of the following expression after reading 
          in the values of x and y. Program will ask the user to input value X and Y, 
*/

#include<iostream>
using namespace std;

int main()
{ 
	double X, Y, Total1, Total2;                               // declare variable X, Y, Total1 and Total2

	cout << "Please enter value X: " << endl;                  //Ask user to value enter value X
	cin >> X;									               //prompt and receive 
	X = 3 * X;                                                 //calculate value X 
	cout << "Value X is: " << X << endl;                       //Print out value X.

	cout << "Please enter value Y : " << endl;                 //Ask user to value enter value Y
	cin >> Y;                                                  //prompt and receive 
	Y = 3 * X + Y;                                            //calculate value Y
	cout << "The value Y is: " << Y << endl;                  //Print out value Y

	cout << "Please enter value for total 1: " << endl;       //Ask user to value enter for Total 1
	cin >> Total1;										      //Prompt and receive
	Total1 = (X + Y) / 2;								      //Calculate value X and Y
	cout << "The value for total 1 is: " << Total1 << endl;   //Print out Total 1

	cout << "Please enter value for total 2: " << endl;       //Ask user to value enter for Total 2
	cin >> Total2;										      //Prompt and receive
	Total2 = 3 * X + 7 * Y;                                   //Calculate value X and Y
	cout << "The value for total 2 is: " << Total2 << endl;   //Print out Total 2


	system("pause");										  //Pause program
}

