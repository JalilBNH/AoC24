#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>


int main()
{
    std::ifstream inputFile("./input.txt");
    std::string input;
    int digit1, digit2;
    int res = 0;
    char c;

    std::regex regMul(R"foo((mul\()(\d+),(\d+)\))foo");

    
    while (inputFile.get(c))
    {
        input += c;
    }
    inputFile.close();

    auto begin = std::sregex_iterator(input.begin(), input.end(), regMul);
    auto end = std::sregex_iterator();

    for (std::sregex_iterator i = begin; i != end; i++)
    {
        std::smatch match = *i; 
        digit1 = std::stoi(match[2].str());
        digit2 = std::stoi(match[3].str());
        res += digit1 * digit2;
    }
    std::cout << "Result : "<< res << '\n';
}



