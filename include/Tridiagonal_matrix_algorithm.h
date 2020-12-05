#pragma once
#ifndef __Tridiagonal_matrix_algorithm_H__
#define __Tridiagonal_matrix_algorithm_H__
#include "Simple_func.h"
//This file contains tridiagonal matrix algorithm and the functions needed by this algorithm.

using std::vector;


vector<double> tridiagonal_matrix_algorithm(vector<double> &A, vector<double> &B, vector<double> &C, vector<double> &phi, double hi1, double hi2, double mu1, double mu2); //maybe 2 vector(coeff_matrix_ABC, coeff_Phi)

#endif