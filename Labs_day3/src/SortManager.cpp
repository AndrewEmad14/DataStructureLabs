#include "../headers/CustomLinkedList.h"
#include <iostream>
#include "../headers/SortManager.h"
using namespace std;
bool SortManager::checkOrder(CustomLinkedList &list, Node *index1, Node *index2)
{
    Node *temp = list.getHead();

    while (temp != nullptr)
    {
        if (temp == index1)
        {
            return false;
        }
        else if (temp == index2)
        {

            return true;
        }
        temp = temp->next;
    }
    return false;
}
void SortManager::swapNode(CustomLinkedList &list, Node *index1, Node *index2)
{
    if (index1 == nullptr || index2 == nullptr || index1 == index2)
        return;

    // confirming order of nodes , index1 comes before index2
    if (checkOrder(list, index1, index2))
    {
        Node *tempNode = index1;
        index1 = index2;
        index2 = tempNode;
    }

    // Store surrounding nodes
    Node *index1Prev = index1->prev;
    Node *index1Next = index1->next;
    Node *index2Prev = index2->prev;
    Node *index2Next = index2->next;
    bool areAdjacent = (index1->next == index2);
    // dealing with surrounding nodes
    if (index1Prev != nullptr)
    {
        index1Prev->next = index2;
    }
    else
    {
        list.setHead(index2);
    }

    if (index2Next != nullptr)
    {
        index2Next->prev = index1;
    }
    else
    {
        list.setTail(index1);
    }
    // nothing in between
    if (areAdjacent)
    {

        index2->prev = index1Prev;
        index1->prev = index2;
        index1->next = index2Next;
        index2->next = index1;
    }
    else
    {
        // in between elements

        index2->prev = index1Prev;
        index1->prev = index2Prev;
        index1->next = index2Next;
        index2->next = index1Next;
        index2Prev->next = index1;
        index1Next->prev = index2;
    }
}
void SortManager::bubbleSort(CustomLinkedList &list)
{
    if (list.getHead() == nullptr)
        return;
    Node *outerCurrent = list.getHead();
    bool swapPreformed = true;
    while (outerCurrent && swapPreformed)
    {
        swapPreformed = false;
        Node *innerCurrent = list.getHead();
        while (innerCurrent && innerCurrent->next)
        {
            if (innerCurrent->data > innerCurrent->next->data)
            {
                Node *nextNode = innerCurrent->next;
                swapNode(list, innerCurrent, nextNode);
                swapPreformed = true;
                innerCurrent = nextNode; // Continue from swapped position
            }
            else
            {
                innerCurrent = innerCurrent->next;
            }
        }
        outerCurrent = outerCurrent->next;
    }
}

void SortManager::selectionSort(CustomLinkedList &list)
{
    if (list.getHead() == nullptr)
        return;

    Node *outerCurrent = list.getHead();

    while (outerCurrent)
    {
        Node *minNode = outerCurrent;
        Node *innerCurrent = outerCurrent->next;
        while (innerCurrent)
        {
            if (minNode->data > innerCurrent->data)
                minNode = innerCurrent;

            innerCurrent = innerCurrent->next;
        }
        Node *nextNode = outerCurrent->next;
        swapNode(list, minNode, outerCurrent);
        list.printList();
        cout << "----------------" << endl;
        outerCurrent = nextNode;
    }
}

void SortManager::insertionSort(CustomLinkedList &list)
{
    if (list.getHead() == nullptr)
        return;

    Node *outerCurrent = list.getHead();
    outerCurrent = outerCurrent->next;

    while (outerCurrent)
    {
        Node *key = outerCurrent;
        Node *nextNode = outerCurrent->next;
        Node *innerCurrent = outerCurrent->prev;
        list.detach(key);

        while (innerCurrent && innerCurrent->data > key->data)
            innerCurrent = innerCurrent->prev;

        if (innerCurrent == nullptr)
        {
            list.insertBeforeByNode(list.getHead(), key);
        }
        else
        {
            list.insertAfterByNode(innerCurrent, key);
        }
        list.printList();
        cout << "----------------" << endl;
        outerCurrent = nextNode;
    }
}


//Binary search wont be avilabe because it requires random access 
// the best search for linked list right now is inserting since it doesnt require swaps and 
//insertions are o(1)
// bubble sort have the largest amount of swaps but it can be optimized with a swap flag
// selection is by far the worst because it has to do the whole loop to work