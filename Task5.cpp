#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

int main() {
    ofstream outFile("students.txt", ios::app);

    if (!outFile.is_open()) {
        cout << "Error: Could not open students.txt." << endl;
        return 1;
    }

    char name[20];
    int id;
    float grade;
    char choice;

    do {
        cout << "Enter student name: ";
        cin.getline(name, 20);

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student grade: ";
        cin >> grade;

        // Save the student record with '$' as the delimiter.
        outFile << name << ", " << id << ", " << grade << " $" << endl;

        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice == 'y' || choice == 'Y');

    outFile.close();

    cout << "Student records saved successfully in students.txt." << endl;

    return 0;
}
