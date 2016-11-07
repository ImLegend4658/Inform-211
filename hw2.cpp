/*************************************************************************
Name     : 
Source   :  HW2.CPP
Compiler :  Visual C++ .NET
DESCRIPTION:  Program designed to read in any sentence and replace the
              word hell, whether it is upper or lower case or even a
              mixture or both, with the word heck.  The letters in the
              word heck will match the case of the original word hell.

=========================================================================*/
#include <iostream.>
#include <ctype.h>
using namespace std;

void GetSentence(char Str[]);
void CopyString(char StrCopy[], char Str[]);
void MakeUpperCase(char StrCopy[]);
void InsertBlankStartEnd(char StrCopy[]);
void ReplacePuncWithBlanks(char StrCopy[]);
void SearchAndReplaceHell(char StrCopy[]);
void DeleteBlankStartEnd(char StrCopy[]);
void OriginalCaseAndPunc(char Str[], char StrCopy[]);


const MAX_LENGTH = 60;


//**************************  main  **************************************

void main()
{
  char Str[MAX_LENGTH] = "";
  char StrCopy[MAX_LENGTH] = "";

  GetSentence(Str);
  while (Str[0] != 0)
    {
     CopyString(StrCopy,Str);
     MakeUpperCase(StrCopy);
     InsertBlankStartEnd(StrCopy);
     ReplacePuncWithBlanks(StrCopy);
     SearchAndReplaceHell(StrCopy);
     DeleteBlankStartEnd(StrCopy);
     OriginalCaseAndPunc(Str,StrCopy);

     cout << "\nOriginal: ";
     cout << "\"" << Str << "\"";
     cout << "\nCensored sentence:";
     cout << " \"" << StrCopy << "\"" << endl;
     cout << "---------------------------------------------------------\n\n";
     GetSentence(Str);
    }
  cout << endl << "Goodbye...";
 
}




/*********************  GetSentence  *****************************
Action : Function will retrieve a sentence typed in by user and
         return back to main.
Parameters:
  S[]     : Pointer to string address
=================================================================*/
void GetSentence(char S[])
{
   cout << "Enter sentence==> ";
   cin.getline(S, MAX_LENGTH);
}


/******************  MakeUpperCase  *****************************
Action : Function will convert all characters to upper case.
Parameters:
  S[]      : Pointer to string to convert letters to upper case
Precondition: char array needs to end in null terminator
==================================================================*/
void MakeUpperCase(char S[])
{
   for (int i=0; S[i] != 0; ++i)
     S[i] = toupper(S[i]);
}


/*****************  InsertBlankStartEnd  ****************************
Action : Function will insert a blank space in the first and last
         location of the string, leaves NULL at end.
Parameters:
  S[]     : Pointer to the string to insert blank in first and last
Precondition: array ends in NULL
====================================================================*/
void InsertBlankStartEnd(char S[])
{
   int LengthS = 0;              // The length of the string

   for (int i=0; S[i] != 0; ++i) //This finds the length of S
     LengthS++;

   S[LengthS] = ' ';         // Adds blank to end of string
   S[LengthS+1] = 0;         // Puts null character at end

    for (int k = LengthS+1; k >= 0; --k)
      S[k+1] = S[k];            // Shifts string over to right by one
    S[0] = ' ';                // puts blank in first location
}

/*********************  ReplacePuncWithBlank  ************************
Action  : Will replace any non letter character with a blank space
Parameters:
  S[]     : pointer to string address to replace with blanks
Precondition: array ends in NULL
======================================================================*/
void ReplacePuncWithBlanks(char S[])
{
   for (int i=0; S[i] != 0; ++i)
     if (!(isalpha(S[i])))          //if characeter is not letter
       S[i] = ' ';                  //then replace with a blank
}
/**********************  SearchAndReplaceHell  ************************
Action  :  This function will find the occurences of the string HELL
           in the sentence and replace with the string HECK.
Parameters:
  S[]     : pointer to string to replace word HELL
Precondition: array ends in NULL
=====================================================================*/
void SearchAndReplaceHell(char S[])
{
   for (int i=0; S[i] != 0; ++i)
     if ((S[i] == ' ') && (S[i+1] == 'H') && (S[i+2] == 'E') &&
        (S[i+3] == 'L') && (S[i+4] == 'L') && (S[i+5] == ' '))
           {
            S[i+3] = 'C';
            S[i+4] = 'K';
           }
}
/********************  DeleteBlankStartEnd  ***************************
Action  : This function will delete the blank at start and end of string
Parameters :
  S[]      : pointer to string address
Precondition: array ends in NULL
=====================================================================*/
void DeleteBlankStartEnd(char S[])
{
   for (int i=0; S[i] != 0; ++i)
     S[i] = S[i+1];                //deletes first blank
   S[i-2] = 0;                     //deletes last blank, by putting null
}
/************************  OriginalCaseAndPunc  **********************
Action  : Replaces original case and puts other characters back as well.
Parameters :
  Orig[]   : pointer to address of original string
  S[]      : pointer to
Precondition: array ends in NULL
======================================================================*/
void OriginalCaseAndPunc(char Orig[], char S[])
{
   for (int i=0; S[i] != 0; ++i)
     {
      if (islower(Orig[i]))            //if original character is lower case
        S[i] = tolower(S[i]);         //then convert copy to lower case

      if (S[i] == ' ')                //if copy has a blank then replace
        S[i] = Orig[i];               //with what is in original spot
     }
}
/***********************  CopyString  **********************************
Action  : Makes a copy of one string to another.
Parameters:
  S[]     : pointer to source string
  C[]     : pointer to copy string
Precondition: array ends in NULL
=======================================================================*/
void CopyString(char C[], char S[])
{
   for (int i=0; S[i] != 0; ++i)
     C[i] = S[i];
   C[i] = 0;                //makes sure that string has a null character
}


/**************************  Output  *******************************

Enter sentence==> Hell, its hot as hell looking for shells in hell!

Original: "Hell, its hot as hell looking for shells in hell!"
Censored sentence: "Heck, its hot as heck looking for shells in heck!"
---------------------------------------------------------

Enter sentence==> hell

Original: "hell"
Censored sentence: "heck"
---------------------------------------------------------

Enter sentence==> hell's bell's

Original: "hell's bell's"
Censored sentence: "heck's bell's"
---------------------------------------------------------

Enter sentence==> hell-o

Original: "hell-o"
Censored sentence: "heck-o"
---------------------------------------------------------

Enter sentence==> hel

Original: "hel"
Censored sentence: "hel"
---------------------------------------------------------

Enter sentence==>

Goodbye...Press any key to continue

*/
