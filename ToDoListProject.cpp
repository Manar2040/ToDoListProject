#include <iostream>
#include "ToDoList.h"

using namespace std;

int main()
{
    ToDoList List;

    while (true)
    {
        cout << "Choose an option (Enter the number): " << endl;
        cout << "1- Add a task " << endl;
        cout << "2- Delete an existing task" << endl;
        cout << "3- Show all tasks" << endl;
        cout << "4- Mark a task as done " << endl;
        cout << "5- Check task status" << endl;
        cout << "6-Count number of tasks: " << endl;
        cout << "0- Exit " << endl;
        
        int option;
        cin >> option;

        if (option == 1)
        {
            string name;
          
            cout << "Enter Task Name: " << endl;
            cin >> name;
           

            List.add(name);
        }
        else if (option == 2)
        {
            string name;
            cout << "Enter the name of the task to delete:" << endl;
            cin >> name;
            List.Delete(name);
        }
        else if (option == 3)
        {
            List.Display();
        }
        else if (option == 4)
        {
            string name;
            cout << "Enter the name of the task to mark:" << endl;
            cin >> name;
            List.MarkTaskAsDone(name);
        }
        else if (option == 5)
        {
            string name;
            cout << "Enter the name of the task to check:" << endl;
            cin >> name;
            int status = List.checkStatus(name);
            if (status == 2)
                cout << "The specified task was not found, please check the name and try again!" << endl;
            else if (status == 1)
                cout << "The specified task is Done." << endl;
            else
                cout << "The specified task is still in progress." << endl;
        }
        else if (option == 6) {
            cout << List.countTasks() << endl;
        }
        else if (option == 0)
            break;
        else
        {
            cout << "Invalid option selected. Please try again." << endl;
        }
        
        cout << endl;
    }
   
}


