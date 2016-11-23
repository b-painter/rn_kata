#include <iostream>

#include "RomanNumeralTest.h"


int main( void )
{
	// create a test object
	RomanNumeralTest test;

	// arabic to roman test conversions
	std::cout << "Executing arabic number to roman numeral tests:" << std::endl;
	std::cout << std::endl;

	test.testArabicToRomanConversions();

	std::cout << std::endl;

	// roman to arabic test conversions
	std::cout << "Executing roman numeral to arabic number tests:" << std::endl;
	std::cout << std::endl;

	test.testRomanToArabicConversions();

	std::cout << std::endl;

	// complete
	return 0;
}


