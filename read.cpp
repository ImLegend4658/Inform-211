#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

int main(){

ifstream Openme; 
string name; 
Openme.open("SECROT.txt");

while(Openme >>name)
{
cout<<name<<" "; 
}
 
Openme.close();

 }


