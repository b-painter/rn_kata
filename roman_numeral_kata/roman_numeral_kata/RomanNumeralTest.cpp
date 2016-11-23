#include "RomanNumeralTest.h"

#include "RomanNumeralConverter.h"

#include <string>
#include <cassert>
#include <iostream>
#include <iomanip>


// constructor
RomanNumeralTest::RomanNumeralTest()
{
}


// destructor
RomanNumeralTest::~RomanNumeralTest()
{
}


// struct for initializing converstions to test
struct ArabicRomanPair
{
	unsigned int arabicNumber;
	char         romanNumeral[16];
};


// test cases for arabic to roman conversions
void RomanNumeralTest::testArabicToRomanConversions()
{
	ArabicRomanPair testPairs[] = 
	{
		// test cases used during development
		{    1 , "I" } ,
		{    2 , "II" } ,
		{    3 , "III" } ,
		{    4 , "IV" } ,
		{    5 , "V" } ,
		{    8 , "VIII" } ,
		{    9 , "IX" } ,
		{   10 , "X" } ,
		{   11 , "XI" } ,
		{   20 , "XX" } ,
		{   40 , "XL" } ,
		{   50 , "L" } ,
		{   60 , "LX" } ,
		{   90 , "XC" } ,
		{  100 , "C" } ,
		{  110 , "CX" } ,
		{  111 , "CXI" } ,
		{  149 , "CXLIX" } ,
		{  198 , "CXCVIII" } ,
		{  200 , "CC" } ,
		{  300 , "CCC" } ,
		{  400 , "CD" } ,
		{  500 , "D" } ,
		{  600 , "DC" } ,
		{  800 , "DCCC" } ,
		{  900 , "CM" } ,
		{ 1000 , "M" } ,
		{ 2000 , "MM" } ,
		{ 3000 , "MMM" } ,

		// since there is no roman numeral representing more than 1000,
		// and the rules dictate that M can only repeat at most 3 times,
		// the highest arabic integer that can be tested is 3999
		{ 3999 , "MMMCMXCIX" } , 

		// sanity check for passing in 0
		{    0 , "" } , 

		// test cases specified in the kata
		{    1 , "I" } , 
		{    3 , "III" } , 
		{    9 , "IX" } , 
		{ 1066 , "MLXVI" } , 
		{ 1989 , "MCMLXXXIX" } , 
	};


	// execute the arabic to roman test cases
	RomanNumeralConverter converter;
	std::string romanNumeral;

	for ( int i=0 ; i<sizeof(testPairs)/sizeof(ArabicRomanPair) ; i++ )
	{
		// output to console the conversion about to occur
		std::cout << "Testing conversion from " 
			      << std::right << std::setw( 4) << testPairs[i].arabicNumber << " to " 
				  << std::left  << std::setw(10) << testPairs[i].romanNumeral << " : ";

		// perform the conversion
		romanNumeral = converter.ConvertArabicToRoman( testPairs[i].arabicNumber );

		// evaluate the conversion and output to console
		bool didPass = (romanNumeral == testPairs[i].romanNumeral);
		std::cout << (didPass ? "passed" : "       FAILED") << std::endl;
	}
}


// test cases for roman to arabic conversions
void RomanNumeralTest::testRomanToArabicConversions()
{
	ArabicRomanPair testPairs[] = 
	{
		// test cases used during development
		{    1 , "I" } ,
		{    2 , "II" } ,
		{    3 , "III" } ,
		{    4 , "IV" } ,
		{    5 , "V" } ,
		{    6 , "VI" } ,
		{    9 , "IX" } ,
		{   10 , "X" } ,
		{   30 , "XXX" } ,
		{   40 , "XL" } ,
		{   70 , "LXX" } ,
		{   90 , "XC" } ,
		{  100 , "C" } ,
		{  110 , "CX" } ,
		{  400 , "CD" } ,
		{  600 , "DC" } ,
		{ 1000 , "M" } ,

		// since there is no roman numeral representing more than 1000,
		// and the rules dictate that M can only repeat at most 3 times,
		// the highest arabic integer that can be tested is 3999
		{ 3999 , "MMMCMXCIX" } ,

		// sanity check for passing in string with invalid character
		{    0 , "G" } ,

		// use cases specified in the kata
		{    1 , "I" } ,
		{    3 , "III" } ,
		{    9 , "IX" } ,
		{ 1066 , "MLXVI" } ,
		{ 1989 , "MCMLXXXIX" } ,

		// sanity checks for passing in invalid roman numeral strings
		{    0 , "VV" } ,
		{    0 , "LL" } ,
		{    0 , "DD" } ,
		{    0 , "IIII" } ,
		{    0 , "XXXX" } ,
		{    0 , "CCCC" } ,
		{    0 , "MMMM" } ,
		{    0 , "IL" } ,
		{    0 , "IC" } ,
		{    0 , "ID" } ,
		{    0 , "IM" } ,
		{    0 , "XD" } ,
		{    0 , "XM" } ,
		{    0 , "VX" } ,
		{    0 , "VL" } ,
		{    0 , "VC" } ,
		{    0 , "VD" } ,
		{    0 , "VM" } ,
		{    0 , "LC" } ,
		{    0 , "LD" } ,
		{    0 , "LM" } ,
		{    0 , "DM" } ,
		{    0 , "IIV" } ,
		{    0 , "IIX" } ,
		{    0 , "XXL" } ,
		{    0 , "XXC" } ,
		{    0 , "CCD" } ,
		{    0 , "CCM" } ,
	};


	// execute the roman to arabic test cases
	RomanNumeralConverter converter;
	unsigned int arabicNumber = 0;

	for ( int i=0 ; i<sizeof(testPairs)/sizeof(ArabicRomanPair) ; i++ )
	{
		// output to console the conversion about to occur
		std::cout << "Testing conversion from " 
				  << std::left  << std::setw(10) << testPairs[i].romanNumeral << " to "
			      << std::right << std::setw( 4) << testPairs[i].arabicNumber << " : " ;

		// perform the conversion
		arabicNumber = converter.ConvertRomanToArabic( testPairs[i].romanNumeral );

		// evaluate the conversion and output to console
		bool didPass = (arabicNumber == testPairs[i].arabicNumber);
		std::cout << (didPass ? "passed" : "       FAILED") << std::endl;
	}
}


