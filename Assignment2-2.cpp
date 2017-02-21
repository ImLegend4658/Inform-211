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

The last name is:  Aldawk 1
ID Number is: 127
The last name is:  Aldawk 2
ID Number is: 176
The last name is:  Aldawk 3
ID Number is: 207
The last name is:  Aldawk 4
ID Number is: 353
The last name is:  Aldawk 5
ID Number is: 435
The last name is:  Aldawk 6
ID Number is: 536
The last name is:  Aldawk 7
ID Number is: 695
The last name is:  Aldawk 8
ID Number is: 777
The last name is:  Aldawk 9
ID Number is: 804
The last name is:  Aldawk 10
ID Number is: 893
The last name is:  Aldawk 11
ID Number is: 1742
The last name is:  Aldawk 12
ID Number is: 1917
The last name is:  Aldawk 13
ID Number is: 2023
The last name is:  Aldawk 14
ID Number is: 2371
The last name is:  Aldawk 15
ID Number is: 3660
The last name is:  Aldawk 16
ID Number is: 3765
The last name is:  Aldawk 17
ID Number is: 4183
The last name is:  Aldawk 18
ID Number is: 4534
The last name is:  Aldawk 19
ID Number is: 5147
The last name is:  Aldawk 20
ID Number is: 5397
The last name is:  Aldawk 21
ID Number is: 5570
The last name is:  Aldawk 22
ID Number is: 5894
The last name is:  Aldawk 23
ID Number is: 6152
The last name is:  Aldawk 24
ID Number is: 6482
The last name is:  Aldawk 25
ID Number is: 6884
The last name is:  Aldawk 26
ID Number is: 7018
The last name is:  Aldawk 27
ID Number is: 7395
The last name is:  Aldawk 28
ID Number is: 7723
The last name is:  Aldawk 29
ID Number is: 7868
The last name is:  Aldawk 30
ID Number is: 8183
The last name is:  Aldawk 31
ID Number is: 8498
The last name is:  Aldawk 32
ID Number is: 8655
The last name is:  Aldawk 33
ID Number is: 8964
The last name is:  Aldawk 34
ID Number is: 9044
The last name is:  Aldawk 35
ID Number is: 9075
The last name is:  Aldawk 36
ID Number is: 9352
The last name is:  Aldawk 37
ID Number is: 9603
The last name is:  Aldawk 38
ID Number is: 9645
The last name is:  Aldawk 39
ID Number is: 10039
The last name is:  Aldawk 40
ID Number is: 10087
The last name is:  Aldawk 41
ID Number is: 11491
The last name is:  Aldawk 42
ID Number is: 11601
The last name is:  Aldawk 43
ID Number is: 11675
The last name is:  Aldawk 44
ID Number is: 11881
The last name is:  Aldawk 45
ID Number is: 12234
The last name is:  Aldawk 46
ID Number is: 12744
The last name is:  Aldawk 47
ID Number is: 13763
The last name is:  Aldawk 48
ID Number is: 13950
The last name is:  Aldawk 49
ID Number is: 14272
The last name is:  Aldawk 50
ID Number is: 14433
The last name is:  Aldawk 51
ID Number is: 14945
The last name is:  Aldawk 52
ID Number is: 14952
The last name is:  Aldawk 53
ID Number is: 15221
The last name is:  Aldawk 54
ID Number is: 15952
The last name is:  Aldawk 55
ID Number is: 16294
The last name is:  Aldawk 56
ID Number is: 16913
The last name is:  Aldawk 57
ID Number is: 17560
The last name is:  Aldawk 58
ID Number is: 17726
The last name is:  Aldawk 59
ID Number is: 18024
The last name is:  Aldawk 60
ID Number is: 18441
The last name is:  Aldawk 61
ID Number is: 19206
The last name is:  Aldawk 62
ID Number is: 19385
The last name is:  Aldawk 63
ID Number is: 19791
The last name is:  Aldawk 64
ID Number is: 19858
The last name is:  Aldawk 65
ID Number is: 19958
The last name is:  Aldawk 66
ID Number is: 20183
The last name is:  Aldawk 67
ID Number is: 20341
The last name is:  Aldawk 68
ID Number is: 21235
The last name is:  Aldawk 69
ID Number is: 21560
The last name is:  Aldawk 70
ID Number is: 21662
The last name is:  Aldawk 71
ID Number is: 21707
The last name is:  Aldawk 72
ID Number is: 21770
The last name is:  Aldawk 73
ID Number is: 22973
The last name is:  Aldawk 74
ID Number is: 23054
The last name is:  Aldawk 75
ID Number is: 23481
The last name is:  Aldawk 76
ID Number is: 23566
The last name is:  Aldawk 77
ID Number is: 24386
The last name is:  Aldawk 78
ID Number is: 25069
The last name is:  Aldawk 79
ID Number is: 25535
The last name is:  Aldawk 80
ID Number is: 26482
The last name is:  Aldawk 81
ID Number is: 26640
The last name is:  Aldawk 82
ID Number is: 26640
The last name is:  Aldawk 83
ID Number is: 26939
The last name is:  Aldawk 84
ID Number is: 27201
The last name is:  Aldawk 85
ID Number is: 28051
The last name is:  Aldawk 86
ID Number is: 28228
The last name is:  Aldawk 87
ID Number is: 28552
The last name is:  Aldawk 88
ID Number is: 28686
The last name is:  Aldawk 89
ID Number is: 28818
The last name is:  Aldawk 90
ID Number is: 28855
The last name is:  Aldawk 91
ID Number is: 29152
The last name is:  Aldawk 92
ID Number is: 29396
The last name is:  Aldawk 93
ID Number is: 29770
The last name is:  Aldawk 94
ID Number is: 30159
The last name is:  Aldawk 95
ID Number is: 30242
The last name is:  Aldawk 96
ID Number is: 30578
The last name is:  Aldawk 97
ID Number is: 31785
The last name is:  Aldawk 98
ID Number is: 31802
The last name is:  Aldawk 99
ID Number is: 31960
The last name is:  Aldawk 100
ID Number is: 32570
Please enter ID number you want to search!! (enter 0 to quit)
158
This ID number: 158 was not found
Please enter ID number you want to search!! (enter 0 to quit)
3257
This ID number: 3257 was not found
Please enter ID number you want to search!! (enter 0 to quit)
32570
The location is: 100
This ID number: 32570 was found
Please enter ID number you want to search!! (enter 0 to quit)
7018
The location is: 26
This ID number: 7018 was found
Please enter ID number you want to search!! (enter 0 to quit)
207
The location is: 3
This ID number: 207 was found
Please enter ID number you want to search!! (enter 0 to quit)
17726
The location is: 58
This ID number: 17726 was found
Please enter ID number you want to search!! (enter 0 to quit)
258
This ID number: 258 was not found
Please enter ID number you want to search!! (enter 0 to quit)
100
This ID number: 100 was not found
Please enter ID number you want to search!! (enter 0 to quit)
87
This ID number: 87 was not found
Please enter ID number you want to search!! (enter 0 to quit)
52
This ID number: 52 was not found
Please enter ID number you want to search!! (enter 0 to quit)
51
This ID number: 51 was not found
Please enter ID number you want to search!! (enter 0 to quit)
48
This ID number: 48 was not found
Please enter ID number you want to search!! (enter 0 to quit)
127
The location is: 1
This ID number: 127 was found
Please enter ID number you want to search!! (enter 0 to quit)
695
The location is: 7
This ID number: 695 was found
Please enter ID number you want to search!! (enter 0 to quit)
0
Press any key to continue . . .





