#pragma once
#ifndef __Simple_func_H__
#define __Simple_func_H__
//This file contains simple functions needed by all algorithms of the program.( Google Translate =) )

#define _USE_MATH_DEFINES
#include <vector>
#include <cmath>
#include <iostream>



const double ksi = 0.4;
const double mu1 = 0;
const double mu2 = 1;
const double x0 = 0;
const double x1 = 1;
inline double k1(double x, bool mode) { if (mode) return 1.4; return (x + 1); }
inline double k2(double x, bool mode) { if (mode) return 0.4; return x; }
inline double q1(double x, bool mode) { if (mode) return 0.4; return x; }
inline double q2(double x, bool mode) { if (mode) return 0.16; return x * x; }
inline double f1(double x, bool mode) { if (mode) return 0.4; return x; }
inline double f2(double x, bool mode) { if (mode) return exp(-0.4); return exp(-x); }
inline double u(double x) 
{
	double c1 = -0.156392771964;
	double c2 = -0.843607228036;
	double c3 = 2.23501503598;
	double c4 = 1.84965510460;
	if (x < ksi)
		return c1 * exp(sqrt(2.0 / 7.0) * x) + c2 * exp(-sqrt(2.0 / 7.0) * x) + 1.0;
	else return c3 * exp(sqrt(2.0 / 5.0) * x) + c4 * exp(-sqrt(2.0 / 5.0) * x) - 6.25 * exp(-0.4);
}
#endif