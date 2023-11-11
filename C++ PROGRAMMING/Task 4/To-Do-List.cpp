/*TASK 4
TO-DO LIST
Build a simple console-based to-do list
manager that allows users to add, view, and
delete tasks
Task Input: Allow users to input tasks they want to add to the list.(DONE)
Add Task: Implement a function to add tasks to the list.(DONE)
View Tasks: Display the list of tasks with their status (completed or
pending).(DONE)
Mark Task as Completed: Allow users to mark tasks as completed.(DONE)
Remove Task: Provide an option to remove tasks from the list.(DONE)*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class todolist
{
    vector<string> list;
    vector<string> status;
    string comp = "Completed";
    string incomp = "Pending";

    int tasks_num;

public:
    void input_tasks()
    {
        cout << "===== INPUT TASKS =====\n";
        cout << "Please enter the number of tasks you want to add: ";
        cin >> tasks_num;

        cout << "\nEnter your tasks:\n";
        for (int i = 0; i < tasks_num; i++)
        {
            string task;
            cout << "Task " << (i + 1) << ": ";
            cin >> task;
            list.push_back(task);
            status.push_back(incomp);
        }

        cout << "Tasks added successfully!\n";
        cout << "\n";
    }

    void add_task()
    {
        cout << "==== ADD TASKS ====\n";
        cout << "How many tasks would you like to add? ";
        int num;
        cin >> num;

        cout << "Enter the tasks:\n";
        for (int i = 0; i < num; i++)
        {
            string task;
            cout << "Task " << (i + 1) << ": ";
            cin >> task;
            list.push_back(task);
            status.push_back(incomp);
        }

        cout << "Tasks added successfully!\n";
    }

    void remove_tasks()
    {
        cout << "===== REMOVE TASK =====\n";
        cout << "Current tasks:\n";
        display_tasks();
        cout << "Enter the number of the task you want to remove: ";
        int num;
        cin >> num;

        if (num < 1 || num > list.size())
        {
            cout << "Invalid task number. Please enter a valid task number.\n";
            return;
        }

        list.erase(list.begin() + (num - 1));
        status.erase(status.begin() + (num - 1));

        cout << "Task removed successfully.\n";
        cout << "Updated tasks:\n";
        display_tasks();

        cout << "=========================\n";
    }

    void mark_complete()
    {
        cout << "===== MARK TASK AS COMPLETE =====\n";

        if (list.empty())
        {
            cout << "No tasks available to mark as complete.\n";
        }
        else
        {
            cout << "Current Tasks:\n";
            display_tasks();

            cout << "\nEnter the number corresponding to the task you want to mark as complete: ";
            int num;
            cin >> num;

            if (num >= 1 && num <= list.size())
            {
                status[num - 1] = comp;
                cout << "Task marked as complete.\n";
            }
            else
            {
                cout << "Invalid task number. Please enter a valid task number.\n";
            }
        }

        cout << "=================================\n";
    }

    void display_tasks()
    {
        cout << "=======================\n";
        cout << "        TASKS\n";
        cout << "=======================\n";
        cout << "Sr. No.   Tasks           Status\n";
        cout << "---------------------------------\n";

        for (int i = 0; i < list.size(); i++)
        {
            cout << setw(8) << (i + 1) << setw(16) << list[i] << setw(12) << status[i] << "\n";
        }

        cout << "=======================\n";
    }

    void manage_tasks()
    {

        while (true)
        {
            cout << "===== TO-DO LIST MANAGER =====\n";
            cout << "1. Add tasks\n";
            cout << "2. Remove tasks\n";
            cout << "3. Mark task as complete\n";
            cout << "4. Display tasks\n";
            cout << "5. Close To-do list\n";
            cout << "==============================\n";
            cout << "Enter the number corresponding to the operation you want to perform: ";

            int num;
            cin >> num;
            if (num == 5)
            {
                break;
            }

            switch (num)
            {
            case 1:
                add_task();
                break;
            case 2:
                remove_tasks();
                break;
            case 3:
                mark_complete();
                break;
            case 4:
                display_tasks();
                break;
            case 5:

                break;
            }
        }
    }
};

int main()
{
    cout << "===================================\n";
    cout << "        WELCOME TO TO-DO-LIST\n";
    cout << "===================================\n";
    cout << "Plan your day and stay organized!\n";
    cout << "How many tasks do you want to enter?\n";
    cout << "===================================\n";

    todolist daily_task;
    daily_task.input_tasks();
    daily_task.manage_tasks();
}