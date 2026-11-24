#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "How many persons do you want to add? ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number of persons." << endl;
        return 1;
    }

    // Step 1: Get persons' details and save them in persons.txt
    ofstream outFile("persons.txt");
    if (!outFile.is_open()) {
        cout << "Error opening persons.txt." << endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        Person person;

        cout << "Enter name of person " << i + 1 << ": ";
        getline(cin >> ws, person.name);

        cout << "Enter age of person " << i + 1 << ": ";
        cin >> person.age;

        outFile << person.name << '\n' << person.age << '\n';
    }
    outFile.close();

    // Step 2: Read all persons from persons.txt into a vector
    ifstream inFile("persons.txt");
    if (!inFile.is_open()) {
        cout << "Error reading persons.txt." << endl;
        return 1;
    }

    vector<Person> people;
    Person person;

    while (getline(inFile, person.name)) {
        if (!(inFile >> person.age)) {
            break;
        }
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        people.push_back(person);
    }
    inFile.close();

    if (people.empty()) {
        cout << "No persons were found in the file." << endl;
        return 1;
    }

    // Find the youngest and oldest persons
    auto youngest = min_element(people.begin(), people.end(),
        [](const Person& a, const Person& b) {
            return a.age < b.age;
        });

    auto oldest = max_element(people.begin(), people.end(),
        [](const Person& a, const Person& b) {
            return a.age < b.age;
        });

    // Save the results in results.txt
    ofstream resultsFile("results.txt");
    if (!resultsFile.is_open()) {
        cout << "Error opening results.txt." << endl;
        return 1;
    }

    resultsFile << "Youngest person: " << youngest->name
                << ", Age: " << youngest->age << '\n';
    resultsFile << "Oldest person: " << oldest->name
                << ", Age: " << oldest->age << '\n';

    resultsFile.close();

    cout << "The youngest and oldest persons were saved in results.txt." << endl;

    return 0;
}
