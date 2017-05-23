#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

int main (){
string name; 
string iam; 


ofstream write; 

cout<<"Would you please enter the massege you want? "<<endl; 
getline(cin,name);
write.open("SECROT.txt");
write<<name;
write.close();

}
