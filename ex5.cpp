#include <iostream>

void buble_pop(bool envelope[12][12])
{
	for (int c = 0; c < 12; c++)
	{
		for (int q = 0; q < 12; q++)
		{
			std::cout << (envelope[c][q] ? 'o' : 'x');
		}
		std::cout << std::endl;
	}
}

int buble_poping(bool envelope[12][12], int coordinate[4], int counter)
{
	for (int x = coordinate[0]; x != coordinate[2]+1; (x > coordinate[2] ? x-- : x++))
	{
		for(int y = coordinate[1]; y != coordinate[3]+1; (y > coordinate[3] ? y-- : y++))
			if (x < 12 && y < 12 && x >= 0 && y >= 0)
			{
				envelope[y][x] = false;
				counter--;
			}
	}
	return counter;
}

int main()
{
	bool bubble_envelope[12][12];
	int count = sizeof(bubble_envelope);
	int coordinate[4];

	//inicialization bubble_envelope
	for (int c = 0; c < 12; c++)
	{
		for (int q = 0; c < 12; c++)
		{
			bubble_envelope[c][q] = true;
		}
	}

	while (count != 0)
	{
		std::cin >> coordinate[0] >> coordinate[1] >> coordinate[2] >> coordinate[3];
		count = buble_poping(bubble_envelope, coordinate, count);
		buble_pop(bubble_envelope);
		std::cout << "Pop!\n";
		//std::cout << count;
	}
	return 0;
}