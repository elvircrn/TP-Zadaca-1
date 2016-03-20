#include <iostream>
#include <vector>
#include <exception>
#include <cstdio>
#include <stdexcept>

using std::cin;
using std::cout;
using std::vector;
using std::endl;

int fast_pow(int base, int power)
{
	if (power == 0)
		return 1;
	else if (power == 1)
		return base;
	else if (power % 2 == 0)
	{
		int t = fast_pow(base, power / 2);
		return t * t;
	}
	else
		return base * fast_pow(base, power - 1);
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

bool isArmstrong(int number)
{
	if (number < 0)
		return false;
	else if (number == 0)
		return true;

	int val = 0, n = getSize(number), tmp = number;

	while (tmp)
	{
		val += fast_pow(tmp % 10, n);
		tmp /= 10;
	}

	return number == val;
}

vector <int> ArmstrongoviBrojevi(int p, int q)
{
	vector <int> result;


	if (p > q)
		return result;

	for (int i = p; i <= q; i++)
		if (isArmstrong(i))
			result.push_back(i);

	return result;
}

int main()
{
	int p, q;
	cin >> p >> q;

	vector <int> result;
	
	result = ArmstrongoviBrojevi(p, q);

	if (result.size() == 0)
		cout << "Nema Armstrongovih brojeva u trazenom opsegu" << endl;
	else
	{
		for (int i = 0; i < result.size(); i++)
			if (i == 0)
				cout << result [0];
			else
				cout << ", " << result [i];
		cout << endl;
	}
	
	return 0;
}
