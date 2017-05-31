#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std; 

int TheRoots(int num1);
void Randoms(int num2);

int main()
{

int num1, num2, result;

result=TheRoots(num1);
cout<<"the root is "<<result<<endl;

Randoms(num2);


}

int TheRoots(int num1){
cout<<"/////////////////////// First station for roots/////////// "<<endl;
int number;

number= sqrt(550);

return number;

}

void Randoms(int num2)
{
cout<<"/////////////// Second Station for Random number//////////////"<<endl;
int arr[7];

for (int i=0;i<7;i++){

arr[i]= rand() %15;
cout<<arr[i]<<endl;
}

}
