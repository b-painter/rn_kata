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


// conversion from arabic numbers to roman numerals
std::string RomanNumeralConverter::ConvertArabicToRoman( unsigned int arabic )
{
	std::string roman;

	// the kata didn't specify any sanity checking, so I am doing none
	// - unsigned int forces the input to be >= 0
	// - but large inputs could cause a long string of M's to be produced

	// process the largest values first, leaving progressively smaller integers
	// to convert and append to the output string

	// add M's for 1000's
	while ( arabic >= 1000 )
	{
		roman += "M";
		arabic -= 1000;
	}

	// add CM's for 900's
	while ( arabic >= 900 )
	{
		roman += "CM";
		arabic -= 900;
	}

	// add D's for 500's
	while ( arabic >= 500 )
	{
		roman += "D";
		arabic -= 500;
	}

	// add CD's for 400's
	while ( arabic >= 400 )
	{
		roman += "CD";
		arabic -= 400;
	}

	// add C's for 100's
	while ( arabic >= 100 )
	{
		roman += "C";
		arabic -= 100;
	}

	// add XC's for 90's
	while ( arabic >= 90 )
	{
		roman += "XC";
		arabic -= 90;
	}

	// add L's for 50's
	while ( arabic >= 50 )
	{
		roman += "L";
		arabic -= 50;
	}

	// add XL's for 40's
	while ( arabic >= 40 )
	{
		roman += "XL";
		arabic -= 40;
	}

	// add X's for 10's
	while ( arabic >= 10 )
	{
		roman += "X";
		arabic -= 10;
	}

	// add IX's for 9's
	while ( arabic >= 9 )
	{
		roman += "IX";
		arabic -= 9;
	}

	// add V's for 5's
	while ( arabic >= 5 )
	{
		roman += "V";
		arabic -= 5;
	}

	// add IV's for 4's
	while ( arabic >= 4 )
	{
		roman += "IV";
		arabic -= 4;
	}

	// add I's for 1's
	while ( arabic >= 1 )
	{
		roman += "I";
		arabic--;
	}

	return roman;
}


// conversion from roman numerals to arabic numbers
unsigned int RomanNumeralConverter::ConvertRomanToArabic( std::string roman  )
{
	int arabic = 0;  // signed int here, to handle cases such as IX, where value 
	                 // will temporarily go negative (-1) before adding 10

	unsigned int len = roman.length();
	for ( std::string::size_type i=0 ; i<len ; i++ )
	{
		switch ( toupper(roman[i]) )
		{
		// roman numeral I
		case 'I':
			// look for an I preceding V or X
			if ( i < (len-1) )
			{
				if ( (toupper(roman[i+1]) == 'V') || (toupper(roman[i+1]) == 'X') )
				{
					// this I precedes either V or X, subtract 1
					arabic -= 1;
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
			arabic += 5;
			break;

		// roman numeral X
		case 'X':
			// look for an X preceding L or C
			if ( i < (len-1) )
			{
				if ( (toupper(roman[i+1]) == 'L') || (toupper(roman[i+1]) == 'C') )
				{
					// this X precedes either L or C, subtract 10
					arabic -= 10;
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
			arabic += 50;
			break;

		// roman numeral C
		case 'C':
			// look for an C preceding D or M
			if ( i < (len-1) )
			{
				if ( (toupper(roman[i+1]) == 'D') || (toupper(roman[i+1]) == 'M') )
				{
					// this C precedes either D or M, subtract 100
					arabic -= 100;
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
			arabic += 500;
			break;

		default:
			// found an invalid roman numeral character, return arabic number 0
			return 0;
			break;
		}
	}

	assert( arabic >= 0 );
	return (unsigned int)arabic;
}


