/*
1732. Find the Highest Altitude
Easy

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for 
all (0 <= i < n). Return the highest altitude of a point.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int largestAltitude(vector<int>& gain)
        {
            vector<int> prefixSum(gain.size() + 1);
            int highestAltitude = 0;
            cout << gain.size() << endl;
            prefixSum[0] = 0;
            for (size_t i = 1; i <= gain.size(); i++)
            {
                prefixSum[i] = prefixSum[i - 1] + gain[i - 1];
                highestAltitude = max(highestAltitude, prefixSum[i]);
            }
            return (highestAltitude);
        }
};

class Solution2 {
    public:
        int largestAltitude(vector<int>& gain) {
            int maxi = 0;
        int sum = 0;
        for(int i = 0 ;i < gain.size();i++)
        {
            sum += gain[i];
            maxi = max(maxi,sum);
        }
        return maxi;
        }
};

int main()
{
    vector<int> netGain = {44,32,-9,52,23,-50,50,33,-84,47,-14,84,36,-62,37,81,-36,-85,-39,67,-63,64,-47,95,91,-40,65,67,92,-28,97,100,81};
    Solution mySolution;
    cout << mySolution.largestAltitude(netGain);
    return (0);
}