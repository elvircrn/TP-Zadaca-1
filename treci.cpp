#include <iostream>
#include <vector>
#include <exception>
#include <cstdio>
#include <stdexcept>
#include <complex>
#include <climits>

namespace TP
{
	template <class T> 
		using Matrix = std::vector <std::vector <T> >;

	template <class T>
		Matrix<T> createMatrix(int n, int m)
		{
			if (n <= 0 || m <= 0)
				throw std::domain_error("Nekorektna matrica");

			return Matrix<T>(n, std::vector<T>(m));
		}

	template <class T>
		void printMatrix(const Matrix<T> &matrix)
		{
			for (int i = 0; i < matrix.size(); i++, std::cout << std::endl)
				for (int j = 0; j < matrix [0].size(); j++)
					std::cout << matrix [i] [j] << ' ';
		}

	template <class T>
		bool validateMatrix(const Matrix <T> &matrix)
		{
			if (matrix.size() == 0)
				return false;

			for (int i = 0; i < matrix.size(); i++)
				if (matrix [i].size() != matrix [0].size())
					return false;

			return true;
		}

	int getSize(int number)
	{
		int ret = 0;
		while (number > 0)
		{
			ret++;
			number /= 10;
		}
		return ret;
	}
}

const std::complex<int> dirs [8] { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };

std::complex<double> VrhMatrice(TP::Matrix<int> matrix, int p, int q)
{
	int m = matrix.size();

	if (!TP::validateMatrix(matrix))
		throw std::domain_error("Nekorektna matrica");

	int n = matrix [0].size();

	if (p < 0 || q < 0 || p >= m || q >= n)
		throw std::range_error("Nekorektna pocetna pozicija");

	std::complex<int> currentLocation(p, q);

	while (true)
	{
		int maxElement = -1;
		int maximum = matrix [currentLocation.real()] [currentLocation.imag()];
		for (int i = 0; i < 8; i++)
		{
			auto next = currentLocation + dirs [i];

			if (next.real() < 0 || next.imag() < 0 || next.real() >= m || next.imag() >= n || matrix [next.real()] [next.imag()] <= maximum)
				continue;

			maxElement = i;
			maximum = matrix [next.real()] [next.imag()];
		}

		if (maxElement != -1)
			currentLocation += dirs [maxElement];
		else
			break;
	}

	return std::complex<double> (currentLocation.real(), currentLocation.imag());
}

int main()
{
	int m, n, p, q;
	
	std::cin >> m >> n >> p >> q;
	
	try
	{
		auto matrix = TP::createMatrix<int>(m, n);

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				std::cin >> matrix [i] [j];

		auto result = VrhMatrice(matrix, p, q);
		
		std::cout << (int)result.real() << ' ' << (int)result.imag() << std::endl;
	}
	catch (std::range_error e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::domain_error e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}



