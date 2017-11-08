/*
Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

Example:

Input: 2

Output: 987

Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

Note:

The range of n is [1,8].
*/

/*
 *
 */

#include "helper.h"

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        long largest = 0;
        long high = long(pow(10, n)) - 1, low = (high + 1) / 10;
        for (long i = high; i >= low; i--) {
            string s = to_string(i);
            string t(s);
            reverse(t.begin(), t.end());
            long palindrome = stol(s + t);
            for (long j = high; j * j >= palindrome; j--) {
                if (palindrome % j == 0) {
                    return palindrome % 1337;
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    cout << s.largestPalindrome(1) << endl;
    cout << s.largestPalindrome(2) << endl;
    cout << s.largestPalindrome(3) << endl;
    cout << s.largestPalindrome(4) << endl;
    cout << s.largestPalindrome(5) << endl;
    cout << s.largestPalindrome(6) << endl;
    cout << s.largestPalindrome(7) << endl;
    cout << s.largestPalindrome(8) << endl;


    return 0;
}
