/*
Author :Aziz Aldawk
Date :  3/30/2016
Language : C++
Purpose : This a program to determine if a number
read in main from the console is a prime using
a call to a void function
*/
#include <iostream>
using namespace std;

void ThePrime(int Num);

int main(){

	int Num;
	int NM;
	//declare variables.

	cout << "Please enter number to find prime" << endl;
	cin >> Num;
	//prompt and receive from user. 


	ThePrime(Num);
	//receive from argument function. 

	system("pause");
	//please pause program. 

}//end call function. 

void ThePrime(int Num){

	int i;
	//declare variable. 


	if (Num % 2)
		cout << " it is prime " << endl;
	else
		cout << "  sorry is not prime " << endl;

	//show user if number is prime or not. 

}// end argument function. 