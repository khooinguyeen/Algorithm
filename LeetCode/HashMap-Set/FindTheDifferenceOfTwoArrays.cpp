/*
2215. Find the Difference of Two Arrays
Easy

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> nums1Set(nums1.begin(), nums1.end());
            unordered_set<int> nums2Set(nums2.begin(), nums2.end());

            vector<int> diff1, diff2;

            // Find elements in nums1 but not in nums2
            for (int num : nums1Set) {
                if (nums2Set.find(num) == nums2Set.end()) {
                    diff1.push_back(num);
                }
            }

            // Find elements in nums2 but not in nums1
            for (int num : nums2Set) {
                if (nums1Set.find(num) == nums1Set.end()) {
                    diff2.push_back(num);
                }
            }

            // Return the results as a vector of vectors
            return {diff1, diff2};
        }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 3};
    vector<int> nums2 = {1, 1, 2, 2};
    vector<vector<int>> result = solution.findDifference(nums1, nums2);
    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return (0);
}