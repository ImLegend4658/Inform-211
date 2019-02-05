/*
Author :Aziz Aldawk
Date :  9/3/2016
Language : C++
Purpose : This program to generate the results for fifty rolls of a die. The program  
           uses a call to a function named RollDie
*/
#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

double RollDie(double Num);
//function
int main(){

        int num;
        //declare variables.
        cout << "Please enter number that you want to roll die it " << endl;
        cin >> num;
        //prompt and receive. 

        RollDie(num);
        //receive from function. 

     //   system("pause");
}

double RollDie(double Num)
{
        int Z;
        int min =1;
        int max =6;
        srand(time(0));

        for (Z = 0; Z < 10; Z++)
                cout << rand() % (max-min +1)+min << endl;

        return 0;
}
