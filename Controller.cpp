#include "pch.h"
#include "Controller.h"

#include <chrono>

Controller::Controller()
{
	_backtrace.setViewObj(_view);
}

void Controller::Solve()
{
	int emptyCells = _view.getPuzzle(_inputSet);
	auto start = std::chrono::system_clock::now();

	_workingSet = _inputSet;
	if (_backtrace.backtrace(_workingSet, emptyCells))
	{
		Log::INFO("Backtrace successful!");
	}
	else
	{
		Log::INFO("Backtrace unsuccessful!");
	}

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;

	Log::INFO("Printing Solvent:");
	_view.printPuzzle(_workingSet);

	Log::INFO("Solved in %lf seconds", elapsed_seconds.count());
}
