/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 */

/*
 * Brute force. Find the number first, then digit is the index th digit of num
*/

#include "helper.h"

class Solution {
public:
    int findNthDigit(int n) {
        long base = 9;
        int digits = 1;
        while (n - base * digits > 0) {
            n -= base * digits;
            base *= 10;
            digits++;
        }

        int num = (n - 1) / digits + base / 9;

        int index = (n - 1) % digits + 1;

        for (int i = 0; i < digits - index; i++) {
            num /= 10;
        }

        return num % 10;

    }
};

int main() {
    Solution s;

    cout << s.findNthDigit(1000000000) << endl;
    cout << s.findNthDigit(250) << endl;
    cout << s.findNthDigit(11) << endl;
    cout << s.findNthDigit(3) << endl;
    return 0;
}
