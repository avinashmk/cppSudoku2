#include "pch.h"
#include "Controller.h"

Controller::Controller()
{
	_backtrace.setViewObj(_view);
}

void Controller::Solve()
{
	_view.getPuzzle(_inputSet);
	_workingSet = _inputSet;
	if (_backtrace.backtrace(_workingSet))
	{
		Log::INFO("Backtrace successful!");
	}
	else
	{
		Log::INFO("Backtrace unsuccessful!");
	}
	Log::INFO("Printing Solvent:");
	_view.printPuzzle(_workingSet);
}
