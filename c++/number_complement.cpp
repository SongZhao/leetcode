/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/

/*
 *
 */

#include "helper.h"

class Solution {
public:
    int findComplement(int num) {
        int res = 0, index = 0;
        while (num) {
            res += (1 - (num & 1)) << (index++);
            num >>= 1;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.findComplement(2) << endl;
    cout << s.findComplement(5) << endl;
    cout << s.findComplement(1) << endl;

    return 0;
}
