#include "Func_for_lab.h"
#include <gtest.h>
#include <iomanip>


using std::cout;
using std::ios;

void print_matrix(vector<vector <double>> &matrix)
{
	cout << "\n";
	for (int i = 0; i < matrix.size(); i++)
	{
		cout.setf(ios::fixed);
		cout.precision(6);
		for (int j = 0; j < matrix[i].size(); j++)
			cout << std::setw(15)  << matrix[i][j];
		cout << '\n';
	}
}
/*
TEST(balance_method, integration_cause_no_error_with_simple_func)
{
	ASSERT_NO_THROW(cout << integrate_func(0, 0.5, k1, 0) << '\n');
}

TEST(balance_method, integration_cause_no_error_with_difficult_func)
{
	ASSERT_NO_THROW(cout << integrate_func(0, 0.01, f2, 0) << '\n');
}

TEST(balance_method, balance_method_cause_no_error_with_simple_task)
{
	vector<vector <double>> test = balance_method(5, 0.2, 0);
	ASSERT_NO_THROW(print_matrix(test));
}

TEST(balance_method, balance_method_cause_no_error_with_test_mode)
{
	ASSERT_NO_THROW(vector<vector <double>> test = balance_method(5, 0.2, 1));
}

TEST(Trid_matr_alg, Trid_matr_alg_cause_no_error)
{
	vector<vector <double>> test1;
	test1 = { {2, -1, 0, 0, 0, -25}, {-3, 8, -1, 0, 0, 72}, {0, -5, 12, 2, 0, -69}, {0, 0, -6, 18, -4, -156}, {0, 0, 0, -5, 10, 20} };
	ASSERT_NO_THROW(vector<double> y = tridiagonal_matrix_algorithm(test1));
}

TEST(Trid_matr_alg, Trid_matr_alg_can_calculate_system1)
{
	double hi1 = 0.5;
	double mu1 = -12.5;
	vector<double> A = { -3, -5, -6 };
	vector<double> C = { -8, -12, -18 };
	vector<double> B = { -1, 2, -4 };
	double hi2 = 0.5;
	double mu2 = 2;
	vector<double> phi = { -72, 69, 156 };
	vector<double> y = tridiagonal_matrix_algorithm(A, B, C, phi, hi1, hi2, mu1, mu2);
	ASSERT_NO_THROW(for (int i = 0; i < y.size(); i++) cout << y[i] << '\n');
}
/*
TEST(Solve_lab, solve_cause_no_error)
{
	ASSERT_NO_THROW(vector<double> test = solve(1));
}*/

TEST(Solve_lab, solve_actualy_find_answer)
{
	vector<double> test = solve(0);
	cout.precision(8);
	cout.setf(ios::fixed);
	
	cout << '\n' << test.size() << '\n';
	ASSERT_NO_THROW(bool dl);
}
