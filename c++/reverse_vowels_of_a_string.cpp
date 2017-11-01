/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
 */

/*
 * two pointers
*/

#include "helper.h"

class Solution {
public:
    string reverseVowels(string s) {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            while (i < j && !isVowel(s[i])) {
                i++;
            }
            while (i < j && !isVowel(s[j])) {
                j--;
            }
            swap(s[i], s[j]);
        }
        return s;
    }

private:
    bool isVowel(char c) {
        return tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u';
    }
};

int main() {
    Solution s;
    cout << s.reverseVowels("hello") << endl;
    cout << s.reverseVowels("leetcode") << endl;
    cout << s.reverseVowels("aA") << endl;
    return 0;
}
