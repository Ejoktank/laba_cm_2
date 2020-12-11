#include "Func_for_lab.h"
//This file contains the functions needed by user.


vector<double> solve(bool mode)
{
	int n = 100;
	vector <double> answer;
	double h, stepik;
	double max_eps = EPSILON + 1;
	double x_eps = 0;
	if (mode)
	{
		vector<double> u_x;
		while (abs(max_eps) > EPSILON)
		{
			n *= 10;
			h = (x1 - x0) / n;
			vector<double> A, B, C, phi_matrix;
			double mu1, mu2, hi1, hi2;
			balance_method(n, h, 1, A, B, C, phi_matrix, hi1, hi2, mu1, mu2);
			answer = tridiagonal_matrix_algorithm(A, B, C, phi_matrix, hi1, hi2, mu1, mu2);
			u_x.resize(n + 1);
			stepik = x0;
			for (int i = 0; i < n + 1; i++)
			{
				u_x[i] = u(stepik);
				//	std::cout << "u[" << i << "] = " << u_x[i] << "       ";
				//	std::cout << "v[" << i << "] = " << answer[i] << '\n';
				stepik += h;
			}
			x_eps = x0 + h;
			max_eps = u_x[1] - answer[1];
			for (int i = 2; i < n; i++)
			{
				if (max_eps < abs(u_x[i] - answer[i]))
				{
					x_eps = x0 + h * (i - 1);
					max_eps = abs(u_x[i] - answer[i]);
				}
			}
			std::cout << "\nx_Exps = " << x_eps << " eps = " << abs(max_eps) << '\n';
		}
	}
	else
	{
		vector<double> answer_h2;
		std::cout << "\nx_Exps = " << x_eps << " eps = " << abs(max_eps) << '\n';
		while (abs(max_eps) > EPSILON)
		{
			n = 100;
			h = (x1 - x0) / n;
			vector<double> A, B, C, phi_matrix;
			double mu1, mu2, hi1, hi2;
			balance_method(n, h, mode, A, B, C, phi_matrix, hi1, hi2, mu1, mu2);
			answer = tridiagonal_matrix_algorithm(A, B, C, phi_matrix, hi1, hi2, mu1, mu2);
			A.clear();
			B.clear();
			C.clear();
			phi_matrix.clear();
			h = (x1 - x0) / (2 * n);
			balance_method(2 * n, h, mode, A, B, C, phi_matrix, hi1, hi2, mu1, mu2);
			answer_h2 = tridiagonal_matrix_algorithm(A, B, C, phi_matrix, hi1, hi2, mu1, mu2);
			stepik = x0;
			h = (x1 - x0) / n;
			x_eps = x0 + h;
			for (int i = 1; i < n; i++)
			{
				//std::cout << "v[" << i << "] = " << answer[i] << "       ";
				//std::cout << "v2[" << i << "] = " << answer_h2[i * 2] << '\n';
				if (max_eps > abs(answer_h2[i * 2] - answer[i]))
				{
					x_eps = x0 + h * (i - 1);
					max_eps = abs(answer_h2[i * 2] - answer[i]);
				}
			}
			std::cout << "\nx_Exps = " << x_eps << " eps = " << abs(max_eps) << '\n';
		}

	}
	return answer;
};

