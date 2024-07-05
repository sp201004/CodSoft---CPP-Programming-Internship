#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

void addTask(vector<Task>& tasks) {
    cout << "Enter the number of tasks you want to add: ";
    int numberOfTasks;
    cin >> numberOfTasks;
    cin.ignore(); // To ignore the newline character left in the buffer

    for (int i = 0; i < numberOfTasks; ++i) {
        cout << "Enter task description for task " << i + 1 << ": ";
        string description;
        getline(cin, description);
        tasks.push_back(Task(description));
    }
    cout << numberOfTasks << " task(s) added successfully.\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description 
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(vector<Task>& tasks) {
    cout << "Pending tasks:\n";
    vector<size_t> pendingTaskIndices;

    for (size_t i = 0; i < tasks.size(); ++i) {
        if (!tasks[i].completed) {
            cout << pendingTaskIndices.size() + 1 << ". " << tasks[i].description << "\n";
            pendingTaskIndices.push_back(i);
        }
    }

    if (pendingTaskIndices.empty()) {
        cout << "No pending tasks to mark as completed.\n";
        return;
    }

    cout << "Enter tasks to mark as completed (separated by spaces): ";
    string input;
    cin.ignore();
    getline(cin, input);
    stringstream ss(input);
    size_t taskNumber;
    vector<size_t> taskNumbers;

    while (ss >> taskNumber) {
        if (taskNumber == 0 || taskNumber > pendingTaskIndices.size()) {
            cout << "Invalid! 🚫 task number: " << taskNumber << ".\n";
            return;
        }
        taskNumbers.push_back(pendingTaskIndices[taskNumber - 1]);
    }

    for (size_t i = 0; i < taskNumbers.size(); ++i) {
        tasks[taskNumbers[i]].completed = true;
    }
    cout << "Selected tasks marked as completed.\n";
}

void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display.\n";
        return;
    }

    cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description 
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }

    cout << "Enter tasks to remove (separated by spaces): ";
    string input;
    cin.ignore();
    getline(cin, input);
    stringstream ss(input);
    size_t taskNumber;
    vector<size_t> taskNumbers;

    while (ss >> taskNumber) {
        if (taskNumber == 0 || taskNumber > tasks.size()) {
            cout << "Invalid! 🚫 task number: " << taskNumber << ".\n";
            return;
        }
        taskNumbers.push_back(taskNumber - 1);
    }

    // Sort taskNumbers in descending order to avoid issues when erasing elements
    sort(taskNumbers.rbegin(), taskNumbers.rend());

    for (size_t i = 0; i < taskNumbers.size(); ++i) {
        tasks.erase(tasks.begin() + taskNumbers[i]);
    }
    cout << "Selected tasks removed successfully.\n";
}

void displayMenu() {
    cout << "\nTo-Do List Manager\n\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task(s) as Completed\n";
    cout << "4. Remove Task(s)\n";
    cout << "5. Exit\n";
    cout << "\nEnter your choice: ";
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "\nInvalid! 🚫 choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}