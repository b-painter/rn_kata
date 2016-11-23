#include "RomanNumeralTest.h"

#include "RomanNumeralConverter.h"

#include <string>
#include <cassert>


// constructor
RomanNumeralTest::RomanNumeralTest()
{
}


// destructor
RomanNumeralTest::~RomanNumeralTest()
{
}


// test cases
void RomanNumeralTest::testConversions()
{
	RomanNumeralConverter converter;
	std::string romanNumeral;

	// arabic to roman tests
	romanNumeral = converter.ConvertArabicToRoman( 1 );
	assert( romanNumeral == "I" );

	romanNumeral = converter.ConvertArabicToRoman( 2 );
	assert( romanNumeral == "II" );

	romanNumeral = converter.ConvertArabicToRoman( 3 );
	assert( romanNumeral == "III" );

	romanNumeral = converter.ConvertArabicToRoman( 4 );
	assert( romanNumeral == "IV" );

	romanNumeral = converter.ConvertArabicToRoman( 5 );
	assert( romanNumeral == "V" );

	romanNumeral = converter.ConvertArabicToRoman( 8 );
	assert( romanNumeral == "VIII" );

	romanNumeral = converter.ConvertArabicToRoman( 9 );
	assert( romanNumeral == "IX" );

	romanNumeral = converter.ConvertArabicToRoman( 10 );
	assert( romanNumeral == "X" );

	romanNumeral = converter.ConvertArabicToRoman( 11 );
	assert( romanNumeral == "XI" );

	romanNumeral = converter.ConvertArabicToRoman( 20 );
	assert( romanNumeral == "XX" );

	romanNumeral = converter.ConvertArabicToRoman( 40 );
	assert( romanNumeral == "XL" );

	romanNumeral = converter.ConvertArabicToRoman( 50 );
	assert( romanNumeral == "L" );

	romanNumeral = converter.ConvertArabicToRoman( 60 );
	assert( romanNumeral == "LX" );

	romanNumeral = converter.ConvertArabicToRoman( 90 );
	assert( romanNumeral == "XC" );

}


