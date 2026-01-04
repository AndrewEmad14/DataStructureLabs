#ifndef SORT_MANAGER_H
#define SORT_MANAGER_H
#include "CustomLinkedList.h"
class SortManager
{
public:
    static void swapNode(CustomLinkedList &list, Node *index1, Node *index2);
    static void bubbleSort(CustomLinkedList &list);
    static void selectionSort(CustomLinkedList &list);
    static void insertionSort(CustomLinkedList &list);
    static bool checkOrder(CustomLinkedList &list, Node *index1, Node *index2);
};
#endif