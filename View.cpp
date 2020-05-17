#include "pch.h"
#include "View.h"

#include <iostream>

int View::getPuzzle(Grid & puzzle) const
{
	int emptyCells = 0;
	Log::INFO("Give me something!");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int input;
			std::cin >> input;
			if ((input >= 0) && (input <= 9))
			{
				if constexpr (SHOW_PROGRESS_BAR)
				{
					if (input == 0)
					{
						emptyCells++;
					}
				}
				puzzle.at(i, j) = input;
			}
			else
			{
				Log::ERR("Incompatible input given: %d", input);
				return emptyCells;
			}
		}
	}
	return emptyCells;
}

bool View::printPuzzle(const Grid& puzzle) const
{
	std::cout << std::endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << "  ";
			if (const int& entry = puzzle.At(i, j); entry == 0)
			{
				std::cout << ".";
			}
			else
			{
				std::cout << entry;
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return true;
}

void View::fancyPrint(const Grid & puzzle) const
{
	if constexpr(FANCY_PRINT)
	{
		std::system("cls");
		printPuzzle(puzzle);
	}
}
