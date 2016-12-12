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
         delete (NodeToBeDeleted);                  //free memory for computer
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
  char NewChar;
  NodePtr LastNode;                  //Will point to last node of list

  ZapList(List);                     //make sure list is empty
  LastNode = List;

  cin.get(NewChar);
  while (NewChar != '\n')             //check character for end of line
    {
     LastNode->Link = new(nothrow) Node;   //build new node at end of list

     if (LastNode->Link == NULL)    //check for error allocating memory
        AbortProgram();
     else
        {
         LastNode = LastNode->Link;  //LastNode points at end of list
         LastNode->Ch = NewChar;     //store next character in list
         LastNode->Link = NULL;      //store NULL at end of list
         }

     cin.get(NewChar);               //get next character from input
    }
}