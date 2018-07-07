#include<fstream> 
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std; 
/*this program about ask user who wants to regist on webside like Facebook 
 * it will requiare user, pass and email. 
 * all copy right@ Aziz Aldawk 2018

 * please note: This has been updated and bugs have been fixed.
	        7/6/2018 7:07 pm.

++++++++++++++++ The purpose of this program ++++++++++++++++++
::: This example of being used to steal our information by hackers. 
    Also, we need to be more carefull when you get string emaill or 
   even link from any social media. 
   some of them tells you, you have to enter user and pass bla bla bla
   and then you have nothing got. 
  the only usefull for hackers that have your information. 
  for example, if you got netflix email that tells you, you have to 
click the link and enter user and password. 
If i were you, i would go to netflix website not click the link. :)
stay safe and be smarter .:::
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
class resg
{
	public:
void TheUser(string &user1);
void Pass(string &password1);
void Email(string &emails11);
// it allows to being accessd from private.
void setUsers();
string  getUsers();
void setPass();
string getPass();
void setEmail();
string  getEmail();
// it promot to user and receive. 
void Display();
// show up to the user.

	private:
string user;
string password;
string email;
// unable to access unless from functions inside the class.
};

int main(){

resg REGS;

REGS.Display();

}

/*=============== Private ===============
 user, pass, and email are being allowed 
to be access from private on this way. 
========================================*/
void resg::TheUser(string &user1){

	user = user1;
}

void resg::Pass(string &password1)
{

	password = password1;

}

void resg::Email(string &emails11)
{

	email = emails11;
}
/*======= Set and get ==========
set: prompt and recieve from the user. 
get: return what user has already written.
============================*/
void resg::setUsers(){
	string names;
	cout<<"...أدخل اسم المستخدم "<<endl;
	getline(cin,names);
	TheUser(names);
}

string resg::getUsers(){
	return user;
}


void resg::setPass(){
	string passw;
	cout<<"...أدخل كلمة السر"<<endl;
	getline(cin,passw); 
	//cin>>passw;
	Pass(passw);
}

string resg::getPass(){
	return password;
}


void resg::setEmail(){

	string email98;

	cout<<"...أدخل الايميل تبعك"<<endl;
	cin>>email98;
	Email(email98);
}


string resg::getEmail(){
	return email;
	}

/*======== Display and function =========
What the propuse?
Display: it prompt to user or the screen
get: recieves what already user has written.
========================================*/
void resg::Display(){

	setUsers();
	setPass();
	setEmail();

// Already forgot something: get is what received by user :)
//	cout<<"Username is: "<<getUsers()<<endl
//		<<"Password: ******* ::::: "<<"Show Password: "<<getPass()<<endl
//<<"Email: "<<getEmail()<<endl;

///////////
ofstream readme;

readme.open("testme.txt");
readme<<getUsers()<<endl
	<<getPass()<<endl;
	//<<getEmail()<<endl;
readme.close();

}
