/*

841. Keys and Rooms
Medium


There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. 
Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
When you visit a room, you may find a set of distinct keys in it. 
Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, 
return true if you can visit all the rooms, or false otherwise.

*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        vector<int> check;
        stack<int> keys;

        check.push_back(0);
        keys.push(0);

        while (!keys.empty())
        {
            int current_room = keys.top();
            cout << current_room << " ";
            keys.pop();
            for (int k : rooms[current_room])
            {
                if (find(check.begin(), check.end(), k) == check.end())
                {
                    check.push_back(k);
                    keys.push(k);
                }
            }
        }
        if (check.size() == rooms.size())
            return (true);
        return (false);
    }
};


class Solution2 
{
    public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int roomNums = rooms.size();
        queue<int> q;
        vector<bool> visited(roomNums,false);
        
        visited[0] = true;
        q.push(0);
        
        while(!q.empty()){
            int currentRoom = q.front();
            q.pop();
            
            for(int key : rooms[currentRoom]){
                if(!visited[key]){
                    visited[key] = true;
                    q.push(key);
                }
            }
        }
        
        for(bool alreadyVisited : visited){
            if(!alreadyVisited) return false;
        }
        return true;
    }
};


int main()
{
    vector<vector<int>> rooms;
    rooms.push_back({1});
    rooms.push_back({2});
    rooms.push_back({3});
    rooms.push_back({});
    Solution2 solution;
    cout << solution.canVisitAllRooms(rooms);
    return (0);
}