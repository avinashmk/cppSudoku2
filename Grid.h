#pragma once

#include "Log.h"

#include <vector>

constexpr int GRID_SIZE = 81;
constexpr int GRID_ROWS = 9;
constexpr int GRID_COLUMNS = 9;
constexpr int EMPTY = 0;
const std::vector<int> ENTRIES{1, 2, 3, 4, 5, 6, 7, 8, 9};

class Grid
{
	std::vector<int> _grid;

	int getIndex(const int& row, const int& column) const;
	int getRow(const int& index) const;
	int getColumn(const int& index) const;

	bool isRowSafe(const int & row,
				   const int & column,
				   const int & entry) const;
	bool isColumnSafe(const int & row,
					  const int & column,
					  const int & entry) const;
	bool is3x3Safe(const int & row,
				   const int & column,
				   const int & entry) const;
public:
	Grid();
	Grid(const Grid&) = default;
	Grid(Grid&&) = default;
	Grid& operator=(const Grid&) = default;
	Grid& operator=(Grid&&) = default;
	~Grid() = default;

	int& at(const int & row, const int & column);
	int At(const int & row, const int & column) const;
	bool fetchFirstUnsolved(int& row, int& column) const;
	bool isSafe(const int & row, const int & column, const int & entry) const;
};
