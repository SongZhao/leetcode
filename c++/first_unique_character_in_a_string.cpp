/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
 */

/*
 * Hash
*/

#include "helper.h"

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int,int>> dict;
        int res = s.size();
        for (int i = 0;i < s.length();i++) {
            dict[s[i]].first++;
            dict[s[i]].second = i;
        }
        for (auto &it: dict) {
            if (it.second.first == 1) {
                res = min(res, it.second.second);
            }
        }

        return res == s.size() ? -1 : res;
    }
};

int main() {
    Solution s;
    cout << s.firstUniqChar("leetcode") << endl;
    cout << s.firstUniqChar("loveleetcode") << endl;
    cout << s.firstUniqChar("") << endl;

    return 0;
}
