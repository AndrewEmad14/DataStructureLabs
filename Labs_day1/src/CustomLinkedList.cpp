
#include "../headers/CustomLinkedList.h"
#include <iostream>
#include <stdexcept>
using namespace std;
// constructors

CustomLinkedList::CustomLinkedList() : head(nullptr), tail(nullptr) {}

// insertions

// add at the end of the list

bool CustomLinkedList::add(int data)
{
	Node *newNode = new Node(data);
	// if head is null (meaning list is empty) then make head and tail point to newNode
	// there is no previous node or next node
	if (!head)
	{
		head = newNode;
		tail = newNode;
		return true;
	}
	// link the newNode to the end of the list by doing three steps:
	// 1. make current tail's next point to newNode
	// 2. make newNode's previous point to current tail
	// 3. update tail to point to newNode

	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
	return true;
}

bool CustomLinkedList::insertAfterByIndex(int index, int data)
{
	if (head == nullptr || index < 0)
		return false;
	Node *temp = getNode(index);
	if (temp == nullptr)
		return false;
	Node *newNode = new Node(data);
	// Connect newNode to temp's next
	newNode->prev = temp;
	newNode->next = temp->next;
	// Update temp's next to point to newNode
	temp->next = newNode;
	// If there was a node after temp, update its prev pointer
	if (newNode->next != nullptr)
	{
		newNode->next->prev = newNode;
	}
	else
	{
		// We inserted at the end, so update tail
		tail = newNode;
	}

	return true;
}
bool CustomLinkedList::insertBeforeByIndex(int index, int data)
{
	if (head == nullptr || index < 0)
		return false;
	Node *temp = getNode(index);
	if (temp == nullptr)
		return false;
	Node *newNode = new Node(data);
	// Connect newNode to temp's prev
	newNode->next = temp;
	newNode->prev = temp->prev;
	// update temp prev
	temp->prev = newNode;
	if (newNode->prev != nullptr)
	{
		newNode->prev->next = newNode;
	}
	else
	{
		head = newNode;
	}
	// Connect newNode to temp's previous
	return true;
}

// insert after data
bool CustomLinkedList::insertAfter(int afterData, int data)
{
	int index = findFirst(afterData);
	return insertAfterByIndex(index, data);
}

bool CustomLinkedList::insertBefore(int beforeData, int data)
{
	int index = findFirst(beforeData);
	return insertBeforeByIndex(index, data);
}
// remove functions

// remove at a certain index
bool CustomLinkedList::removeAt(int index)
{
	if (head == nullptr || index < 0)
		return false;

	Node *temp = getNode(index);
	if (temp == nullptr)
		return false;
	// Update previous node's next pointer (or head if no previous)
	if (temp->prev != nullptr)
	{
		temp->prev->next = temp->next;
	}
	else
	{
		head = temp->next; // Removing head
	}

	// Update next node's prev pointer (or tail if no next)
	if (temp->next != nullptr)
	{
		temp->next->prev = temp->prev;
	}
	else
	{
		tail = temp->prev; // Removing tail
	}
	delete temp;
	return true;
}

// remove the first occurence of data
bool CustomLinkedList::removeFirstData(int data)
{
	int index = findFirst(data);
	if (index == -1)
		return false;
	return removeAt(index);
}

int CustomLinkedList::getCount()
{
	if (head == nullptr)
	{
		return 0;
	}
	int counter = 0;
	Node *current = head;
	while (current)
	{
		current = current->next;
		counter++;
	}

	return counter;
}

bool CustomLinkedList::removeALL(int data)
{
	bool removed = false;
	while (removeFirstData(data))
	{
		removed = true;
	}
	return removed;
}
// helpers
int CustomLinkedList::findFirst(int data)
{
	if (head == nullptr)
	{
		return -1;
	}

	Node *current = head;
	int index = 0;
	bool isFound = false;
	while (current && !isFound)
	{
		if (current->data == data)
		{
			isFound = true;
		}
		else
		{
			current = current->next;
			index++;
		}
	}
	if (!isFound)
	{
		return -1;
	}
	return index;
}
Node *CustomLinkedList::getNode(int index)
{
	if (index < 0 || head == nullptr)
	{
		return nullptr;
	}

	Node *current = head;
	for (int i = 0; i < index && current != nullptr; i++)
	{
		current = current->next;
	}
	return current;
}
int CustomLinkedList::getDataByIndex(int index)
{
	if (index < 0)
	{
		throw invalid_argument("Index is negative");
	}
	if (head == nullptr)
	{
		throw invalid_argument("List is empty");
	}

	Node *temp = getNode(index);
	if (temp != nullptr)
	{
		return temp->data;
	}
	throw invalid_argument("Index is out of bounds");
}

// display
void CustomLinkedList::printList()
{
	if (head == nullptr)
	{
		throw logic_error("List is empty");
		return;
	}

	Node *current = head;

	while (current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
