#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// do split int on input --> stringstream
// store listOne, listTwo --> sort
// do distance calculation --> if/else
// calculate total distance --> sum

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

    // do distance calculation --> if/else
    vector<int> difference;
    for (int i = 0; i < listOne.size(); i++)
    {
        if (listOne[i] - listTwo[i] < 0)
        {
            difference.push_back(listTwo[i] - listOne[i]);
        }
        else
        {
            difference.push_back(listOne[i] - listTwo[i]);
        }
    }

    // calculate total distance --> sum
    int sum = 0;
    for (int num : difference)
    {
        sum += num;
    }

    cout << "The total distance is: " << sum << endl;
    // The total distance is: 2742123

    return 0;
}