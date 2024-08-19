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
	void Draw();
	bool IsCellOutside(int row, int col);
	int grid[20][10];

private:
	int numRows;
	int numCols;
	int cellSize;
	vector<Color> colors;
};