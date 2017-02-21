#include <iostream>
#include <time.h> 
using namespace std;
/*
name: Aziz Aldawk
Date: 2/9/2017
Homework #2
purpose: This program will contains a structure with
         ID number, first and last name. Also, do 
		 binary search ID was found or not. 
*/
struct MyID
{
	char  FirstName[40]; //Lenght of char that can hold string.
	char LastName[40];  //Lenght of char that can hold string.
	int IdNumber;
};

void InitializeArray(MyID IDNumber[], int Size);
void SortTheArray(MyID IDNumber[], int Size);
int BinarySearch(MyID IDNumber[], int Size, int target);
//Function declaration. 

/*==========================================================
In the main:
  prupose: First and last name inside the loop  that repeat the same
  name everytime. Also, in this case, without 
  ask user to enter their name everytime. 

  Three call functions inside the main. 
===========================================================*/
int main(){
	// declare Size for array. 
	const int Size = 100;
	//Declare varible for structer. 
	MyID IDNumber[Size];
	//declare varibles
	int result; 
	int target=0;
	int num = 0;

	//make copy of first and last name many times. 
	for (int i = 0; i < Size; i++){
		strcpy_s(IDNumber[i].FirstName, "Aziz");
		strcpy_s(IDNumber[i].LastName, "Aldawk");
	}	
	//Function call
	InitializeArray(IDNumber, Size);
	SortTheArray(IDNumber, Size);

	do{// ask user to enter the ID number, that she/he wants to search it. 
		cout << "Please enter ID number you want to search!! (enter 0 to quit)" << endl;
		cin >> target;
		if (target > 0) {
			result = BinarySearch(IDNumber, Size, target);

			if (result <= 0)
				cout << "This ID number: " << target << " was not found" << endl;
			else
				cout << "This ID number: " << target << " was found " << endl;
		}
	} while (target !=0);

	system("pause"); // Please pause the program. 
}// end of the main.

/*========================================================
prupose of the Initialize Array:
ID Number: must be none zero and give random number of 4 digits:

First, and last name: must be repeaition with display
				     the number who many times.

==========================================================*/
void InitializeArray(MyID IDNumber[], int Size){
	srand(time(0)); //access to time that change rand every second..

	for (int i = 0; i < Size; i++){
		IDNumber[i].FirstName;
	    IDNumber[i].LastName;	
		IDNumber[i].IdNumber = rand() ;
	}
}
/*===========================================================
The prupose of sort array: sort is swap the values to
to make order numbers.
before sorting: 
9 8 6 4 3 1 0
after sorting number, should be:
0 1 3 4 6 8 9
============================================================*/
void SortTheArray(MyID IDNumber[], int Size){

	int Swap = 0;   // to hold variable for swap values;
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size - 1; j++)
		{
			if (IDNumber[j].IdNumber > IDNumber[j + 1].IdNumber)
			{
				MyID Swap = IDNumber[j];
				IDNumber[j] = IDNumber[j+1];
				IDNumber[j+1] = Swap;
			} // Swap values to make order numbers. 
		}// end inner for loop. 

	}// end outer for loop.

	for (int i = 0; i < Size; i++)
	{		
		//cout << IDNumber[i].FirstName << " ";
		cout <<  "The last name is:  "<< IDNumber[i].LastName <<" "<< i + 1 << endl;
		cout << "ID Number is: "<< IDNumber[i].IdNumber << endl;
	}
}  
/*===============================================
The prupose of binary search
It takes the sorted array and do a binary search
for an ID in the array. Return the index to 
thestructure element or, an indicator that
the ID was not found.
=================================================*/
int BinarySearch(MyID IDNumber[], int Size, int target){

	int first = 0; 
	int last = Size - 1;
	int midd;

	midd = (first + last) / 2;

	while (first <= last){
		if (IDNumber[midd].IdNumber < target)
		{
			first = midd + 1;
		}
		else if (IDNumber[midd].IdNumber == target)
		{
			cout << "The location is: " << midd+1 << endl; 
			return 1; // if number found. i will return to 
			          // user the number is found.
		}
		else
		{
			last = midd - 1;
		}
		midd = (first + last) / 2;
	}
	if (first > last)
	{
	return 0; // if number was not found. it will return to 
	          // user that number was not found.
	}
}
