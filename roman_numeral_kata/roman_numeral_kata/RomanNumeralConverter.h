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
};


#endif

