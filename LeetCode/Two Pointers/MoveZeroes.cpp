/*
283. Move zeroes
Easy

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (auto i = nums.rbegin(); i != nums.rend(); ++i) {
            // swap 0 with non-zero
            cout << *i << endl;
            if (*i == 0) {
                auto j = std::next(i).base(); // Convert reverse iterator to a forward iterator
                std::rotate(j, std::next(j), nums.end());
            }
        }
    }
};

int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(0); 
    v.push_back(3); 
    v.push_back(6);
    v.push_back(0);
    v.push_back(2);
    v.push_back(3);
    for (auto it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
    Solution mysol;
    mysol.moveZeroes(v);
    cout << endl;
    for (auto it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
    return (0); 
    }