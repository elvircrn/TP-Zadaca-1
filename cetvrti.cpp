#include <iostream>
#include <vector>
#include <exception>
#include <cstdio>
#include <stdexcept>
#include <complex>
#include <climits>
#include <string>

namespace TP
{
#undef DEBUG

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
			for (auto i : matrix)
			{
				for (auto j : i)
				{
					std::cout << j << ' ';
				}
				std::cout << std::endl;
			}
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

	//nije da ne moze KMP...
	std::size_t find(const std::string &text, const std::string &what)
	{
		if (text.length() < what.length())
			return std::string::npos;
		for (int i = 0; i < text.length(); i++)
		{
			bool same = true;
			for (int j = 0; j < what.length(); j++)
			{
				if (i + j >= text.length() || text [i + j] != what [j])
				{
					same = false;
					break;
				}
			}

			if (same)
				return static_cast<size_t>(i);
		}

		return std::string::npos;
	}
}

// so simple ^_^
std::string solve(std::string text, const std::string &expression)
{
	//auto where = text.find(expression);
	auto where = TP::find(text, expression);
	if (where == std::string::npos)
		return text;
	else
		return text.substr(0, (int)where) + "(" + expression + ")" + solve (text.substr(where + expression.length(), text.length()), expression);
}

std::string IstakniFraze(std::string input, std::vector <std::string> words)
{
	std::string help = input;
	for (auto &x : words)
		help = solve(help, x);
	return help;
}

int main()
{
    freopen ("in.txt", "r", stdin);
	/*
	std::string text = "Izasla je prva zadaca iz predmeta Tehnike programiranja, a ovih dana ocekujemo i jos zadaca iz drugih predmeta";
	std::string query = "zadaca";
	std::cout << IstakniFraze(text, { "zadaca", "Tehnike programiranja", "drugih predmeta", "meso od sira" }) << std::endl;
	*/

	std::string text;
	std::cout << "Unesite recenicu:";
	std::getline(std::cin, text);

	std::vector<std::string> input;

    std::string q;
    std::getline(std::cin, q);
    while (!std::cin.eof())
	{
		input.push_back(q);
        std::getline(std::cin, q);
    }
	std::cout << IstakniFraze(text, input) << std::endl;

	return 0;
}
