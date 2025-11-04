#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <tuple>
#include "aoc/dataparser.h"

int computeDistance(std::vector<int> v1, std::vector<int> v2);
int computeSimilarity(std::vector <int> v1, std::vector<int> v2);

int main()
{
    std::tuple<std::vector<int>, std::vector<int>> listInput;
    std::vector<int> list1, list2;

    int dist, simScore;
    int j = 0;
    int counter = 0;

    
    listInput = aoc::twoColsParser("./day-1/input.txt");

    list1 = std::get<0>(listInput);
    list2 = std::get<1>(listInput);

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    // first part
    dist = computeDistance(list1, list2); 
    std::cout << "part 1 : " << dist << "\n";

    // second part
    
    simScore = computeSimilarity(list1, list2);
    std::cout << "part 2 : " << simScore << "\n";

    return 0;
}



int computeDistance(std::vector<int> v1, std::vector<int> v2)
{
    int dist = 0;

    for (int i = 0; i < v1.size(); i++)
    {
        dist += abs(v1[i] - v2[i]);
    }

    return dist;
}

int computeSimilarity(std::vector <int> v1, std::vector<int> v2)
{
    int simScore = 0;
    int counter = 0;
    int j = 0;

    for (int i = 0; i < v1.size(); i++)
    {
        if (i > 0 && !(v1[i] == v1[i - 1]))
        {
            counter = 0;
        }

        while (v2[j] <= v1[i] && j < v2.size())
        {
            if (v1[i] == v2[j])
            {
                counter++;
            }
            j++;
        }
        simScore += counter * v1[i];
    }

    return simScore;
}