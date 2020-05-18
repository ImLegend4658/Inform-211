#include <iostream>
#include <string>
#include <fstream>
/*
Author: Abdulaziz
This is program to let you create a file after input
Also, you can name the file too. 
*/
using namespace std; 

int main(){
string line; 
cout<<"please write the note you want to keep it here"<<endl; 
getline(cin,line);
// in order to write whatever you want you have you ask user first
// that value can transfer to inside the file. 
ofstream readme;
string filename;
cout<<"Enter filename: "<<endl;
cin>>filename;
readme.open(filename + ".txt");
readme<<line<<endl; 
readme.close();

}
