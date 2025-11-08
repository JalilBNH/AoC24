#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include "aoc/dataparser.h"



int main()
{
    std::string input;
    int res = 0;    
    bool doCheck = true;

    std::regex regMul(R"foo(do\(\)|don\'t\(\)|mul\((\d+),(\d+)\))foo");

    input = aoc::txtToString("./day-3/input.txt");
    

    auto begin = std::sregex_iterator(input.begin(), input.end(), regMul);
    auto end = std::sregex_iterator();

    for (std::sregex_iterator i = begin; i != end; i++)
    {
        std::smatch match = *i;
        
        if (match.str() == "don't()"){doCheck = false;}
        else if (match.str() == "do()"){doCheck = true;}
        else 
        {
            if (doCheck)
            {
                res += std::stoi(match[1].str()) * std::stoi(match[2].str());
            }    
        }
    }
    std::cout << "Result : "<< res << std::endl;
}



