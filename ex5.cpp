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
	int temp = 0;

	//inicialization bubble_envelope
	for (int c = 0; c < 12; c++)
	{
		for (int q = 0; c < 12; c++)
		{
			bubble_envelope[c][q] = true;
		}
	}
	std::cout << "Poping bubbles from China\n" << std::endl;
	while (count > 0)
	{
		buble_pop(bubble_envelope);
		std::cout << std::endl  << "Input coordinats: ";
		std::cin >> coordinate[0] >> coordinate[1] >> coordinate[2] >> coordinate[3];
		temp = count;
		count = buble_poping(bubble_envelope, coordinate, count);
		for (int i = temp - count; i > 0; i-- ) std::cout << "Pop!\n";
		std::cout << std::endl;
		
	}
	std::cout << "Babbles end.";
	return 0;
}