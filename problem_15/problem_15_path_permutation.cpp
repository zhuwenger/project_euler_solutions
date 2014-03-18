#include <iostream>
#include <cstdlib>

using namespace std;

inline void
show_path(int *matrix[], int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j];

			if (j == size - 1) {
				cout << endl;
			} else {
				cout << " ";
			}
		}
	}

	cout << endl;
}

inline int
check_step_right(int *matrix[], int size, int x, int y)
{
	return (y < size - 1 && matrix[x][y + 1] != 1) ? 1 : 0;
}

inline int
check_step_down(int *matrix[], int size, int x, int y)
{
	return (x < size - 1 && matrix[x + 1][y] != 1) ? 1 : 0;
}

void
find_path_recursive(int *matrix[], int size, 
	int x, int y, unsigned long long &total_num)
{
	matrix[x][y] = 1;

	int step_right_available = check_step_right(matrix, size, x, y);
	int step_down_available = check_step_down(matrix, size, x, y);

	if (step_right_available) {
		find_path_recursive(matrix, size, x, y + 1, total_num);
		matrix[x][y + 1] = 0;
	}

	if (step_down_available) {
		find_path_recursive(matrix, size, x + 1, y, total_num);
		matrix[x + 1][y] = 0;
	} 

	if (!step_right_available && !step_down_available) {
		// show_path(matrix, size);
		total_num++;
	}
}

void
find_path_non_recursive(int *matrix[],
	const int size, const int start_x, 
	const int start_y, unsigned long long &total_num)
{
	if (size <= 0) {
		total_num = 0;
		return;
	} else if (size == 1) {
		total_num = 1;
		return;
	}

	int x = start_x, y = start_y, end = size - 1;
	matrix[x][y] = 1;

	bool step_right_mode = true;

	while (true) {
		if (x == end && y == end) {
			total_num++;
			matrix[x][y] = 0;

			// Comes from the bottom line
			while (y > 0 && matrix[x][y - 1] == 1) {
				matrix[x][--y] = 0;
			}

			// Retreat along vertical line
			while (x > 0 && matrix[x - 1][y] == 1) {
				matrix[--x][y] = 0;
			}

			if (x == start_x && y == start_y) {
				break;
			} else {
				--y;
				step_right_mode = false;
				continue;
			}
		}

		if (step_right_mode) {
			if (check_step_right(matrix, size, x, y)) {
				matrix[x][++y] = 1;
			} else {
				step_right_mode = false;
			}

			continue;
		} else {
			if (check_step_down(matrix, size, x, y)) {
				matrix[++x][y] = 1;

				if (y < end) {
					step_right_mode = true;
				}
			}
		}
	}
}

inline unsigned long long
find_path(int *matrix[], int size)
{
	unsigned long long total_num = 0;
	matrix[0][0] = 1;
	find_path_non_recursive(matrix, size, 0, 1, total_num);
	return total_num * 2;
}

int main(int argc, char *argv[])
{
	if (argc <= 1) {
		cout << "Usage: " << argv[0]
			 << " number" << endl;
		return -1;
	}

	int size = atoi(argv[1]);

	cout << "Size=" << size << endl;

	int **matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	int result = find_path(matrix, size);
	cout << "Result=" << result << endl;

	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;
	return 0;
}
