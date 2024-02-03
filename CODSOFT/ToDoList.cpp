#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};


void displayTasks(const vector<Task>& tasks);
void addTask(vector<Task>& tasks);
void markTaskAsCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\nTask Manager Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                displayTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting Task Manager. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}

void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        cout << "Task List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " - " << (tasks[i].completed ? "Completed" : "Pending") << "\n";
        }
    }
}

void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter the task description: ";
    cin.ignore(); 
    getline(cin, description);

    tasks.push_back(Task(description));
    cout << "Task added successfully.\n";
}

void markTaskAsCompleted(vector<Task>& tasks) {
    displayTasks(tasks);

    if (!tasks.empty()) {
        int index;
        cout << "Enter the task number to mark as completed: ";
        cin >> index;

        if (index > 0 && index <= static_cast<int>(tasks.size())) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
}

void removeTask(vector<Task>& tasks) {
    displayTasks(tasks);

    if (!tasks.empty()) {
        int index;
        cout << "Enter the task number to remove: ";
        cin >> index;

        if (index > 0 && index <= static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed successfully.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
}
