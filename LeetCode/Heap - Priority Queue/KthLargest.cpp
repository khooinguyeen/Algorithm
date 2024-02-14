/*

215. Kth Largest Element in an Array
Medium

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

*/

#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums)
        {
            if (minHeap.size() < static_cast<size_t>(k))
                minHeap.push(num);
            else if (num > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(num);
            }
        }
        return (minHeap.top());
    }
};

int main()
{
    vector<int> nums = {3, 5, 2, 7, 1, 8, 8};
    int k = 3;
    Solution solution;
    cout << solution.findKthLargest(nums, k) << endl;
    return (0);
}