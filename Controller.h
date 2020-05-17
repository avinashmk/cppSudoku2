#pragma once
#include "pch.h"
#include "Grid.h"
#include "View.h"
#include "Backtrace.h"

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
