/*
Author :Aziz Aldawk
Date :  4/21/2016
Language : C++
Purpose :a program that calls a function to calculate the 
        sum of each column and each row of a 4 x 4 matrix 
		and store the results in another two dimensional array(4 x 2)

Problem #2
lab #12
*/
#include <iostream>
using namespace std;
void PrintMatrix(int arr[][4], int Size);
void PrintMatrix(int arr[][2], int size);
int main(){

	int arr[4][4];
	//declare varibals array. 

	for (int row = 0; row < 4; row++){
		for (int col = 0; col < 4; col++)
		{
			cout << "Please enter number row and col " << "<"<<row <<">"<< "," <<"<"<< col<<">" << endl;
			cin >> arr[row][col];
		}

		cout << endl;
	}//prompt and recieve from user by useing for loop. 

	PrintMatrix(arr, 4);
	//receive result from the user. 
	cout << endl;
	PrintMatrix(arr, 2);
	//receive result from the user. 
	system("pause");
}//end of function call. 

void PrintMatrix(int arr[][4], int Size){

	int sum = 0;
	for (int row = 0; row < Size; row++){
		for (int col = 0; col < 4; col++)
		{

			arr[row][col] = arr[row][col] + arr[row][col];
			cout << arr[row][col] << "\t";
		}
		cout << endl;
	}

	
	//calucale numbers for colmns (4 x 4)
}//end of argument function. 

void PrintMatrix(int arr[][2], int size){

	int sum = 0;
	for (int row = 0; row < size; row++){
		for (int col = 0; col < 2; col++)
		{

			arr[row][col] = arr[row][col] + arr[row][col] ;
			cout << arr[row][col] << "\t";
		}
		cout << endl;
	}

	
	//calucale numbers for colmns (4 x 2)
}//end of argument functions. 