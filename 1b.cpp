#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// do split int on input --> stringstream
// store listOne, listTwo --> sort(optional)
// do counting --> for loop count
// calculate similarity score --> sum

int main()
{
    ifstream inputData;
    vector<int> listOne, listTwo;

    inputData.open("1_input.txt");

    // stringstream
    // https://www.geeksforgeeks.org/cpp/stringstream-c-applications/
    // do split int on input --> stringstream
    int val1, val2;
    while (inputData >> val1 >> val2)
    {
        // store listOne, listTwo
        listOne.push_back(val1);
        listTwo.push_back(val2);
    }

    inputData.close();

    // listOne, listTwo --> sort
    sort(listOne.begin(), listOne.end());
    sort(listTwo.begin(), listTwo.end());

    // do counting --> for loop count
    vector<pair<int, int>> similarCount;
    for (int num : listOne)
    {
        // count
        // https://www.w3schools.com/cpp/ref_algorithm_count.asp
        int freq = count(listTwo.begin(), listTwo.end(), num);
        similarCount.push_back({num, freq});
    }

    // calculate similarity score --> sum
    int sum = 0;
    for (pair<int, int> num : similarCount)
    {
        // cout << num.first << " " << num.second << endl;
        sum += num.first * num.second;
    }

    cout << "The similarity score is: " << sum << endl;
    // The similarity score is : 21328497

    return 0;
}