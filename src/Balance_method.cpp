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
	for (i; i < x1; i += h)
	{
		coeff.push_back((1 / h) * (integrate_func(i, i + h, func2, mode)));
	}
}

vector<vector <double>> balance_method(int n, double h, bool mode)
{
	vector<vector <double>> answer;
	vector<double> a, d, phi;
	create_coeff(x0, x1, a, h, inv_k_1, inv_k_2, mode);
	for (int i = 0; i < a.size(); i++)
		a[i] = 1 / a[i];
	create_coeff(x0 + h * 0.5, x1, d, h, q1, q2, mode);
	create_coeff(x0 + h * 0.5, x1, phi, h, f1, f2, mode);
	answer.resize(n);
	for (int i = 0; i < answer.size(); i++)
	{
		answer[i].resize(n + 1);
		for (int j = 0; j < answer[i].size(); j++)
			answer[i][j] = 0;
	}
	int i; 
	answer[0][0] = 1;
	answer[0][1] = -(a[1] / (a[0] + a[1] + d[0] * h * h));
	answer[0][n] = (h * h * phi[0] + mu1 * a[0]) / (a[0] + a[1] + d[0] * h * h);
	for (i = 1; i < n - 1; i++)
	{
		answer[i][i - 1] = a[i - 1] / (h * h);
		answer[i][i] = -( (a[i - 1] + a[i]) / (h * h) + d[i - 1]);
		answer[i][i + 1] = a[i] / (h * h);
		answer[i][n] = -phi[i - 1];
	}
	answer[n - 1][n - 2] = -(a[n - 2] / (a[n - 2] + a[n - 1] + d[n - 2] * h * h));
	answer[n - 1][n - 1] = 1;
	answer[n - 1][n] = (phi[n - 2] * h * h + mu2 * a[n - 1]) / (a[n - 2] + a[n - 1] + d[n - 2] * h * h);
	return answer;
};
