#include <iostream>
#include <string>
using namespace std; // std: standerd<> 
/*
 this program for testing and studying only. 
 we are not responsbility for any thing constant harmfull or copy right.

*/

void friendly();
void shy(int audienceCount);

int main ()
{

friendly();
shy(6);
cout<<"one more time"<<endl;
shy(2);
friendly();
cout<<"end of program"<<endl;


//program please pause a min
}


void friendly()
{
cout<<"Hello World"<<endl; 

}

void shy(int audienceCount)
{
if (audienceCount < 5)
return;
cout<<"good bye"<<endl; 
}
