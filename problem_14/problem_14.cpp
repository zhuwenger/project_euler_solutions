#include <iostream>

#define EDGE 1000000

using namespace std;

int main()
{
	int max_length = 0, max_number = 0;
	int length;
    unsigned long number;

	for (int i = 1; i <= EDGE; ++i)
	{
		length = 1;
		number = i;

		while (number != 1)
		{
			if (number % 2 == 0) {
				number /= 2;
			} else {
				number = 3 * number + 1;
			}
            
            ++length;
		}

		if (length > max_length) {
			max_length = length;
			max_number = i;
		}
	}

	cout << max_number << " "
		 << max_length << endl;
	return 0;
}

