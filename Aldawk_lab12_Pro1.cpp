/*
Author :Aziz Aldawk
Date :  4/21/2016
Language : C++
Purpose : a program that calls a function to increment the elements
of a user desired column in a two dimensional array by a desired amount..
Problem #1
lab #12
*/
#include <iostream>
using namespace std;

void prinMatrix(int arr[][4], int SIZE);
int main(){

	int array2D[4][4];
	//declare varibals. 

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++){
			cout << "Please enter number" << row << "," << col << endl;
			cin >> array2D[row][col];
		}
		cout << endl;
	}
	//ask user has to enter number everytimes. 

	for (int i = 0; i < 4; i++){
		for (int Z = 0; Z < 4; Z++){
			cout << array2D[i][Z] << "\t";

		}
		cout << " " << endl;
	}// doing array until show up result. 

	cout << endl;

	prinMatrix(array2D, 4);
	//recieve from function argument. 


	system("pause");
	//please pause program. 
}
//end of function call. 
void prinMatrix(int arr[][4], int SIZE)
{
	int incCol = 2, value = 0;

	for (int row = 0; row< SIZE; row++)
	{


		arr[row][incCol] = arr[row][incCol] + value;

		cout << arr[row][incCol] << '\t' << endl;

	}//increment the elements of a user desired column.
	cout << endl;
}
//end of function arguments.
