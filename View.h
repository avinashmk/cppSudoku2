#pragma once
#include "pch.h"
#include "Log.h"
#include "Grid.h"

struct View
{
	int getPuzzle(Grid& puzzle) const;
	bool printPuzzle(const Grid& puzzle) const;
	void fancyPrint(const Grid& puzzle) const;
};