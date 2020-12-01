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
	double c1 = 0.7348403689121162;
	double c2 = -1.7348403689121161;
	double c3 = -0.670609108165965;
	double c4 = -3.6275438934922133;
	if (x > ksi)
		return c1 * exp(sqrt(2/7) * x) + c2 * exp(-sqrt(2/7) * x) + 1;
	else return c3 * exp(sqrt(2 / 5) * x) + c4 * exp(-sqrt(2 / 5) * x) - 6.25 * exp(-0.4);
}
#endif