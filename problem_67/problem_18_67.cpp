#include <iostream>
#include <fstream>

using namespace std;

const int TRIANGLE_MAX = 1024 * 1024;

int get_index(int level, int index_of_level)
{
	int start_index = 0;

	for (int i = 1; i < level; i++) {
		start_index += i;
	}

	return start_index + index_of_level;
}

int calculate_levels(int triangle[], int size)
{
	int num_level = 0, i = 0;

	while (i < size) {
		i += num_level++;
	}

	return num_level - 1;
}

int calculate_max(int triangle[], int size)
{
	int levels = calculate_levels(triangle, size);
	
	for (int level = levels - 1; level >= 0; level--) {
		int start_index = get_index(level, 0);
		int end_index = get_index(level + 1, 0);

		for (int i = start_index; i < end_index; i++) {
			int left_down = triangle[i + level];
			int right_down = triangle[i + level + 1];
			int choosen_down;

			if (left_down > right_down) {
				choosen_down = left_down;
			} else {
				choosen_down = right_down;
			}

			triangle[i] += choosen_down;
		}
	}

	return triangle[0];
}

int main(int argc, char *argv[])
{
	if (argc <= 1) {
		cout << "Usage: " << argv[0]
			 << " filename" << endl;
		return -1;
	}

	int triangle[TRIANGLE_MAX];
	int triangle_length = 0;

	ifstream fin(argv[1]);
	int input;
	while (fin >> input) {
		triangle[triangle_length++] = input;
	}

	cout << calculate_max(triangle, triangle_length) << endl;
	return 0;
}

