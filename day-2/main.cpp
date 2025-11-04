#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

std::vector<std::vector<int>> stringToIntTab(std::string inputPath);
bool comp(int a, int b);
bool checkStepCondition(int a, int b);
bool isSorted(std::vector<int> line);
bool checkLineStep(std::vector<int> line);
bool isLineSafe(std::vector<int> line);

int main()
{
    int least = 1;
    int most = 3;
    bool safeState;
    int increaseState;
    int safeCount = 0;

    int diff;
    int pDiff;

    std::vector<std::vector<int>> input;

    input = stringToIntTab("./input.txt");

    std::cout << "Input size : " << input.size() << std::endl;
    for (int i = 0; i < input.size(); i++)
    {
        if (isLineSafe(input[i]))
        {
            safeCount++;
        }
    }

    std::cout << "Safe count : " << safeCount << std::endl;

    return 0;
}

std::vector<std::vector<int>> stringToIntTab(std::string inputPath)
{
    std::ifstream inputFile(inputPath);
    std::string inputLine;
    int number;

    std::vector<std::vector<int>> input;

    while (getline(inputFile, inputLine))
    {
        std::stringstream iss(inputLine);
        std::vector<int> line;

        while (iss >> number)
        {
            line.push_back(number);
        }
        input.push_back(line);
    }

    inputFile.close();
    return input;
}

bool comp(int a, int b)
{
    return a > b;
}

bool isSorted(std::vector<int> line)
{
    if (std::is_sorted(line.begin(), line.end()) || std::is_sorted(line.begin(), line.end(), comp))
    {
        return true;
    }
    return false;
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

bool checkLineStep(std::vector<int> line)
{

    for (int i = 0; i < line.size() - 1; i++)
    {
        if (!(checkStepCondition(line[i], line[i + 1])))
        {
            return false;
        }
    }
    return true;
}

bool isLineSafe(std::vector<int> line)
{
    bool sorted, stepCondition;

    sorted = isSorted(line);
    stepCondition = checkLineStep(line);

    if (sorted && stepCondition)
    {
        return true;
    }
    return false;
}
