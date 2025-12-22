#include <iostream>

using namespace std;
class Exception
{
public:
    int code;
    char *name;
};
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedQueue
{

    Node *head;

public:
    LinkedQueue()
    {
        head = NULL;
    }
    void push(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    int pop()
    {
        if (head == NULL)
        {
            // cout<<"Error  Stack is Empty";
            Exception e;
            e.code = 404;
            e.name = "Queue Empty";
            throw e;
            // return -1;
        }
        Node *temp = head;
        head = head->next;
        int data = temp->data;
        delete temp;
        return data;
    }

    void display()
    {
        Node *current = head;
        cout << "\n ============================ \n";
        while (current != NULL)
        {
            cout << current->data << "\t";
            current = current->next;
        }
        cout << "\n ============================ \n";
    }
};

int main()
{
    LinkedQueue s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.display();
    try
    {
        s.pop(); // 10
        s.pop(); // 20
        s.pop(); // 30
        s.pop(); // 40
    }
    catch (Exception e)
    {
        cout << e.name;
    }
    s.display(); // 20 10
    // cout << "Hello world!" << endl;
    return 0;
}
