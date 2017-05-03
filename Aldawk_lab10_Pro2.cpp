/*
Author :Aziz Aldawk
Date :  4/6/2016
Language : C++
Purpose :  This program about an overloaded function 
            area to determine the area of a rectangle and circle.
Problem  #2
Lab #10
*/
#include <iostream>
#include <cmath>
using namespace std;

void TheAREA(double& myrectangle, double length, double breadth);
void TheAREA(double& circle, double radius);
//default argument functions. 
int main(){

	double rectangle;
	double circle=0, length = 0, breadth = 0, radius=0;
	//declare varibales. 

	TheAREA(rectangle, length, breadth);
	TheAREA(circle, radius);
	//Received by argument functions.

	system("pause");
	//Please pause program.

}//end of call function. 

void TheAREA(double& myrectangle, double length, double breadth){


	cout << "Please enter the Breadth and Length" << endl; 
	cin >> breadth;
	cin  >> length;
	//prompt and receive from user. 

	myrectangle = (breadth*length);
	//caluclate numbers.

	cout << "The area of rectangle is " << myrectangle << endl;
	//receive result. 

}//Argument function. 

void TheAREA(double& circle, double radius)
{

	cout<<"Please enter number of radius "<<endl; 
	//Ask user to enter number of radious.
	cin>>radius;
	//prompt and receive from user. 

	circle = 3.14* radius*radius;
	//Caluclate numbers. 

	cout << "The Area of circle " << circle << endl; 
	//prompt result to user. 

}//Argument function. 