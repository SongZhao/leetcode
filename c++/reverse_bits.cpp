/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer
*/

/*
 * reverse first n - k elements, then reverse last k elements, then reverse all elements
*/

#include "helper.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++)
            result = (result << 1) + (n >> i & 1);

        return result;
    }
};

int main() {
    Solution s;
    uint32_t n = 43261596;
    cout << s.reverseBits(n) << endl;
    return 0;
}
