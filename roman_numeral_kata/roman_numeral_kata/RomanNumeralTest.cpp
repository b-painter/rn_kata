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

	romanNumeral = converter.ConvertArabicToRoman( 100 );
	assert( romanNumeral == "C" );

	romanNumeral = converter.ConvertArabicToRoman( 110 );
	assert( romanNumeral == "CX" );

	romanNumeral = converter.ConvertArabicToRoman( 111 );
	assert( romanNumeral == "CXI" );

	romanNumeral = converter.ConvertArabicToRoman( 149 );
	assert( romanNumeral == "CXLIX" );

	romanNumeral = converter.ConvertArabicToRoman( 198 );
	assert( romanNumeral == "CXCVIII" );

	romanNumeral = converter.ConvertArabicToRoman( 200 );
	assert( romanNumeral == "CC" );

	romanNumeral = converter.ConvertArabicToRoman( 300 );
	assert( romanNumeral == "CCC" );

	romanNumeral = converter.ConvertArabicToRoman( 400 );
	assert( romanNumeral == "CD" );

	romanNumeral = converter.ConvertArabicToRoman( 500 );
	assert( romanNumeral == "D" );

	romanNumeral = converter.ConvertArabicToRoman( 600 );
	assert( romanNumeral == "DC" );

	romanNumeral = converter.ConvertArabicToRoman( 800 );
	assert( romanNumeral == "DCCC" );

	romanNumeral = converter.ConvertArabicToRoman( 900 );
	assert( romanNumeral == "CM" );

	romanNumeral = converter.ConvertArabicToRoman( 1000 );
	assert( romanNumeral == "M" );

	romanNumeral = converter.ConvertArabicToRoman( 2000 );
	assert( romanNumeral == "MM" );

	romanNumeral = converter.ConvertArabicToRoman( 3000 );
	assert( romanNumeral == "MMM" );

}


