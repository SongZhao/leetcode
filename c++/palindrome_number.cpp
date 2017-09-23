/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

/*
 * A negative number is not a palindrome. O(logN)
*/

#include "helper.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int y = 0;
        int tmp = x;
        while (tmp != 0) {
            int residual = tmp % 10;
            tmp /= 10;
            y = y * 10 + residual;
        }
        return x == y;
    }
};

int main() {
    Solution s;
    int x = 0;
    cout << s.isPalindrome(x) << endl;
    x = 12121;
    cout << s.isPalindrome(x) << endl;
    x = 121121;
    cout << s.isPalindrome(x) << endl;
    x = 122321;
    cout << s.isPalindrome(x) << endl;
    return 0;
}
