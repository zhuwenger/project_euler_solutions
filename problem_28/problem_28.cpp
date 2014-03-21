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
			cout << matrix[x][y] << " ";
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

	// Step right for the first square
	matrix[x][++y] = n++;

	while (n <= max)
	{
		// Step down along the right edge
		for (; x <= right_down[0]; ++x)
		{
			matrix[x][y] = n++;
		}

		// Mark right down
		matrix[x][y] = n++;
		right_down[0] = x;
		right_down[1] = y;

		// Step left along the bottom edge
		for (; y >= left_down[1]; --y)
		{
			matrix[x][y] = n++;
		}

		// Mark left down
		matrix[x][y] = n++;
		left_down[0] = x;
		left_down[1] = y;

		// Step up along the left edge
		for (; x >= left_up[0]; --x)
		{
			matrix[x][y] = n++;
		}

		// Mark left up
		matrix[x][y] = n++;
		left_up[0] = x;
		left_up[1] = y;

		// Step right along the right edge
		for (; y >= right_up[1]; ++y)
		{
			matrix[x][y] = n++;
		}

		// Mark right up
		matrix[x][y] = n++;
		right_up[0] = x;
		right_up[1] = y;

		show_matrix(5);
	}

	return 0;
}

int main()
{
	generate_spiral_matrix(5);
	show_matrix(5);
	return 0;
}
