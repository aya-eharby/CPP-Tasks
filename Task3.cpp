#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Write the original sentence to welcome.txt
    ofstream outFile("welcome.txt");

    if (!outFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    outFile << "Hello Everybody";
    outFile.close();

    // Read the sentence from the file
    ifstream inFile("welcome.txt");

    if (!inFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string sentence;
    getline(inFile, sentence);
    inFile.close();

    // Replace "body" with "one"
    size_t position = sentence.find("body");

    if (position != string::npos) {
        sentence.replace(position, 4, "one");
    }

    // Write the final sentence to the same file
    ofstream finalFile("welcome.txt");

    if (!finalFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    finalFile << sentence;
    finalFile.close();

    cout << sentence << endl;

    return 0;
}
