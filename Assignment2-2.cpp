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

ID Number is: 19506
The last name is:  Aldawk 57
ID Number is: 19975
The last name is:  Aldawk 58
ID Number is: 20060
The last name is:  Aldawk 59
ID Number is: 20237
The last name is:  Aldawk 60
ID Number is: 20801
The last name is:  Aldawk 61
ID Number is: 20830
The last name is:  Aldawk 62
ID Number is: 21610
The last name is:  Aldawk 63
ID Number is: 21953
The last name is:  Aldawk 64
ID Number is: 22689
The last name is:  Aldawk 65
ID Number is: 23337
The last name is:  Aldawk 66
ID Number is: 23420
The last name is:  Aldawk 67
ID Number is: 23671
The last name is:  Aldawk 68
ID Number is: 23693
The last name is:  Aldawk 69
ID Number is: 24038
The last name is:  Aldawk 70
ID Number is: 24132
The last name is:  Aldawk 71
ID Number is: 25075
The last name is:  Aldawk 72
ID Number is: 25388
The last name is:  Aldawk 73
ID Number is: 25453
The last name is:  Aldawk 74
ID Number is: 26113
The last name is:  Aldawk 75
ID Number is: 27226
The last name is:  Aldawk 76
ID Number is: 27375
The last name is:  Aldawk 77
ID Number is: 27411
The last name is:  Aldawk 78
ID Number is: 27804
The last name is:  Aldawk 79
ID Number is: 27977
The last name is:  Aldawk 80
ID Number is: 28051
The last name is:  Aldawk 81
ID Number is: 28158
The last name is:  Aldawk 82
ID Number is: 28381
The last name is:  Aldawk 83
ID Number is: 28517
The last name is:  Aldawk 84
ID Number is: 28646
The last name is:  Aldawk 85
ID Number is: 28741
The last name is:  Aldawk 86
ID Number is: 28809
The last name is:  Aldawk 87
ID Number is: 28949
The last name is:  Aldawk 88
ID Number is: 29333
The last name is:  Aldawk 89
ID Number is: 29361
The last name is:  Aldawk 90
ID Number is: 29636
The last name is:  Aldawk 91
ID Number is: 29641
The last name is:  Aldawk 92
ID Number is: 30100
The last name is:  Aldawk 93
ID Number is: 30733
The last name is:  Aldawk 94
ID Number is: 30854
The last name is:  Aldawk 95
ID Number is: 31164
The last name is:  Aldawk 96
ID Number is: 31311
The last name is:  Aldawk 97
ID Number is: 31614
The last name is:  Aldawk 98
ID Number is: 31986
The last name is:  Aldawk 99
ID Number is: 32381
The last name is:  Aldawk 100
ID Number is: 32583
Please enter ID number you want to search!! (enter 0 to quit)
802
This ID number: 802 was not found
Please enter ID number you want to search!! (enter 0 to quit)
502
The location is: 2
This ID number: 502 was found
Please enter ID number you want to search!! (enter 0 to quit)
11503
The location is: 29
This ID number: 11503 was found
Please enter ID number you want to search!! (enter 0 to quit)
11283
This ID number: 11283 was not found
Please enter ID number you want to search!! (enter 0 to quit)
31311
The location is: 96
This ID number: 31311 was found
Please enter ID number you want to search!! (enter 0 to quit)
32583
The location is: 100
This ID number: 32583 was found
Please enter ID number you want to search!! (enter 0 to quit)
17168
The location is: 49
This ID number: 17168 was found
Please enter ID number you want to search!! (enter 0 to quit)
58
This ID number: 58 was not found
Please enter ID number you want to search!! (enter 0 to quit)
1356
This ID number: 1356 was not found
Please enter ID number you want to search!! (enter 0 to quit)
4747
This ID number: 4747 was not found
Please enter ID number you want to search!! (enter 0 to quit)
11111
This ID number: 11111 was not found
Please enter ID number you want to search!! (enter 0 to quit)
0
Press any key to continue . . .







