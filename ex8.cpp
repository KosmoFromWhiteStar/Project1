#include <iostream>

void display_(bool battlefield[][10])
{
	std::cout << std::endl;
	for (int y = -2; y < 10; y++)
	{
		for (int x = -2; x < 10; x++)
		{
			if (!(x == -2 && y == -2)) 
			{
				if (y < -1 && x < 0 )std::cout << " ";
				if (y < 0 && x == -1)std::cout << "  ";
				if (x == -1 && y == -1)std::cout << "+";
				if (y == -2 && x >= 0) std::cout << " " << x << "  ";
				else if (y == -1 && x >= 0) std::cout << "----";
				if (x == -2 && y >= 0) std::cout << y << ' ';
				else if (x == -1 && y >= 0) std::cout << "|";
				if (x >= 0 && y >= 0) std::cout << (battlefield[x][y] ? "[I]" : " 0 ") << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void arrange_ship(bool sea_battle[][10])
{
	int coordinata[4];
	bool place = false;
	bool distance = false;
	int temp;

	// 4[i]
	/*for (int i = 4; i > 0; i--)
	{
		std::cout << "You can stay [I] (one cells) " << i << " ships\nCoordinate: ";
		for (int i = 0; i < 2;i++)std::cin >> coordinata[i];
		if (!(sea_battle[coordinata[0]][coordinata[1]])) sea_battle[coordinata[0]][coordinata[1]] = true;
		display_(sea_battle);
	}*/
	
	//3[II]
	/*for (int i = 3; i > 0; i--)
	{
		std::cout << "You can stay [I][I](two cells)" << i << " ships\nCoordinate: ";
		for (int i = 0; i < 4;i++)std::cin >> coordinata[i];
		place = (coordinata[0] == coordinata[2]) || (coordinata[1] == coordinata[3]);
		distance = (2 == (std::abs(coordinata[0] - coordinata[2]) + 1)) 
			    || (2 == (std::abs(coordinata[1] - coordinata[3]) + 1));

		if (place && distance && !(sea_battle[coordinata[0]][coordinata[1]]) 
							  && !(sea_battle[coordinata[2]][coordinata[3]]))
		{
			sea_battle[coordinata[0]][coordinata[1]] = true;
			sea_battle[coordinata[2]][coordinata[3]] = true;
		}
		else
		{
			std::cout << "That can not be stay!\n";
			i++;
		}
		std::cout << std::endl;
		display_(sea_battle);
	}*/
	
	//2[III]

	for (int i = 2; i > 0; i--)
	{
		std::cout << "You can stay [I][I][I](three cells) " << i << " ships\nCoordinate: ";
		for (int i = 0; i < 4;i++)std::cin >> coordinata[i];
		// 9 9 9 7
		place = (coordinata[0] == coordinata[2]) || (coordinata[1] == coordinata[3]);
		
		distance = (3 == (std::abs(coordinata[0] - coordinata[2]) + 1))
			|| (3 == (std::abs(coordinata[1] - coordinata[3]) + 1));
		
		bool right = place && distance && !(sea_battle[coordinata[0]][coordinata[1]])
									   && !(sea_battle[coordinata[2]][coordinata[3]])
									   && (!(sea_battle[coordinata[2]][coordinata[3]+1]) 
									        || !(sea_battle[coordinata[0]+1][coordinata[1]])); 
										// если ставить друг над другом. выдаёт ошибку

		if (right)
		{
			sea_battle[coordinata[0]][coordinata[1]] = true;
			sea_battle[coordinata[2]][coordinata[3]] = true;
			
			if (coordinata[0] == coordinata[2] && coordinata[1] != coordinata[3])
			{
				temp = (coordinata[1] > coordinata[3] ? coordinata[3] : coordinata[1]);
				sea_battle[coordinata[2]][temp + 1] = true;
			}
			else
			{
				temp = (coordinata[0] > coordinata[2] ? coordinata[2] : coordinata[0]);
				sea_battle[temp + 1][coordinata[1]] = true;
			}
			
		}
		else
		{
			std::cout << "That can not be stay!\n";
			i++;
		}
		std::cout << std::endl;
		display_(sea_battle);
	}
	
	//1[IIII]
	for (int i = 1; i > 0; i--)
	{
		std::cout << "You can stay [I][I][I][I] (four cells)" << i << " ships\nCoordinate: ";
		for (int i = 0; i < 4;i++)std::cin >> coordinata[i];
		// 9 9 9 7
		place = (coordinata[0] == coordinata[2]) || (coordinata[1] == coordinata[3]);

		distance = (4 == (std::abs(coordinata[0] - coordinata[2]) + 1))
			|| (4 == (std::abs(coordinata[1] - coordinata[3]) + 1));

		if (place && distance && !(sea_battle[coordinata[0]][coordinata[1]])
			&& !(sea_battle[coordinata[2]][coordinata[3]]))
		{
			sea_battle[coordinata[0]][coordinata[1]] = true;
			sea_battle[coordinata[2]][coordinata[3]] = true;
			int temp;
			if (coordinata[0] == coordinata[2] && coordinata[1] != coordinata[3])
			{
				temp = (coordinata[1] > coordinata[3] ? coordinata[3] : coordinata[1]);
				sea_battle[coordinata[2]][temp + 1] = true;
				sea_battle[coordinata[2]][temp + 2] = true;
			}
			else
			{
				temp = (coordinata[0] > coordinata[2] ? coordinata[2] : coordinata[0]);
				sea_battle[temp + 1][coordinata[1]] = true;
				sea_battle[temp + 2][coordinata[1]] = true;
			}
			
		}
		else
		{
			std::cout << "That can not be stay!\n";
			i++;
		}
		std::cout << std::endl;
		display_(sea_battle);
	}

}

int main()
{
	//                      [x] [y]
	bool sea_battle_field_p1[10][10];
	bool sea_battle_field_p2[10][10];

	for (int i = 0; i < 10; i++) {
		for (int x = 0; x < 10;x++)
		{
			sea_battle_field_p1[x][i] = false;
			sea_battle_field_p2[x][i] = false;
		}

	}
	/*
	 4 маленьких кораблика размером в одну клетку,
	 3 небольших корабля размером в две клетки, 
	 2 средних корабля размером в три клетки 
	 и один большой корабль размером в четыре клетки
	*/
	/*std::cout << "Sea Battle!!!\a\n\nInput name first player:";
	std::string p1;
	std::cin >> p1;
	std::cout << "\nInput snd player: ";
	std::string p2;
	std::cin >> p2;*/

	std::cout <</* p1 <<*/ " arrange ships;\nYou have 4 [I], 3 [II], 2 [III], 1[IIII]\n";
	arrange_ship(sea_battle_field_p1);
	//arrange_ship(sea_battle_field_p2);



}