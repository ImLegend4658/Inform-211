/*
Author :Aziz Aldawk
Date :  2/17/2016
Language : C++
Purpose : this a program Construct a logical expression to represent 
          each of the following conditions by reading a value for the variable 
		  being used in the condition
*/

#include <iostream>
using namespace std;

int main(){

	int score;
	char a1 = 'a';
	char a2 = 'b';
	char G = (0,1,2,3,4,5,6,7);
	char n1 = 'W';
	char n2 = 'Z';
	char Z = (0, 1, 2, 3, 4, 5, 6, 7);
	char N3;
	//Declare variables

	cout << "Please enter your score \n";
	cin >> score;
	//prompt and receive from user. 
	if ((score >= 80) && (score <90)) {
		cout << "Condition for is true" << endl;
	}
	else {
		cout << "Condition for is false" << endl;
	}
	//see if score is greater than or equal to 80 but less than 90

	cout << "Please enter one char \n";
	cin >> a1;
	//prompt and receive from user.

	if ((a1 == 'N') || (a1 == 'n'))
	{
		cout << "Condition for is true" << endl;
	}
	else
	{
		cout << "Condition for is false" << endl;
	}
	//see if answer's user is either ‘N’ or ‘n’

	cout << "Please enter one char \n";
	cin >> a2;
	//prompt and receive from user.

	if ((a2 == 'b') && !(a2= 8))
	{
		cout << "Condition for is true" << endl; 
	} 
	else{

		cout << "Condition for is false" << endl;
	}
	//show result if n is even but not 8
	cout << "Please enter one char here:  \n";
	cin >> n1;
	//prompt and receive from user.

	if ((n1 == G) != (n1 = 3))
	{
		cout << "Condition for is true" << endl;
	}
	else
	{
		cout << "Condition for is false" << endl;
	}
	//Show result if n is between 0 and 7 but not equal to 3. 

	cout << "Please enter one char here: " << endl;
	cin >> n2;
	//prompt and receive from user.

	if ((n2 == Z) != (n2 == 'Z'))
	{
		cout << "Condition for is true" << endl;
	}
	else
	{
		cout << "Condition for is false" << endl;
	}
	//Show result if n is between 0 and 7 but not even

	cout << "Please enter one char here: " << endl;
	cin >> N3;
	//prompt and receive from user.

	if ((N3 / 3) != (N3 / 30))
	{
		cout << "Condition for is true" << endl;
	}
	else
	{
		cout << "Condition for is false" << endl;
	}
	//show result if n is divisible by 3 but not by 30

	system("pause");
	//Please pause program. 
}