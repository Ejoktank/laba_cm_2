#include "Func_for_lab.h"
//This file contains the functions needed by user.


vector<double> solve(int n, double x0, double x1, bool mode)
{
	vector <double> answer;
	double h;
	vector<double> u_x;
	h = (x1 - x0) / n;
	vector<double> A, B, C, phi_matrix;
	double mu1, mu2, hi1, hi2;
	balance_method(n, h, x0, x1, mode, A, B, C, phi_matrix, hi1, hi2, mu1, mu2);
	answer = tridiagonal_matrix_algorithm(A, B, C, phi_matrix, hi1, hi2, mu1, mu2);
	return answer;
};

