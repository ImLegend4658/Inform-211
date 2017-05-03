/*
Author :Aziz Aldawk
Date :  2/3/2016
Language : C++
Purpose : This program about To compute how many cereal boxes are there in one metric ton to onuces.
*/

#include<iostream>
using namespace std;

int main()
{
	double cereal_boxes;  
	//declare variabl
	const double METRIC_TON= 35273.92;
	//declare variabl
	cout << "How many cereal boxes are there in one metric ton"<< endl; 
	//Ask user to enter how many cereal boxes are ther in one metric ton.
	cin>> cereal_boxes;
	//prompt and receive 
	cereal_boxes = (METRIC_TON/16);
	//Convert from metric ton to onuce 
	cout << "Cereal boxes are there in one metric ton to in ounces are: "<<cereal_boxes<< endl;
	//print out number that convert from metric to ounce 
	system ("pause");
	//Please pause program

}
