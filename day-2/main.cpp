#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
#include <tuple>
#include "aoc/dataparser.h"


bool checkStepCondition(int a, int b);
void updateFlags(int a, int b, bool *isIncreasing, bool *isDecreasing);
bool isLineSafe(std::vector<int> line);

int main()
{
    int least = 1;
    int most = 3;
    bool safeState;
    int idxRemove;
    int increaseState;
    int safeCount = 0;
    

    int diff;
    int pDiff;

    std::vector<std::vector<int>> input;
    std::vector <int> inputCopy;

    input = aoc::stringToIntTab("./day-2/input.txt");

    std::cout << "Input size : " << input.size() << std::endl;
    for (int i = 0; i < input.size(); i++)
    {
        safeState = isLineSafe(input[i]);
        if (safeState)
        {
            safeCount++;
        }
        else
        {
            int j = 0;
            while (!safeState && j < input[i].size())
            {
                inputCopy = input[i];
                inputCopy.erase(inputCopy.begin()+j);
                safeState = isLineSafe(inputCopy);
                j++;
            }
            if (safeState){safeCount++;}
        }
    }

    std::cout << "Safe count : " << safeCount << std::endl;

    return 0;
}


bool checkStepCondition(int a, int b)
{
    int diff;

    diff = b - a;
    if (abs(diff) < 1 || abs(diff) > 3)
    {
        return false;
    }
    return true;
}

void updateFlags(int a, int b, bool *isIncreasing, bool *isDecreasing)
{
    if (a > b){*isDecreasing = false;} 
    else {*isIncreasing = false;}
}

bool isLineSafe(std::vector<int> line)
{
    bool isIncreasing = true;
    bool isDecreasing = true;

    for (int i = 0; i < line.size() - 1; i++)
    {
        if (!(checkStepCondition(line[i], line[i + 1])))
        {
            return false;
        }
        
        updateFlags(line[i], line[i+1], &isIncreasing, &isDecreasing);

        if (!isIncreasing && !isDecreasing)
        {
            return false;
        }
    }
    return true;
}