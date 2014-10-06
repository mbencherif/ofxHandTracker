#include <iostream>
#include "FingerParameters.h"

namespace ofxHT {

/* DEPRECATED:
Parameters::Parameters(void)
{
}


Parameters::~Parameters(void)
{
}
*/
/*
DiscreteLocalParameters::DiscreteLocalParameters(int _params) {
	params = _params;

	//params = params & 0x11111;

	//cout << "INPUT PARAMS: " << params << endl;

	int value = 0;
	int index = 0;

	while(index < 5) {
		value = params & 0x1;
		states[index] = value;
		//cout << "PARAMS: " << params << " INDEX: " << index << " VALUE: " << value << endl;

		params = params >> 1; //params / 2;
		index++;
	}
}
*/

FingerParameters FingerParameters::operator+(const FingerParameters&  other)
{
	FingerParameters temp;

	temp.fz1 = fz1 + other.fz1;
	temp.fz2 = fz2 + other.fz2;
	temp.fz3 = fz3 + other.fz3;
	temp.fz4 = fz4 + other.fz4;

	temp.fx1 = fx1 + other.fx1;
	temp.fx2 = fx2 + other.fx2;
	temp.fx3 = fx3 + other.fx3;
	temp.fx4 = fx4 + other.fx4;
	
	temp.tz = tz + other.tz;
	temp.tx = tx + other.tx;

	temp.clampParams();

	return temp;

	/*return FingerParameters(fz1 + other.fz1,
						   fz2 + other.fz2,
						   fz3 + other.fz3,
						   fz4 + other.fz4,
						   tx + other.tx,
						   tz + other.tz);
						   */
}

FingerParameters FingerParameters::operator-(const FingerParameters&  other)
{
	return FingerParameters(fz1 - other.fz1,
						   fz2 - other.fz2,
						   fz3 - other.fz3,
						   fz4 - other.fz4,
						   tx - other.tx,
						   tz - other.tz);
}

FingerParameters FingerParameters::operator*(const float factor)
{
	return FingerParameters(fz1*factor,
						   fz2*factor,
						   fz3*factor,
						   fz4*factor,
						   tx*factor,
						   tz*factor);
}
/*
FingerParameters& FingerParameters::operator=(const FingerParameters&  other)
{
	// Do the assignment operation!
	this->fx1 = other.fx1;
	this->fx2 = other.fx2;
	this->fx3 = other.fx3;
	this->fx4 = other.fx4;

	this->fz1 = other.fz1;
	this->fz2 = other.fz2;
	this->fz3 = other.fz3;
	this->fz4 = other.fz4;

	this->tx = other.tx;
	this->tz = other.tz;

	//return other; 
	return *this;
}*/


/*ostream & operator<<(ostream & leftOp, FingerParameters & rightOp)
{
	// Print the data members of rightOp using leftOp like you would using cout
   
	// Return the output stream object so the operator may be cascaded correctly
	leftOp << "Z: " << rightOp.fz1 << ',' << rightOp.fz2 << ',' << rightOp.fz3 << ',' << rightOp.fz4 << ',' << '\n' << endl;
	return leftOp;     
}

ofLog & operator<<(ofLog & leftOp, FingerParameters &rightOp)
{
	// Print the data members of rightOp using leftOp like you would using cout
   
	// Return the output stream object so the operator may be cascaded correctly
	leftOp << "Z: " << rightOp.fz1 << ',' << rightOp.fz2 << ',' << rightOp.fz3 << ',' << rightOp.fz4 << ',' << '\n' << endl;
	return leftOp;     
}*/

}