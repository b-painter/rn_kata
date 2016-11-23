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


