#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string names[] = {
        "Hadeer Mahmoud",
        "Youssef Ali",
        "Ahmed Mostafa",
        "Esraa Ebrahim"
    };

    int size = sizeof(names) / sizeof(names[0]);

    sort(names, names + size);

    cout << "Student names in ascending order:\n";
    for (int i = 0; i < size; i++) {
        cout << names[i] << endl;
    }

    return 0;
}
