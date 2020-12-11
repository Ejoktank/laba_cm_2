#include "Balance_method.h"
//This file contains balance algorithm and the functions needed by this algorithm.

using std::cout;


double integrate_func(double left, double right, double(*func)(double, bool), bool mode)
{
	return ((func(left, mode) + func(right, mode)) / 2) * (right - left);
}

double inv_k_1(double x, bool mode)
{
	return 1 / k1(x, mode);
}

double inv_k_2(double x, bool mode)
{
	return 1 / k2(x, mode);
}

void create_coeff(double beg, double end, vector<double> &coeff, double h, double (*func1)(double, bool), double(*func2)(double, bool), bool mode)
{
	coeff.resize(0);
	double i = beg;
	for (i = beg; (i + h) < ksi; i += h)
	{
		coeff.push_back((1 / h) * integrate_func(i, i + h, func1, mode));
	}
	coeff.push_back((1 / h) * ((integrate_func(i, ksi, func1, mode) + integrate_func(ksi, i + h, func2, mode) ) ) );
	i += h;
	for (i; (i + h) < end; i += h)
	{
		coeff.push_back((1 / h) * (integrate_func(i, i + h, func2, mode)));
	}
	/*if (i + h / 2 < end)
	{
		cout << "Parararam: " << (end - i) << '\n';
		coeff.push_back((1 / h) * (integrate_func(i, end, func2, mode)));
	}*/
}

void balance_method(int n, double h, bool mode, vector<double> &A, vector<double> &B, vector<double> &C, vector<double> &phi_matrix, double &hi1, double &hi2, double &mu1, double &mu2)
{
	vector<double> a, d, phi;
	create_coeff(x0, x1, a, h, inv_k_1, inv_k_2, mode); // a -> n - 1
	for (int i = 0; i < a.size(); i++)
		a[i] = 1 / a[i];
	create_coeff(x0 + h * 0.5, x1 - h * 0.5, d, h, q1, q2, mode); // d -> n - 2
	create_coeff(x0 + h * 0.5, x1 - h * 0.5, phi, h, f1, f2, mode); // phi -> n - 2
	std::cout << d.size() << '\n';
	hi1 = a[1] / (a[0] + a[1] + d[0] * h * h);
	mu1 = (phi[0] * h * h + a[0] * x0) / (a[0] + a[1] + d[0] * h * h);
	for (int i = 1; i < n - 2; i++)
	{
		A.push_back( a[i] / (h * h) );
		C.push_back( (a[i] + a[i + 1]) / (h * h) + d[i] );
		B.push_back(a[i + 1] / (h * h));
		phi_matrix.push_back(phi[i]);
	}
	hi2 = a[n - 3] / (a[n - 3] + a[n - 2] + d[n - 3] * h * h);
	mu2 = (phi[n - 3] * h * h + a[n - 2] * x1) / (a[n - 3] + a[n - 2] + d[n - 3] * h * h);

};
