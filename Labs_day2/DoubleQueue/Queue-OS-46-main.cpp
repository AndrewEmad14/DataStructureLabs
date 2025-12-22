#include <iostream>
using namespace std;

/*
Simple Queue :
  problems : deleted Elements cant Be reused
  solution : Circular Queue

Delete ===> Front
Insert ===> Rear
==================================================
Circular Queue
Delete ===> Front
Insert ===> Rear
==================================================
Priority Queue

Delete ===> Priority, Front
Insert ===>  Rear
==================================================
Double Ended Queue
=============================
Input Restricted  [One Inertion , Both Delete]
insertRear();
deleteFront();
deleteRear();


Output Restricted
insertRear();
insertFront();
deleteFront();


*/
class MinaQueue
{
private:
    int *items;
    int rear; // EnterIndex
    // int fornt; //OutIndex
    int capicty;
    int size;

public:
    int fornt; // OutIndex
    MinaQueue(int capicty)
    {
        rear = -1;
        fornt = -1;
        // size=0;
        this->capicty = capicty;
        items = new int[capicty];
    }
    ~MinaQueue()
    {
        delete[] items;
    }

    void insertRear(int item)
    {
        // Check Full
        if ((fornt == 0 && rear == capicty - 1) || (fornt == rear + 1))
        {
            // if(size == capicty){}
            // Resize Dynamic Array
            cout << "is Full " << endl;
            return;
        }

        // Setting Rear and Front
        // First Element
        if (rear == -1 && fornt == -1)
        {
            rear = 0;
            fornt = 0;
        }
        else if (rear == capicty - 1)
        { //&& fornt != 0
            rear = 0;
        }
        else
        {
            rear++;
        }
        // Add item
        items[rear] = item;
        // size++;
    }
    int deleteFront()
    {
        // Check Empty
        if (fornt == -1)
        {
            cout << "Empty Queue";
            return -1;
        }
        // if(size == 0 ){cout<<"Empty Queue" ; return -1;}

        // Backup Item
        int temp = items[fornt];
        // Delete Item
        items[fornt] = -10; //-10 for Debug
        // Change Front and Rear
        if (fornt == rear)
        {
            fornt = -1;
            rear = -1;
        }
        else if (fornt == capicty - 1)
        {
            fornt = 0;
        }
        else
        {
            fornt++;
        }
        // return Item
        // size--;
        return temp;
    }

    void display()
    {
        cout << "\n========================================\n";

        // Empty
        if (fornt == -1)
        {
            cout << "Empty Queue";
            return;
        }
        /*if(fornt <= rear){
            for (int i= fornt ; i<= rear; i++){
                cout<<items[i]<< "\t";
            }
        }else { //fornt >= rear
            for (int i= fornt ; i< capicty; i++){
                cout<<items[i]<< "\t";
            }
            for (int i= 0 ; i<= rear; i++){
                cout<<items[i]<< "\t";
            }

        }*/
        // rear =0 front =1
        // fornt 3   rear = 2   3 4 0 1 2
        int i = (fornt) % capicty; // 3%5 ===> 3
        while (i != rear)
        {
            cout << items[i] << "\t";
            i = (i + 1) % capicty;
        }
        cout << items[rear];
        cout << "\n========================================\n";
    }

    void insertFront(int item)
    {
        // check Full
        if ((fornt == 0 && rear == capicty - 1) || (fornt == rear + 1))
        {
            // if(size == capicty){}
            // Resize Dynamic Array
            cout << "is Full " << endl;
            return;
        }

        // Setting Rear and Front
        // First Element
        if (rear == -1 && fornt == -1)
        {
            rear = 0;
            fornt = 0;
        }
        else if (fornt == 0)
        { //&& fornt != 0
            fornt = capicty - 1;
        }
        else
        {
            fornt--;
        }
        // Add item
        items[fornt] = item;
    }
    int deleteRear()
    {
        // Check Empty
        if (rear == -1)
        {
            cout << "Empty Queue";
            return -1;
        }
        // if(size == 0 ){cout<<"Empty Queue" ; return -1;}

        // Backup Item
        int temp = items[rear];
        // Delete Item
        items[rear] = -10; //-10 for Debug
        // Change Front and Rear
        if (fornt == rear)
        {
            fornt = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = capicty - 1;
        }
        else
        {
            rear--;
        }
        // return Item
        // size--;
        return temp;
    }
};

int main()
{
    MinaQueue q(10);
    q.insertRear(10);
    q.insertRear(20);
    q.insertRear(30);
    q.insertRear(40);
    q.insertRear(50);
    q.insertRear(60);
    q.insertFront(5);
    q.display();                                   // 10 20 30 40 50
    cout << "data is " << q.deleteRear() << endl;  // 10
    cout << "data is " << q.deleteRear() << endl;  // 20
    q.display();                                   // 30 40 50
    q.insertRear(70);                              // rear = 0
    q.insertRear(80);                              // rear = 1
    q.display();                                   // 30 40 50 70 80
    cout << "data is " << q.deleteRear() << endl;  // 30
    cout << "data is " << q.deleteRear() << endl;  // 40
    cout << "data is " << q.deleteFront() << endl; // 50
    cout << "data is " << q.deleteFront() << endl; // 70
    cout << "data is " << q.deleteFront() << endl; // 80
    cout << "data is " << q.deleteFront() << endl; // Empty -1
    q.display();                                   // Empty

    q.insertRear(90);
    q.insertRear(100);
    q.insertRear(1000);
    q.display(); // 90 100 1000

    return 0;
}
