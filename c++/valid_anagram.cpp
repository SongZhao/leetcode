/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for (char c:s) {
            if (map.find(c) == map.end()) {
                map[c] = 1;
            } else {
                map[c]++;
            }
        }

        for (char c:t) {
            if (map.find(c) == map.end()) {
                return false;
            } else {
                map[c]--;
            }
        }

        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second != 0) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    Solution s;
    cout << s.isAnagram("anagram", "nagaram") << endl;
    cout << s.isAnagram("rat", "car") << endl;
    return 0;
}
