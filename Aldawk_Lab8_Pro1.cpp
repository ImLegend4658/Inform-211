/*
Author :Aziz Aldawk
Date :  3/23/2016
Language : C++
Purpose : This a program to determine the value of coins being deposited
from the different denomination of the coins the teller at the
bank receives.
*/
#include <iostream>
using namespace std;
void amountInCents(double quar, double dimes, double nickel, double pennies, double& process);
void amountInDoller(double amountInCents, double& process1);
void totalInCents(int amountInCents, double& process2);
//function definition.

int main(){
	double quarters, dimes, nickel, pennies;
	double result = 0, result2 = 0, result3 = 0;
	double Cents = 0;
	int Total = 0;
	double Z, G;
	int R;
	double MM, SS;
	//declare variables 

	cout << "Please enter quarters number: ";
	cin >> quarters;
	cout << endl;
	cout << "Please enter dimes number: ";
	cin >> dimes;
	cout << endl;
	cout << "Please enter nickel: ";
	cin >> nickel;
	cout << endl;
	cout << "Please enter Pennies number: ";
	cin >> pennies;
	cout << endl;
	//prompt and receive from user.

	amountInCents(quarters, dimes, nickel, pennies, result);
	//receive by function definition. 
	amountInDoller(Cents, result2);

	//receive by function definition.
	totalInCents(Total, result3);
	//receive by function definition.
	
	cout << "Amount in doller is:  " <<result2<<". "<<result3 <<endl;

	//receive by function definition.

	system("pause");
	//please pause the program. 

}// Call function. 

void amountInCents(double quar, double dimes, double nickel, double pennies, double& process)
{

	process = (25 * quar + 10 * dimes + 5 * nickel + pennies);
}//function definition pass to call function.


void amountInDoller(double amountInCents, double& process1)
{
	process1 = (amountInCents / 100);
}//function definition pass to call function.

void totalInCents(int amountInCents, double& process2)
{
	process2 = (amountInCents % 100);
}//function definition pass to call function.

