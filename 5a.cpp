#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// load grid
// skip edges (center 'A')
// check diagonals for M and S
// count totalSum

int main()
{
    ifstream inputData;
    string line;
    vector<string> grid;
    int totalSum = 0;

    // grid forming
    inputData.open("4_input.txt");

    while (getline(inputData, line))
    {
        if (!line.empty())
        {
            grid.push_back(line);
        }
    }

    inputData.close();

    // grid dimensions
    int rows = grid.size();
    int cols = grid[0].size();
    // string target = "XMAS";

    // skip edges
    for (int r = 1; r < rows - 1; r++)
    {
        for (int c = 1; c < cols - 1; c++)
        {
            // find center 'A'
            if (grid[r][c] == 'A')
            {
                // check diagonals for M and S

                // TL to BR
                char tl = grid[r - 1][c - 1];
                char br = grid[r + 1][c + 1];

                // TR to BL
                char tr = grid[r - 1][c + 1];
                char bl = grid[r + 1][c - 1];

                bool diag1Valid = (tl == 'M' && br == 'S') || (tl == 'S' && br == 'M');
                bool diag2Valid = (tr == 'M' && bl == 'S') || (tr == 'S' && bl == 'M');

                // count totalSum
                if (diag1Valid && diag2Valid)
                {
                    totalSum++;
                }
            }
        }
    }

    cout << "The total times X-MAS appear is: " << totalSum << endl;

    return 0;
}