/*
Author  :  Abdulaziz Aldawk
Date    :  1/27/2016
Language:  C++
Purpose :  To calculate total cost of apples based on
number of pounds and cost per pound

*/

#include <iostream> // used for cin, cout
#include <cstdlib>  // used for Exit_SUCCESS
using namespace std;

int main(void)
{
	double totalCostOfApples, PoundsOfApples, costPerPound;

	cout << "Welcome to Backyard Apple Growers  " << endl << endl;
	cout << "Enter the Number of pounds  : ";
	cin >> PoundsOfApples;
	cout << "Enter the Cost per Pound  :";  
	cin >> costPerPound;
	totalCostOfApples = PoundsOfApples* costPerPound;
	cout << "for "
		<< PoundsOfApples << " Pounds, the cost is : "
		<< totalCostOfApples << "\n";

	cin.get();
	cin.get();
}