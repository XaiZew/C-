#include <iostream>
#include <vector>
#include "tttm.hpp"

int gridSize;

int main()
{
  std::string grid[3][3] = {" ", " ", " ",
                            " ", " ", " ",
                            " ", " ", " "};
  gridSize = sizeof(grid) / sizeof(grid[0]);
  displayGrid(grid);
  loop(grid);
  std::cout << "\nGame Over!\n";
}