#include <iostream>
#include <fstream>
#include <string>
#include<filesystem>
using namespace std; 

int main (){
bool exis = true; 
ifstream input;
char num;
string filenames;
cout<<"Enter filename to read it: "<<endl; 
cin>>filenames;
input.open(filenames+".txt");
if(input.fail()){
    cout<<"doesnt exsit"<<endl;
    exit(0);
}
while (! input.eof()){

input.get(num);

cout<<num; 

}

input.close();
}
