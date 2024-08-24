#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
  Game();
  ~Game();
  void Draw(int padding);
  void HandleInput();
  void MoveBlockDown();
  bool gameOver;
  int score;
  Music music;

private:
  Grid grid;
  void MoveBlockLeft();
  void MoveBlockRight();
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  bool IsBlockOutside();
  void RoateBlock();
  void LockBlock();
  bool BlockFits();
  void Reset();
  void UpdateScore(int linesCleared, int moveDownPoints);
  std::vector<Block> blocks;
  Block currentBlock;
  Block nextBlock;
  Sound rotateSound;
  Sound clearSound;
};