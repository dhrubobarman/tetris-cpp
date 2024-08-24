#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>

using namespace std;

class Grid
{
public:
	Grid();
	void Init();
	void Print();
	void Draw(int padding);
	bool IsCellOutside(int row, int col);
	bool IsCellEmpty(int row, int col);
	int ClearFullRows();
	int grid[20][10];

private:
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int numRows);
	int numRows;
	int numCols;
	int cellSize;
	vector<Color> colors;
};