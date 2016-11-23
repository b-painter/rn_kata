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

	while ( arabic >= 1 )
	{
		roman += "I";
		arabic--;
	}

	return roman;
}


