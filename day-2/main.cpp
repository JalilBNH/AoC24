#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>

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

    input = stringToIntTab("./test_input.txt");

    std::cout << "Input size : " << input.size() << std::endl;
    for (int i = 0; i < input.size(); i++)
    {
        safeState = true;
        int j = 1;
        while (j < input[i].size() && safeState)
        {
            diff = input[i][j] - input[i][j - 1];

            if (abs(diff) < least || abs(diff) > most)
            {
                safeState = false;
            }

            if (j >= 2)
            {
                if (std::signbit(diff) != std::signbit(pDiff))
                {
                    safeState = false;
                }
            }

            pDiff = diff;
            j++;
        }

        if (safeState)
        {
            safeCount++;
        }
    }

    std::cout << "Safe count : " << safeCount << std::endl;

    return 0;
}