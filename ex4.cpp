#include <iostream>

int main()
{
	float matrx_A[4][4];
	float matrx_b[4];
	float result_matrix[4] = { 0,0,0,0 };

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			std::cin >> matrx_A[x][y];
		}
	}

	for (int y = 0; y < 4; y++)
	{
		std::cin >> matrx_b[y];
	}

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			result_matrix[y] += matrx_A[x][y] * matrx_b[x];
		}
	}
	

	for (int y = 0; y < 4; y++)
	{
		std::cout << result_matrix[y] << std::endl;
	}
}