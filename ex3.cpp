#include <iostream>

bool match(int matx_1[4][4], int matx_2[4][4])
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (matx_1[x][y] != matx_2[x][y]) return false;
		}
	}
	return true;
}

void matrix_e (int matx_1[][4])
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (matx_1[x][y] == matx_1[y][x]) matx_1[x][y] = 1;
			else matx_1[x][y] = 0;
			
		}
	}
}

int main()
{
	int matx_1[4][4];
	int matx_2[4][4];

	std::cout << "Input first matrix \n";
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			std::cin >> matx_1[x][y];
		}
	}

	std::cout << "Input second matrix: \n";
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			std::cin >> matx_2[x][y];
		}
	}
	
	bool match_matrix = match(matx_1, matx_2);
	std::cout << (match_matrix ? "Equal" : "No equal") << std::endl;
	if (match_matrix)
	{
		matrix_e(matx_1);
		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				std::cout << matx_1[x][y];
			}
			std::cout << std::endl;
		}
	}

	return 0;
}

