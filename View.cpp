#include "pch.h"
#include "View.h"

#include <iostream>

bool View::getPuzzle(Grid & puzzle) const
{
	Log::INFO("Give me something!");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int input;
			std::cin >> input;
			if ((input >= 0) && (input <= 9))
			{
				puzzle.at(i, j) = input;
			}
			else
			{
				Log::ERR("Incompatible input given: %d", input);
				return false;
			}
		}
	}
	return true;
}

bool View::printPuzzle(const Grid& puzzle) const
{
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
