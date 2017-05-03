/*
Author :Aziz Aldawk
Date :  2/10/2016
Language : C++
Purpose : This program will ask user to enter three numbers and
it will calcuale their sum. then, ask user to enter
guess number. after that, program will show result to user
if he/she got equal, greater, or less than sum.
*/

#include<iostream>
using namespace std;

int main()
{
	int num1, num2, num3, sum, guessnum;
	//declare variables num1,num2,num3,sum,guessnu.
	cout << "Please enter first value " << endl;  //Ask user to enter first value.
	cin >> num1;                                  //Receive from user
	cout << "Please enter second value " << endl; //Ask user to enter second value.
	cin >> num2;                                 //Receive from user. 
	cout << "Please enter third value " << endl; //Ask user to enter third vale.
	cin >> num3;                                 //Receive from user. 
	cout << "Please enter your guess value number" << endl;
	//Ask user to enter guess value number. 
	cin >> guessnum;
	//Receive from user. 
	sum = (num1 + num2 + num3);               //calculate sum with num1, num2 and num3

	if (guessnum > sum)
		//Show and give result user If the guess value is greater than sum. 
	{
		cout << "You overestimated the sum" << endl;
	}
	else if (guessnum < sum)
		//Show and give result user If the guess value is less than sum. 
	{
		cout << "You underestimated the sum" << endl;

	}
	else if (guessnum == sum)
		//Show and give result user If the guess value is equal than sum.
	{
		cout << "Congratulations! You guessed correctly" << endl;
	}

	system("pause");       //Please pause program. 
}