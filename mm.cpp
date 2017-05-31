#include <iostream>
#include <ctime>
/*
author: Abdulaziz Aldawk 
this program about time to shut down computers or Devices automatically . also it can 
turn it on depand of local time.
*/
using namespace std;

int main()
{
	
	const int num1 = 12;
	const int num2 = 13;

	time_t t1 = time(0);
	struct tm* now = localtime (&t1);

	cout << t1 << endl; 

	cout << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << endl; 


	if ((num1 <= now->tm_min) && (num2 >= now->tm_min))
		cout << "this system is turn it on" << endl;
	else
		cout << "this system is turn it to off"<< endl;

	
}
