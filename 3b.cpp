#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

// regex pattern
// check for do & dont
// calculation
// count totalSum

int main()
{
    ifstream inputData;
    string line;
    int totalSum = 0;
    bool isEnabled = true;

    inputData.open("3_input.txt");

    // MUL(X, Y) OR do() OR don't()
    regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\)|(do\(\))|(don't\(\)))");

    while (getline(inputData, line))
    {
        // String Match
        // https://www.geeksforgeeks.org/cpp/smatch-regex-regular-expressions-in-c/
        smatch match;

        string tempLine = line;

        // Regex Search
        // https://www.geeksforgeeks.org/cpp/program-to-find-all-match-of-a-regex-in-a-string/
        while (regex_search(tempLine, match, pattern))
        {
            if (match[3].matched)
            {
                // do()
                isEnabled = true;
            }
            else if (match[4].matched)
            {
                // don't()
                isEnabled = false;
            }
            else if (match[1].matched && match[2].matched)
            {
                // mul(X,Y) if enabled
                if (isEnabled)
                {
                    int x = stoi(match[1]);
                    int y = stoi(match[2]);
                    totalSum += (x * y);
                }
            }

            // Move to the rest of the string
            tempLine = match.suffix().str();
        }
    }

    cout << "All of the results of the multiplications is: " << totalSum << endl;

    inputData.close();
    return 0;
}