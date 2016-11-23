#include "RomanNumeralConverter.h"

#include <string>


// constructor
RomanNumeralConverter::RomanNumeralConverter()
{
}


// destructor
RomanNumeralConverter::~RomanNumeralConverter()
{
}


// conversion from arabic numbers to roman numerals
std::string RomanNumeralConverter::ConvertArabicToRoman( int arabic )
{
	std::string roman;

	// add X's for 10's
	while ( arabic >= 10 )
	{
		roman += "X";
		arabic -= 10;
	}

	// add V's for 5's
	while ( arabic >= 5 )
	{
		roman += "V";
		arabic -= 5;
	}

	// add I's for 1's
	while ( arabic >= 1 )
	{
		roman += "I";
		arabic--;
	}

	return roman;
}


