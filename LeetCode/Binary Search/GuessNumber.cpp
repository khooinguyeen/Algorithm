/*

374. Guess Number Higher or Lower
Easy 

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.

*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

using namespace std;
int guess(int num){}
class Solution {
public:
    int guessNumber(int n) {
        return (binarySearch(1, n));
    }

    int binarySearch(int low, int high)
    {
        int middle = low + (high - low)/2;
        if (guess(middle) == 0)
            return (middle);
        if (guess(middle) == -1)
            return (binarySearch(low, middle - 1));
        else
            return (binarySearch(middle + 1, high));
    }
};

class Solution2 {
    public:
    int guessNumber(int n) {
        int l = 1;
        while(l <= n) {
            int m = l + (n - l) / 2;
            int r = guess(m);
            if(r == 0) return m;
            if(r == 1) {
                l = m + 1;
            } else n = m - 1;
        }
        return l;
    }
};