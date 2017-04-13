#include <iostream>
using namespace std; 
/*===============================================================
Author: Aziz Aldawk.
Date: 4/3/2017
Homework #4
purpose: This program will be able to get and set pizza's order
		 from customers. the program will display what type 
		 the pizza and size with prices.
=================================================================*/
class Pizza
{
public:// member function of class.
	void OutputDescription();
	void SetThePizza(int myType, int thetype);
	int GetThePizza();
	int GetTheTypeOfPizza();
	void Set_computePrice();
	double Get_computerPrice();
private:// only on class function can access by priavite.
	int ThePizza_TypeANDSize;
	int thetypepizza;
	double price; 
};

int main(){
	//declare varibles for class.
	Pizza order1[4];
	//ask for each order by array. 
	for (int i = 0; i < 4; i++){
		order1[i].OutputDescription();
		cout << "Your Total is: $" << order1[i].Get_computerPrice() << " enjoy your pizza" << endl;
		cout << endl; 
	}
 
	system("pause");// please pause program; 
 }
/*========================= The Decription ============================================
The prupose: this function will ask the customers what 
             type and size the pizza, they want. 

setThePizza = it receives order from customers.
Set_ComputerPrice = takes the order to prompt price for customers
                    that how much the total is. 
=======================================================================*/
void Pizza::OutputDescription(){
	//declare varibles.
	int TypePizza; 
	int WhattheType;
	//Ask customers what type of pizza, they want. 
	cout << "Welcome to our Pizza and Please choose what the type of Pizza you want" << endl
		<< "Deep dish pizza, please press <1>" << endl
		<< "Hand Tossed pizza, Please press <2>" << endl
		<< "Pen Pizza, Please press <3>" << endl; 
	//prompt from the user. 
	cin >> WhattheType;
	//Ask customers what size of the pizza, they want.
	cout << "Please choose Size of pizza you want" << endl
		<< "Small Pizza is $10 with Topping, please press <1>" << endl
		<< "Medium Pizza is $14 with Topping, Please press number <2>" << endl
		<< "Large Pizza is $17  with Topping, Please press number <3>" << endl;
	//prompt from user.
	cin >> TypePizza;
	//function that takes order from costomers.
	SetThePizza(TypePizza, WhattheType);
	//calculate and prompt total.  
	Set_computePrice();
}
/*====================Set The Pizza ================================
The prupose: This function is copy Constructor that allow 
             the varibles to be used or assign with other varibles.
============================================================*/
void Pizza::SetThePizza(int myType, int thetype){

	ThePizza_TypeANDSize=myType;
	thetypepizza = thetype;
}
/*==================== three functions ================================
The prupose: those function are Constructor that allow
		     the varibles in private to be used outside 
			 the class member. 
============================================================*/
int Pizza::GetThePizza()
{
 return ThePizza_TypeANDSize;
}

int Pizza::GetTheTypeOfPizza()
{
	return thetypepizza;
}

double Pizza::Get_computerPrice(){

		return price; 
}
/*===================Set Computer Price ========================
The prupose: this function will be able to display
             the total of the price the orders. 

Get The TypeofPizza: this function will be able to prompt
					 the type of pizza. 
Get The pizza: This function wil be able to prompt 
			   total which include topping and size of pizza. 
==============================================================*/
void Pizza::Set_computePrice()
{
	//declare string or characters. 
	char s1[20] = "Deep Dish";
	char s2[20] = "Hand Tossed";
	char s3[5] = "Pan";
	
	switch (GetTheTypeOfPizza())
	{
	case 1:
		s1; //Deep Dish.
		break;
	case 2:
		s2; // Hand Tossed.
		break;
	case 3:
		s3; // Pen
		break;
	default:
		cout << "error" << endl;
		exit(0); // program will exit. 
	}

	//declare varibles 
	int Topping;
	int num = 1;
    int topping; 
	//ask user how many topping, they want on the pizza.
	cout << "How many Topping do you want on the Pizza?" << endl
	     << "*** Please note: $2 per Topping ***" << endl;

	cin >> Topping; 

	topping = num + Topping;
	// it will add number the user has enterd with price of topping. 

	switch(GetThePizza()){

		case 1:
			price = 10 + topping;
		break;
		case 2:
			price = 14 + topping;
		break;
		case 3: 
			price = 17 + topping;
		break;
		default:
		cout<<"error"<<endl; 
		exit(0); // will exit the program. 
			}
	}





