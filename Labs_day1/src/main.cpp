#include <iostream>
#include "../headers/CustomLinkedList.h"
using namespace std;

int main(void)
{
    CustomLinkedList myLinkedList;
    myLinkedList.add(1);
    myLinkedList.add(2);
    myLinkedList.add(3);
    myLinkedList.removeAt(1);
    myLinkedList.printList();
    cout << myLinkedList.getCount() << endl;

    return 0;
}
