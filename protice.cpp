#include <iostream>
using namespace std; 
/*
protice with simple codes of fractions 


*/
int main(){

	double demon;
	double numon;
	double enter;
	int choicNum;

	cout << "welcome to our program fruction :)"<<endl
		<< "please choice the number what you need" << endl
		<< " Addition, press number <1>" << endl
		<< "Subtruction, press number <2>" << endl
		<< "Mulity, press number <3>" << endl
		<< "divition, press number <4>" << endl;
	cin >> choicNum;

	cout << "please enter demon number" << endl;
	cin >> demon;

	cout << "please enter numon number" << endl;
	cin >> numon;


	switch (choicNum)
	{
	case 1:
		enter = (demon / numon) + (numon / demon);

		cout << enter<< " Fraction on addtion is: " << endl;
		break;
	case 2:
		enter = (demon / numon) - (numon / demon);
		cout << enter << " Fraction on substract is: " << endl;
		break;
	case 3:
		enter = (demon / numon) * (numon / demon);
		cout << enter << " Fraction on multi is: " << endl;
		break;
	case 4:
		enter = (demon / numon) / (numon / demon);
		cout << enter << " Fraction on multi is: " << endl;
		break;
	default:
		cout << "error" << endl; 
		exit(1);
	}

	system("pause"); 

}
