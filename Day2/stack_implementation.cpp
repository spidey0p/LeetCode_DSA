#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int size;
    int *arr;
    int top;

public:
    Stack()
    {
        top = -1;
        size = 1000;
        arr = new int[size];
    }
    void push(int x)
    {
        top++;
        arr[top] = x;
    }
    int pop()
    {
        int x = arr[top];
        top--;
        return x;
    }
    int Top()
    {
        return arr[top];
    }
    int Size()
    {
        return top + 1;
    }
};

int main()
{
    Stack s;
    s.push(6);
    s.push(9);
    s.push(69);
    cout << "Top of the stack before deleting the element is:" << s.Top() << endl;
    cout << "Size of the stack before deleting the element is" << s.Size() << endl;
    cout << "The element deleted is:" << s.pop() << endl;
    cout << "Size of the stack after deleting element is:" << s.Size() << endl;
    cout << "Top of the stack after deleting an element is:" << s.Top() << endl;
    return 0;
}