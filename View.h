#pragma once
#include "pch.h"
#include "Log.h"
#include "Grid.h"

struct View
{
	bool getPuzzle(Grid& puzzle) const;
	bool printPuzzle(const Grid& puzzle) const;
	void fancyPrint(const Grid& puzzle) const;
};