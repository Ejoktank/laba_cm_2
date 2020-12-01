#include "Func_for_lab.h"
//This file contains the functions needed by user.


vector<double> solve(bool mode)
{
	int n = 9;
	vector <double> answer(n);
	for (int i = 0; i < n; i++)
		answer[i] = 0;
	vector<double> u_x(n);
	double h = (x1 - x0) / n;
	double stepik = x0;
	for (int i = 0; i < n; i++)
	{
		u_x[i] = u(stepik);
		stepik += h;
	}
	double max_eps = u_x[0] - answer[0];
	for (int i = 1; i < n; i++)
		if (max_eps < u_x[i] - answer[i])
			max_eps = u_x[i] - answer[i];
	while (abs(max_eps) > EPSILON)
	{
		n+=150;
		h = (x1 - x0) / n;
		answer = tridiagonal_matrix_algorithm(balance_method(n, h, 1));
		u_x.resize(n);
		stepik = x0;
		for (int i = 0; i < n; i++)
		{
			u_x[i] = u(stepik);
			stepik += h;
		}
		max_eps = u_x[0] - answer[0];
		for (int i = 1; i < n; i++)
			if (max_eps < u_x[i] - answer[i])
				max_eps = u_x[i] - answer[i];
		std::cout << abs(max_eps) << '\n';
	}
	return answer;
};

