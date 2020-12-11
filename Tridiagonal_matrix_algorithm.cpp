#include "Tridiagonal_matrix_algorithm.h"
//This file contains tridiagonal matrix algorithm and the functions needed by this algorithm.


vector<double> tridiagonal_matrix_algorithm(vector<double> &A, vector<double> &B, vector<double> &C, vector<double> &phi, double hi1, double hi2, double mu1, double mu2)
{
	int n = A.size() + 2;
	vector <double> answer(n);
	vector <double> alfa(n - 1);
	vector <double> beta(n - 1);
	alfa[0] = hi1;
	beta[0] = mu1;
	for (int i = 0; i < alfa.size() - 1; i++)
	{
		alfa[i + 1] = B[i] / (C[i] - A[i] * alfa[i]);
		beta[i + 1] = (phi[i] + A[i] * beta[i]) / (C[i] - A[i] * alfa[i]);
	}
	answer[n - 1] = (- hi2 * beta[beta.size() - 1] - mu2) / (hi2 * alfa[alfa.size() - 1] - 1);
	for (int i = n - 2; i >= 0; i--)
	{
		answer[i] = alfa[i] * answer[i + 1] + beta[i];
	}
	answer.emplace(answer.begin(), x0);
	answer.push_back(x1);
	return answer;
};