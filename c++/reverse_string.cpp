/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
 */

/*
 *
*/

#include "helper.h"

class Solution {
public:
    string reverseString(string s) {
        for (int i = 0; i < s.length() / 2; i++) {
            swap(s[i], s[s.length() - i - 1]);
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseString("hello") << endl;
    cout << s.reverseString("ab") << endl;
    return 0;
}
