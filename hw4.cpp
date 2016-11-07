/*******************************************************************
Author  :  
Date    :
Homework:
Compiler:  Visual C++ .NET
Source  :  HW4.CPP

Action  :  Program will read in text and keeps track of the number of
           characters, words and lines from an external file. File name
           is the second argument in command line.  Main program also
           gives the user the ability to use command line input to program.
           This will tell program what to display, i.e. display the
           number of words only, or lines or all of them.
           example at command line if this file is called "hw4.cpp":

                  hw4  filename  /options

           possible options are
                    l  : liness
                    w  : words
                    c  :characters

   NOTE : This program will only run with command line input from external
          file given on the command line.  Cannot use keyboard input for this
          program.
*********************************************************************/
#include <iostream>
#include <ctype.h>
#include <string>
#include <fstream>
using namespace std;

struct CmdLineRecord
{
   enum { MAX_NAME_LENGTH = 32 };    // Max allowable filename chars
   int SyntaxError;                  // True if user syntax is incorrect
   int WantsLineCount;               // set to true if user wants line count
   int WantsWordCount;               // set to true if user wants word count
   int WantsCharCount;               // set to true if user wants char count
};

struct CountsRecord
{
   unsigned LineCount;          // number of lines
   unsigned WordCount;          // number of words
   unsigned CharCount;          // number of characters
};

void DetermineWhatUserWants(CmdLineRecord & User, int arg, char * arv[]);
int CountLineWordChar(CountsRecord & Data, char File[]);
void ReportResults(CmdLineRecord User, CountsRecord Data);

int main(int argc, char * argv[])
{
   CmdLineRecord User;
   CountsRecord Data;
   int FileOpened = 1;

   DetermineWhatUserWants(User, argc, argv);
   if (!User.SyntaxError)
      FileOpened = CountLineWordChar(Data, argv[1]);

   if (FileOpened)
      ReportResults(User, Data);
   else
     cerr << "Cannot open file " << argv[1];

   return 0;
}
//------------------------------------------------------------------------


/**************  DetermineWhatUserWants  ****************************
Action  :  Function will determine what the user wants to have displayed
           for the count, based on command line input, i.e. does user
           want to display how many lines or words or characters or
           combination of them, or if an input error occurred. Second
           argument in command line must be the file name the third argument
           is the option of display.

           Command line options are inputed after the "/" char and are:
                c : character count
                w : word count
                l : line count

           If no options are inputed then the default of display all count
           totals is done, otherwise the option is done.  One option or two
           is permitted after the "/", illegal character option will result
           in a syntax error.

Parameters:
  Reference  :
    U        : User variable of struct type given above
  Value
    arg      : number of command line arguments
    *arv[]   : array of pointers each pointing to different argument
Returns    : nothing
Preconditions : None
=======================================================================*/

void DetermineWhatUserWants(CmdLineRecord & U, int arg, char * arv[])
{

  U.SyntaxError = 0;
  U.WantsLineCount = 0;    //initialize all wants to zero to start
  U.WantsCharCount = 0;
  U.WantsWordCount = 0;

  if (arg == 1)                 // No file name given in command line
    U.SyntaxError = 1;

  else if (arg == 2)            // Only file name given
     {                          // Therefore want to count everything
      U.SyntaxError = 0;
      U.WantsLineCount = 1;
      U.WantsCharCount = 1;
      U.WantsWordCount = 1;
     }

  else if (arg == 3)            // FIle name and One Command line argument
     {
      if (strlen(arv[2]) > 3)      //check length of command argument
         U.SyntaxError = 2;           //error too many possible options

      else if (strlen(arv[2]) == 1 && arv[2][0] != '/')
         U.SyntaxError = 3;           // unrecongized character

      else if (strlen(arv[2]) == 1)
         U.SyntaxError = 5;           // error to few options

      else if (arv[2][0] == '/')
         {
          if (tolower(arv[2][1]) == 'w')
              U.WantsWordCount = 1;
          else if (tolower(arv[2][1]) == 'c')
              U.WantsCharCount = 1;
          else if (tolower(arv[2][1]) == 'l')
              U.WantsLineCount = 1;
          else
              U.SyntaxError = 3;        //error unrecognized character

          if (strlen(arv[2]) == 3)      //check for a second command option
             {
              if (tolower(arv[2][2]) == 'w')
                  U.WantsWordCount = 1;
              else if (tolower(arv[2][2]) == 'c')
                  U.WantsCharCount = 1;
              else if (tolower(arv[2][2]) == 'l')
                  U.WantsLineCount = 1;
              else
                  U.SyntaxError = 3;     //error unrecognized character
             }
         }
      else
        U.SyntaxError = 3;            //error unrecognized character
     }
  else
     U.SyntaxError = 4;             //error to many command line arguments
}

/*********************  CountLineWordChar  *****************************
Action  :  Function will count the number of characters, words and lines
           in given input stream of text ended by control Z, ^Z, EOF

Parameters:
  Reference :
    Data    : variable of type struct given above
  Value
    File[]  : second command line argument that has the file to read from

Returns   : 1 if file opened, 0 if can not open file or not found

NOTE   :  Characters are everything, including newline and form feed.
          Words are delimited by whitespace characters and EOF.
          Does not take into consideration hypentation, words are composed
          numbers and letters, punctuation also included in words.

Precondition : none
=======================================================================*/
int CountLineWordChar(CountsRecord & Data, char File[])
{
   char ch;                  // current character in stream
   char NextCh;              // Next character in stream
   ifstream FileIn;          // declare FileIn to be input file

   FileIn.open(File);        // open file, and prepare to read from it

   if (FileIn.fail())        // error in opening file then exit
     return 0;

   Data.CharCount = 0;
   Data.WordCount = 0;
   Data.LineCount = 0;

   FileIn.get(ch);                   //read first character from input stream
   while (!FileIn.eof())             //continue until end of file
     {
      FileIn.get(NextCh);           //look at next character in stream

      Data.CharCount += 1;       //count all characters

      if ((ch == '\n') || (ch == '\r') || FileIn.eof())
         Data.LineCount += 1;
      if ((!isspace(ch) && isspace(NextCh)) || (!isspace(ch) && FileIn.eof()))
         Data.WordCount += 1;
      ch = NextCh;               //let ch be the next character
     }

   FileIn.close();      //closing file
   return 1;
}


/**********************  ReportResults  ********************************
Action  :  Function will display the number of words, lines or characters
           or all of them depending on what the user entered on the command
           line input.
Parameters :
  Value    : 2 value parameters, User - what to display
                                 Data - holds the number to display
Returns    : nothing
======================================================================*/

void ReportResults(CmdLineRecord User, CountsRecord Data)
{
  if (User.SyntaxError == 1)
    {
     cout << "SYNTAX ERROR: No file name given on command line\n";
     cout << " form of \"HW4  [filename] \"/\" option1option2\"\n";
    }
  else if (User.SyntaxError == 2)
    {
     cout << "SYNTAX ERROR: Too many options in command line\n";
     cout << " form of \"HW4  [filename] \"/\" option1option2\"\n";
    }
  else if (User.SyntaxError == 3)
    cout << "SYNTAX ERROR  unrecognized character in command line argument\n";
  else if (User.SyntaxError == 4)
    cout << "SYNTAX ERROR:  Too many command line argument\n";
  else if (User.SyntaxError == 5)
    {
     cout << "SYNTAX ERROR: Too few options in command line\n";
     cout << " form of \"HW4  [filename] \"/\" option1option2\"\n";
    }
  else
     {
      if (User.WantsCharCount)
         cout << "\ncharacters = " << Data.CharCount;
      if (User.WantsWordCount)
         cout << "\nWords = " << Data.WordCount;
      if (User.WantsLineCount)
         cout << "\nlines = " << Data.LineCount;
      cout << endl;
     }
}
