#include <iostream>
#include <vector>
#include <exception>
#include <cstdio>
#include <stdexcept>

using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::domain_error;

typedef vector <vector <double> > Matrix;

bool validateMatrix (const Matrix &matrix)
{
	if (matrix.size() == 0)
		return false;
	
	for (int i = 0; i < matrix.size(); i++)
		if (matrix [i].size() != matrix [0].size())
			return false;

	return true;
}

void printMatrix(const Matrix &matrix)
{
	for (auto i : matrix)
	{
		for (auto j : i)
		{
			cout << j << ' ';
		}
		cout << endl;
	}
}

Matrix EkspanzijaMatrice (const Matrix &matrix, int p, int q)
{
	if (p <= 0 || q <= 0)
		throw domain_error("Nelegalni parametri");

	if (!validateMatrix(matrix))
		throw domain_error("Nekorektna matrica");
	
	int m = matrix.size(), n = matrix [0].size();

	Matrix solution (m * p, vector <double> (n * q));

	for (int i = 0; i < m * p; i++)
		for (int j = 0; j < n * q; j++)
			solution [i] [j] = matrix [i / p] [j / q];

	return solution;
}


int main()
{
	int m, n, p, q;
	
	cin >> m >> n;
	Matrix matrix (m, vector <double>(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix [i] [j];

	cin >> p >> q;

	try
	{
		Matrix result = EkspanzijaMatrice(matrix, p, q);
		printMatrix(EkspanzijaMatrice(matrix, p, q));
	}
	catch (domain_error e)
	{
		cout << e.what() << endl;
	}
	

	return 0;
}

