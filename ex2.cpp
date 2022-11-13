#include <iostream>


char winer(char filed[3][3])
{
	for (int y = 0; y < 3; y++)
	{
		if (filed[0][y] == filed[1][y] && filed[0][y] == filed[2][y] && filed[0][y] != ' ') return filed[0][y];
		
	}
	for (int x = 0; x < 3; x++)
	{
		if (filed[x][0] == filed[x][1] && filed[x][0] == filed[x][2] && filed[x][0] != ' ') return filed[x][0];
	}
	if (filed[0][0] == filed[1][1] && filed[0][0] == filed[2][2] && filed[0][0] != ' ') return filed[0][0];
	if (filed[0][2] == filed[1][1] && filed[0][2] == filed[2][0] && filed[0][2] != ' ') return filed[0][2];
	return 'c';
}

int main()
{
	//[x][y]
	char filed[3][3] = { {' ', ' ',' ',},
			 		     {' ', ' ',' ',},
			 	   	     {' ', ' ',' ',} };

	int coordinate[2] = { 0, 0 };
	char temp = '0';
	char player = 'x';
	bool winstrike = false;

	do
	{
		std::cout << "Input "<< (char)toupper(player) << " player: ";
		for (int i = 0; i < 2; i++)
		{
			std::cin >> temp;
			if (temp > '3' || temp < '0')
			{
				std::cout << "Incorect num; Again\n";
				i--;
			}
			else coordinate[i] = temp - 48;
		}
		if (filed[coordinate[0]][coordinate[1]] != ' ')
		{
			std::cout << "Error. Again: \n";
		}
		else 
		{
			for (int y = 0; y < 3; y++)
			{
				if (y != 0) std::cout << "---+---+---" << std::endl;
				for (int x = 0; x < 3; x++)
				{
					if (coordinate[0] == x && coordinate[1] == y && filed[x][y] == ' ') filed[x][y] = (player == 'x' ? 'x' : 'o');
					std::cout << ' ' << filed[x][y] << ' ' << (x != 2 ? "|" : " ");
				}
				std::cout << std::endl;
			}
			player = (player == 'x' ? 'o' : 'x');
			winstrike = (winer(filed) == 'c' ? true : false);
		}
		if (winer(filed) == 'l')break;
	} while (winstrike);
	if (winer(filed) != 'l') std::cout << "Winner player " << winer(filed) << std::endl;
	else std::cout << "Draw";
	return 0;
}