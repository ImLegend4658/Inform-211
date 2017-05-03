/*
Author :Aziz Aldawk
Date :  4/6/2016
Language : C++
Purpose : this program a function named sort 
          that takes three integer parameters by reference
Problem # 4
lab #10
*/

#include <iostream>
using namespace std;

int sort(int A, int B, int C, int& num, int& num2, int& num3);
//default argument. 

int main(){
	int num, num2, num3; 
	int A = 30, B = 10, C = 20;
	//declare varibales. 

	sort(A, B,C, num, num2,num3);
	//receive result from argument functions. 

	cout << "A= " << A << " B= " << B << " C= " << C << endl;
	cout << endl; 
	cout << "A= " << num << " B= " << num2 << " C= " << num3 << endl;
	//prompt and receive from users. 
	//result comes from argument functions. 

	system("pause");
	//Please pause program. 
}//end of call function. 

int sort(int A, int B, int C, int& num, int& num2, int& num3){
	
	num = B;
	B = A;
	A = num;
	//Convert number 10 in B to A. 

	num2 = C;
	C = B;
	B = num2;
	//Convert number 20 in C to B.

	
	num3 = C;
	C = C;
	C = num3; 
	//Number 20 was hold by C but it convert it by self
	//to a new C of 30
	
	return num, num2, num3 ; 
	//return results to call function. 

}//argument fucnction. 
