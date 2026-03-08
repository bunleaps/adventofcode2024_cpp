#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// grid dimensions
// direction vectors (8 ways)
// boundary check
// totalSum count

int main()
{
    ifstream inputData;
    string line;
    vector<string> grid;
    int totalSum = 0;

    inputData.open("4_input.txt");

    // grid forming
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
    string target = "XMAS";

    // direction vectors (N, NE, E, SE, S, SW, W, NW)
    int dRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Iterate all character
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            // Only search if we find 'X'
            if (grid[r][c] == 'X')
            {
                // Check all 8 directions
                for (int dir = 0; dir < 8; dir++)
                {
                    bool match = true;

                    for (int i = 1; i < 4; i++)
                    {
                        int nextR = r + (dRow[dir] * i);
                        int nextC = c + (dCol[dir] * i);

                        // boundary check
                        if (nextR < 0 || nextR >= rows || nextC < 0 || nextC >= cols)
                        {
                            match = false;
                            break;
                        }

                        // check for M, A, S sequence
                        if (grid[nextR][nextC] != target[i])
                        {
                            match = false;
                            break;
                        }
                    }

                    // count totalSum
                    if (match)
                    {
                        totalSum++;
                    }
                }
            }
        }
    }

    cout << "The total times XMAS appear is: " << totalSum << endl;

    return 0;
}