#include "../headers/CustomLinkedList.h"
#include <iostream>
#include "../headers/SortManager.h"
using namespace std;

void SortManager::bubbleSort(CustomLinkedList &list)
{
    Node *innerCurrent = list.getNode(0);
    Node *outerCurrent = list.getNode(0);
    while (outerCurrent)
    {
        while (innerCurrent->next)
        {
            if (innerCurrent->data > innerCurrent->next->data)
            {
                int temp = innerCurrent->data;
                innerCurrent->data = innerCurrent->next->data;
                innerCurrent->next->data = temp;
            }
            innerCurrent = innerCurrent->next;
        }
        innerCurrent = list.getNode(0);
        outerCurrent = outerCurrent->next;
    }
}