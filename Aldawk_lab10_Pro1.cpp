/*
Author :Aziz Aldawk
Date :  4/6/2016
Language : C++
Purpose : This an overloaded function product 
          that determines the product of 2, 3, and 4 integers
Problem #1
Lab #10
*/
#include <iostream>
using namespace std;

void Prodect(int& n1, int& n2, int &x);
void prodect(int& n1, int& n2, int& n3, int&Z);
void product(int&n1, int& n2, int& n3, int& n4, int& G);
//Default Arguments.

int main(){

	int n1, n2, n3, n4;
	int X;
	int Z;
	int G;
	//declare varibales.

	cout << "Please enter number four times" << endl;
	//Ask user to enter number four times. 
	cin >> n1;
	cin >> n2;
	cin >> n3;
	cin >> n4;
	cout << endl;
	//receive from user. 

	Prodect(n1, n2, X);
	//receive from Arguments function.
	cout << "product with first number and second numbers: " << X << endl;
	//receive result from argument function.
	prodect(n1, n2, n3, Z);
	//receive from Arguments function.
	cout << "Product with first number, scond number, and third numbers: " << Z << endl;
	//receive result from argument function.
	product(n1, n2, n3, n4, G);
	//receive from Arguments function.
	cout << "Product with first, second, third, and fourth numbers: " << G << endl;
	//receive result from argument function.

	system("pause");
	//Please pause program. 
}// end of call fuction. 

void Prodect(int& n1, int& n2, int &X){

	X = n1*n2;
	//caluclate numbers that have enterd by user. 

}// argument function. 

void prodect(int& n1, int& n2, int& n3, int&Z){

	Z = n1*n2*n3;
	//Caluclate numbers that have enterd by user. 
}//argument function. 

void product(int&n1, int& n2, int& n3, int& n4, int& G){

	G = n1*n2*n3*n4;
	//Caluclate by numbers that have enterd by user. 

}//Argument function. 