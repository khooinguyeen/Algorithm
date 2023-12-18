#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int num = 0;

    stack<int> myStack;
    myStack.push(42);
    myStack.push(21);
    myStack.push(22);
    myStack.push(24);
    myStack.push(42);
    myStack.push(num);
    myStack.pop();
    myStack.pop();
    myStack.pop();

    while (!myStack.empty())
    {
        cout << myStack.top() << endl;
        myStack.pop();
    }
}