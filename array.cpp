#include<iostream>
#include<cstdlib>
#include<string>
/*
All copy right and you cannot use it for anything use without any permission. 
Abdulaziz.>
Please note: do not copy and past without any permission. 
thanks  
*/
using namespace std; 


void rand ( int arr[], int size);
void name( int arr[], int size);
int main(){

const int size =100;
int arr[size];

rand(arr,size);
name(arr,size);
}

void rand(int arr[],  int size)
{

for ( int i=0; i<size;i++)
{

arr[i] = rand();
cout<<arr[i]<<endl; 
}

}

void name( int arr[], int size)
{

string thename;

for (int i=0; i<size;i++)
{

cout<<"could you please enter your name "<<endl; 
getline(cin,thename);

cout<<"your name is "<<thename<<" and id is "<<arr[i]<<endl; 

}


}







