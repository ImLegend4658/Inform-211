/*************************************************************
Author  :  Matt Holloway
Source File :  hw3.cpp
Compiler:  Visual C++ .NET
Action :  Overall program deals with the birthday paradox, which
          states if 23 people are chosen at random, then there is
          a greater then 50% chance that at least two will have the
          same birthday.  Program will display a menu that will allow
          the user to
            1) have birthday paradox explained
            2) generate 1000 sets of birthdays in groups of 23
            3) display one set of 23 birthdays
            4) quit
*******************************************************************/
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
using namespace std;

void TellBirthdayParadox(void);
void DisplayMenu(char &response);
void GenerateBirthdaySet(int Set[]);
void DisplayBirthdaySet();
void SelectionSort(int A[], int ArraySize);
void ConvertYearToMonthAndDay(int DayofYear,
                              int &MonthNumber,
                              int &DayNumber);
int DaysInMonth(int MonthNumber);
void VerifyBirthdayParadox();


const int SAMPLE_SIZE = 23;
const int NUMBER_OF_SETS = 1000;
const int FW = 2;               //Field width for display

void main()
{
   char response;

   srand(time(NULL));
   do
     {
      DisplayMenu(response);
      switch(response)
        {
        case '1': TellBirthdayParadox();
                break;
        case '2': VerifyBirthdayParadox();
                break;
        case '3': DisplayBirthdaySet();
                break;
        case 'E' : cout << "Good Bye";
        }
     }
   while (response != 'E');
}

/***********************  DisplayMenu  ******************************
Action  : Function will display the menu used in program
Parameters :
  IN  :  none
  OUT :  the users entered choice.
Returns : nothing
===================================================================*/
void DisplayMenu(char & choice)
{
   cout << endl << endl;
   cout << "Choose one of the following:\n";
   cout << "  1) Explain the birthday paradox\n";
   cout << "  2) Check birthday paradox by generating " << NUMBER_OF_SETS
        << " sets of birthdays\n";
   cout << "  3) Display one set of 23 birthdays\n";
   cout << "  E) Exit\n";
   cout << "\nEnter choice ---> ";
   cin >> choice;
   while ((choice != '1') && (choice != '2')
          && (choice !='3') && (choice != 'E'))
     {
      cout << "\n\n\nINCORRECT CHOICE, PLEASE ENTER AGAIN!! --> ";
      cin >> choice;
     }
}


/**********************  TellBirthdayParadox  ***************************
Action  : This function just explains what the birthday paradox is to
          the user.
Parameters: none
Returns   : nothing
========================================================================*/
void TellBirthdayParadox()
{
  cout << endl << endl << endl;
  cout << "The Birthday Paradox States :\n";
  cout << "\nIf 23 people are chosen at random, then the chances\n"
       << "are more than 50% that at least two will have the\n"
       << "same birthday.\n\n\n";
  cout << "Press ENTER key to get back to menu.";
  cin.ignore(2);
}


/**********************  GenerateBirthdaySet  *************************
Action  :  This function will randomly generate a number between 1 and
           365, where each number corresponds to a day of the year, i.e
           a is Jan 1 and 365 is Dec 31.  The number will then be stored
           in an array of integers that will have 23 elements in it.
Parameters :
  Set[]    : pointer to birthday array that has 23 random birthdays
Returns  : nothing
=======================================================================*/
void GenerateBirthdaySet(int Set[])
{
   for (int i=1; i!=SAMPLE_SIZE + 1; ++i)
     Set[i] = 1 + rand()%365;
}

/************************  Swap  *****************************************
  DESCRIPTION  Interchanges the contents of A and B.

  PARAMETERS   IN-OUT  A and B, the variables to swap

  NOTE         This function is declared to be inline so that the overhead
               of a function call is avoided.
  PRECONDITION: A and B assumed to be integers
========================================================================*/
inline void Swap (int &A, int &B)
{
  int Temp= A;
  A = B;
  B = Temp;
}


/*************************  SelectionSort *********************************

DESCRIPTION  Sorts the members of the array List[1..Last]. (The array
             element in position 0 is ignored.) This version of the
             selection sort works by finding the smallest element of the
             entire array and placing it in its correct position (1).
             Next the smallest element in List[2]..List[Last] is found
             and placed in position 2. After step N, the elements
             List[1]..List[N] are in their correct places.

PARAMETERS
  List       IN-OUT, an array with subscripts from 0..Last of int

  Last       IN    , the subscript of the last array member to be sorted

CALLS        Swap, an inline function to swap array elements.

NOTE:        To sort List[0..Last] change for loop to:

             for ( Start = 0; Start < Last; ++Start )

Precondition: Last does not go outside scope or array
======================================================================== */
void SelectionSort (int List[], int  Last)
{
  int i, Start, SubSmall;

  for ( Start = 1; Start < Last; ++Start )   // Sort items 1..Last
    {
    SubSmall = Start;                        //  subscript of smallest elt.

    for ( i = Start + 1; i <= Last; i++ )    //  Find subscript of smallest
      if ( List[i] < List[SubSmall] )        //   elt. in tail end of array
        SubSmall= i;

    Swap(List[SubSmall],  List[Start]);      // Place in correct position
    }

}




/*******************  DaysInMonth  *************************************
Action  : Function will accept a given month number from 1 to 12 and
          return the number of days in that month, i.e. for month 3,
          which corresponds to March the value of 31 is returned.
Parameters :
  IN    : the corresponding month number
  OUT   : none
Returns   : the number of actual days in that given month
Precondition:  MonthNumber is in range from 1 to 12 inclusively
======================================================================*/
int DaysInMonth(int MonthNumber)
{
   switch(MonthNumber)
     {
     case 2:return 28;
     case 4:
     case 6:
     case 9:
     case 11: return 30;
     default:return 31;
     }
}

/***************  ConvertYearToMonthAndDay  ****************************
Action  :  This function will accept the Day of the Year, i.e. 34, 276
           or 356 and convert it to the correct Month number, 1 for
           January to 12 for December, and find the correct day of the
           month, between 1 and 30 or 31 or 28.
Parameters
  Input  : the day of year
  output : the month number and day number
Returns  : nothing
Precondition: DayofYear needs to be between 1 and 365
======================================================================*/
void ConvertYearToMonthAndDay(int DayofYear,
                              int &MonthNumber,
                              int &DayNumber)
{
   MonthNumber = 1;     // let MonthNumber be that of January to start
   while (DayofYear > DaysInMonth(MonthNumber))
     {                                        //subtract days in given month
      DayofYear -= DaysInMonth(MonthNumber);  //from total days in year
      MonthNumber += 1;                       // then go to next month
     }
   DayNumber = DayofYear;
}


/***********************  DisplayBirthdaySet  **************************
Action  :  This function will display a Birthday set of 23 randomly
           chosen birthdays.  Also will display them chronological order
           and if multiple birthdays are found for same date then the
           number of them is placed next to month.
Parameters : none
Returns    : nothing
=========================================================================*/
void DisplayBirthdaySet()
{
    int Birthday[SAMPLE_SIZE + 1];   //array containing birthdays

    char * NameofMonth[] = {"ERROR","January    ","February   ","March      ",
               "April      ","May        ","June       ","July       ",
               "August     ","September  ","October    ","November   ",
               "December   "};

    int MonthNumber;       //i.e. 1 to 12, for January to December
    int DayNumber;         //i.e. 1 to 30 or 31 or 28
    int k;
    int BirthdayMatches;        //Number of occurences of a birthdate
    int BirthdaysDisplayed=0;   //keeps track number of birthdays displayed


    GenerateBirthdaySet(Birthday);
    SelectionSort(Birthday,SAMPLE_SIZE);    //Sorts birthday array

    cout << "Here are the results of generating a set of 23 birthdays\n";
    cout << "=========================================================\n";

    for (int i=1; i!=SAMPLE_SIZE+1; ++i)
      {
       if (BirthdaysDisplayed % 3 == 0)
         cout << endl;                //display three birthdays per line

       k = i;
       BirthdayMatches = 1;

       while (((k+1) != SAMPLE_SIZE+1) && (Birthday[k] == Birthday[k+1]))
          {
           ++k;
           BirthdayMatches += 1;  //if another birthday found then
          }                       //add one to birthdaymatches

       i = k;

       ConvertYearToMonthAndDay(Birthday[i], MonthNumber, DayNumber);

       if (BirthdayMatches == 1)
          cout << "     " << NameofMonth[MonthNumber] << setw(FW)
               << DayNumber << "  ";
       else
          cout << " (" << BirthdayMatches << ") " << NameofMonth[MonthNumber]
               << setw(FW) << DayNumber << "  ";

       BirthdaysDisplayed += 1;     //increment counter for each display
      }
    cout << "\n\n\nPress ENTER key to return to the menu";
    cin.ignore(2);
}












/*********************  VerifyBirthdayParadox  *************************
Action :  This function will verify the birthday paradox by generating
          100 sets of groups of 23 random birthdays, and then checking
          to see if it is over 50%.
Parameters : none
returns    : nothing
======================================================================*/
void VerifyBirthdayParadox()
{
   int NumberofMatches = 0;
   int Birthday[SAMPLE_SIZE+1];
   int i;

   for (int k=1; k <= NUMBER_OF_SETS; ++k)
     {
      GenerateBirthdaySet(Birthday);
      SelectionSort(Birthday,SAMPLE_SIZE);

      /* the following loop will search through the birthday array
         until it finds a match or until it reaches the end of the
         array, then if i is less than sample size there was at
         least one match in set*/

      i=1;
      while (((i+1) != SAMPLE_SIZE+1) && (Birthday[i] != Birthday[i+1]))
         ++i;
      if (i < SAMPLE_SIZE)
        NumberofMatches += 1;
     }

   cout << "\n\n\n\nGenerating " << NUMBER_OF_SETS << " sets of 23 birthdays "
        << "and checking for matches...\n";
   cout << "\nResults : "<< NumberofMatches << " out of " << NUMBER_OF_SETS
	   << " (" <<  setiosflags(ios::fixed | ios::showpoint) << setprecision(2)
        << (((float)NumberofMatches)/NUMBER_OF_SETS) * 100
        << "%) of the sets contained matching birthdays";
   cout << "\n\nPress ENTER key to continue";
   cin.ignore(2);
}
