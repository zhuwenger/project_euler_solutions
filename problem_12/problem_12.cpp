#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int
find_triangular_divisors(int number, int num_divisors)
{
	int num_divisors_found = 0;

	if (number > 0)
	{
		num_divisors_found = 1;

		if (number > 1)
		{
			num_divisors_found = 2;

			int number_sqrt = sqrt(number);

			for (int i = 2; i < number_sqrt; ++i)
			{
				if (number % i == 0)
				{
					num_divisors_found += 2;
				}
			}
		}
	}

	return num_divisors_found;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "Usage: " << argv[0]
			 << " num_divisor" << endl;
		return -1;
	}

	int num_divisors = atoi(argv[1]);
	if (num_divisors <= 0)
	{
		cout << "Invalid num_divisor"
			 << endl;
		return -2;
	}

	int triangle_number = 0;
	for (int i = 1;
		find_triangular_divisors(triangle_number, num_divisors) < num_divisors;
		triangle_number += i++) {}

	cout << triangle_number << endl;

	return 0;
}
