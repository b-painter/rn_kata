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


