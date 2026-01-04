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
  bool detach(Node *target);
  // remove the first occurence of data

  bool removeFirstData(int data);
  // 1. insert node after given node
  bool insertAfter(int afterData, int data);
  bool insertAfterByIndex(int index, int data);
  bool insertAfterByNode(Node *current, Node *target);
  // 2. insert node before given node
  bool insertBefore(int beforeData, int data);
  bool insertBeforeByIndex(int index, int data);
  bool insertBeforeByNode(Node *current, Node *target);
  void setHead(Node *newHead);
  void setTail(Node *newTail);
  Node *getHead() const;
  Node *getTail() const;
  // 3. get number of nodes
  int getCount();
  // 4. get data in the given
  int getDataByIndex(int index);
  // 5. Remove All Nodes
  bool removeALL(int data);
  // print list
  void printList();
  Node *getNode(int index);
};
#endif
