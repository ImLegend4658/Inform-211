#include <iostream>
#include <string>
#include <fstream>
// Whatever or whoever you are, DONT DELETE THIS FILE, I REPEAT
// DONT DELETE THIS FILE BECAUSE I NEED TO KNOW MY CODE AND WHAT I HAVE WRITTEND HERE SO BE NICE AND KINE :)
using namespace std; 

int main(){
string line; 
cout<<"please write the note you want to keep it here"<<endl; 
getline(cin,line);
// in order to write whatever you want you have you ask user first
// that value can transfer to inside the file. 
ofstream readme;


readme.open("README.txt");
readme<<line<<endl; 
readme.close();

}
