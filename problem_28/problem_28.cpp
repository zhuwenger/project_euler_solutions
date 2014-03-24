#include <iostream>

#define MAX_EDGE 1023
#define DOT_SIZE 2

using namespace std;

int matrix[MAX_EDGE][MAX_EDGE] = {0};

void
show_matrix(int edge_size)
{
	for (int x = 0; x < edge_size; ++x)
	{
		for (int y = 0; y < edge_size; ++y)
		{
			cout << matrix[x][y] << "\t";
		}

		cout << endl;
	}
}

int
generate_spiral_matrix(int edge_size)
{
	if (edge_size > MAX_EDGE || edge_size % 2 == 0)
	{
		return -1;
	}

	int core = edge_size / 2, max = edge_size * edge_size;
	int x = core, y = core, n = 1;
	int left_up[] = {x, y}, right_up[] = {x, y},
		right_down[] = {x, y}, left_down[] = {x, y};

	// Mark core
	matrix[x][y] = n++;

	while (n <= max)
	{
		// Step right for the next square
		matrix[x][++y] = n++;

		// Step down along the right edge
		for (++x; x <= right_down[0]; ++x)
		{
			matrix[x][y] = n++;
		}

		// Mark right down
		matrix[x][y] = n++;
		right_down[0] = x;
		right_down[1] = y;

		// Step left along the bottom edge
		for (--y; y >= left_down[1]; --y)
		{
			matrix[x][y] = n++;
		}

		// Mark left down
		matrix[x][y] = n++;
		left_down[0] = x;
		left_down[1] = y;

		// Step up along the left edge
		for (--x; x >= left_up[0]; --x)
		{
			matrix[x][y] = n++;
		}

		// Mark left up
		matrix[x][y] = n++;
		left_up[0] = x;
		left_up[1] = y;

		// Step right along the right edge
		for (++y; y <= right_up[1]; ++y)
		{
			matrix[x][y] = n++;
		}

		// Mark right up
		matrix[x][y] = n++;
		right_up[0] = x;
		right_up[1] = y;
	}

	return 0;
}

unsigned long
calculate_diagonals(int edge_size)
{
	int x, y, core = edge_size / 2;
	unsigned long sum_diagonals = matrix[core][core];

	// Left up diagonal
	for (x = 0, y = 0; x < core && y < core; ++x, ++y)
	{
		sum_diagonals += matrix[x][y];
	}

	// Right up diagonal
	for (x = 0, y = edge_size - 1; x < core && y > core; ++x, --y)
	{
		sum_diagonals += matrix[x][y];
	}

	// Left down diagonal
	for (x = edge_size - 1, y = 0; x > core && y < core; --x, ++y)
	{
		sum_diagonals += matrix[x][y];
	}

	// Right down diagonal
	for (x = edge_size - 1, y = edge_size - 1; x > core && y > core; --x, --y)
	{
		sum_diagonals += matrix[x][y];
	}

	return sum_diagonals;
}

int main()
{
	int edge_size = 1001;

	generate_spiral_matrix(edge_size);

//	show_matrix(edge_size);

	cout << calculate_diagonals(edge_size) << endl;
	
	return 0;
}
