/**********************************************************************
 PROGRAMMER :  Matt Holloway
 COMPILER   :  Visual C++ .NET
 SOURCE FILE:  HW7.CPP

 ACTION:     Reads words from stdin and displays them in 3 columns.
             For the purposes of this routine, a "word" is any
             contiguous sequence of non-blank characters.
             Words are truncated after 255 characters.
             Which is contraint put upon by the String class.

 NOTES :     The program does not handle correctly words longer than
             255. If such words are encountered, they
             are truncated.

             Only as many as MAX_WORD_COUNT words can be stored in the
             array holding the words.

         Uses the String class, that is defined in the file called
         "String2.cpp",  instead of char arrays.
=====================================================================*/
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include "string2.cpp"
using namespace std;

void WriteWords (String Word[],
                 int    Count[],
                 int    TotalWordCount,
                 int    DistinctWordCount);

void StoreWord (String NewWord,
                String Word[],
                int    Count[],
                int    &TotalWordCount,
                int    &DistinctWordCount,
                int    MaxWordCount);

/***************************  main  ***********************************/
void main()
{
  const    MAX_WORD_COUNT  = 130;

  String  NewWord,
          NullString = "",
		  Word[MAX_WORD_COUNT + 1] = {"",""};       // ALWAYS allow 1 extra slot!

  int      Count[MAX_WORD_COUNT + 1] ={0}, // Initialize array to zeros
           DistinctWordCount = 0,
           TotalWordCount = 0;

  cin >> NewWord;               //  Get the first word

  while ( NewWord != NullString )
    {
    StoreWord (NewWord, Word, Count, TotalWordCount, DistinctWordCount,
               MAX_WORD_COUNT);

    cin >> NewWord;             //  Get the next word
    }

  WriteWords(Word, Count, TotalWordCount, DistinctWordCount);
}
/***************************  StoreWord   ********************************

DESCRIPTION  Adds a String NewWord (holding up to 254 characters)
             to the end of the array Word.

PARAMETERS   NewWord            The String to be added
             Word               An array of String variables
             DistinctWordCount  The number of different words in the array
             TotalWordCount     The total number of word in the file
             MaxWordCount       The max number of words that can be stored
                                in the array Word. If DistinctWordCount ==
                                MaxWordCount, the function is exited.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void StoreWord (String NewWord,
		String Word[],
		int     Count[],
		int    &TotalWordCount,
		int    &DistinctWordCount,
		int     MaxWordCount)
{
  int k = 0;

  while ( Word[k] < NewWord && k < DistinctWordCount )
    ++k;

  // Assert:  k is NewWord's correct position in the ordered array Word

  if ( NewWord == Word[k] )   // NewWord is already there
    {
    ++Count[k];
    ++TotalWordCount;
    }

  else if ( DistinctWordCount < MaxWordCount ) // Room for a new word
    {
    ++DistinctWordCount;  // If this line reached, found new word
    ++TotalWordCount;

    for ( int i = DistinctWordCount-1;  i > k;  --i ) // Make room for
      {                                               //  NewWord
      Word[i] = Word[i-1];
      Count[i] = Count[i-1];
      }
    Word[k] = NewWord; // Store NewWord in array
    Count[k] = 1;
    }
}

/***************************  WriteWords   ********************************

DESCRIPTION  Writes the strings in the array Word to standard output.
	     The words are left justified and padded with blanks.
	     After WORDS_PER_ROW words have been written a new line is
	     started.

PARAMETERS   Word       An array of String
             WordCount  The number of words in the array

CALLS        cout <<, setf and  setw

NOTE         Typical output would look something like that below.

    Word        Count  |     Word        Count  |     Word        Count  |

                       |                        |                        |
All                 1  | As                  1  | Dick                1  |
Dick,               1  | Did                 1  | Jane                1  |
Jane,               1  | Spot                1  | Spot's              1  |
Spot?               1  | a                   5  | account             1  |
after.              1  | ago,                1  | altered             1  |
and                 1  | away                1  | brokerage           1  |
but                 1  | computer            1  | end.                1  |
engineer            1  | ever                2  | executive           1  |
expect,             1  | few                 1  | firm.               1  |
for                 2  | happened            1  | happily             1  |
happy               1  | he                  1  | his                 1  |
is                  2  | large               1  | lived               1  |
major               1  | might               1  | never               1  |
of                  1  | passed              1  | personality.        1  |
pleasant            1  | senior              1  | success             1  |
the                 1  | they                1  | to                  2  |
top                 1  | vendor.             1  | was                 1  |
what                1  | wonder              1  | years               1  |
you                 2  |

Total    Word Count : 64

Distinct Word Count : 55
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void WriteWords (String  Word[],
                 int     Count[],
                 int     TotalWordCount,
                 int     DistinctWordCount)
{
  const char *Header1   = "    Word        Count   | ",
             *Header2   = "                        | ",
             *Separator = "   | ";

  const WORD_FW       = 17,
        COUNT_FW      = 4,
        WORDS_PER_ROW = 3;

  cout << "\n\n";

  if ( TotalWordCount == 0 )
    return;

  for ( int C = 1; C <= WORDS_PER_ROW;  ++C )
    cout << Header1;
  cout << endl;

  for ( C = 1; C <= WORDS_PER_ROW; ++C )
    cout << Header2;
  cout << endl;

  int N = 0;

  while ( N < DistinctWordCount )
    {
    for ( C = 1; C <= WORDS_PER_ROW && N < DistinctWordCount; ++C )
      {
      cout << setiosflags(ios::left)  << setw(WORD_FW) << Word[N];
      cout << setiosflags(ios::right) << setw(COUNT_FW)<< Count[N];
      cout << Separator;
	  cout << resetiosflags(ios::right);
      ++N;
      }
    cout << endl;
    }

  cout << "\nTotal    Word Count : " << TotalWordCount    << endl;
  cout << "\nDistinct Word Count : " << DistinctWordCount << endl;
}