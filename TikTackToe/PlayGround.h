#pragma once
#include <iostream>
#include "Box.h"

class PlayGround
{
public:
	PlayGround(string& NameCross, string& NameCircle)
	{
		Empty* test = new Empty();
		box* bbb = new Empty();
		bbb->Draw();
		empty = new Empty();
		cross = new Cross(NameCross);
		circle = new Circle(NameCircle);
		activegamer = cross;
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				a[i][j] = empty;
			}
		}

	}
	bool win(box* gamer)
	{
		if (((a[0][0] == gamer) && (a[0][1] == gamer) && (a[0][2] == gamer)) || ((a[1][0] == gamer) && (a[1][1] == gamer) && (a[1][2] == gamer)) || ((a[2][0] == gamer) && (a[2][1] == gamer) && (a[2][2] == gamer)) || ((a[0][0] == gamer) && (a[1][0] == gamer) && (a[2][0] == gamer)) || ((a[0][1] == gamer) && (a[1][1] == gamer) && (a[2][1] == gamer)) || ((a[0][2] == gamer) && (a[1][2] == gamer) && (a[2][2] == gamer)) || ((a[0][0] == gamer) && (a[1][1] == gamer) && (a[2][2] == gamer)) || ((a[0][2] == gamer) && (a[1][1] == gamer) && (a[2][0] == gamer)))
		{
			return 1;
		}
	}
	bool win()
	{
		return win(passive);
	}
	void print()
	{
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				std::cout << a[i][j]->Draw();
			}
			std::cout << std::endl;
		}
	}
	int activePos(int pos)
	{
		pos = pos - 1;
		int j = pos % 3;
		int i = pos / 3;
		if (a[i][j] == empty)
		{
			if (activegamer == circle)
			{
				a[i][j] = circle;
				activegamer = cross;
				passive = circle;
				return 1;
			}
			else
			{
				a[i][j] = cross;
				activegamer = circle;
				passive = cross;
				return 1;
			}
		}
		else
		{
			std::cout << "Error. Try again" << std::endl;
			return 0;
		}

	}
	void printhint()
	{
		std::cout << "[1][2][3]" << std::endl;
		std::cout << "[4][5][6]" << std::endl;
		std::cout << "[7][8][9]" << std::endl;
		std::cout << "---------" << std::endl;
	}
	string WinnerName()
	{
		return passive->GetName();
	}
private:
	box* a[3][3];
	box* empty;
	box* cross;
	box* circle;
	box* activegamer;
	box* passive;
};
