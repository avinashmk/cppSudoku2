#include "pch.h"
#include "Backtrace.h"

#include <random>
#include <algorithm>

Backtrace::Backtrace() : _shuffledEntrySet(ENTRIES), _progressPercent(0)
{
	if constexpr (USE_MT_ENGINE)
	{
		static std::random_device rd;
		static std::mt19937 g(rd());
		std::shuffle(_shuffledEntrySet.begin(),
					 _shuffledEntrySet.end(),
					 g);
	}
}

void Backtrace::setViewObj(const View& view)
{
	_view = &view;
}

bool Backtrace::backtrace(Grid& grid, int emptyCells)
{
	bool retVal = false;
	_workingSet = grid;
	if constexpr (SHOW_PROGRESS_BAR)
	{
		_progressPercent = 100 - emptyCells;
	}
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
				reportProgress(r, c);
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
		Log::printProgress(100);
		Log::INFO("No more unsolved pieces!");
		_workingSet = (grid);
		retVal = true;
	}
	return retVal;
}

std::vector<int> Backtrace::getEntries()
{
	if constexpr (SHUFFLE_ENTRIES)
	{
		std::shuffle(_shuffledEntrySet.begin(),
					 _shuffledEntrySet.end(),
					 std::default_random_engine());
	}
	auto ret = _shuffledEntrySet;
	return ret;
}

void Backtrace::reportProgress(int row, int column)
{
	if constexpr (SHOW_PROGRESS_BAR)
	{
		int pp = (++row * 10) + ++column;
		if (pp > _progressPercent)
		{
			_progressPercent = pp;
			Log::printProgress(_progressPercent);
		}
	}
}
