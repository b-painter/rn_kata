#include <iostream>

#include "RomanNumeralTest.h"


int main( void )
{
	// create a test object
	RomanNumeralTest test;

	// test conversions
	test.testArabicToRomanConversions();

	test.testRomanToArabicConversions();

	return 0;
}


