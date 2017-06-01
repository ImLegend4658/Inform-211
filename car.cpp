#include <iostream>
#include <cstdlib>
#include <string>
using namespace std; 
struct cars
{

string name;
int age;
int model;

};

void yourName(cars &Regest);
void yourAge(cars &Regest);
void TheModel(cars &Regest);
void Result(cars &Regest);
int main()
{

cars Regest;

yourName(Regest);
yourAge(Regest);
TheModel(Regest);
Result(Regest);

}

void yourName(cars &Regest){

cout<<"Would you please enter your name "<<endl;
getline(cin, Regest.name);
}

void yourAge(cars &Regest){

cout<<"Dear: "<< Regest.name<<" welcome to kreeem"<<endl;

cout<<"Would you please enter your age"<<endl; 
cin>> Regest.age;
}

void TheModel (cars &Regest){


cout<<"Dear: "<<Regest.name<<" enter model your car"<<endl; 
cin>> Regest.model;
}

void Result(cars &Regest){

cout<<"Your result is here"<<endl; 

if (Regest.age >18)
cout<<"Dear "<<Regest.name<<" Congrates, your age is"<<Regest.age<<endl; 
else {
cout<<"Dear "<<Regest.name<<"you still kid, sorry come back later"<<endl;
exit(1);}

if (Regest.model > 2013)

cout<<"Congrates, your can start to work whenever you want, a good day :)"<<endl; 
else 
cout<<"sorry, we cant accept your car, still too old"<<endl; 

}
