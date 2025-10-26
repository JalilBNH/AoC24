#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> list1, list2;

    int num1, num2, dist, simScore;
    int j = 0;
    int counter = 0;

    string inputLine;

    ifstream inputFile("./input.txt");

    while (getline(inputFile, inputLine))
    {
        num1 = stoi(inputLine.substr(0, inputLine.find(" ")));
        num2 = stoi(inputLine.substr(inputLine.find(" ") + 3, inputLine.size() - 1));

        list1.push_back(num1);
        list2.push_back(num2);
    }

    inputFile.close();

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    // first part
    dist = 0;
    for (int i = 0; i < list1.size(); i++)
    {
        dist += abs(list1[i] - list2[i]);
    }
    cout << "part 1 : " << dist << "\n";

    // second part
    simScore = 0;
    for (int i = 0; i < list1.size(); i++)
    {
        if (i > 0 && !(list1[i] == list1[i - 1]))
        {
            counter = 0;
        }

        while (list2[j] <= list1[i] && j < list2.size())
        {
            if (list1[i] == list2[j])
            {
                counter++;
            }
            j++;
        }
        simScore += counter * list1[i];
    }
    cout << "part 2 : " << simScore << "\n";

    return 0;
}