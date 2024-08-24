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

void Grid::Draw(int padding)
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			int cellValue = grid[row][column];
			Color drawColor = colors[cellValue];
			DrawRectangle(column * cellSize + 1 + padding, row * cellSize + 1 + padding, cellSize - 1, cellSize - 1, drawColor);
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

bool Grid::IsCellEmpty(int row, int column)
{
	if (grid[row][column] == 0)
	{
		return true;
	}
	return false;
}

int Grid::ClearFullRows()
{
	int completed = 0;
	// Iterate through each row from bottom to top
	for (int row = numRows - 1; row >= 0; row--)
	{
		// Check if the current row is full
		if (IsRowFull(row))
		{
			// If the row is full, clear it
			ClearRow(row);
			completed++;
		}
		else if (completed > 0)
		{
			// Move all rows above the cleared row down by completed rows found
			MoveRowDown(row, completed);
		}
	}
	return completed;
}

bool Grid::IsRowFull(int row)
{
	// Iterate through each column in the row
	for (int col = 0; col < numCols; col++)
	{
		// If any cell in the row is empty, return false
		if (grid[row][col] == 0)
		{
			return false;
		}
	}
	// If all cells in the row are filled, return true
	return true;
}

void Grid::ClearRow(int row)
{
	// Iterate through each column in the row
	for (int col = 0; col < numCols; col++)
	{
		// Set the value of each cell in the row to 0 (empty)
		grid[row][col] = 0;
	}
}

void Grid::MoveRowDown(int row, int numRows)
{
	// Iterate through each column in the row
	for (int col = 0; col < numCols; col++)
	{
		// Copy the value of the cell in the current row to the cell in the next row
		grid[row + numRows][col] = grid[row][col];
		// Set the value of the cell in the current row to 0 (empty)
		grid[row][col] = 0;
	}
}
