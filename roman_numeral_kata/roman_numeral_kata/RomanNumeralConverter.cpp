#include "RomanNumeralConverter.h"

#include <string>
#include <cassert>


// constructor
RomanNumeralConverter::RomanNumeralConverter()
{
}


// destructor
RomanNumeralConverter::~RomanNumeralConverter()
{
}


// function to build up a roman numeral string a piece at a time from the arabic number
// based on how large the remaining number is
bool RomanNumeralConverter::BuildRomanNumeral( std::string &roman , unsigned int &arabic , unsigned int value , char *c )
{
	bool valid = true;
	int nbSeq = 0;

	while ( arabic >= value )
	{
		if ( ++nbSeq > 3 ) valid = false;
		roman += c;
		arabic -= value;
	}

	return valid;
}


// conversion from arabic numbers to roman numerals
std::string RomanNumeralConverter::ConvertArabicToRoman( unsigned int arabic )
{
	// struct definition and array of integer values to convert an arabic number
	// into roman numeral a piece at time
	struct ArabicValues
	{
		unsigned int arabicValue;
		char         romanLetters[4];
	};

	ArabicValues arabicValues[] = 
	{
		// process the largest values first, leaving progressively smaller integers
		// to convert and append to the output string
		{ 1000 , "M"  } ,
		{  900 , "CM" } ,
		{  500 , "D"  } ,
		{  400 , "CD" } ,
		{  100 , "C"  } ,
		{   90 , "XC" } ,
		{   50 , "L"  } ,
		{   40 , "XL" } ,
		{   10 , "X"  } ,
		{    9 , "IX" } ,
		{    5 , "V"  } ,
		{    4 , "IV" } ,
		{    1 , "I"  } ,
	};


	// variables used to check the input number for validity
	bool invalid = false;
	int nbSeqM = 0;

	// perform the conversion from arabic to roman
	std::string roman;

	for ( int i=0 ; i<sizeof(arabicValues)/sizeof(ArabicValues) ; i++ )
	{
		bool validConversion = BuildRomanNumeral( roman , arabic , arabicValues[i].arabicValue , arabicValues[i].romanLetters );
		if ( ! validConversion ) invalid = true;
	}

	// return result
	if ( invalid ) return "";

	return roman;
}


// conversion from roman numerals to arabic numbers
unsigned int RomanNumeralConverter::ConvertRomanToArabic( std::string roman  )
{
	int arabic = 0;  // signed int here, to handle cases such as IX, where value 
	                 // will temporarily go negative (-1) before adding 10

	// variables used to check the input string for validity
	bool invalid = false;
	int nbV = 0;
	int nbL = 0;
	int nbD = 0;
	int nbSeqI = 0;
	int nbSeqX = 0;
	int nbSeqC = 0;
	int nbSeqM = 0;

	// process the input string
	unsigned int len = roman.length();
	for ( std::string::size_type i=0 ; i<len ; i++ )
	{
		// get the current and next characters
		char c = toupper(roman[i]);
		char n = toupper(roman[i+1]);

		// reset the counts for repeating I, X, C, M
		if ( c != 'I' ) nbSeqI = 0;
		if ( c != 'X' ) nbSeqX = 0;
		if ( c != 'C' ) nbSeqC = 0;
		if ( c != 'M' ) nbSeqM = 0;

		switch ( c )
		{
		// roman numeral I
		case 'I':
			// count multiple sequential I's
			if ( ++nbSeqI > 3 ) invalid = true;

			// look for an I preceding a higher value character
			if ( i < (len-1) )
			{
				if ( (n == 'L') || (n == 'C') || (n == 'D') || (n == 'M') )
				{
					// invalid subtraction of I from L, C, D, or M
					invalid = true;
				}
				else if ( (n == 'V') || (n == 'X') )
				{
					if ( nbSeqI > 1 )
					{
						// invalid multiple I's being subtracted
						invalid = true;
					}
					else
					{
						// valid subtraction of I from V or X, subtract 1
						arabic -= 1;
					}
				}
				else
				{
					// this I does not precede V or X, add 1
					arabic += 1;
				}
			}
			else
			{
				// this I is the last character in the roman numeral, add 1
				arabic += 1;
			}
			break;

		// roman numeral V
		case 'V':
			// look for an V preceding an X, L, C, D, or M
			if ( i < (len-1) )
			{
				if ( (n == 'X') || (n == 'L') || (n == 'C') || (n == 'D') || (n == 'M') )
				{
					// invalid subtraction of V
					invalid = true;
				}
			}
			arabic += 5;
			if ( ++nbV > 1 ) invalid = true;
			break;

		// roman numeral X
		case 'X':
			// count multiple sequential X's
			if ( ++nbSeqX > 3 ) invalid = true;

			// look for an X preceding a higher value character
			if ( i < (len-1) )
			{
				if ( (n == 'D') || (n == 'M') )
				{
					// invalid subtraction of X from D or M
					invalid = true;
				}
				else if ( (n == 'L') || (n == 'C') )
				{
					if ( nbSeqX > 1 )
					{
						// invalid multiple X's being subtracted
						invalid = true;
					}
					else
					{
						// valid subtraction of X from L or C, subtract 10
						arabic -= 10;
					}
				}
				else
				{
					// this X does not precede L or C, add 10
					arabic += 10;
				}
			}
			else
			{
				// this X is the last character in the roman numeral, add 10
				arabic += 10;
			}
			break;

		// roman numeral L
		case 'L':
			// look for an L preceding a C, D, or M
			if ( i < (len-1) )
			{
				if ( (n == 'C') || (n == 'D') || (n == 'M') )
				{
					// invalid subtraction of L
					invalid = true;
				}
			}
			arabic += 50;
			if ( ++nbL > 1 ) invalid = true;
			break;

		// roman numeral C
		case 'C':
			// count multiple sequential C's
			if ( ++nbSeqC > 3 ) invalid = true;

			// look for an C preceding D or M
			if ( i < (len-1) )
			{
				if ( (n == 'D') || (n == 'M') )
				{
					if ( nbSeqC > 1 )
					{
						// invalid multiple C's being subtracted
						invalid = true;
					}
					else
					{
						// valid subtraction of C from D or M, subtract 100
						arabic -= 100;
					}
				}
				else
				{
					// this C does not precede D or M, add 100
					arabic += 100;
				}
			}
			else
			{
				// this C is the last character in the roman numeral, add 100
				arabic += 100;
			}
			break;

		// roman numeral D
		case 'D':
			// look for a D preceding an M
			if ( i < (len-1) )
			{
				if ( n == 'M' )
				{
					// invalid subtraction of D
					invalid = true;
				}
			}
			arabic += 500;
			if ( ++nbD > 1 ) invalid = true;
			break;

		// roman numeral M
		case 'M':
			// count multiple sequential M's
			if ( ++nbSeqM > 3 ) invalid = true;

			arabic += 1000;
			break;

		default:
			// found an invalid roman numeral character, return arabic number 0
			invalid = true;
			break;
		}
	}

	if ( invalid ) return 0;

	assert( arabic >= 0 );
	return (unsigned int)arabic;
}


