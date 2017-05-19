#include <iostream>
#include <string>
using namespace std; 
//all my copyright@2017
struct mywork
{
int num; 
string name; 
};

void addName(mywork &head);
void addAge(mywork &head);
void FinalCal(mywork &head);
int main ()
{
mywork head; 

addName(head);
addAge(head);
FinalCal(head);
}

void addName(mywork &head)
{

cout<<" what is your name? "<<endl; 
getline(cin, head.name);

}

void addAge(mywork &head){

cout<<"please enter your age "<< head.name<<endl; 
cin>>head.num; 
}

void FinalCal(mywork &head){

if (head.num >18)
cout<<head.name<<" enjoy the party :)"<<endl; 
else 
cout<<head.name<<" back to home and drink milk and sleep well :) "<<endl; 

}





