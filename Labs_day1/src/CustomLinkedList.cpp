
#include "../headers/CustomLinkedList.h"
#include <iostream>

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

bool CustomLinkedList::insertAfterByIndex(int data, int index)
{
    if (head == nullptr || index < 0)
        return false;
    Node *temp = getNode(index);
    if (temp == nullptr)
        return false;
    Node *newNode = new Node(data);
    // Update previous node's next pointer (or head if no previous)
    if (temp->next != nullptr)
    {
        temp->next->prev = newNode;
        newNode->next = temp->next;
    }
    else
    {
        newNode->next = head->next;
        head = newNode;
    }

    if (temp->prev != nullptr)
    {
        temp->next = newNode;
        newNode->prev = temp;
    }
    else
    {
        newNode->prev = tail;
        tail = newNode;
    }

    delete temp;
    return true;
}
bool CustomLinkedList::insertBeforeByIndex(int data, int index)
{
    return true;
}

// insert after data
bool CustomLinkedList::insertAfter(int data, int afterData)
{
    int index = findFirst(afterData);
    return insertAfterByIndex(index, afterData);
}

bool CustomLinkedList::insertBefore(int data, int beforeData)
{
    int index = findFirst(beforeData);
    return insertBeforeByIndex(index, beforeData);
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

void CustomLinkedList::removeALL(int data)
{
}
// helpers
int CustomLinkedList::findFirst(int data)
{
    if (head == nullptr)
    {
        return -1;
    }

    Node *current = head;
    int index;
    bool running = true;
    while (current && running)
    {
        if (current->data == data)
        {
            running = false;
        }
        else
        {
            current = current->next;
            index++;
        }
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
    if (index < 0 || head == nullptr)
        return -1;
    Node *temp = getNode(index);
    if (temp != nullptr)
    {
        return temp->data;
    }
    return -1;
}

// display
void CustomLinkedList::printList()
{
    if (head == nullptr)
        return;

    Node *current = head;

    while (current)
    {
        cout << current->getData();
        current = current->getNext();
    }
    cout << endl;
}
