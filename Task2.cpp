#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("fruit.txt");

    if (!inFile.is_open()) {
        cout << "Error: Could not open fruit.txt for reading." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    ofstream outFile("fruit.txt", ios::app);

    if (!outFile.is_open()) {
        cout << "Error: Could not open fruit.txt for writing." << endl;
        return 1;
    }

    outFile << "Fresh Fruits" << endl;
    outFile.close();

    return 0;
}
