/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n > 0) {
            n /= 5;
            res+= n;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.trailingZeroes(10) << endl;
    cout << s.trailingZeroes(1) << endl;
    return 0;
}
