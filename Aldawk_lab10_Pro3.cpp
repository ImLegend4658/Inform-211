/*
Author :Aziz Aldawk
Date :  4/6/2016
Language : C++
Purpose :  This program an overloaded function 
           to calculate the volume of a cylinder and cube
Problem  #3
Lab #10
*/

#include <iostream>
#include <cmath>
using namespace std; 

double MyMath(double radius, double highest,double V);
double MyMath(double V);
//default argument functions. 

int main(){

	
	double radius=0, highest=0, V=0; 
	//declare varibales. 

	MyMath(radius, highest, V);
	MyMath(V);
	//receive results from argument functions. 

	system("pause");
	//Please pause program. 

}//End of call function. 

double MyMath(double radius, double highest, double V)
{
	const double PI = 3.1415;
	//declared varibale that hold specific number. 
	cout << "Please enter radius" << endl;
	cin >> radius;
	cout << "Please enter highest" << endl;
	cin >> highest; 
	//Prompt and receive from the user. 

	V = PI*radius*radius*highest;
	//caluclate numbers to volume.
	cout << "the volume of a cylinder is: " << V << endl;
	//receive result of volume.

	return V; 
	//return result to call function. 

}//argument function. 

double MyMath(double V)
{
	int num; 
	//declare varibale. 

	cout << "Please enter number to cube number you want" << endl;
	//ask user to enter number to convert it to cube. 
	cin >> num; 
	//receive number from user. 

	V = num*num*num;
	//calucalte cube number of volume. 

	cout << "cube of number " << num << " is " << V << endl;
	//receive result of volume to user. 

	return V;
	//return result of volume to call function. 

}//Argument function. 