#include <iostream>

void displayGrid(std::string grid[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int y = 0; y < 3; y++)
    {
      std::cout << grid[i][y] << "|";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void loop(std::string grid[3][3])
{
  int row;
  int collumn;
  int turn = 1;
  while (true)
  {
    std::cout << "Type what row and collumn to place cross.\nrow: ";
    std::cin >> row;
    std::cout << "\ncollumn: ";
    std::cin >> collumn;

    if (collumn > 3 || row > 3) // So the array won't wrap around
    {
      std::cout << "You can't place there!\n";
      continue;
    }

    row--;
    collumn--;

    if (grid[row][collumn] == " ") // checks if place is blank
    {
      if (turn % 2 == 0)
      {
        grid[row][collumn] = "Y";
      }
      else
      {
        grid[row][collumn] = "X";
      }
    }
    else
    {
      std::cout << "You can't place there!\n";
      continue;
    }
    turn++;
    std::cout << "\nturn: " << turn << "\n";
    displayGrid(grid);

    if (grid[0][0] == grid[0][1] && grid[0][0] == grid[0][2] && grid[0][0] != " ")
    {
      std::cout << "Top across row done.";
      break;
    }
    else if (grid[1][0] == grid[1][1] && grid[1][0] == grid[1][2] && grid[1][0] != " ")
    {
      std::cout << "Middle across row done.";
      break;
    }
    else if (grid[2][0] == grid[2][1] && grid[2][0] == grid[2][2] && grid[2][0] != " ")
    {
      std::cout << "Bottom across row done.";
      break;
    }
    else if (grid[0][0] == grid[1][0] && grid[0][0] == grid[2][0] && grid[0][0] != " ")
    {
      std::cout << "Left down row done.";
      break;
    }
    else if (grid[0][1] == grid[1][1] && grid[0][1] == grid[2][1] && grid[0][1] != " ")
    {
      std::cout << "Middle down row done.";
      break;
    }
    else if (grid[0][2] == grid[1][2] && grid[0][2] == grid[2][2] && grid[0][2] != " ")
    {
      std::cout << "Right down row done.";
      break;
    }
    else if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][3] && grid[0][0] != " ")
    {
      std::cout << "BackSlash row done.";
      break;
    }
    else if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0] && grid[0][2] != " ")
    {
      std::cout << "ForwardSlash row done.";
      break;
    }
  }
}