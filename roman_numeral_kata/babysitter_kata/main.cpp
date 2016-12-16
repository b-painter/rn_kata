#include <iostream>

#include "Babysitter_test.h"


int main( void )
{
	// create a test object
	BabysitterTest test;

	std::cout << "Executing tests:" << std::endl;
	std::cout << std::endl;

	test.test_babysitter();

	std::cout << std::endl;

	// complete
	return 0;
}


