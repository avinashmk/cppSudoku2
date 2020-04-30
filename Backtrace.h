#pragma once
#include "pch.h"
#include "Grid.h"
#include "View.h"
#include "Log.h"

class Backtrace
{
	Grid _workingSet;
	const View* _view;

public:
	void setViewObj(const View& util);
	bool backtrace(Grid& grid);

private:
	bool completeTrace(Grid grid);
};