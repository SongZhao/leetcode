/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.

*/

/*
 * Get tail first for case s ends with spaces
*/

#include "helper.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int tail = s.size() - 1;
        while (s[tail] == ' ') {
            tail--;
        }
        for (int i = tail; i >= 0; i--) {
            if (s[i] == ' ') {
                return tail - i;
            }
        }

        return tail + 1;
    }

};

int main() {
    Solution s;
    cout << s.lengthOfLastWord("") << endl;
    cout << s.lengthOfLastWord("hello") << endl;
    cout << s.lengthOfLastWord("Hello World") << endl;
    cout << s.lengthOfLastWord("a  ") << endl;
    return 0;
}
