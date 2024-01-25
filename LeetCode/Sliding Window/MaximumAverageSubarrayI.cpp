/*
Easy

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            int current_sub = 0;

            for (int i = 0; i < k; ++i)
            {
                current_sub += nums[i];
            }

            double max_sum = current_sub;

            for (size_t i = 1; i < (nums.size() - k + 1); ++i)
            {
                if (current_sub >= max_sum)
                    max_sum = current_sub;
                current_sub -= nums[i - 1];
                current_sub += nums[i + k - 1];
            }

            if (current_sub >= max_sum)
                    max_sum = current_sub;

            return (max_sum / k);
        }
};

class Solution2 {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans  = 0;
        double sum = 0;
        for(int i =0; i < k;i++)
        {
            sum += nums[i];
        }
        ans = sum; 
        for(int i = k ;i < nums.size();i++)
        {
            sum += nums[i];
            sum -= nums[i-k];
            ans = max(ans,sum);
        }
        return (ans/k) ;
    }
};

int main()
{
    vector<int> numbers = {8860,-853,6534,4477,-4589,8646,-6155,-5577,-1656,-5779,-2619,-8604,-1358,-8009,4983,7063,3104,-1560,4080,2763,5616,-2375,2848,1394,-7173,-5225,-8244,-809,8025,-4072,-4391,-9579,1407,6700,2421,-6685,5481,-1732,-8892,-6645,3077,3287,-4149,8701,-4393,-9070,-1777,2237,-3253,-506,-4931,-7366,-8132,5406,-6300,-275,-1908,67,3569,1433,-7262,-437,8303,4498,-379,3054,-6285,4203,6908,4433,3077,2288,9733,-8067,3007,9725,9669,1362,-2561,-4225,5442,-9006,-429,160,-9234,-4444,3586,-5711,-9506,-79,-4418,-4348,-5891};
    int k = 93;
    Solution1 mySolution;
    cout << mySolution.findMaxAverage(numbers, k) << endl;
    return (0);
}