#include <iostream>
#include <string>

// fstream to work with file
#include <fstream>

#include <vector>


using namespace std;

int main(){

    vector<int> list1, list2;

    int newInt;
    string myText;

    ifstream MyReadFile("./data/input.txt");

    while (getline (MyReadFile, myText)){
        newInt = stoi(myText);
        cout << newInt << "\n";
    }
    

    cout << "Hello world !\n";

    return 0;
}