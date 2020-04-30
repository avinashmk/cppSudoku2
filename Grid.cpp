#include "pch.h"
#include "Grid.h"

int Grid::getIndex(const int & row, const int & column) const
{
	int index = (row * GRID_COLUMNS) + column;
	return index;
}

int Grid::getRow(const int & index) const
{
	int row = index / GRID_COLUMNS;
	return row;
}

int Grid::getColumn(const int & index) const
{
	int column = index % GRID_ROWS;
	return column;
}

Grid::Grid() : _grid(GRID_SIZE, EMPTY)
{
}

int& Grid::at(const int & row, const int & column)
{
	return _grid.at(getIndex(row, column));
}

int Grid::At(const int & row, const int & column) const
{
	int value = _grid.at(getIndex(row, column));
	return value;
}

bool Grid::fetchFirstUnsolved(int & row, int & column) const
{
	if (auto it = std::find(std::begin(_grid), std::end(_grid), 0);
		it != std::end(_grid))
	{
		int index = static_cast<int>(it - std::begin(_grid));
		row = getRow(index);
		column = getColumn(index);
		return true;
	}
	return false;
}


bool Grid::isSafe(const int & row, 
				  const int & column, 
				  const int & entry) const
{
	if ((isRowSafe(row, column, entry))
		&& (isColumnSafe(row, column, entry))
		&& (is3x3Safe(row, column, entry)))
	{
		return true;
	}
	return false;
}

bool Grid::isRowSafe(const int & row,
					 const int & column,
					 const int & entry) const
{

	for (int c = 0; c < 9; c++)
	{
		if (entry == At(row, c))
		{
			return false;
		}
	}
	return true;
}

bool Grid::isColumnSafe(const int & row,
						const int & column,
						const int & entry) const
{
	for (int r = 0; r < 9; r++)
	{
		if (entry == At(r, column))
		{
			return false;
		}
	}
	return true;
}

bool Grid::is3x3Safe(const int & row,
					 const int & column,
					 const int & entry) const
{
	int rowLowerLimit = row / 3;
	rowLowerLimit *= 3;

	int columnLowerLimit = column / 3;
	columnLowerLimit *= 3;

	int rowUpperLimit = rowLowerLimit + 3;
	int columnUpperLimit = columnLowerLimit + 3;

	for (int r = rowLowerLimit; r < rowUpperLimit; r++)
	{
		for (int c = columnLowerLimit; c < columnUpperLimit; c++)
		{
			if (entry == At(r, c))
			{
				return false;
			}
		}
	}
	return true;
}
