#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

// read each lines
// each [int] from the lines
// push back to reports[]
// comparison check
// count safe reports

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
        // sort(nums.begin(), nums.end());

        bool isIncreasing = nums[1] > nums[0];
        bool isSafe = true;

        // Check adjacent differences
        for (size_t i = 0; i < nums.size() - 1; ++i)
        {
            int diff = nums[i + 1] - nums[i];
            int distance = abs(diff);

            if ((isIncreasing && diff < 0) || (!isIncreasing && diff > 0))
            {
                isSafe = false;
                break;
            }

            if (distance < 1 || distance > 3)
            {
                isSafe = false;
                break;
            }
        }

        // Print the status
        if (isSafe)
        {
            safeCount++;
        }
    }

    cout << "The total reports that are safe is: " << safeCount << endl;

    return 0;
}