/*************************************************************************
PROGRAMMER:   Matt Holloway  and  John Russo
SOURCE:       MyFloatD.cpp
COMPILER:     Visual C++ .NET

DESCRIPTION:  Implements a dynamic class, "MyFloatD", that permits work
              with floating point numbers between 0 and 1 that represent
              decimals, such as 0.1 with perfect accuracy.
DATA
STRUCTURES    Digits are stored in a dynamic array [0..MaxDigit + 1]
              of  char, For example, after storing the real number 0.1207
              in the array Number, the array would look as follows.
			  
                 0     1     2     3     4               MAX_DIGITS
             |-----+-----+-----+-----+-----+-       -+-----+-----+
     Number  | --- |  1  |  2  |  0  |  7  |   ...   |  0  |  0  |
             |-----+-----+-----+-----+-----+-       -+-----+-----+

	      The 0th position of the array is not unused.

	      Also in the class data member list is

	      MaxDigits        Holds the max number of digits that a
                           MyFloat instance can have

	      NumberOfDigits   Holds the number of digits that are
                           currently used to hold the MyFloat.

                           If NumberOfDigits is 0, a MyFloat should
                           be regarded as unitialized.

          MEMBER FUNCTIONS

              >>            Reads a MyFloat from standard intput. Standard
                            reading conventions should be followed.

              <<            Writes a leading 0, a decimal point, and the
                            digits in a MyFloat to standard output. If the
                            MyFloat is unititialized, a "0.?" is output.

              Digits        Returns the number of valid digits of a
                            MyFloat.

              Dig           Returns the Nth digit of a MyFloat.

              MaxDigits     Returns the maximum number of valid digits of
                            MyFloat.

              =             Converts a string representing a float between
                            0 and 1 to a MyFloat. For example, if X is an
                            instance of MyFloat, a programmer could use
                            X = "0.1234567";

              ==            Returns 1 if two MyFloats are equal, 0 otherwise.

              >             Returns 1 if left hand side MyFloat is greater
                            than the rhs, 0 otherwise.

              +             Computes the sum of two huge ints.
*************************************************************************/
#include <iostream>
#include <ctype.h>
#include <new>
using namespace std;

class MyFloat
{
  char *Number;

  enum { DEFAULT_LENGTH = 10 };   // Default string length

  int  NumberOfDigits;
  int  MaxNumberOfDigits;

public:

 ~MyFloat();

  MyFloat ()                  // Inline default constructor
  {
    NumberOfDigits = 0;
    MaxNumberOfDigits = DEFAULT_LENGTH;
    Number = new(nothrow) char[DEFAULT_LENGTH+1];
    if ( Number == NULL )
      MaxNumberOfDigits = 0;
    else
      for ( int k = 1; k <= MaxNumberOfDigits; ++k )
	Number[k] = 0;
  }

  MyFloat (const MyFloat &X);

  MyFloat(unsigned Length);

  int Digits()
  { return NumberOfDigits; }

  int MaxDigits()
  {return MaxNumberOfDigits;}

  MyFloat operator+ (const MyFloat& Rhs);

  MyFloat operator= (char* FloatStr);

  MyFloat& operator= (const MyFloat &RightSide);

  friend ostream& operator<< (ostream& Cout, const MyFloat& X);

  friend istream& operator>> (istream& Cin, MyFloat& X);

  int operator== (const MyFloat& Rhs);

  int operator>  (const MyFloat& Rhs);

//int operator<= (const MyFloat& Rhs);

};


/************************  ~MyFloat  *************************************

   The class destructor. This function is called automatically
   when an instance of the MyFloat class goes out of scope. In particular,
   the destructor is called to return dynamically allocated storage when
   a function is exited. Storage for the following will be deallocated.

     1)  local variables
     2)  parameters passed by value

   Dealloacating dynamic memory crucial or memory leaks will eventually
   cause problems.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
MyFloat::~MyFloat()
{
  delete Number; // Return dynamic storage associated with Number.
}

/******************  MyFloat (copy constructor)    ***********************

  IMPORTANT   Because this constructor has a single MyFloat reference
  NOTE        parameter, the compiler automatically makes it the copy
              constructor for the MyFloat class.

  The copy constructor is called under the following circumstances.

  1)  When an instance of the MyFloat class is passed by value to a
      function, the copy constructor makes a copy of the class instance.

  2)  When a MyFloat is initialized in a declaration, as in
      "MyFloat X1 = X2;", the copy constructor is called to make a copy
      of X2.

  3)  When an instance of the MyFloat class is returned as a function
      value or from a MyFloat operater, the copy constructor makes a
      copy of the return value.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
MyFloat::MyFloat (const MyFloat &X)
{
  Number = new(nothrow) char[X.MaxNumberOfDigits+1]; //  Create storage for deep copy

  if ( Number == NULL )                     //  Memory allocation failed
    {
    MaxNumberOfDigits = 0;
    NumberOfDigits    = 0;
    }
  else
    {
    MaxNumberOfDigits = X.MaxNumberOfDigits; //  Make length fields the same
    NumberOfDigits    = X.NumberOfDigits;

    for ( int K = 1;  K <= X.MaxNumberOfDigits;  ++K )    //  Copy data in dynamic storage
      Number[K] = X.Number[K];
    }
}

/*********************   MyFloat (unsigned)  *****************************

   A constructor that allows declarations of the form "MyFloat X(100);",
   which creates a MyFloat having a maximum length of 100, and which is
   initialized to garbage.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
MyFloat::MyFloat(unsigned Length)
{
  Number = new(nothrow) char[Length + 1];

  if ( Number == NULL )                    // Memory allocation error
    MaxNumberOfDigits = 0;                // No memory available
  else
    MaxNumberOfDigits = Length;

  for ( int k = 1; k <= MaxNumberOfDigits; ++k )
    Number[k] = 0;

  NumberOfDigits = 0;
}


/*********************   operator>>  *************************************

   Uses the following rules in a attempt to read a MyFloat.

    - White space and leading zeros are skipped

    - If first non-whitespace char is not a '0' or '.' the function
      returns, with this->NumberOfDigits set to 0.

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

  X.NumberOfDigits = 0;

  In >> Ch;                                      //    Skip whitespace.

  if ( !In.good() || Ch != '.' && Ch != '0' )
    return In;                                   //  NumberOfDigits is 0.

  while ( In.good() && Ch == '0' )               //  Skip leading zeros
    Ch = In.get();

  if ( Ch != '.' || !In.good() )  // Input error or eof
    return In;

  In.get(Ch);                     //  Get first char to right of '.'

  if ( !isdigit(Ch) )              //  NumberOfDigits is still 0.
    return In;

  X.NumberOfDigits = 1;              //  We have at least 1 significant

  N = 0;
  while ( isdigit(Ch) && In.good() && N < X.MaxNumberOfDigits )
    {
    X.Number[++N] = Ch - '0';                       //  Convert char to int
    Ch = In.get();
    }

  if ( In.good() )    // Follow standard input conventions
    In.putback(Ch);

  X.NumberOfDigits = N;

  while ( N < X.MaxNumberOfDigits )       // Pad with trailing zeros
    X.Number[++N] = 0;

  return In;
}


/**********************   operator<<  ************************************

   Displays a MyFloat X with accuracy to X.NumberOfDigits decimal places
   showing.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ostream& operator<< (ostream& Out, const MyFloat& X)
{
  int N;

  Out << "0.";

  for (N = 1; N <= X.NumberOfDigits; ++N)
    Out << int(X.Number[N]);

  if ( X.NumberOfDigits == 0 )
    Out << '?';

  return Out;
}

/**********************   operator+   ************************************

  Adds X and Y to yield Sum. The algorithm learned in grade school is
  used, adding pairs of digits, starting from the right an having
  occasional carries. The code depends on the fact that unused
  digits of a MyFloat are set to zero by constructor MyFloat(unsigned).

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
MyFloat MyFloat::operator+ (const MyFloat& Rhs)
{
  int k,
      DigitsInSum;

  if ( NumberOfDigits > Rhs.NumberOfDigits )
    DigitsInSum = NumberOfDigits;
  else
    DigitsInSum = Rhs.NumberOfDigits;

  MyFloat Sum(DigitsInSum);          //  Constructor zeros out digit array

  if ( Sum.MaxNumberOfDigits == 0 )  // Out of memory
    return Sum;
  else if ( this->MaxNumberOfDigits == 0 || Rhs.MaxNumberOfDigits == 0 )
    {
    Sum.MaxNumberOfDigits = 0;
    return Sum;
    }
  Sum.NumberOfDigits = DigitsInSum;

  for ( k = DigitsInSum; k >= 1; --k )
    {
    if ( k <= NumberOfDigits && k <= Rhs.NumberOfDigits )
      Sum.Number[k] += Number[k] + Rhs.Number[k];

    else if ( k > Rhs.NumberOfDigits )       // Right operand used up
      Sum.Number[k] += Number[k];

    else                                            // Left operand used up
      Sum.Number[k] += Rhs.Number[k];

    if ( Sum.Number[k] >= 10 )        // Need to carry a 1
      {
      Sum.Number[k]     -= 10;        // Can't store more than 9 in Number
      ++Sum.Number[k - 1];            // Carry is at most 1
      }
    }

  return Sum;
}


/**********************   operator==  ***********************************

  Returns 1 if two MyFloats are equal, otherwise returns a 0. Ignores the
  NumberOfDigits field and the FieldWidth field.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int MyFloat::operator== (const MyFloat& Rhs)
{
  MyFloat Shorter, Longer;

  if ( NumberOfDigits <= Rhs.NumberOfDigits )
    {
    Shorter = *this;
    Longer  = Rhs;
    }
  else
    {
    Longer  = *this;
    Shorter = Rhs;
    }

  for ( int k = 1; k <= Shorter.NumberOfDigits; ++k ) // Check first part
    if ( Shorter.Number[k] != Longer.Number[k] )
      return 0;

  while ( k <= Longer.NumberOfDigits )         // Check last part
    if ( Longer.Number[k++] != 0 )              // Must have trailing zeros
      return 0;

  //  Assert:  All digits from 1..Longer.MaxLength are equal

  return 1;
}

/**********************   operator<=  ***********************************

  Returns 1 if two MyFloats are equal, otherwise returns a 0. Ignores the
  NumberOfDigits field and the FieldWidth field.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int MyFloat::operator<= (const MyFloat& Rhs)

{
  int k, ShortestNumberOfDigits;

  ShortestNumberOfDigits = NumberOfDigits < Rhs.NumberOfDigits ? NumberOfDigits : Rhs.NumberOfDigits;

  for ( k = 1;  k <= ShortestNumberOfDigits; ++k )
    if ( Number[k] > Rhs.Number[k] )
      return 0;
    else if ( Number[k] < Rhs.Number[k] )
      return 1;

  //  Assert: Shorter operand has digits identical to first digits of longer

  if ( NumberOfDigits <= Rhs.NumberOfDigits ) // Rhs is not shorter and therefore not smaller
    return 1;

  else                        // *this has more digits
    return 0;

}
*/

/**********************   operator>   ***********************************

  Returns 1 if lhs < rhs, otherwise returns a 0. Ignores the
  NumberOfDigits field and the FieldWidth field.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int MyFloat::operator>  (const MyFloat& Rhs)
{
  int k, ShortestNumberOfDigits;

  ShortestNumberOfDigits = NumberOfDigits < Rhs.NumberOfDigits ? NumberOfDigits : Rhs.NumberOfDigits;

  for ( k = 1;  k <= ShortestNumberOfDigits; ++k )
    if ( Number[k] < Rhs.Number[k] )
      return 0;
    else if ( Number[k] > Rhs.Number[k] )
      return 1;

  //  Assert: Shorter operand has digits identical to first digits of longer

  if ( NumberOfDigits >= Rhs.NumberOfDigits ) // Rhs is not shorter and therefore not smaller
    return 1;

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
  int k = 0, n, i, NumberCharLeft = 0;

  NumberOfDigits = 0;  // Flag to indicate unitialized MyFloat

  while ( (isspace(Rhs[k]) || Rhs[k] == '0') && Rhs[k] != 0  )    //  Skip blanks and zeros
    ++k;

 //  ASSERT:  Rhs[k] == '.' or Rhs[k] = 0

  if ( Rhs[k] != '.' )
    return *this;                 // Error, no decimal point

  ++k;                            // Move to char after '.'

  i = k;              // determine length of remaining array to make sure not to big
  while (Rhs[i++])
     ++NumberCharLeft;

  if (MaxNumberOfDigits < NumberCharLeft)
  {
	delete[] Number;	// deallocate storage
	
	Number = new(nothrow) char[NumberCharLeft + 1];  // allocate enough space
	if (Number == NULL)                     // check for free memory
	  return *this;

	MaxNumberOfDigits = NumberCharLeft;   // new MyFloat has new maximum length
  }

  n = 1;

  while ( n <= MaxNumberOfDigits && isdigit(Rhs[k]) ) //  Copy rest of string
    Number[n++] = Rhs[k++] - '0';

  
  NumberOfDigits = n - 1;

  while ( n < MaxNumberOfDigits )       // Pad with trailing zeros
    Number[++n] = 0;

  return *this;
}
/*************************** operator=     ******************************

  Called when an assignment of the form S1 = S2, where S1 and S2 are
  both instances of the MyFloat class. If this routine were not written,
  the system would supply a "standard" assignment operator, which would
  not work properly. It would copy only the address stored in S2.Number, and
  not the data pointed to by S2.Number. This copying of a pointer only is
  usually called a "shallow copy".
  The function below makes what is called a "deep copy", i.e. it copies
  all of the fields of S2 as well as the data pointed to by S2.Number.

  If the receiving MyFloat is too small additional memory is allocated.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
MyFloat& MyFloat::operator= (const MyFloat &Rhs)
{
  int K = 0;

  if ( this == &Rhs )             // Don't copy MyFloat to itself
    return *this;

  if ( MaxNumberOfDigits < Rhs.NumberOfDigits )         // Not enought room in *this
    {
    delete[] Number;                            // Deallocate storage

    Number = new(nothrow) char[Rhs.NumberOfDigits + 1];  // Allocate enough space
    if ( Number == NULL )                       // Not enough free memory
      return *this;

    MaxNumberOfDigits = Rhs.NumberOfDigits;    // New MyFloat has length of Rhs
    }
  NumberOfDigits = Rhs.NumberOfDigits;         // New MyFloat has length of Rhs

  for ( K = 1; K <= Rhs.NumberOfDigits; ++K )
    Number[K] = Rhs.Number[K];                   // Copy char from Rhs to Lhs.

  return *this;   //  Allow cascading of operator, i.e. allow statements
}                 //    of the form "S1 = S2 = S3;"
