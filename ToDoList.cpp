#include "ToDoList.h"
#include <iostream>

using namespace std;

// Constructor initializes the Head to NULL
ToDoList::ToDoList()
{
	Head = nullptr;
}

// Checks if the to-do list is empty
bool ToDoList::IsEmpty()
{
	return(Head == nullptr);
}

// Adds a new task to the to-do list
void ToDoList::add(string taskName)
{  
	Node* newTask = new Node();
	newTask->TaskName = taskName;
	
	

	if (IsEmpty()) {
		Head = newTask;
	}
	else {
		newTask->NextTask = Head;
		Head = newTask;
	}
	cout << "The Task was added Successfully!" << endl;
}

// Displays all tasks in the to-do list
void ToDoList::Display()
{
	Node* temp = Head;
	if (IsEmpty())
		cout << "The ToDo list is Empty" << endl;

	while (temp != NULL)
	{
		cout << "Task Name : " << temp->TaskName  << ", Statue: ";
		if (temp->isDone) cout << "Done";
		else cout << "In Progress";
		cout << endl;
		temp = temp->NextTask;
	}
}

// Checks if a task with the given name exists in the list
bool ToDoList::isFound(string taskName)
{
	Node* temp = Head;
	while (temp != NULL)
	{
		if (temp->TaskName == taskName)
			return true;
		temp = temp->NextTask;
	}
	return false;
}

//Mark task as Done
void ToDoList::MarkTaskAsDone(string taskName)
{
	if (!isFound(taskName))
	{
		cout << "This task isn't found, Check the name! " << endl;
		return;
    }
	Node* temp = Head;
	while (temp != NULL)
	{
		if (temp->TaskName == taskName)
		{
			temp->isDone = true;
				
		}
		temp = temp->NextTask;
	}
	cout << " Greate Work! The Task is Done." << endl;
}
// Checks the status of a task with the given name
int ToDoList::checkStatus(string taskName)
{
	Node* temp = Head;
	while (temp != NULL)
	{
		if (temp->TaskName == taskName)
		{
			if (temp->isDone == true)
				return 1;
			else
				return 0;
		}
		temp = temp->NextTask;
	}
	return 2; // Task not found

}

// Deletes a task with the given name from the list
void ToDoList::Delete(string taskName)
{
	if (!isFound(taskName))
	{
		cout << "This task isn't found, Check the name! "<<endl;
		return;
	}
	if (taskName == Head->TaskName) 
	{
		Node* dltptr = Head;
		Head = Head->NextTask;
		delete dltptr;
	}
	else
	{
		Node* temp = Head;
		while (temp->NextTask->TaskName!=taskName)
		{ 
			temp = temp->NextTask;
		}
		Node* dltptr = temp->NextTask;
		temp->NextTask = temp->NextTask->NextTask;
		delete dltptr;
	}
	cout << "The Task was Deleted Successfully" << endl;
}
int ToDoList::countTasks()
{
	int c = 0;
	Node* temp = Head;

	while (temp != NULL)
	{
		c++;
		temp = temp->NextTask;
	}
	return c;
}