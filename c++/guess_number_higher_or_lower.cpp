/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.
 */

/*
 * Binary Search
*/

#include "helper.h"

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long start = 1, end = n;
        while (end >= start) {
            long mid = (end - start) / 2 + start;
            if (guess(mid) == 0) {
                return mid;
            } else if (guess(mid) == -1) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};

int guess(int num) {
    if (num == 6) {
        return 0;
    } else if (num < 6) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    Solution s;
    cout << s.guessNumber(10) << endl;

    return 0;
}
