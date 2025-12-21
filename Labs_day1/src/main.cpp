#include <iostream>
#include "../headers/CustomLinkedList.h"
using namespace std;

int main(void)
{
  CustomLinkedList myLinkedList;
  myLinkedList.add(2);
  myLinkedList.add(2);
  myLinkedList.add(2);
  myLinkedList.add(2);
  myLinkedList.add(2);

  myLinkedList.printList();
  cout << myLinkedList.getCount() << endl;
  try
  {
    cout << myLinkedList.getDataByIndex(-1) << endl;
  }
  catch (invalid_argument &e)
  {
    cout << e.what() << endl;
  }
  cout << "find first function: " << myLinkedList.findFirst(100) << endl;
  cout << "Remove all occurrences of 2: " << myLinkedList.removeALL(2) << endl;
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
