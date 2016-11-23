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

	romanNumeral = converter.ConvertArabicToRoman( 5 );
	assert( romanNumeral == "V" );

}


