/*
Author :Aziz Aldawk
Date :  4/21/2016
Language : C++
Purpose : a program to transpose the rows into columns and columns 
          into rows for a square matrix of size 4 x 4
Problem #4
lab #12
*/
#include <iostream>
using namespace std;
int main(){

	int arr[4][4];
	int convert;
	//declare variables. 

	for (int row = 0; row < 4; row++){
		for (int col = 0; col < 4; col++){

			cout << "Please enter number twice" <<"<"<<row<<">"<<","<<"<"<<col<<">"<< endl;
			cin >> arr[row][col];
		}
		cout << endl;
	}//ask user to enter number twice.


	for (int row = 0; row < 4; row++){
		for (int col = 0; col < 4; col++){

			cout << arr[row][col] << "\t";
		}
		cout << endl;
	}//prompt the numbers have enterd by user. 
	
	cout << endl;


	for (int row = 0; row < 4; row++){
		for (int col = 0; col < 4; col++){

			convert = arr[row][col];
			arr[row][col] = arr[col][row];
			arr[col][row] = convert;
			
			cout << arr[col][row] << "\t";
		}

		cout << endl;

	}//prompt numbers but this time it converted row to columns and columns to rows.

	system("pause");
	//please pause program. 
}