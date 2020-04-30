#include "pch.h"
#include "Backtrace.h"

void Backtrace::setViewObj(const View& view)
{
	_view = &view;
}

bool Backtrace::backtrace(Grid& grid)
{
	bool retVal = false;
	_workingSet = grid;
	if (retVal = completeTrace(_workingSet))
	{
		grid = _workingSet;
	}
	return retVal;
}

bool Backtrace::completeTrace(Grid grid)
{
	bool retVal = false;
	Log::DEBUG("Backtrace::completeTrace() ENTER >>> ");

	if (int r = 0, c = 0;
		grid.fetchFirstUnsolved(r, c))
	{
		for (int entry = 1; entry <= 9; entry++)
		{
			if (grid.isSafe(r, c, entry))
			{
				Log::DEBUG("Backtrace::completeTrace() Trying %d at %d, %d", entry, r, c);
				grid.at(r, c) = entry;
				_view->fancyPrint(grid);
				if (completeTrace(grid))
				{
					retVal = true;
					break;
				}
				else
				{
					continue;
				}
			}
		}
	}
	else
	{
		Log::INFO("No more unsolved pieces!");
		_workingSet = (grid);
		retVal = true;
	}
	return retVal;
}
