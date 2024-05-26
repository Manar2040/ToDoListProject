#ifndef NODE_H
#define NODE_H
#include <string>
struct Node
{
	std::string TaskName;
	
	 bool isDone=false;
	Node* NextTask = nullptr;

};

#endif