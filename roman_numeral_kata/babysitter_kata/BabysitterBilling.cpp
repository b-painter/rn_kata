#include "BabysitterBilling.h"

#include <string>
#include <cassert>


// constructor
BabysitterBilling::BabysitterBilling()
{
}


// destructor
BabysitterBilling::~BabysitterBilling()
{
}


double BabysitterBilling::compute( double start , double end , double bedtime )
{
	const double startToBedRate = 12.0;
	const double bedToMidnightRate = 8.0;
	const double midnightToEndRate = 16.0;
	const double midnight = 24.0;

	double charge = 0.0;

	double earlier = (end < midnight) ? end : midnight;
	double later = (start > bedtime) ? start : bedtime;

	double startToBedTime    = (bedtime - start) >= 0.0 ? (bedtime - start) : 0.0;
	double bedToMidnightTime = (earlier - later) >= 0.0 ? (earlier - later) : 0.0;
	double midnightToEndTime = (end - midnight) >= 0.0 ? (end - midnight) : 0.0;

	charge += ( startToBedRate    * startToBedTime    );
	charge += ( bedToMidnightRate * bedToMidnightTime );
	charge += ( midnightToEndRate * midnightToEndTime );

	return charge;
}



