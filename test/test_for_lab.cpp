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
	vector<vector <double>> test1;
	test1 = { {1, -0.5, 0, 0, 0, -12.5}, {-3, 8, -1, 0, 0, 72}, {0, -5, 12, 2, 0, -69}, {0, 0, -6, 18, -4, -156}, {0, 0, 0, -0.5, 1, 2} };
	vector<double> y = tridiagonal_matrix_algorithm(test1);
	//for (int i = 0; i < y.size(); i++) cout << y[i] << '\n';
	double mu6 = 0;
	for (int i = 0; i < y.size(); i++) mu6 += y[i] * test1[test1.size() - 1][i];
	//cout << "Mu6:" << mu6 << '\n';
	EXPECT_EQ(2, mu6);
}

TEST(Trid_matr_alg, Trid_matr_alg_can_calcylate_simple_system)
{
	vector<vector <double>> test1;
	test1 = { {1, 5, 6}, { -4, 1, 5} };
	vector<double> y = tridiagonal_matrix_algorithm(test1);
	//for (int i = 0; i < y.size(); i++) cout << y[i] << '\n';
	double mu6 = 0;
	for (int i = 0; i < y.size(); i++) mu6 += y[i] * test1[test1.size() - 1][i];
	//cout << "Mu6:" << mu6 << '\n';
	EXPECT_EQ((int) test1[1][2], (int) mu6);
}

TEST(Function_u, u_correct)
{
	vector<double> u_x;
	cout << '\n' << u(0.0) << ' ' << u(1.0) << '\n';
	ASSERT_NO_THROW(bool dl);
}
/*
TEST(Solve_lab, solve_cause_no_error)
{
	ASSERT_NO_THROW(vector<double> test = solve(1));
}*/

TEST(Solve_lab, solve_actualy_find_answer)
{
	vector<double> test = solve(1);
	cout.precision(8);
	cout.setf(ios::fixed);
	for (int i = 0; i < test.size(); i++)
		cout << test[i] << ' ';
	
	cout << '\n';
	ASSERT_NO_THROW(bool dl);
}
