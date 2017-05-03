/*
Author :Aziz Aldawk
Date :  3/30/2016
Language : C++
Purpose : This a program to determine the value of coins being deposited
from the different denomination of the coins the teller at the
bank receives.
*/
#include <iostream>
using namespace std;
void Addcoins(double quar, double dimes, double nickel, double pennies, double& process);
void FindDollars(double& amountInCents, double process1);
void FindCents(int& amountInCents, double& process2);
void OutPutResults(double& AddCoin, double& findDoller, double& findcents);
//function definition.

int main(){
	double quarters, dimes, nickel, pennies;
	double result = 0;
	double result2 = 0;
	double result3 = 0;
	double Cents;
	int Total;
	
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

	Cents = (result);
	Total = (result);

	Addcoins(quarters, dimes, nickel, pennies, result);
	//receive by function definition. 
	FindDollars(Cents, result2);
	//receive by function definition.
	FindCents(Total, result3);
	//receive by function definition.

	OutPutResults(result, result2, result3);
	//receive by function definition.

	system("pause");
	//please pause the program. 

}// Call function. 

void Addcoins(double quar, double dimes, double nickel, double pennies, double& process)
{

	process = (25 * quar + 10 * dimes + 5 * nickel + pennies);
}//function definition pass to call function.


void FindDollars(double& amountInCents, double process1)
{
	process1 = (amountInCents / 100);
}//function definition pass to call function.

void FindCents(int& amountInCents, double& process2)
{
	process2 = (amountInCents % 100);
}//function definition pass to call function.

void OutPutResults(double& AddCoin, double& findDoller, double& findcents)
{


	if ((findDoller = 0) && (AddCoin = 0))
		cout << "no coins given as input" << endl;
	else if ((findcents = 0) && (AddCoin != 0))
		cout << "Cents are: " << findcents << endl;
	else if ((findDoller != 0) && (AddCoin = 0))
		cout << "Dollars are: " << findDoller << endl;
	else
		cout << "Total dollars" << findDoller << endl;



}//function definition pass to call function.
