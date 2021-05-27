#include <iostream>
#include <Windows.h>
#include "PlayGround.h"
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	string name1, name2;
	int i = 0;
	int pos;
	cout << "Enter the name of 1 player" << endl;
	cin >> name1;
	cout << "Enter the name of 2 player" << endl;
	cin >> name2;
	PlayGround* play = new PlayGround(name1, name2);
	cout << "The Battle has began" << endl;
	play->printhint();
	do
	{
		cin >> pos;
		system("cls");
		play->printhint();
		i = i + play->activePos(pos);
		play->print();
		if (play->win() == 1)
		{
			std::cout << "Winner is ";
			std::cout << play->WinnerName() << std::endl;;
			std::cout << "Game ended" << std::endl;
			system("pause");
			return 1;
		}
		else if (i >= 9)
		{
			pos = 0;
			cout << "Game ended" << endl;
		}
	} while (pos != 0);
	system("pause");
}