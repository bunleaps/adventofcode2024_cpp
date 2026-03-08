#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

// regex pattern
// calculation
// count totalSum

int main()
{
    ifstream inputData;
    string line;
    int totalSum = 0;

    inputData.open("3_input.txt");

    // MUL(X, Y)
    regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");

    while (getline(inputData, line))
    {
        // String Match
        // https://www.geeksforgeeks.org/cpp/smatch-regex-regular-expressions-in-c/
        smatch match;

        // Regex Search
        // https://www.geeksforgeeks.org/cpp/program-to-find-all-match-of-a-regex-in-a-string/
        while (regex_search(line, match, pattern))
        {
            int x = stoi(match[1]);
            int y = stoi(match[2]);
            totalSum += (x * y);

            // remove everything up to the end of the match
            // so we don't find the same 'mul' again in the next loop
            line = match.suffix().str();
        }
    }

    cout << "All of the results of the multiplications is: " << totalSum << endl;

    inputData.close();
    return 0;
}