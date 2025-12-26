#ifndef NODE_H
#define NODE_H
class Node
{

public:
  int data;
  Node *next;
  Node *prev;
  Node(int val);
  Node();
  int getData() const;
  Node *getNext() const;
  Node *getPrev() const;
  void setNext(Node *nxt);
  void setPrev(Node *prv);
};
#endif
