/*
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built
 one character at a time by other words in words. If there is more than one possible answer, return the longest word
 with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input:
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation:
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input:
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation:
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
Note:

All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].
*/

/*
 * Can also use Trie data structure
*/

#include "helper.h"

class Solution {
public:

    struct comp {
        bool operator()(const string &lhs, const string &rhs) const {
            if (lhs.size() > rhs.size())
                return true;
            if (lhs.size() == rhs.size())
                return lhs < rhs;
            return false;
        }
    };

    string longestWord(vector<string> &words) {
        if (words.empty())
            return "";

        //create a set such that the elements are ordered as per their decreasing lengths.
        //If the lengths are equal, then they are ordered lexicographically.
        set<string, comp> s(words.begin(), words.end());

        int i;
        for (auto &it : s) {
            for (i = 1; i < it.size(); i++) {
                string str = it.substr(0, i);
                if (s.find(str) == s.end())
                    break;
            }
            if (i == it.size()) return it;
        }

        return "";
    }
};

int main() {
    Solution s;
    vector<string> words;
    words = {"k", "lg", "it", "oidd", "oid", "oiddm", "kfk", "y", "mw", "kf", "l", "o", "mwaqz", "oi", "ych", "m",
             "mwa"};
    cout << s.longestWord(words) << endl;
    words = {"w", "wo", "wor", "worl", "world"};
    cout << s.longestWord(words) << endl;
    words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << s.longestWord(words) << endl;

    return 0;
}
