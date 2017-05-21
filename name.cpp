#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

int main (){
string name; 

cout<<"please enter message you want"<<endl; 
getline(cin,name);
ofstream write; 

write.open("Thelegendery.txt");
write<<name;
write.close();

}
