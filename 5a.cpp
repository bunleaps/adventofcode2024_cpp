#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// rule storage (matrix)
// parse rules and updates
// check if order is valid
// count totalSum of middle pages

int main()
{
    ifstream inputData("5_input.txt");
    string line;

    // 100x100 matrix
    // page numbers are 2 digits
    bool isBefore[100][100] = {false};
    int totalSum = 0;

    // parse rules (X|Y means X must come before Y)
    while (getline(inputData, line) && !line.empty())
    {
        int x = stoi(line.substr(0, 2));
        int y = stoi(line.substr(3, 2));
        isBefore[x][y] = true;
    }

    // parse updates
    while (getline(inputData, line))
    {
        vector<int> pages;
        stringstream ss(line);
        string temp;

        while (getline(ss, temp, ','))
        {
            pages.push_back(stoi(temp));
        }

        // check if order is valid
        bool isValid = true;
        for (int i = 0; i < pages.size(); i++)
        {
            for (int j = i + 1; j < pages.size(); j++)
            {
                // check rule
                if (isBefore[pages[j]][pages[i]])
                {
                    isValid = false;
                    break;
                }
            }
        }

        // count totalSum of middle pages
        if (isValid)
        {
            totalSum += pages[pages.size() / 2];
        }
    }

    cout << "The total sum of middle page numbers is: " << totalSum << endl;

    return 0;
}