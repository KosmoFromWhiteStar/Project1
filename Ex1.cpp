#include <iostream>
#include <windows.devices.radios.h>

void ex1()
{
	int spoon_and_fok[2][6] = { {4, 3, 3, 3, 3, 3}, {4, 3, 3, 3, 3, 3} };
	int plate[2][6] = { {3,2,2,2,2,2}, {3,2,2,2,2,2} };
	int chair[2][6] = { {1,1,1,1,1,1}, {1,1,1,1,1,1} };
	chair[1][5] = 2;

	spoon_and_fok[2][3] -= 1; // ложку украли
	spoon_and_fok[1][1] -= 1; // Vip share one spoon.
	spoon_and_fok[2][3] += 1;
	plate[1][1] -= 1;
	// Strange task
}