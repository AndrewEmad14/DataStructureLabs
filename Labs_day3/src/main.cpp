#include <iostream>
#include "../headers/CustomLinkedList.h"
#include "../headers/SortManager.h"
using namespace std;

int main(void)
{
  CustomLinkedList myLinkedList;
  myLinkedList.add(5);
  myLinkedList.add(20);
  myLinkedList.add(12);
  myLinkedList.add(1);
  myLinkedList.add(7);
  SortManager::bubbleSort(myLinkedList);
  try
  {
    myLinkedList.printList();
  }
  catch (logic_error &e)
  {
    cout << e.what() << endl;
  }
  return 0;
}
