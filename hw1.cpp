/******************************************************************
Name  :
Source : HW1.CPP
Action : Program will read in from standard input and determine the
         frequency of word lengths found in input.  An appropriate
         table is also displayed.  Maximum word length is 15 characters
         words greater then 15 are counted as length 15. 
         Average word length also displayed.

Note   : Words include hyphenated and ones with apostrophes.  Words with
         apostrophes, i.e. Jim's, will count the apostrophe as part of the
         word length. Hyphen is counted if word on same line, else not.

         Also an int array is used to hold the number of words with
         length associated with matching subscript, with subscript 0
         not being used.  So subscript 1 corresponds to word length of 1,
         subscript 2 to word length of 2 and so on.
------------------------------------------------------------------------*/
#include <iostream>
#include <ctype.h>
#include <iomanip>
using namespace std;

int NextWordLength(void);                    // function prototypes
void DisplayFrequencyTable(const int Words[]);

const int WORD_LENGTH = 16;                // global constant for array

void main()
{
  int WordLength;                        // actual length of word 0 to X
  int NumOfWords[WORD_LENGTH] = {0};     // array holds # of lengths of words

  WordLength = NextWordLength();
  while (WordLength)                  // continue to loop until no word, i.e. 0
    {                                 // increment length counter
      (WordLength <= 14) ? (++NumOfWords[WordLength]) : (++NumOfWords[15]);
      WordLength = NextWordLength();
    }

  DisplayFrequencyTable(NumOfWords);
}

/**********************  NextWordLength  ********************************
Action  : Will determine the length of the next word. Hyphenated words and
          words with apostrophes are counted as one word accordingly
Parameters : none
Returns   : the length of word, 0 if none, i.e. end of file
-----------------------------------------------------------------------*/
int NextWordLength(void)
{
  char Ch;
  int EndOfWord = 0,       //tells when we have read in one word
      LengthOfWord = 0;

  Ch = cin.get();                           // get first character
  while (!cin.eof() && !EndOfWord)
   {
     while (isspace(Ch) || ispunct(Ch))      // Skips leading white spaces
        Ch = cin.get();                      // and leading punctation marks

     if (isalnum(Ch))          // if character is a letter or number
        ++LengthOfWord;        // then increment word length

     Ch = cin.get();           // get next character

     if ((Ch == '-') && (cin.peek() == '\n')) //check for hyphenated word over two lines
       {
         Ch = cin.get();       // don't count hyphen and remove the newline char
         Ch = cin.get();       // get next character then on next line
       }

     if ((Ch == '-') && (isalpha(cin.peek()))) //check for hyphenated word in one line
	 {
         ++LengthOfWord;       // count the hyphen as part of word
         Ch = cin.get();       // get next character
	 }

     if ((Ch == '\'') && (isalpha(cin.peek()))) // check for apostrophe in word
      {
        ++LengthOfWord;        // count apostrophe in word length
        Ch = cin.get();        // and get next letter
      }

     if (isspace(Ch) || ispunct(Ch) || cin.eof())  // is it end of word
       EndOfWord++;
   }

  return LengthOfWord;
}

/***********************  DisplayFrequencyTable  **************************
Action  :  Will display the frequency of length of words along with the
           average word length
Parameters
  IN     : Pointer to array holding the frequency of the lengths
Returns  : Nothing
Precondition: for loop does not go beyond WORD_LENGTH
------------------------------------------------------------------------*/
void DisplayFrequencyTable(const int Words[])
{
  int TotalWords = 0, TotalLength = 0;

  cout << "\nWord Length      Frequency\n";
  cout << "------------     ----------\n";

  for (int i = 1; i <= WORD_LENGTH-1; i++)
    {
     cout << setw(4) << i << setw(18) << Words[i] << endl;
     TotalLength += (i*Words[i]);
     TotalWords += Words[i];
    }

  cout << "\nAverage word length is ";

  if (TotalLength)
     cout << float(TotalLength)/TotalWords << endl;
  else
    cout << 0 << endl;
}
