#ifndef SORT_MANAGER_H
#define SORT_MANAGER_H
#include "CustomLinkedList.h"
class SortManager
{
public:
    static void bubbleSort(CustomLinkedList &list);
    static void selectionSort(CustomLinkedList &list);
};
#endif