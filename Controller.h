#pragma once
#include "pch.h"
#include "Grid.h"
#include "View.h"
#include "Backtrace.h"

// TODO:
// Change from int to less memory datatype.
// All util/interface like methods to be const.
// All commons to be thread-safe.
// Inherit Util class to get rid of setUtilOb() and other bs

class Controller
{
	Grid _inputSet;   // The original puzzle
	Grid _workingSet; // The working solution

	View _view;
	Backtrace _backtrace;

public:
	Controller();
	void Solve();
};
