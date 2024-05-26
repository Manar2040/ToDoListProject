#ifndef TODOLIST_H
#define TODOLIST_H

#include <string>
#include "Node.h"

class ToDoList {
 public:
	ToDoList();
	bool IsEmpty();
	void add(std::string taskName);
	void Display();
	bool isFound(std::string taskName);
	int checkStatus(std::string taskName);
	void Delete(std::string taskName);
	void MarkTaskAsDone(std::string taskName);
	int countTasks();
  private:
	  Node* Head;

};
#endif