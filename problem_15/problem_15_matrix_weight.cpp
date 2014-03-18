#include <iostream>
#include <cstdlib>

using namespace std;

inline void
show_matrix(int *matrix[], const int size)
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

inline void
show_matrix_weight(unsigned long long *matrix_weight[],
                   const int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix_weight[i][j];
            
			if (j == size - 1) {
				cout << endl;
			} else {
				cout << " ";
			}
		}
	}
    
	cout << endl;
}

inline void
empty_matrix(int *matrix[], const int size,
             const int start_x, const int start_y)
{
	for (int x = start_x; x < size; x++) {
		for (int y = start_y; y < size; y++) {
			matrix[x][y] = 0;
		}
	}
}

void
calculate_matrix_weight(int *matrix[],
                        unsigned long long *matrix_weight[],
                        const int size)
{
    int last_index = size - 1;
    
    // Initialize the edges
    for (int i = 0; i < size; i++) {
        matrix_weight[i][last_index] = 1;
        matrix_weight[last_index][i] = 1;
    }
    
    // Calculate from right to left (bottom to upside)
    for (int x = last_index - 1; x >= 0; x--) {
        for (int y = last_index - 1; y >= 0; y--) {
            matrix_weight[x][y] = matrix_weight[x + 1][y] + matrix_weight[x][y + 1];
        }
    }
}

unsigned long long
find_path(int *matrix[],
          unsigned long long *matrix_weight[],
          const int size)
{
	if (size <= 0) {
		return 0;
	} else if (size == 1) {
		return 1;
	}

	calculate_matrix_weight(matrix, matrix_weight, size);

	show_matrix_weight(matrix_weight, size);
	return matrix_weight[0][0];
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

	// Alloc space for matrix and weight
	int **matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	unsigned long long **matrix_weight = new unsigned long long*[size];
	for (int i = 0; i < size; i++) {
		matrix_weight[i] = new unsigned long long[size];
	}

	unsigned long long result = find_path(matrix, matrix_weight, size);
	cout << "Result=" << result << endl;

	// Release resources
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}

	for (int i = 0; i < size; i++) {
		delete[] matrix_weight[i];
	}

	delete[] matrix;
	delete[] matrix_weight;

	return 0;
}

