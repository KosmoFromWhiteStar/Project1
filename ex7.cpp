#include <iostream>


int main()
{
	//             [x][y][z]
	short maincraft[5][5][10];
	//                  [x][y]
	short heights_matrix[5][5];

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			for (int z = 0; z < 10; z++)
			{
				maincraft[x][y][z] = 0;
			}
		}
	}


	
	
	std::cout << "Input matrix of heights: \n";
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++)
		{
			std::cin >> heights_matrix[x][y];
		}
	}
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++){
			for (int z = 0; z < heights_matrix[x][y]; z++)
			{
				maincraft[x][y][z] = 1;
			}

		}
	}
	
	std::cout << "input slice: ";
	int z = 0;
	std::cin >> z;

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			std::cout << maincraft[x][y][z-1] << ' ';
		}
		std::cout << std::endl;
	}

}