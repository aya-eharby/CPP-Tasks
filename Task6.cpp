#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main()
{
    const char* fileName = "grades.txt";
    const char* tempFileName = "grades_temp.txt";
    const char* backupFileName = "grades_backup.txt";
    int grade;

    // Step 1: Create grades.txt and write five integer grades.
    ofstream outFile(fileName);
    if (!outFile.is_open())
    {
        cout << "Error: Could not create grades.txt.\n";
        return 1;
    }

    cout << "Enter five integer grades:\n";
    for (int i = 1; i <= 5; ++i)
    {
        cout << "Grade " << i << ": ";
        if (!(cin >> grade))
        {
            cout << "Error: Please enter integer grades only.\n";
            outFile.close();
            return 1;
        }
        outFile << grade << '\n';
    }
    outFile.close();

    // Step 2: Read and print all grades using a reading loop.
    cout << "\nGrades before deletion:\n";
    ifstream inFile(fileName);
    if (!inFile.is_open())
    {
        cout << "Error: Could not open grades.txt for reading.\n";
        return 1;
    }

    while (inFile >> grade)
    {
        cout << grade << '\n';
    }
    inFile.close();

    // Step 3: Copy every grade except the requested grade to a temporary file.
    int gradeToDelete;
    cout << "\nEnter the grade you want to delete: ";
    if (!(cin >> gradeToDelete))
    {
        cout << "Error: Please enter an integer grade.\n";
        return 1;
    }

    inFile.open(fileName);
    if (!inFile.is_open())
    {
        cout << "Error: Could not reopen grades.txt.\n";
        return 1;
    }

    outFile.open(tempFileName);
    if (!outFile.is_open())
    {
        cout << "Error: Could not create the temporary file.\n";
        inFile.close();
        return 1;
    }

    int deletedCount = 0;
    while (inFile >> grade)
    {
        if (grade == gradeToDelete)
        {
            ++deletedCount; // Delete every occurrence of the entered grade.
        }
        else
        {
            outFile << grade << '\n';
        }
    }

    inFile.close();
    outFile.close();

    // Step 4: Replace the original file with the temporary file.
    // A backup is used so the original can be restored if replacement fails.
    std::remove(backupFileName); // Remove an old backup, if one exists.

    if (std::rename(fileName, backupFileName) != 0)
    {
        cout << "Error: Could not prepare the original file for replacement.\n";
        return 1;
    }

    if (std::rename(tempFileName, fileName) != 0)
    {
        std::rename(backupFileName, fileName); // Try to restore the original.
        cout << "Error: Could not replace grades.txt. The original file was restored if possible.\n";
        return 1;
    }

    std::remove(backupFileName);

    cout << "\n";
    if (deletedCount > 0)
    {
        cout << "Success: Grade " << gradeToDelete << " was deleted "
             << deletedCount << " time(s).\n";
    }
    else
    {
        cout << "Success: Grade " << gradeToDelete
             << " was not found, so the grades stayed unchanged.\n";
    }

    // Display the contents of grades.txt after deletion.
    cout << "\nGrades after deletion:\n";
    inFile.open(fileName);
    if (!inFile.is_open())
    {
        cout << "Error: Could not open the updated grades.txt.\n";
        return 1;
    }

    bool hasGrades = false;
    while (inFile >> grade)
    {
        cout << grade << '\n';
        hasGrades = true;
    }
    inFile.close();

    if (!hasGrades)
    {
        cout << "The file is empty.\n";
    }

    return 0;
}
