#ifndef CUSTOM_LINKED_LIST_H
#define CUSTOM_LINKED_LIST_H
#include "Node.h"
class CustomLinkedList
{
    Node *head;
    Node *tail;

public:
    CustomLinkedList();
    // add data to the end of the linked list
    bool add(int data);
    int findFirst(int data);
    // remove data at a certain index
    bool removeAt(int index);
    //remove the first occurence of data
    bool removeFirstData(int data);
    // 1. insert node after given node
    bool insertAfter(int data, int afterData);
    bool insertAfterByIndex(int data,int index);
    // 2. insert node before given node
    bool insertBefore(int data, int beforeData);
    bool insertBeforeByIndex(int data,int index);

    // 3. get number of nodes
    int getCount();
    // 4. get data in the given
    int getDataByIndex(int index);
    // 5. Remove All Nodes
    void removeALL(int data);
    // print list
    void printList();
    Node* getNode(int index);
};
#endif
