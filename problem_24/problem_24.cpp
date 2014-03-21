#include <iostream>
#include <cstdlib>

#define LENGTH 10

const char source[] = "0123456789";

void
find_permutation(const char *source, char *usage, char *permutation,
		int size, int current_position,
		unsigned long order, unsigned long &num_found)
{
	for (int i = 0; i < LENGTH; ++i)
	{
		if (usage[i])
		{
			continue;
		}

		permutation[current_position] = source[i];
		usage[i] = 1;

		if (current_position == LENGTH - 1)
		{
			num_found++;

			if (num_found == order)
			{
				for (int i = 0; i < LENGTH; i++)
				{
					std::cout << permutation[i];
				}

				std::cout << std::endl;
				exit(0);
			}
		}
		else
		{
			find_permutation(source, usage, permutation, size,
					current_position + 1, order, num_found);
		}

		usage[i] = 0;
	}
}

void
find_permutation(unsigned long order)
{
	char usage[LENGTH] = {0};
	char permutation[LENGTH] = {0};
	unsigned long num_found = 0;

	find_permutation(source, usage, permutation, LENGTH,
			0, order, num_found);
}

int main()
{
	find_permutation(1000000);
	return 0;
}
