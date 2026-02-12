#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

// comparison check helper
// check dampVer for safe
// count safe

// helper function reduce looping
bool checkSafe(vector<int> nums)
{
    bool isIncreasing = nums[1] > nums[0];

    for (size_t i = 0; i < nums.size() - 1; ++i)
    {
        int diff = nums[i + 1] - nums[i];
        int distance = abs(diff);

        if (distance < 1 || distance > 3)
            return false;
        if ((isIncreasing && diff < 0) || (!isIncreasing && diff > 0))
            return false;
    }

    return true;
}

int main()
{
    string line;
    ifstream inputData;

    inputData.open("2_input.txt");

    // [[nums], [nums], [...], ...]
    vector<vector<int>> reports;

    while (getline(inputData, line))
    {
        // stringstream
        // https://www.geeksforgeeks.org/cpp/stringstream-c-applications/
        stringstream ss(line);
        vector<int> currentReport;
        int tempValue;

        while (ss >> tempValue)
        {
            currentReport.push_back(tempValue);
        }

        reports.push_back(currentReport);
    }

    inputData.close();

    int safeCount = 0;

    for (vector<int> nums : reports)
    {
        if (checkSafe(nums))
        {
            safeCount++;
        }
        else
        {
            bool foundNewSafe = false;

            for (int i = 0; i < nums.size(); i++)
            {
                vector<int> dampVer = nums;
                dampVer.erase(dampVer.begin() + i);

                if (checkSafe(dampVer))
                {
                    foundNewSafe = true;
                    break;
                }
            }

            if (foundNewSafe)
            {
                safeCount++;
            }
        }
    }

    cout << "The total reports that are safe is: " << safeCount << endl;
    // The total reports that are safe is: 301

    return 0;
}