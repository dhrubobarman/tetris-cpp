#include "block.h"

Block::Block()
{
  cellSize = 30;
  rotationState = 0;
  colors = GetCellColors();
  rowOffset = 0;
  columnOffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
  std::vector<Position> tiles = GetCellPositions();
  for (Position item : tiles)
  {
    int x = item.column * cellSize + 1 + offsetX;
    int y = item.row * cellSize + 1 + offsetY;
    DrawRectangle(x, y, cellSize - 1, cellSize - 1, colors[id]);
  }
};

void Block::Move(int rows, int columns)
{
  rowOffset += rows;
  columnOffset += columns;
}

std::vector<Position> Block::GetCellPositions()
{
  std::vector<Position> tiles = cells[rotationState];
  std::vector<Position> movedTiles;

  for (Position item : tiles)
  {
    Position newPosition = Position(item.row + rowOffset, item.column + columnOffset);
    movedTiles.push_back(newPosition);
  }
  return movedTiles;
}

void Block::Rotate()
{
  rotationState++;
  if (rotationState == (int)cells.size())
  {
    rotationState = 0;
  }
}

void Block::UndoRotation()
{
  rotationState--;
  if (rotationState == -1)
  {
    rotationState = cells.size() - 1;
  }
}
