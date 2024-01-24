/*

933. Number of Recent Calls
Easy

You have a RecentCounter class which counts the number of recent requests within a certain time frame.

Implement the RecentCounter class:

RecentCounter() Initializes the counter with zero recent requests.
int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.

*/

#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
private:
    queue<int> requests;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        int limit = t - 3000;
        requests.push(t);
        while (!requests.empty() && requests.front() < limit)
        {
            requests.pop();
        }
        return (requests.size());
    }
};

int main()
{
    RecentCounter *recentCounter = new RecentCounter();
    cout << recentCounter->ping(1) << endl;
    cout << recentCounter->ping(100) << endl;
    cout << recentCounter->ping(3001) << endl;
    cout << recentCounter->ping(3002) << endl;
    return (0);
}