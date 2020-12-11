#pragma once
#ifndef __Func_for_lab_H__
#define __Func_for_lab_H__
//This file contains the functions needed by user.


#include "Balance_method.h"
#include "Tridiagonal_matrix_algorithm.h"
#define EPSILON 5e-07


vector<double> solve(int n, double x0, double x1, bool mode); //Solution for our task.


#endif