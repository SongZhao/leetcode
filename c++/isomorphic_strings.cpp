/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

/*
 * Note that no two characters may map to the same character
*/

#include "helper.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_map<char, bool> mappedChars;
        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) == map.end()) {
                if (mappedChars.find(t[i]) != mappedChars.end()) {
                    return false;
                }
                mappedChars[t[i]] = true;
                map[s[i]] = t[i];
            } else {
                if (map[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isIsomorphic("egg", "add") << endl;
    cout << s.isIsomorphic("foo", "bar") << endl;
    cout << s.isIsomorphic("paper", "title") << endl;
    cout << s.isIsomorphic("bc", "aa") << endl;
    return 0;
}
