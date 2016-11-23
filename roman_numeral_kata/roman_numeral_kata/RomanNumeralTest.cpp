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

	// arabic to roman tests
	std::string romanNumeral = converter.ConvertArabicToRoman( 1 );
	assert( romanNumeral == "I" );
}


