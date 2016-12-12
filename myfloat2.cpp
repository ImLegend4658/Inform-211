/*************************************************************************

PROGRAMMER:   Matt Holloway  and  John Russo
SOURCE:       MyFloat2.cpp
COMPILER:     Visual C++ .NET

DESCRIPTION:  Partially implements a class, "MyFloat2", that permits work
              with floating point numbers between 0 and 1 that have
              up to MAX_DIGITS digits of accuracy.
DATA
STRUCTURES    Digits of MyFloats are stored in an array [1..MAX_DIGITS + 1]
              of char, For example, after storing the real number 0.1207
              in the array Number, the array would look as follows.
			  
                0     1     2     3     4               19   20
             |-----+-----+-----+-----+-----+-       -+-----+-----+
     Number  | --- |  1  |  2  |  0  |  7  |   ...   |  0  |  0  |
             |-----+-----+-----+-----+-----+-       -+-----+-----+

	      The 0th position of the array is currently unused.

	      Also in the class data member list is

      MAX_DIGITS       Constant that holds the max number of
                       digits of accuracy for MyFloat members.

      NumberofDigits   Holds the number of digits that are used
                       to hold the MyFloat.

                       If NumberofDigits is 0, a MyFloat should
                       be regarded as unitialized.

    MEMBER FUNCTIONS :

          >>            Reads a MyFloat from standard intput. Standard
                        reading conventions should be followed.

          <<            Writes a leading 0, a decimal point, and the
                        digits in a MyFloat to standard output. If the
                        MyFloat is unititialized, a "0.?" is output.

	      Digits        Returns the number of valid digits of a MyFloat.

	      MaxDigits     Returns the maximum number of valid digits of MyFloat.

          =             Converts a string representing a float between
                        0 and 1 to a MyFloat. For example, if X is an
                        instance of MyFloat, a programmer could use
                        X = "0.1234567";

          ==            Returns 1 if two MyFloats are equal, 0 otherwise.

          >             Returns 1 if left hand side MyFloat is greater
                        than the rhs, 0 otherwise.

	      +             Computes the sum of two MyFloats.

*************************************************************************/
#include <iostream>
#include <ctype.h>
using namespace std;


class MyFloat
{
  enum { MAX_DIGITS =  20 };      // Private data members

  char Number[MAX_DIGITS + 1];
  char NumberofDigits;

public:

  MyFloat()                   // Inline default constructor
  {
    NumberofDigits = 0;
  }

  int Digits()                // inline member function Digits()
   {
     return NumberofDigits;
   }

  int MaxDigits()            // inline member function
   {
     return MAX_DIGITS;
   }

  MyFloat operator+ (const MyFloat& Rhs);

  MyFloat operator= (char* FloatStr);

  friend ostream& operator<< (ostream& Out, const MyFloat& X);

  friend istream& operator>> (istream& In, MyFloat& X);

  int operator>  (const MyFloat& Rhs);

  int operator== (const MyFloat& Rhs);
  
};

/*********************   operator>>  *************************************

   Uses the following rules in a attempt to read a MyFloat.

    - White space and leading zeros are skipped

    - If first non-whitespace char is not a '0' or '.' the function
      returns, with this->NumberofDigits set to 0.

    - Digits after the decimal point are stored in this->Number array

    - Input terminates when a non-numeric char is encountered. This
      character is left in the input stream.

   NOTE:  Caller should check Digits(). If it is set to 0 if an input
	  error has occured.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
istream& operator>> (istream& In, MyFloat& X)
{
  char Ch;
  int  N;

  X.NumberofDigits = 0;

  In >> Ch;                                      //    Skip whitespace.

  if ( !In.good() || Ch != '.' && Ch != '0' )
    return In;                                   //  NumberofDigits is 0.

  while ( isspace(Ch) || Ch == '0' )       //  Skip leading zeros and spaces
    Ch = In.get();

  if ( Ch != '.' || !In.good() )  // Input error or eof
    return In;

  In.get(Ch);                     //  Get first char to right of '.'

  X.NumberofDigits = 1;           //  We have at least 1 significant

  N = 0;
  while ( isdigit(Ch) && In.good() && N < X.MAX_DIGITS )
  {
    X.Number[++N] = Ch - '0';            //  Convert char to int
    Ch = In.get();
  }

  In.putback(Ch);     // put back last character read into input stream

  X.NumberofDigits = N;

  while ( N < X.MAX_DIGITS )       // Pad with trailing zeros
    X.Number[++N] = 0;

  return In;
}

/**********************  operator<< **************************************
   Displays a MyFloat X with accuracy to X.NumberofDigits decimal places
   showing.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ostream& operator<< (ostream& Out, const MyFloat& X)
{
  int N;

  Out << "0.";

  for (N = 1; N <= X.NumberofDigits; ++N)
  Out << int(X.Number[N]);

  if ( X.NumberofDigits == 0 )
    Out << '?';
  return Out;
}

/*****************************  operator+  ******************************
  Action  :  Will add two MyFloats together and return the MyFloat value.
             Standard addition rules apply, carry over into ones is
             ignored.

  Returns  :  A MyFloat that has addition of two other MyFloats
-----------------------------------------------------------------------*/
MyFloat MyFloat::operator+ (const MyFloat &N)
{
  MyFloat A;
  int Carry = 0, Sum;

  for (int k = MAX_DIGITS; k >= 1; k--)
    {
      Sum = Number[k] + N.Number[k] + Carry;

      if (Sum <= 9)
      {
         A.Number[k] = Sum;
         Carry = 0;
      }
      else
      {
         A.Number[k] = Sum % 10;
         Carry = 1;
      }
    }

  if (NumberofDigits > N.NumberofDigits)
     A.NumberofDigits = NumberofDigits;
  else
     A.NumberofDigits = N.NumberofDigits;

  return A;
}

/**********************   operator==  ***********************************

  Returns 1 if two MyFloats are equal, otherwise returns a 0. Ignores the
  NumberofDigits field and the FieldWidth field.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int MyFloat::operator== (const MyFloat& Rhs)
{
  int MaxLength, k;

  if ( NumberofDigits <= Rhs.NumberofDigits )
    MaxLength = Rhs.NumberofDigits;
  else
    MaxLength = NumberofDigits;

  for ( k = 1; k <= MaxLength; ++k )
    if ( Number[k] != Rhs.Number[k] )
      return 0;

  //  Assert:  All digits from 1..MaxLength are equal

  return 1;
}

/**********************   operator>   ***********************************

  Returns 1 if lhs < rhs, otherwise returns a 0. Ignores the
  NumberofDigits field and the FieldWidth field.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int MyFloat::operator>  (const MyFloat& Rhs)
{
  int k, ShortestNumberOfDigits;

  ShortestNumberOfDigits = (NumberofDigits < Rhs.NumberofDigits)
                           ? NumberofDigits : Rhs.NumberofDigits;


  for ( k = 1;  k <= ShortestNumberOfDigits; ++k )
    if ( Number[k] < Rhs.Number[k] )
      return 0;
    else if ( Number[k] > Rhs.Number[k] )
      return 1;

  //  Assert: Shorter operand has digits identical to first digits of longer

  if ( NumberofDigits >= Rhs.NumberofDigits ) // Rhs is not shorter and
    return 1;                                 // therefore not smaller

  else                        // *this has more digits
    return 0;
}

/***************************  operator=   ********************************

DESCRIPTION Allows MyFloat assignments of the form

            X = "0.1223334444";

PARAMETERS  Rhs (RightHandSide) a null terminated char array that represents
            a floating point number between 0 and 1. Blanks and zeros that
            precede the decimal point are ignored.

RETURNS     Reference to the newly changed MyFloat.

NOTE:       Caller can detect a format error by calling Digits(). If it
            returns a 0, then Rhs is illegally formatted.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
MyFloat MyFloat::operator= (char Rhs[] )
{
  int k = 0, n;

  NumberofDigits = 0;  // Flag to indicate unitialized MyFloat

  while ( (isspace(Rhs[k]) || Rhs[k] == '0') && Rhs[k] != 0  )    //  Skip blanks and zeros
    ++k;

  //  ASSERT:  Rhs[k] == '.' or Rhs[k] != 0

  if ( Rhs[k] != '.' )
    return *this;                 // Error, no decimal point

  ++k;                            // Move to char after '.'

  n = 1;

  while ( n <= MAX_DIGITS && isdigit(Rhs[k]) ) //  Copy rest of string
    Number[n++] = Rhs[k++] - '0';

  NumberofDigits = n - 1;

  while ( n < MAX_DIGITS )       // Pad with trailing zeros
    Number[++n] = 0;

  return *this;
}