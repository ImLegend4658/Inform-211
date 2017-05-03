/*
Author :Aziz Aldawk
Date :  3/23/2016
Language : C++
Purpose : This a program that calls a function to 
           compute the grade when the user inputs a score
*/

#include <iostream>
using namespace std;

int calculateGrades(int& firstnum);
//function definition.
int main(){

	int Score;
	//declare Varibales. 

	cout << "Please enter your grade" << endl;
	cin >> Score;
	//Prompt and receive from the user. 

	calculateGrades(Score);
	cout << "your grade is: " << calculateGrades(Score) << endl;
	//Receive result from function definition. 

	system("Pause");
	//Please pause program. 

}//Call funcation. 

int calculateGrades(int& firstnum){

	switch (firstnum / 10)
		//show user result what he/she got of grade.
	{

	case 10:
	case 9:
		cout << "you got an A \n";
		break;
	case 8:
		cout << "you got a B \n";
		break;
	case 7:
		cout << "you got a C \n";
		break;
	case 6:
		cout << "you got a D \n";
		break;
	case 5:
		cout << "you got an F \n";
		break;
	}
	return firstnum;
}//function definition pass to call function.