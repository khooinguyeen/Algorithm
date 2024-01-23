/*

2390. Removing Stars From a String
Medium

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.

*/


#include <iostream>
#include <stack>
using namespace std;

class Solution {
    public:
        string removeStars(string s) {
            stack<char> resultStack;
            string resultString;
            for (char i : s) {
                if (i == '*')
                    resultStack.pop();
                else
                    resultStack.push(i);
            }
            while (!resultStack.empty()) {
                resultString += resultStack.top();
                resultStack.pop();
            }
            reverse(resultString.begin(), resultString.end());
            return (resultString);
        }
};

int main()
{
    string s = "leet**cod*e";
    Solution solution;
    cout << solution.removeStars(s);
    return (0);
}
