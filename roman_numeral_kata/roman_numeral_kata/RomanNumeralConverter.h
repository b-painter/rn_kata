#ifndef __RomanNumeralConverter__
#define __RomanNumeralConverter__

#include <string>


class RomanNumeralConverter
{
public:
	RomanNumeralConverter();
	~RomanNumeralConverter();

	std::string  ConvertArabicToRoman( unsigned int arabic );
	unsigned int ConvertRomanToArabic( std::string  roman  );

private:
	bool         BuildRomanNumeral( std::string &roman , unsigned int &arabic , unsigned int value , char *c );
};


#endif

