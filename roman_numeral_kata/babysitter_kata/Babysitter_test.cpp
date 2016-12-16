#include "Babysitter_test.h"

#include "BabysitterBilling.h"

#include <string>
#include <cassert>
#include <iostream>
#include <iomanip>


// constructor
BabysitterTest::BabysitterTest()
{
}


// destructor
BabysitterTest::~BabysitterTest()
{
}


void BabysitterTest::test_babysitter()
{
	// execute the arabic to roman test cases
	BabysitterBilling billing;

	double charge;
	
	charge = billing.compute( 21.0 , 23.0 , 21.0 );
	assert ( charge == 16.0 );

	charge = billing.compute( 21.0 , 24.0 , 21.0 );
	assert ( charge == 24.0 );

	charge = billing.compute( 21.0 , 24.0 , 22.0 );
	assert ( charge == 28.0 );

	charge = billing.compute( 21.0 , 25.0 , 22.0 );
	assert ( charge == 44.0 );

	charge = billing.compute( 22.0 , 24.0 , 21.0 );
	assert ( charge == 16.0 );

}


