#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// head is considered as top
class Stack
{
    Node *top; // head
    int maxsize;
    int currentsize;

public:
    Stack(int size) : top(nullptr), maxsize(size), currentsize(0) {}
    bool isEmpty();
    bool isFull();
    int push(int x);
    int pop();
    int peek();
};

// function to check if stack is empty or not
bool Stack::isEmpty()
{
    if (top == nullptr)
        return true;
    else
        return false;
}

// function to check if stack is full or not
bool Stack::isFull()
{
    if (currentsize == maxsize)
        return true;
    else
        return false;
}

// function to push element in stack
int Stack::push(int x)
{
    if (isFull()) // is sttack is full
    {
        cout << "Stack Overflow\n";
        return INT16_MIN;
    }
    Node *newnode = new Node(x);
    newnode->next = top; // basically insertion at head
    top = newnode;
    currentsize++;
    return x;
}

// function to pop element in stack
int Stack::pop()
{
    if (isEmpty()) // if stack is empty
    {
        cout << "Stack Undeflow\n";
        return INT16_MIN;
    }
    Node *temp = top; // basically deletion at head
    top = top->next;
    int result = temp->data;
    delete temp;
    currentsize--;
    return result; // return deleted element
}

// function to get top element without removing it
int Stack::peek()
{
    if (isEmpty()) // if stack is empty
    {
        cout << "Stack is empty\n";
        return INT16_MIN;
    }
    else
        return top->data; // return valur at top
}

int main()
{
    Stack s(10);
    cout << "isEmpty(): " << s.isEmpty() << endl;
    cout << "isFull(): " << s.isFull() << endl;
    cout << "peek(): " << s.peek() << endl;
    cout << endl;

    cout << "Pushing elements:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << s.push(i + 1) << " ";
    }
    cout << endl;

    cout << "isEmpty(): " << s.isEmpty() << endl;
    cout << "isFull(): " << s.isFull() << endl;
    cout << "peek(): " << s.peek() << endl;
    cout << endl;

    cout << "popping elements:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << s.pop() << " ";
    }
    cout << endl;

    cout << "isEmpty(): " << s.isEmpty() << endl;
    cout << "isFull(): " << s.isFull() << endl;
    cout << "peek(): " << s.peek() << endl;
    cout << endl;
}