#include <iostream>
using namespace std;
/*===============================================================
Author: Aziz Aldawk and Dr. Wolfer
Date: 3/18/2017
Homework #3
purpose: this program is link list with function that 
         can add tail, head, and id. after that program will 
		 have other fucntion called delete id, head, and tail. 
=================================================================*/
const int IMGSIZE = 512;
struct  img
{
	int id;
	char pxls[IMGSIZE][IMGSIZE];
	img* next;
};

void clear_Pxls(char pxls[IMGSIZE][IMGSIZE]);
void print_list(img*);
img* initHead();
int add_tail(img*);
int add_head(img*);
int add_id(img*, int id);
int delete_id(img*, int id);
int delete_head(img*);
int delete_tail(img*);
//Function declaration for link list. 

int main(){
	// initialize head on the beginning. 
	img* head = initHead();

		add_tail(head);
		add_head(head);
		add_id(head, head->id);

		delete_id(head, head->id);// function call

		print_list(head); //print the list.
		cout << "the id is deleted" << endl;
		//function call
		delete_head(head);
 		delete_tail(head);

		cout << "head and tail was deleted" << endl;
		cout << endl; // give space between line.


	 system("pause"); // please pause program
}

/*==================== initHead ===============================
 prupose: initialize the head before start creating 
		 link list in order to avoid memory leak. 
=====================================================*/
img* initHead(){

	img* head; 
	head = new img;
	cout << "Head in addtail = " << head << endl; 
	head->id = 1; 
	clear_Pxls(head->pxls);
	head->next = NULL;
	return head; 
}
/*================= Add Tail ===========================================
The purpose: This function adds a new image to 
			 the tail of a linked list, zeros out the pixels, 
			 and assignes the next sequential integer to the image id. 
========================================================================*/
int add_tail(img* head){

	img* temp1 = new img; 

	temp1 = head; 

	while (temp1->next != NULL)
		temp1 = temp1->next; 

	img* temp2 = new img; 
	temp2->id = 2;
	cout << "The Tail was added : " << temp2->id << endl;
	temp2->next = NULL;
	temp1->next = temp2;
	return 0;
}
/*======================= Add Head =================================
The purpose: This function adds a new image to the head of 
			 a linked list, zeros out the pixels, and re-sequence
			 the images id. 
===================================================================*/
int add_head(img* head){

 	img* temp = new img; 
	temp->id = 3;
	cout << "The head was added : "<<temp->id << endl; 
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		return 1;
	}
	else
	{
		while (head->next != NULL)

		head = head->next;
		head->next = temp;
		head = head->next;
	}
	return 0; 
}
/*============= Add id =======================
The purpose: This function adds a new images to  a linked list, 
             that image id's remain in ascending order when  it completes.It zeros 
			 out the image pixls.
==============================================*/
int add_id(img* head, int id){

	
	img* temp11;
	temp11 = head; 

	while (temp11->id != id && temp11->next != NULL){

		temp11 = temp11->next;
 	}
	img* temp2 = new img; 
	temp2->id = 4;
	cout << "the ID was added: " << temp2->id << endl; 
	temp2->next = temp11->next; 
	temp11->next = temp2;
	return 0; 
}
/*========================= Delete id =========================
The purpose: This function removes the images with a given
			 id in a linked list, and deletes from memory. 
==============================================================*/
int delete_id(img* head, int id){
	img* node = new img; 
	node = head; 
 	img* OldNode = node; 
	
	for (int i = 0; i <1; i++)
	{
		OldNode = node; 
		node = node->next;
	}
	OldNode->next = node->next;
	delete(node);
	return 0;
}
/*===================== Delete Head ==========================
The purpose: This funciton removes the images at the head
			 of a linked list, and deletes from memory.
==============================================================*/
int delete_head(img* head){

	img *node = head->next;
	head->id = node->next->id;
	head->next = node->next;

	delete(node);
 	return 0;
}
/*===================== Delete Tail ==========================
The purpose: This funciton removes the images at the tail
of a linked list, and deletes from memory.
==============================================================*/
int delete_tail(img* head){

	img* node = new img; 
	node = head;
	img* oldNode = new img; 
	
	while (node->next != NULL)
	{
		oldNode = node;
		node = node->next;
	}
	oldNode->next = NULL;
	delete(node);

	return 0;
}
/*******************************************************
The purpose: This function will hold space on the memory
             for image that can be used by array. 
********************************************************/
void clear_Pxls(char pxls[IMGSIZE][IMGSIZE])
{
	for (int i = 0; i < IMGSIZE; i++)
	for (int j = 0; j < IMGSIZE; j++)
		pxls[i][j] = 0;

}
/*******************************************************
The purpose: print list is printing the results of linked list
			to the user and show the user what is output is.
********************************************************/
void print_list(img* head)
{

	cout << "Debug: please print this " << endl;

	if (head == NULL)
	{
		cout << "head NULL" << endl;
		return;
	}

	while (head != NULL)
	{
		cout << "ID= " << head->id << endl;
		head = head->next;

	}
}



