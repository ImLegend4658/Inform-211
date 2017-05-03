/*
Author :Aziz Aldawk
Date :  4/14/2016
Language : C++
Purpose : a program that reads 10 numbers into an array
and then allows the user to search for a specific number.
Problem # 2
lab #11
*/

int search(const int num[], int numUesd, int numbers);
//Argument function. 
#include <iostream>
using namespace std;
int main(){

	const int SIZE = 10;
	int arr[SIZE];
	int FinalResult;
	int numbers;
	//Declare variable. 


	for (int i = 0; i < 10; i++)
	{
		cout << "Enter number " <<"<"<<i<<">"<< endl;
		//Ask user to enter 10 times. 
		cin >> arr[i];
		//receive from the user. 
	}//do for loop. 

	cout << "Please enter number that you are looking for!!" << endl;
	//Ask user to enter number, they are looking for. 
	cin >> numbers;
	//receive from the user. 

	FinalResult = search(arr, SIZE, numbers);
	//FinalResult hold variable from search argument function. 

	if (FinalResult == -1)
		cout << numbers << " sorry number not found" << endl;
	//prompt the user if number not found. 
	else
		cout << numbers << " Congratulations, you got the number at position" << FinalResult << endl;
	//prompt the user if number finally found.

	system("pause");
	//Please pause the program.
}//end of function call. 

int search(const int num[], int size, int numbers){

	int index = 0;
	bool found = false;
	//for bool tell that result is false or true. 

	while ((!found) && (index < size)){
		//do loop while. 
		if (numbers == num[index]){
			found = true;
			break;
			//if result found it will break and prompt to user.
		}
		else
			index++;
	}
	if (found)
		return index;
	//return index inside agrument function.
	else
		return -1;
	//return to function call. 

}//Argument function. 