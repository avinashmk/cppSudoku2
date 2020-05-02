#include "pch.h"
#include "Backtrace.h"

#include <random>
#include <algorithm>

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
		for (int entry : getEntries())
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

std::vector<int> Backtrace::getEntries() const
{
	std::vector<int> v = ENTRIES;
	if constexpr (RANDOM_TRACING)
	{
		if constexpr (USE_DEFAULT_RANDOM_ENGINE)
		{
			std::shuffle(v.begin(), v.end(), std::default_random_engine());
		}
		else
		{
			static std::random_device rd;
			static std::mt19937 g(rd());
			std::shuffle(v.begin(), v.end(), g);
		}
	}
	return v;
}
