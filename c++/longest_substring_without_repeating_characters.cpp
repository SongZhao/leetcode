/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


/*
 *
*/

#include "helper.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int maxLen = 0, start = -1;
        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) != map.end() && map[s[i]] > start) {
                start = map[s[i]];
            }
            map[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abba") << endl;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("dvdf") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;

    return 0;
}
