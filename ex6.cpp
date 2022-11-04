#include <iostream>

int main()
{
	int ate[5][5] ;
	//delete inizialization before send
	for (int i = 0;i < 5;i++) {
		for (int x = 0; x < 5; x++)
		{
			ate[i][x] = 0;
		}
	}
	
	int num = 0;
	int temp_ = 0;


	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) 
		{
			temp_ = std::abs((i%2)*4 - j);
			ate[i][temp_] = num;
			num++;
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j)
		{
			std::cout << ate[i][j] << " \t";
		}
		std::cout << std::endl;
	}

}