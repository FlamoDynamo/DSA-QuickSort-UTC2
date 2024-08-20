#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum Priority { Low = 3, Medium = 2, High = 1 };

class Task {
public:
    Task(string name, int estimatedTime, Priority priority, bool isDone)
        : name(name), estimatedTime(estimatedTime), priority(priority), isDone(isDone) {}

    string getName() const { return name; }
    int getEstimatedTime() const { return estimatedTime; }
    Priority getPriority() const { return priority; }
    bool isCompleted() const { return isDone; }

    void setName(string name) { this->name = name; }
    void setEstimatedTime(int estimatedTime) { this->estimatedTime = estimatedTime; }
    void setPriority(Priority priority) { this->priority = priority; }
    void setCompleted(bool isDone) { this->isDone = isDone; }

private:
    string name;
    int estimatedTime;
    Priority priority;
    bool isDone;
};

class Sorter {
public:
    static void quickSort(vector<Task>& tasks, int left, int right, bool ascending, bool byPriority) {
        if (left < right) {
            int pivotIndex = partition(tasks, left, right, ascending, byPriority);
            quickSort(tasks, left, pivotIndex - 1, ascending, byPriority);
            quickSort(tasks, pivotIndex + 1, right, ascending, byPriority);
        }
    }

private:
    static int partition(vector<Task>& tasks, int left, int right, bool ascending, bool byPriority) {
        Task pivot = tasks[left];
        int low = left + 1;
        int high = right;

        while (true) {
            while (low <= high &&
                  ((byPriority ? tasks[low].getPriority() : tasks[low].getEstimatedTime()) <=
                   (byPriority ? pivot.getPriority() : pivot.getEstimatedTime())) == ascending) {
                low++;
            }
            while (low <= high &&
                  ((byPriority ? tasks[high].getPriority() : tasks[high].getEstimatedTime()) >=
                   (byPriority ? pivot.getPriority() : pivot.getEstimatedTime())) == ascending) {
                high--;
            }
            if (low > high) {
                break;
            }
            swap(tasks[low], tasks[high]);
        }
        swap(tasks[left], tasks[high]);
        return high;
    }
};

class TaskManager {
public:
    void addTask(vector<Task>& tasks) {
        string name;
        int estimatedTime;
        int priorityInput;  // Changed to int

        cin.ignore();  // Clear the input buffer
        cout << "Enter task name: ";
        getline(cin, name);
        cout << "Enter estimated time (minutes): ";
        cin >> estimatedTime;
        cout << "Enter priority (1 = High, 2 = Medium, 3 = Low): ";
        cin >> priorityInput;
        Priority priority = static_cast<Priority>(priorityInput); // Convert int to Priority

        tasks.push_back(Task(name, estimatedTime, priority, false));
    }

    void editTask(vector<Task>& tasks, int index) {
        int choice;
        cout << "Choose which field to edit (0 to exit):\n";
        cout << "1. Name\n";
        cout << "2. Estimated time\n";
        cout << "3. Priority\n";
        cout << "4. Completed status\n";
        cout << "> ";
        cin >> choice;

        cin.ignore(); // Clear the input buffer after cin

        while (choice != 0) {
            string name;
            int estimatedTime;
            int priorityInput;  // Changed to int
            bool isDone;

            switch (choice) {
                case 1:
                    cout << "Enter new task name: ";
                    getline(cin, name);
                    tasks[index].setName(name);
                    break;
                case 2:
                    cout << "Enter new estimated time (minutes): ";
                    cin >> estimatedTime;
                    tasks[index].setEstimatedTime(estimatedTime);
                    break;
                case 3:
                    cout << "Enter new priority (1 = High, 2 = Medium, 3 = Low): ";
                    cin >> priorityInput;
                    tasks[index].setPriority(static_cast<Priority>(priorityInput)); // Convert int to Priority
                    break;
                case 4:
                    cout << "Enter new completed status (1 = true, 0 = false): ";
                    cin >> isDone;
                    tasks[index].setCompleted(isDone);
                    break;
            }

            cout << "Choose which field to edit (0 to exit):\n";
            cout << "1. Name\n";
            cout << "2. Estimated time\n";
            cout << "3. Priority\n";
            cout << "4. Completed status\n";
            cout << "> ";
            cin >> choice;

            cin.ignore(); // Clear the input buffer after cin
        }
    }

    void deleteTask(vector<Task>& tasks, int index) {
        tasks.erase(tasks.begin() + index);
    }

    void displayTasks(const vector<Task>& tasks, bool showAll, bool showCompleted, bool showInProgress) {
        for (size_t i = 0; i < tasks.size(); i++) {
            const Task& task = tasks[i];

            if ((showAll || (showCompleted && task.isCompleted()) || (showInProgress && !task.isCompleted())) &&
                (task.getPriority() == High || task.getEstimatedTime() <= 120)) { // Fixed the condition
                cout << i + 1 << ". " << task.getName() << ", " << task.getEstimatedTime() << " minutes, " <<
                    (task.getPriority() == High ? "High" : (task.getPriority() == Medium ? "Medium" : "Low")) << ", " <<
                    (task.isCompleted() ? "Completed" : "In progress") << endl;
            }
        }
    }

    void sortTasks(vector<Task>& tasks, bool byPriority, bool ascending) {
        Sorter::quickSort(tasks, 0, tasks.size() - 1, ascending, byPriority);
    }
};

int main() {
    vector<Task> tasks;
    TaskManager taskManager;

    int choice;
    while (true) {
        cout << "\nTo Do List\n";
        cout << "1. Add task\n";
        cout << "2. Edit task\n";
        cout << "3. Delete task\n";
        cout << "4. Display tasks\n";
        cout << "5. Sort tasks\n";
        cout << "0. Exit\n";
        cout << "> ";
        cin >> choice;

        switch (choice) {
            case 1:
                taskManager.addTask(tasks);
                break;
            case 2:
            {
                int index;
                cout << "Enter task index to edit: ";
                cin >> index;
                taskManager.editTask(tasks, index - 1);
                break;
            }
            case 3:
            {
                int index;
                cout << "Enter task index to delete: ";
                cin >> index;
                taskManager.deleteTask(tasks, index - 1);
                break;
            }
            case 4:
            {
                int choice;
                cout << "Choose which tasks to display (0 to exit):\n";
                cout << "1. All tasks\n";
                cout << "2. Completed tasks\n";
                cout << "3. In progress tasks\n";
                cout << "> ";
                cin >> choice;

                bool showAll = false, showCompleted = false, showInProgress = false;
                switch (choice) {
                    case 1:
                        showAll = true;
                        showCompleted = true;
                        showInProgress = true;
                        break;
                    case 2:
                        showAll = false;
                        showCompleted = true;
                        showInProgress = false;
                        break;
                    case 3:
                        showAll = false;
                        showCompleted = false;
                        showInProgress = true;
                        break;
                    default:
                        return 0;
                }

                int choice2;
                cout << "Choose how to sort tasks (0 to exit):\n";
                cout << "1. By priority (ascending)\n";
                cout << "2. By estimated time (ascending)\n";
                cout << "3. By estimated time (descending)\n";
                cout << "> ";
                cin >> choice2;

                bool byPriority, ascending;
                switch (choice2) {
                    case 1:
                        byPriority = true;
                        ascending = true;
                        break;
                    case 2:
                        byPriority = false;
                        ascending = true;
                        break;
                    case 3:
                        byPriority = false;
                        ascending = false;
                        break;
                    default:
                        return 0;
                }

                taskManager.sortTasks(tasks, byPriority, ascending);
                taskManager.displayTasks(tasks, showAll, showCompleted, showInProgress);
                break;
            }
            case 5:
            {
                int choice;
                cout << "Choose how to sort tasks (0 to exit):\n";
                cout << "1. By priority (ascending)\n";
                cout << "2. By estimated time (ascending)\n";
                cout << "3. By estimated time (descending)\n";
                cout << "> ";
                cin >> choice;

                bool byPriority, ascending;
                switch (choice) {
                    case 1:
                        byPriority = true;
                        ascending = true;
                        break;
                    case 2:
                        byPriority = false;
                        ascending = true;
                        break;
                    case 3:
                        byPriority = false;
                        ascending = false;
                        break;
                    default:
                        return 0;
                }

                taskManager.sortTasks(tasks, byPriority, ascending);
                break;
            }
            case 0:
                return 0;
        }
    }
}
