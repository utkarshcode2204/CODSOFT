#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    string desc;
    cout << "Enter task description: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer before getline
    getline(cin, desc);
    tasks.push_back({desc, false});
    cout << "Task added successfully.\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks in your to-do list.\n";
        return;
    }
    cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". [" << (tasks[i].completed ? 'X' : ' ') << "] " << tasks[i].description << "\n";
    }
    cout << endl;
}

void markTaskCompleted() {
    int taskNum;
    cout << "Enter task number to mark as completed: ";
    while (!(cin >> taskNum) || taskNum < 1 || taskNum > (int)tasks.size()) {
        cout << "Invalid task number. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    tasks[taskNum - 1].completed = true;
    cout << "Task marked as completed.\n";
}

void removeTask() {
    int taskNum;
    cout << "Enter task number to remove: ";
    while (!(cin >> taskNum) || taskNum < 1 || taskNum > (int)tasks.size()) {
        cout << "Invalid task number. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    tasks.erase(tasks.begin() + taskNum - 1);
    cout << "Task removed successfully.\n";
}

int main() {
    int choice;

    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";
        
        while (!(cin >> choice) || choice < 1 || choice > 5) {
            cout << "Invalid choice. Please enter a number between 1 and 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting. Goodbye!\n"; break;
        }
    } while (choice != 5);

    return 0;
}
