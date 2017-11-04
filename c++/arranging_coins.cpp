/*
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
 */

/*
 * Binary search
*/

#include "helper.h"

class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 1) {
            return 1;
        }
        long start = 0, end = n;
        while (end - start > 1) {
            long mid = (end - start) / 2 + start;
            if ((1 + mid) * mid / 2 == n) {
                return mid;
            } else if ((1 + mid) * mid / 2 < n) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return start;
    }
};

int main() {
    Solution s;
    cout << s.arrangeCoins(1) << endl;
    cout << s.arrangeCoins(2) << endl;
    cout << s.arrangeCoins(5) << endl;
    cout << s.arrangeCoins(8) << endl;
    cout << s.arrangeCoins(1804289383) << endl;

    return 0;
}
