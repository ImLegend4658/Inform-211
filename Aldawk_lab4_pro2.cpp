/*
Author :Aziz Aldawk
Date :  2/10/2016
Language : C++
Purpose : This program about program to determine the value of coins being deposited 
         from the different denomination of the coins that the teller at the bank receives
		 quarters, dimes, nickel and pennies.
*/

#include<iostream>
using namespace std;

int main()
{

	double quarters, dimes, nickel, pennies, Total2, Dollars;  
	//declare variables
	int Totalcent;
	//declare variable

	cout << "Please enter quarters number: ";        //Ask user to enter quarters coins.
	cin >> quarters;                                //Receive from user. 
	cout << endl;                                   //New line.
	cout << "Please enter dimes number: ";          //Ask user to enter dimes coins.
	cin >> dimes;                                   //Receive from user.
	cout << endl;                                   //New line.
	cout << "Please enter nickel number: ";        //Ask user to enter nickel coins.
	cin >> nickel;                                 //Receive from user. 
	cout << endl;                                  //New line.
	cout << "Please enter pennies: ";              //Ask user to enter pennies coins. 
	cin >> pennies;                                //Receive from user.
	cout << endl;                                 //New line.

	Totalcent = (25 * quarters + 10 * dimes + 5 * nickel + pennies);

	Dollars = (Totalcent / 100);

	Total2 = (Totalcent % 100);
	//calculate coins and convert it to dollars and total.  
	cout << " Dollars are: " << Dollars << " and Totlal is: " << Total2<<endl;
	//Show user result totals and dollars. 

	system("Pause");                           //Please pause program.
}
