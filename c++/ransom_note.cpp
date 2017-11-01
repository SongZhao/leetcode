/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
 */

/*
 * Hash
*/

#include "helper.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dict;
        for (char c:magazine) {
            dict[c]++;
        }
        for (char c:ransomNote) {
            if (--dict[c] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.canConstruct("a", "b") << endl;
    cout << s.canConstruct("aa", "ab") << endl;
    cout << s.canConstruct("aa", "aab") << endl;

    return 0;
}
