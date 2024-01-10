#include <iostream>
#include <queue>

using namespace std;

void showQueue(queue<int> q)
{
    queue<int> tempQueue = q;
    while (!tempQueue.empty())
    {
        cout << '\t' << tempQueue.front();
        tempQueue.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> myQueue;

    myQueue.push(10);
    myQueue.push(17);
    myQueue.push(42);
    cout << " The queue is: ";
    showQueue(myQueue);
    cout << "\nqueue.size():\t" << myQueue.size();
    cout << "\nqueue.front():\t" << myQueue.front();
    cout << "\nqueue.back():\t" << myQueue.back();
    cout << "\nqueue.pop():";
    myQueue.pop();
    showQueue(myQueue);
    cout << "Time Complexity of all functions: O(1)";
    return (0);
}