/*
Author :Aziz Aldawk
Date :  4/21/2016
Language : C++
Purpose : a program to read a 2D array of 5 rows and 
          3 columns and convert the 2D array into 
		   1D array by column.
Problem #3
lab #12
*/


#include <iostream>
using namespace std;
void TwoD(int arr[][3],int size);
void oneD(int arr[][3], int size);
int main(){

	int arr[5][3];
	//declare varibales. 

	for (int row = 0; row < 5; row++){
		for (int col = 0; col < 3; col++)
		{

			cout << "please enter numbers" << row << "," << col << endl;
			cin >> arr[row][col];
		}
		cout << endl;
	}//do loop for array
	//prompt and recieve from user. 


	TwoD(arr, 3);
	//recieve from argument function. 
	oneD(arr, 3);
	//receieve from argument function and convert it from 2D to 1D. 
	system("pause");
	//please pause program. 

	}//end of function call. 

void TwoD(int arr[][3], int size){

	for (int row = 0; row < size; row++){
		for (int col = 0; col < 3; col++){

			cout << arr[row][col] << "\t";

		}
		cout << endl;
	}
}//end of argument function. 

void oneD(int arr[][3], int size){

	int sum = 0;

	for (int row = 0; row < size; row++){

		for (int col = 0; col < 3; col++){

			sum+=arr[row][col];

		}
	}

	cout << "1D --> " << sum << endl;
}//end of argument function.