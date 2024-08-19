#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
	numRows = 20;
	numCols = 10;
	cellSize = 30;
	Init();
	colors = GetCellColors();
};

void Grid::Init()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			grid[row][column] = 0;
		}
	}
}

void Grid::Print()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			std::cout << grid[row][column] << " ";
		}
		std::cout << std::endl;
	}
}

void Grid::Draw()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			int cellValue = grid[row][column];
			Color drawColor = colors[cellValue];
			DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, drawColor);
		}
	}
}

bool Grid::IsCellOutside(int row, int col)
{
	if (row >= 0 && row < numRows && col >= 0 && col < numCols)
	{
		return false;
	}
	return true;
}
