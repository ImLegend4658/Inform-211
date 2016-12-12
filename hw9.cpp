/*************************************************************************

   AUTHOR  :  Matt Holloway

   SOURCE  :  hw9.cpp
              with the help from shell program a9shell.cpp


   COMPILER: Microsoft Visual C++ .NET

   ACTION  : The program tests routines designed to perform various
             operations on singly linked lists. The lists have a
             dummy head node that holds the  character. The tail of
             the lists points to NULL.

             This is an extended program of homework #8
             The menu choices also all reading in a list from an
             external file and sorting a list.

*************************************************************************/

#include <ctype.h>
#include <iostream>
#include <process.h>        //  Needed for call to exit
#include <fstream>
#include <new>
using namespace std;


struct Node
  {
  enum  { DUMMY_VALUE = 1 };  //  Value () stored in dummy head node.
  char  Ch;                   //  Holds the char data.
  Node *Link;                 //  Points to another struct of type Node.
  };

typedef Node* NodePtr;

void AbortProgram (void);

void AddNode (char    NewChar,
              NodePtr List);

void BuildList (NodePtr List);


void ZapList (NodePtr P);

void DeleteNode (char    CharToDelete,
                 NodePtr List,
                 int    &CharFound);

void StartList (NodePtr &List);

void ShowList (NodePtr List);

void DisplayMenuAndGetMenuChoice (char &MenuChoice);

void TestAddNode (NodePtr List);

void TestBuildList (NodePtr List);

void TestDeleteNode (NodePtr List);

void TestZapList (NodePtr List);

void TestReadList (NodePtr List);

int ReadList (NodePtr List, char FileName[]);

void TestSortList (NodePtr List);

void SortList (NodePtr List);


/*****************************  main   ********************************/

int main(void)
{
  NodePtr List = NULL;

  char MenuChoice;

  system("cls");
  cout << "This program allows you to test the routines needed \n"
          "for homework #9. \n\n";

  StartList(List);
  if (List == NULL)                        //  Unexpected error.
    AbortProgram ();

  do
    {
    DisplayMenuAndGetMenuChoice(MenuChoice);

    switch( MenuChoice )
      {
      case 'Q':  break;                // Exit program

      case 'B':  TestBuildList(List);
                 break;

      case 'A':  TestAddNode(List);
                 break;

      case 'D':  TestDeleteNode(List);
                 break;

      case 'Z':  TestZapList(List);
                 break;

      case 'R':  TestReadList(List);
                 break;

      case 'S':  TestSortList(List);
                 break;

      default :  cout << "\nError: '" << MenuChoice
                      << "' is not an option \n\n";
      }
     }
  while ( MenuChoice != 'Q' );

  return 0;
}

/*********************   DisplayMenuAndGetMenuChoice *********************

   Displays a menu of options and reads the user's choice into the
   parameter MenuChoice. Unbuffered input is used, so the user does
   not have to enter a newline character after typing a menu choice.
   The MenuChoice is upcased.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void DisplayMenuAndGetMenuChoice (char &MenuChoice)
{
  char* Option[] = {"B(uildList", "A(ddNode", "D(eleteNode",
                    " Z(apList", "R(eadList", "S(ortList", "Q(uit", "" };

  char DottedLine[] ="\n- - - - - - - - - - - - - - - "
                     "- - - - - - - - - - - - - - - -\n ";
  int K = 0;

  cout << DottedLine;

  while ( Option[K][0] != 0 )  // while we haven't gotten to ""
    {
    cout << Option[K];         // Display menu option
    cout << "  ";              // Add some white space.
    ++K;
    }

  cout << "=> ";
  cin >> MenuChoice;
  MenuChoice = toupper(MenuChoice);
  cin.ignore(10,'\n');

  cout <<  DottedLine;
}

/************************    TestAddNode  ********************************

   Facilitates the testing of the function AddNode, a function which
   adds a node to the tail end of a linked list. If the enter key is
   pressed in response to the prompt, it is assumed that the user
   wants to exit and this function is aborted.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void TestAddNode (NodePtr List)
{
  char NewChar;

  cout << "\n\n----------------   Testing AddNode   -------------------\n\n";

  cout << "Character to be added? ";
  NewChar = cin.get();
  cin.ignore(10,'\n');

  if (NewChar == '\n')  // User pressed just enter key.
    {
    cout << "Aborting AddNode...";
    return;
    }

  cout << NewChar;
  cout << " --  Adding \'" << NewChar  << "\'";

  AddNode (NewChar, List);

  cout << "\n\nThe new list: ";
  ShowList(List);
}

/*************************    TestBuildList     **************************

   Facilitates the testing of the function BuildList, which is supposed
   to build an ordered linked list of characters.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void TestBuildList (NodePtr List)
{
  cout << "\n\n=================  Testing BuildList  ===================";
  cout << "\n\nType the characters for the list -  "
           "when finished, press enter key\n\n ->";

  BuildList(List);

  cout << "\n\nAfter BuildList, List = ";
  ShowList(List);
}

/***********************    TestDeleteNode   *****************************

   Facilitates the testing of DeleteNode, a function which is supposed
   to delete characters from a linked list.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void TestDeleteNode (NodePtr List)

{
  int  CharFound;
  char CharToBeDeleted;


  cout << "\n\n*****************   Testing DeleteNode   *******************";

  cout << "\n\nCharacter to be deleted? ";
  CharToBeDeleted = cin.get();
  cin.ignore(10,'\n');

  DeleteNode (CharToBeDeleted, List, CharFound);

  if ( CharFound )
    cout << "\n\n'" << CharToBeDeleted << "' has been deleted,";
  else
    cout << "\n\n'" << CharToBeDeleted << "' was not in the list,";

  cout << "\n\nList = ";
  ShowList(List);
}

/***********************    TestZapList  *********************************

   Facilitates the testing of ZapList, a function that is supposed to
   return all storage allocated for a linked list to the heap (except the
   storage occupied by the dummy head node.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void TestZapList (NodePtr List)

{
  cout << "\n\n^^^^^^^^^^^^^^^^^   Calling ZapList  ^^^^^^^^^^^^^^^^^^^^^^^";


  ZapList(List);

  cout << "\n\nList = ";
  ShowList(List);
}

/****************************  AbortProgram   ****************************

   Displays an error message and returns a non-zero error code to
   the operating system.

   Requires exit function prototyped in process.h.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void AbortProgram (void)
{
  cout << "\n\n\a A error has occurred while using the new operator. \n"
          "Returning to the operating system\n";
  cout << "Press ENTER KEY to continue: ";
  cin.get();
  exit(1);
}

/************************    StartList  *********************************

  DESCRIPTION   Creates an empty list, i.e. a singly linked list that
                contains only a dummy head node.

  PARAMETER

    OUT, List   A pointer to the head node of the list. If the
                dynamic memory allocation is unsuccessful, List will
                hold NULL on exit.

  PRECONDITION  List points to NULL. If List points to an actual node,
                calling this routine will create inaccessable memory.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void StartList (NodePtr &List)
{
  List = new(nothrow) Node;
  if (List == NULL)
    return;                        // Memory allocation error.

  List->Ch   = List->DUMMY_VALUE;  // Fill in dummy head node fields
  List->Link = NULL;               // Initialize end of list.
}

/*************************   ShowList  ***********************************

  DESCRIPTION  Displays the character field of all of the nodes in List, a
               singly linked list with a dummy head node. The list is
               enclosed in quotes.

               The constant MAX_CHARS_PER_LINE controls the maximum
               number of characters displayed before a newline char
               is displayed.

  PARAMETER

    IN, List   A pointer to a singly linked list with a dummy head node.

  NOTE         To facilitate debugging this routine displays "NULL"
               if called with List == NULL.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void ShowList (NodePtr List)
{
 // const MAX_CHARS_PER_LINE = 50;

  int CharCount = 0;

  if ( List == NULL )
    {
    cout << " NULL LIST\n\n";
    return;
    }

  cout << "\"";                 //  Display quote for ease of testing.
  while ( List->Link != NULL )
  {
    List = List->Link;
    cout << List->Ch;
    if ( List-> Ch != '\n' )   // Increment CharCount unless newline
      ++CharCount;             //   char is encountered in List
    else
      CharCount = 0;
   // if ( CharCount % MAX_CHARS_PER_LINE == 0 )   //this will allow only
   //   cout << "\     n";                         //50 char per line
  }

  cout << "\"\n\n";
}


/*****************************   ZapList  ********************************

  DESCRIPTION  Frees all the storage space currently occupied by the
               linked list pointed to by List. Does NOT delete the delete
               the dummy head node.

  PARAMETER

    OUT, List  A pointer to a singly linked list with a dummy head node.
               After this call, List will contain only the dummy head node.

  PRECONDITION List must point to a linked list that has a dummy head node
               and a tail node that points at NULL.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void ZapList (NodePtr List)
{
  NodePtr Temp;
  NodePtr StartNode;         //will point to original start of list

  StartNode = List;         //point StartNode to start of original list
  List = List->Link;        // move pointer pass dummy head node

  while (List != NULL)      //continue through list until pointing at null
    {
     Temp = List;           //point Temp at what List is pointing at
     List = List->Link;     //move list to next element in list
     delete Temp;           //free memory storage for computer
    }

  StartNode->Link = NULL;  //makes sure a null at end of dummy head node
}

/****************************   AddNode  *********************************

  DESCRIPTION  Adds a node containing NewChar to the end of List.

  PARAMETERS

    IN, NewChar The character to be added to the end of the list.

    IN, List    A pointer to a singly linked list with a dummy head node.
                The value of List (address of dummy head node) is not
                changed by this routine, so List is passed by value.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void AddNode (char NewChar, NodePtr List)
{
   NodePtr NewNode;

   NewNode = List;
   while (NewNode->Link != NULL)     //search for last node in list
      NewNode = NewNode->Link;

   NewNode->Link = new(nothrow) Node;  //when found last node build new node to it

   if (NewNode->Link == NULL)        //check for error allocating memory
      AbortProgram();
   else
     {
      NewNode = NewNode->Link;      //NewNode points to new last node
      NewNode->Ch = NewChar;        //Add new character to end
      NewNode->Link = NULL;         //make last node point to NULL
     }
}

/****************************    DeleteNode   ****************************

  DESCRIPTION  Deletes the first node of List that contains the char
               CharToDelete. The storage occupied by the deleted
               node is returned to the heap.

  PARAMETERS

    IN, CharToDelete  The character to be deleted.

    IN, List    A pointer to a singly linked list with a dummy head node.
                The value of List is not changed by this routine but the
                linked list itself is changed.

    OUT, CharFound Set to 1 if the CharToDelete is found and deleted and
         0 otherwise.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void DeleteNode (char CharToDelete, NodePtr List, int &CharFound)
{
  NodePtr NodeToBeDeleted;
  NodePtr SearchNode;          //temporary node to search list

  SearchNode = List;          //start at beginning of list

  if (SearchNode->Link != NULL)   //if list is not NULL search it
     {
      while ((SearchNode->Link->Ch != CharToDelete) &&  //search next node for
            (SearchNode->Link->Link != NULL))          //match or until end
                  SearchNode = SearchNode->Link;      //of list is encountered

      if (SearchNode->Link->Ch == CharToDelete)      //if next node has match
         CharFound = 1;                             //then character is found
      else
         CharFound = 0;                            //otherwise no match found

      if (CharFound)
         {
          NodeToBeDeleted = SearchNode->Link;      //node to be deleted now
                                                   //points to node with match
          SearchNode->Link = SearchNode->Link->Link; //current node now points
                                                    //to node after match node
          delete (NodeToBeDeleted);               //free memory for computer
         }
     }
}

/****************************   BuildList    *****************************

  DESCRIPTION   Builds a singly linked list with a dummy head node. The
                characters in the list are in the same order in which the
                user enters them, i.e. new characters are added to the tail
                end of the list.

                Input terminates when the enter key is pressed.

  PARAMETERS

    IN, List    A pointer to a singly linked list with a dummy head node.
                It is imperative that List be initialized before calling
                this routine.

  NOTE          Before building the new list, ZapList is called. This
                ensures that a memory leak does not develop.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void BuildList (NodePtr List)
{
  char Ch;
  NodePtr LastNode;                  //Will point to last node of list

  ZapList(List);                     //make sure list is empty
  LastNode = List;

  cin.get(Ch);
  while (Ch != '\n')                 //check character for end of line
    {
     LastNode->Link = new(nothrow) Node; //build new node at end of list

     if (LastNode->Link == NULL)    //check for error allocating memory
        AbortProgram();
     else
        {
         LastNode = LastNode->Link;  //LastNode points at end of list
         LastNode->Ch = Ch;          //store next character in list
         LastNode->Link = NULL;      //store NULL at end of list
         }

     cin.get(Ch);                    //get next character from input
    }
}

/************************    TestReadList  ********************************

   Facilitates the testing of the function ReadList, a function which
   reads in a list from an external file.  The file is typed in by the
   user, if file does not exist, then an error will occur.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void TestReadList (NodePtr List)
{
  char FileName[32];

  cout << "\n\n----------------  Testing ReadList  -------------------\n\n";

  cout << "Please enter the file to read from? ";
  cin >> FileName;
  cin.ignore(10,'\n');

  if (ReadList (List,FileName))
     {
      cerr << "\nError in opening the file " << FileName << endl;
	  cerr << "Press ENTER KEY";
      cin.get();
      return;
     }

  cout << "\n\nThe list created from the file -- " << FileName << " --\n\n";
  ShowList(List);

  cin.ignore(100,'\n');    //discard the enter from reading in filename
}

/****************************   ReadList    *****************************

  DESCRIPTION   Builds a singly linked list with a dummy head node. The
                characters in the list are read in from an external file
                in the same order in which they are found in file.

                Input to list terminates when the End of File is encountered

  PARAMETERS

    IN, List    A pointer to a singly linked list with a dummy head node.
                It is imperative that List be initialized before calling
                this routine.

    IN, FileName  A pointer to a string that has the name of the file to
                  open, if error in opening then return a 1;

  NOTE          Before building the new list, ZapList is called. This
                ensures that a memory leak does not develop.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int ReadList (NodePtr List,char FileName[])
{
  ifstream indata;              //declare file variable to read from
  char Ch;
  NodePtr LastNode;                  //Will point to last node of list

  ZapList(List);                     //make sure list is empty
  LastNode = List;

  indata.open(FileName);        //open the file to read from
  if (indata.fail())
    return 1;

  indata.get(Ch);            //get first character
  while (!indata.eof())      //check for end of file
    {
     LastNode->Link = new Node;      //build new node at end of list

     if (LastNode->Link == NULL)    //check for error allocating memory
        AbortProgram();
     else
        {
         LastNode = LastNode->Link;  //LastNode points at end of list
         LastNode->Ch = Ch;          //store next character in list
         LastNode->Link = NULL;      //store NULL at end of list
         }

     indata.get(Ch);                    //get next character from file
    }

  indata.close();                  //close the file
  return 0;
}

/***********************    TestSortList  *********************************

   Facilitates the testing of SortList, a function that is supposed to
   return a list that has been sorted, from lowest character value to
   highest.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void TestSortList (NodePtr List)

{
  cout << "\n\n^^^^^^^^^^^^^^^^   Calling SortList  ^^^^^^^^^^^^^^^^^^^^^^^";


  SortList(List);

  cout << "\n\nList = ";
  ShowList(List);
}

/**************************  SortList ************************************

Description  Arranges the singly linked list pointed to by List in
             natural order.  It is assumed that the list has a dummy
             head node.

             The algorithm used is a linked variation of the selection
             sort and works like this:
             Start with EndSorted aimed at first node of list

             repeat
               Find smallest char between EndSorted and end of list
               Swap smallest element with char in EndSorted
               Change EndSorted to next node
             until we get to end of list

             None of the pointers in linked list are changed

Parameters
  IN, List  A pointer to a singly linked list with a dummy head node

-----------------------------------------------------------------------*/
void SortList(NodePtr List)
  {
   NodePtr SmallNode;        //points to smallest char
   NodePtr SearchNode;       //used to search each node in list
   NodePtr EndSorted;       //points to list to sort
   char TempCh;

   if (List->Link == NULL)      //No list to sort
      return;

   if (List->Link->Link == NULL)   //list has only one element
      return;                      //Therefore already sorted

   EndSorted = List->Link;      //start with endsorted at first node
   SmallNode = EndSorted;      //let first element by the smallest
   SearchNode = EndSorted;     //start search at first node of list

   do
     {

      while (SearchNode->Link != NULL)
        {
         SearchNode = SearchNode->Link;         //move searchnode pointer
         if (SearchNode->Ch < SmallNode->Ch)   //check if SearchNode char
            SmallNode = SearchNode;           //is less than SmallNode char
        }

      TempCh = EndSorted->Ch;
      EndSorted->Ch = SmallNode->Ch;       //this swaps two elements
      SmallNode->Ch = TempCh;

      EndSorted = EndSorted->Link;   // move to next node in list
      SmallNode = EndSorted;        //let smallest be the next element
      SearchNode = EndSorted;       //Start next search at new front of list

      }
   while (EndSorted->Link != NULL);     //do until end of list
}
