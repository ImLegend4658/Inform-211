#include <iostream>
#include <cstdlib>
using namespace std; 
/*
name: Aziz Aldawk
Date: 1/26/2017
Homework #1
purpose: a program will fill an array with 1000 random
         numbers and to print the average of the numbers
		 in that array. 
*/
void randary(int ary[], int arylength);
int averageary(int ary[], int arylength);
// Function declaration. 
int main(){

	int const arylength = 1000; 
	int ary[arylength];
	int result;
	//Declare varibles. 

	randary(ary, arylength);
	result = averageary(ary, arylength);
	// function call.
	cout << "The average is: " << result << endl; 
	// it shows the resutl the average of the number in the array.

//	system("pause"); // Please pause the program.
}// End of main.

/*==================================================
purpose of the Randary function:
It fills an array with 1000 random numbers.

===================================================*/

void randary(int ary[], int arylength){

	for (int i = 0; i < arylength; i++){

		ary[i] = rand()% 50 ;
	}
}

/*==================================================
purpose of the averageary function:
it will print the average of the numbers 
in that array.
===================================================*/
int averageary(int ary[], int arylength){
	
	int average; 
	int sum= 0;

	for (int i = 0; i < arylength; i++){

		sum += ary[i];

	}
	average = sum / arylength;

	return average;
}
