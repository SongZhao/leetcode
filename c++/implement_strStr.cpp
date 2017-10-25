/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

/*
 * 
*/

#include "helper.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) {
            return -1;
        }
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            int j = 0;
            for (; j < needle.size() && needle[j] == haystack[i + j]; j++) {

            }
            if (j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.strStr("abcd", "ab") << endl;
    cout << s.strStr("abcd", "cd") << endl;
    cout << s.strStr("abcd", "dc") << endl;

    return 0;
}
