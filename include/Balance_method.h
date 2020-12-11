#pragma once
#ifndef __Balance_method_H__
#define __Balance_method_H__
#include "Simple_func.h"
//This file contains balance algorithm and the functions needed by this algorithm.

using std::vector;

void balance_method(int n, double h, bool mode, vector<double> &A, vector<double> &B, vector<double> &C, vector<double> &phi_matrix, double &hi1, double &hi2, double &mu1, double &mu2);
void create_coeff(double beg, double end, vector<double> &coeff, double h, double(*func1)(double, bool), double(*func2)(double, bool), bool mode);
double integrate_func(double left, double right, double(*func)(double, bool), bool mode);

#endif
