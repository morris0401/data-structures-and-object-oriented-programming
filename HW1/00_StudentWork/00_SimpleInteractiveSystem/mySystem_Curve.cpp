//
// Instructor: Sai-Keung Wong
// Email:	cswingo@cs.nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Hsinchu, Taiwan
// Computer Science
// Date: 2023/02/26
//
#include "mySystem_Curve.h"
#include <iostream>

using namespace std;

//
// no-arg constructor
//
CURVE_FUNCTION::CURVE_FUNCTION()
{
	//xMin = -100.0;
	//xMax= 100.0;

	xMin = -100.0;
	xMax = 100.0;

	mNumSamples = 100;

	a = b = c = d = 1;
	a = 1.0;
	b = -0.5;

	mCurveType = CURVE_TYPE_EXPONENTIAL;
}

//
// set the curve type
//
void CURVE_FUNCTION::setCurveType(CURVE_TYPE type)
{
	//
	// implement your own stuff
	//

	this->mCurveType = type;
}

// increase parameter b
void CURVE_FUNCTION::increase(double dv)
{
	b += dv;
}

// decrease parameter b
void CURVE_FUNCTION::decrease(double dv)
{
	b -= dv;

}

// set the value to parameter c
void CURVE_FUNCTION::setC(double c)
{
	//
	// implement your own stuff
	//
	this->c = c;
}

// set the value to parameter d
void CURVE_FUNCTION::setD(double d)
{
	//
	// implement your own stuff
	//
	this->d = d;
}

// ask for input
void CURVE_FUNCTION::askForInput()
{
	//empty
}

//
// set the interval of x
// xMin <- min_X
// xMax <- max_X
//
void CURVE_FUNCTION::set_IntervalOfX(double min_X, int max_X)
{
	//
	// implement your own stuff
	//
	this->xMin = min_X;
	this->xMax = max_X;
}

//
// return the interval of x
// xMin <- this->xMin
// xMax <- this->xMax
void CURVE_FUNCTION::getIntervalOfX(double& xMin, double& xMax) const
{
	//
	// implement your own stuff
	//
	xMin = this->xMin;
	xMax = this->xMax;

}

//
// return the number of sample points
//
int CURVE_FUNCTION::getNumOfSamples() const
{
	//
	// implement your own stuff
	//
	return mNumSamples;
}

//
// set the number of sample points
// mNumSamples <- num
//
void CURVE_FUNCTION::setNumOfSamplePoints(int num)
{
	//
	// implement your own stuff
	//

	//mNumSamples = 1 + num / 2;
	mNumSamples = num;

}

//
// get the value of a function for x
//
double CURVE_FUNCTION::getValue(double x) const
{
	//
	// implement your own stuff
	//
	double w = 0;
	double y = 0;
	switch (mCurveType) {
	case CURVE_TYPE_EXPONENTIAL:
		//y = sin(4*x);
		w = (x / 2.5);
		y = w / 10 - 1 + (c + sin(4 * d * w)) * exp(-w);
		break;
	case CURVE_TYPE_CONSINE:
		//y = c * x;
		y = c * x - d * x * cos(x);
		break;
	case CURVE_TYPE_QUADRATIC:
		//y = 2;
		y = x * x + c * x + d;
		break;
	}

	return y;
}

//
// randomly compute a value for c 
// inside the interval [u0, u1] in a uniform manner
//
void CURVE_FUNCTION::setRandom_C(double u0, double u1)
{
	//srand(time(NULL));
	this->c = (u1 - u0) * rand() / RAND_MAX + u0;
}

//
// randomly compute a value for d 
// inside the interval [u0, u1] in a uniform manner
//
void CURVE_FUNCTION::setRandom_D(double u0, double u1)
{
	//srand(time(NULL));
	this->d = (u1 - u0) * rand() / RAND_MAX + u0;
}

//
// get the boundary point (x, y)
// point_index = 0: return the leftmost point (x,y)
// point_index = 1: return the rightmost point (x,y)
// 
void CURVE_FUNCTION::getBoundaryPoint(int point_index, double& x, double& y) const
{
	//
	// implement your own stuff
	//
	//x = xMin;
	//y = -10;
	//switch (point_index) {
	//case 0:
		//break;
	//case 1:
		//x = xMax;
		//y = 0;
		//break;
	//};
	switch (point_index) {
	case 0:
		x = xMin;
		y = getValue(x);
		break;
	case 1:
		x = xMax;
		y = getValue(x);
		break;
	}
}

//
// get the x- and y-coordinates of all the extreme points 
//
// store the x- and y-coordinates to X and Y vectors, respectively
//
void CURVE_FUNCTION::getExtremePoints(vector<double>& X, vector<double>& Y) const
{
	X.clear();
	Y.clear();

	//
	// implement your own stuff
	//
	vector <double> store_parr_x;
	vector <double> store_parr_y;
	store_parr_x.clear();
	store_parr_y.clear();

	for (int i = 0; i < mNumSamples; i++) {
		store_parr_x.push_back(xMin + i / (double)(mNumSamples - 1) * (xMax - xMin));
		store_parr_y.push_back(getValue(store_parr_x[i]));
	}

	for (int i = 1; i < mNumSamples - 1; i++) {
		if (store_parr_y[i] > store_parr_y[i - 1] && store_parr_y[i] > store_parr_y[i + 1]) {
			X.push_back(store_parr_x[i]);
			Y.push_back(store_parr_y[i]);
		}
		else if (store_parr_y[i] < store_parr_y[i - 1] && store_parr_y[i] < store_parr_y[i + 1]) {
			X.push_back(store_parr_x[i]);
			Y.push_back(store_parr_y[i]);
		}
	}

}