#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name, id;
    float grade;

    // Accept student data
    cout << "Enter full name: ";
    getline(cin, name);

    cout << "Enter ID: ";
    getline(cin, id);

    cout << "Enter grade: ";
    cin >> grade;

    // Create a new text file
    ofstream file("Student.txt");

    // Write student data into the file
    file << "Full Name: " << name << endl;
    file << "ID: " << id << endl;
    file << "Grade: " << grade << endl;

    file.close();

    cout << "Data saved successfully.";

    return 0;
}
