
#include "../headers/Node.h"
Node::Node(int val) : data(val), next(nullptr), prev(nullptr) {}
Node::Node() : data(0), next(nullptr), prev(nullptr) {}
int Node::getData() const { return data; }
Node *Node::getNext() const { return next; }
Node *Node::getPrev() const { return prev; }
void Node::setNext(Node *nxt) { next = nxt; }
void Node::setPrev(Node *prv) { prev = prv; }
