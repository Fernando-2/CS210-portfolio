#include <iostream>
#include <string>
#include "GroceryTracker.h"

using namespace std;

static void PrintMenu() {
    cout << "\n========== Corner Grocer ==========\n";
    cout << "1. Look up an item frequency\n";
    cout << "2. Print all item frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "Choose an option (1-4): ";
}

static int ReadMenuChoice() {
    string line;
    getline(cin, line);

    try {
        int choice = stoi(line);
        return choice;
    }
    catch (...) {
        return -1;
    }
}

int main() {
    GroceryTracker tracker;

    const string inputFile = "CS210_Project_Three_Input_File.txt";
    const string backupFile = "frequency.dat";

    if (!tracker.LoadFromFile(inputFile)) {
        cout << "Error: Could not open input file: " << inputFile << endl;
        return 1;
    }

    // Create backup file automatically at the beginning
    if (!tracker.WriteBackupFile(backupFile)) {
        cout << "Warning: Could not write backup file: " << backupFile << endl;
    }

    bool running = true;
    while (running) {
        PrintMenu();
        int choice = ReadMenuChoice();

        switch (choice) {
        case 1: {
            cout << "Enter an item to search for: ";
            string item;
            getline(cin, item);

            int count = tracker.GetFrequency(item);
            cout << item << " appears " << count << " time(s)." << endl;
            break;
        }
        case 2:
            cout << "\nITEM FREQUENCIES\n";
            tracker.PrintAllFrequencies();
            break;

        case 3:
            cout << "\nHISTOGRAM\n";
            tracker.PrintHistogram('*');
            break;

        case 4:
            running = false;
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please enter 1, 2, 3, or 4.\n";
            break;
        }
    }

    return 0;
}
