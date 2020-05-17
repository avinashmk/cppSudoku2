#pragma once
#include "pch.h"
#include "Grid.h"
#include "View.h"
#include "Log.h"

// Backtrace
// Wraps the Backtracing algorithm.
// One instance corresponds to one puzzle.
class Backtrace
{
	// Contains the working solution set at any point of time.
	// Also has the final solution after successful backtrace completion.
	Grid _workingSet;

	// The entry set to be used in each recursion.
	// Might or might not be a shuffled set based on
	// flags: SHUFFLE_ENTRIES, USE_MT_ENGINE
	std::vector<int> _shuffledEntrySet;

	// Pointer to View object.
	// Will be used only if flag FANCY_PRINT is true.
	// Otherwise depend on compiler optimization will take care to ignore this.
	const View* _view;

	int _progressPercent;

public:
	Backtrace();
	void setViewObj(const View& util);

	// The entry point to start backtracing algorithm.
	// @param grid. [Input/Output] Reference to the initial puzzle(unsolved).
	// @return true if backtrace is complete and successful.
	bool backtrace(Grid& grid, int emptyCells);

private:
	// The core backtrace algorithm implementation
	// @param grid. working solution passed on through each recursive call.
	// @return true if trace is complete.
	//         false if encounters invalid iteration in current stack.
	bool completeTrace(Grid grid);

	// Utility to give set of entries.
	// Shuffles entries if SHUFFLE_ENTRIES is true.
	// @return The (shuffled)entries.
	std::vector<int> getEntries();

	// Utility to show progress of backtracing.
	// (Ideal but inaccurate progress bar!)
	void reportProgress(int row, int column);
};
