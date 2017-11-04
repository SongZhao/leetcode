/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

/*
 * Sliding window
*/

#include "helper.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.length() < p.length() ){
            return res;
        }
        unordered_map<char, int> dict;

        for (char c:p) {
            dict[c]++;
        }

        int start = 0, end = 0, counter = dict.size();
        while (end < s.length()) {
            char c = s[end];
            if (dict.find(c) != dict.end()) {
                dict[c]--;
                if (dict[c] == 0) {
                    counter--;
                }
            }
            end++;

            while (counter == 0) {
                char tmp = s[start];
                if (dict.find(tmp) != dict.end()) {
                    dict[tmp]++;
                    if (dict[tmp] > 0) {
                        counter++;
                    }
                }
                if (end - start == p.length()) {
                    res.push_back(start);
                }
                start++;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.findAnagrams("", "a") << endl;
    cout << s.findAnagrams("cbaebabacd", "abc") << endl;
    cout << s.findAnagrams("abab", "ab") << endl;
    return 0;
}
