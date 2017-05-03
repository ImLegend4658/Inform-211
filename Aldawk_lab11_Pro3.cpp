/*
Author :Aziz Aldawk
Date :  4/14/2016
Language : C++
Purpose : a program to calculate the variance and standard
          deviation of 15 numbers read from the console.
Problem # 3
lab #11
*/
#include <iostream>
using namespace std;

double findMean(int num[], int SIZE);
double findVar(int num[], double mean, int SIZE);
//agrument functions. 
int main(){

	const int SIZE = 15;
	int num[SIZE];
	double mean,Var, SD;
	int i; 
	//declare varibales.

	for (i = 0; i < 15; i++){

		cout << "Please enter " << i << " The number" << endl;
		//Ask user to enter 15 times of numbers. 
		cin >> num[i];
		//receive number from user. 
	}//do loop. 

	mean = findMean(num, SIZE);
	//variable mean hold it by argument function findMean.

	Var = findVar(num, mean, SIZE);
	//variable var hold it by argument function findVar.
	cout << "The variance of the numbers are: " << Var << endl; 
	//Prompt result to user from agrument function. 
	SD = sqrt(Var); 
	//caluclate var by cube root. 
	cout << "The standard of the numbers are: " << SD << endl; 
	//Prompt result to user from agrument function. 
	system("pause");
	//Please pause the program. 

}// End of function call. 

double findMean(int num[], int SIZE){

	int i;
	double mean = 0;
	//declare variables. 
	for (i = 0; i < SIZE; i++){

		mean = mean + num[i];
		//calculates mean variable.

	}//do loop. 

	mean = mean / SIZE;

	return mean;
	//return to mean in function call. 

}//end of argument function. 

double findVar(int num[], double mean, int SIZE){

	int i; 
	double var=0;
	//declare variables.

	for (i = 0; i < SIZE; i++){

		var = var + pow((num[i] - mean), 2);
		//calculates for var variable. 
	}

	var = var / SIZE;

	return var;
	//return to var variable in the function call. 

}//end of function call. 